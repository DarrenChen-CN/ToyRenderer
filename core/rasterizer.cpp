#include "rasterizer.h"
#include "mathutil.h"
#include<iostream>
Rasterizer::Rasterizer(int width, int height):width(width), height(height){
    renderbuffer = new RenderBuffer(width, height);
}

Rasterizer::Rasterizer(int width, int height, Sceen sceen):width(width), height(height){
    renderbuffer = new RenderBuffer(width, height);
    shadow = new ShadowMap(width, height);
    shadowShader = new ShadowShader();
    this -> sceen = sceen;
}

Rasterizer::~Rasterizer(){
    delete[] renderbuffer;
}

void Rasterizer::drawTriangle(Triangle triangle, Shader* shader, FragmentData& fragmentData){
    Texture* texture = fragmentData.texture;
    // 计算bounding box
    int minX = std::min(triangle.screen[0](0), std::min(triangle.screen[1](0), triangle.screen[2](0)));
    int minY = std::min(triangle.screen[0](1), std::min(triangle.screen[1](1), triangle.screen[2](1)));
    int maxX = std::max(triangle.screen[0](0), std::max(triangle.screen[1](0), triangle.screen[2](0))) + 1;
    int maxY = std::max(triangle.screen[0](1), std::max(triangle.screen[1](1), triangle.screen[2](1))) + 1;
    // std::cout << minX << " " << minY << " " << maxX << " " << maxY << std::endl;
    for(int i = minX; i <= maxX; i ++){
        for(int j = minY; j <= maxY; j ++){
            auto [alpha, beta, gamma] = computeBarycentric(triangle.screen, i + 0.5, j + 0.5);
            if(alpha < 0 || beta < 0 || gamma < 0)continue; // 点在三角形外
            // std::cout << alpha << " " << beta << " " << gamma << std::endl;
            float zInterpolation = alpha * triangle.screen[0](2) + beta * triangle.screen[1](2) + gamma * triangle.screen[2](2);
            Eigen::Vector3f color;
            if(texture != NULL){
                // 纹理坐标插值
                Eigen::Vector2f uvInterpolation = triangle.texCoords[0] * alpha + triangle.texCoords[1] * beta + triangle.texCoords[2] * gamma;
                Eigen::Vector4f posInterpolation = triangle.points[0] * alpha + triangle.points[1] * beta + triangle.points[2] * gamma;
                Eigen::Vector3f normalInterpolation = triangle.normals[0] * alpha + triangle.normals[1] * beta + triangle.normals[2] * gamma;
                fragmentData.postion = posInterpolation;
                fragmentData.normal = normalInterpolation;
                fragmentData.uv = uvInterpolation;
                // 计算阴影
                float isShadow = 0;
                VertexData vertexData;
                vertexData.position = posInterpolation;
                // std::cout << posInterpolation(0) << " " << posInterpolation(1) << " " << posInterpolation(2) << std::endl;
                Eigen::Vector4f shadowScreen = shadowShader -> vertexShader(vertexData); // 切换到光源空间
                // std::cout << shadowScreen(0) << " " << shadowScreen(1) << " " << shadowScreen(2) << std::endl;
                float bias = 0.1;
                if(shadow -> queryDepth(shadowScreen(0), shadowScreen(1)) < shadowScreen(2) - bias)isShadow = 1;
                // std::cout << shadow -> queryDepth(shadowScreen(0), shadowScreen(1)) << " " << shadowScreen(2) + 1e-3 << std::endl;
                fragmentData.shadow = isShadow; 
                color = shader -> fragmentShader(fragmentData);
            }
            else color = alpha * triangle.colors[0] + beta * triangle.colors[1] + gamma * triangle.colors[2];
            renderbuffer->setPixel(i, j, zInterpolation, color);
        }
    }
}

void Rasterizer::draw(){
    computeShadow();
    // for(int i = 0; i < width * height; i ++){
    //     if(shadow -> depthBuffer[i] > -99999)std::cout << i << " " << shadow -> depthBuffer[i] << std::endl;
    // }
    for(Model model: sceen.modelList){
        for(Triangle triangle: model.triangleList){
            VertexData vertexData;
            FragmentData fragmentData;
            for(int i = 0; i < 3; i ++){ 
                vertexData.position = triangle.points[i];
                triangle.screen[i] = model.shader -> vertexShader(vertexData);
            }
            fragmentData.light = sceen.light;
            fragmentData.texture = model.texture;
            fragmentData.viewPos = sceen.camera.position;
            drawTriangle(triangle, model.shader, fragmentData);
        }
    }
}

void Rasterizer::computeShadow(){
    Eigen::Vector3f lightPos = sceen.light -> lightPos;
    // std::cout << lightPos << std::endl;
    Eigen::Vector3f center = sceen.camera.center;
    Eigen::Vector3f up = sceen.camera.up;

    float near = -0.1, far = -50, right = 3, top = 3;
    Eigen::Matrix4f view = lookat(lightPos, center, up);
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f projection = orthographic(near, far, right, top);
    Eigen::Matrix4f viewportMatrix = viewport(width, height, sceen.camera.near, sceen.camera.far);

    shadowShader->setModel(model);
    shadowShader->setView(view);
    shadowShader->setProjection(projection);
    shadowShader->setViewport(viewportMatrix);
    shadowShader->calMVP();

    for(Model model: sceen.modelList){
        for(Triangle triangle: model.triangleList){
            VertexData vertexData;
            FragmentData fragmentData;
            for(int i = 0; i < 3; i ++){ 
                vertexData.position = triangle.points[i];
                triangle.screen[i] = shadowShader -> vertexShader(vertexData);
            }

            // 计算bounding box
            int minX = std::min(triangle.screen[0](0), std::min(triangle.screen[1](0), triangle.screen[2](0)));
            int minY = std::min(triangle.screen[0](1), std::min(triangle.screen[1](1), triangle.screen[2](1)));
            int maxX = std::max(triangle.screen[0](0), std::max(triangle.screen[1](0), triangle.screen[2](0))) + 1;
            int maxY = std::max(triangle.screen[0](1), std::max(triangle.screen[1](1), triangle.screen[2](1))) + 1;
            for(int i = minX; i <= maxX; i ++){
                for(int j = minY; j <= maxY; j ++){
                    auto [alpha, beta, gamma] = computeBarycentric(triangle.screen, i + 0.5, j + 0.5);
                    // std::cout << "111" << std::endl;
                    if(alpha < 0 || beta < 0 || gamma < 0)continue; // 点在三角形外
                    float zInterpolation = alpha * triangle.screen[0](2) + beta * triangle.screen[1](2) + gamma * triangle.screen[2](2);
                    Eigen::Vector3f color;
                    Eigen::Vector4f posInterpolation = triangle.points[0] * alpha + triangle.points[1] * beta + triangle.points[2] * gamma;
                    fragmentData.postion = posInterpolation;
                    color = shadowShader -> fragmentShader(fragmentData);
                    // int y = height - j - 1; // 由于obj文件里的坐标系中y轴是向上的，而SDL2中y轴是向下的，故这里将y进行翻转.
                    int y = j;
                    int x = i;
                    int idx = y * width + x;
                    if(zInterpolation < shadow->depthBuffer[idx])continue;
                    shadow -> depthBuffer[idx] = zInterpolation; // 更新深度缓冲
                    // std::cout << idx << " " << shadow -> depthBuffer[idx] << std::endl;
                    shadow -> shadowmap[idx * 4 + 0] = (unsigned char)color(0);
                    shadow -> shadowmap[idx * 4 + 1] = (unsigned char)color(1);
                    shadow -> shadowmap[idx * 4 + 2] = (unsigned char)color(2);
                }
            }
        }
    }
}
