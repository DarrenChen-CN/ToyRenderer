#include "rasterizer.h"
#include "mathutil.h"
#include<iostream>
Rasterizer::Rasterizer(int width, int height):width(width), height(height){
    renderbuffer = std::make_shared<RenderBuffer>(width, height);
}

Rasterizer::Rasterizer(int width, int height, std::shared_ptr<Sceen> sceen):width(width), height(height){
    renderbuffer = std::make_shared<RenderBuffer>(width, height);
    shadowMap = std::make_shared<ShadowMap>(width, height);
    shadowShader = std::make_shared<ShadowShader>();
    this -> sceen = sceen;
}

Rasterizer::~Rasterizer(){
}

void Rasterizer::drawTriangle(Triangle& triangle, std::shared_ptr<Shader> shader, FragmentData& fragmentData){
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
            // 纹理坐标插值
            Eigen::Vector2f uvInterpolation = triangle.texCoords[0] * alpha + triangle.texCoords[1] * beta + triangle.texCoords[2] * gamma;
            Eigen::Vector4f posInterpolation = triangle.points[0] * alpha + triangle.points[1] * beta + triangle.points[2] * gamma;
            Eigen::Vector3f normalInterpolation = triangle.normals[0] * alpha + triangle.normals[1] * beta + triangle.normals[2] * gamma;
            VertexData v;
            v.position = posInterpolation;
            Vec4 pos = shadowShader -> vertexShader(v);
            // std::cout << pos(0) << " " << pos(1) << " " << pos(2) << std::endl;
            fragmentData.postion = posInterpolation;
            fragmentData.normal = normalInterpolation;
            fragmentData.uv = uvInterpolation;
            color = shader -> fragmentShader(fragmentData);
            // std::cout << color(0) << " " << color(1) << " " << color(2) << std::endl;
            renderbuffer->setPixel(i, j, zInterpolation, color);
        }
    }
}

void Rasterizer::draw(){
    if(shadowShader)
        computeShadow();
    // std::cout << "here" << std::endl;
    // for(int i = 0; i < width * height; i ++){
    //     if(shadow -> depthBuffer[i] > -99999)std::cout << i << " " << shadow -> depthBuffer[i] << std::endl;
    // }
    for(Model& model: *(sceen -> modelList)){
        for(Triangle& triangle: *(model.triangleList)){
            VertexData vertexData;
            FragmentData fragmentData;
            for(int i = 0; i < 3; i ++){ 
                vertexData.position = triangle.points[i];
                triangle.screen[i] = model.shader -> vertexShader(vertexData);
            }
            fragmentData.light = sceen -> light;
            fragmentData.texture = model.texture;
            fragmentData.viewPos = sceen ->camera -> position;
            if(shadowShader){
                fragmentData.shadowMap = shadowMap;
                fragmentData.lightSpaceMatrix = shadowShader -> mvp;
                fragmentData.lightViewportMatrix = shadowShader -> viewport;
                fragmentData.shadowShader = shadowShader;
            }
            drawTriangle(triangle, model.shader, fragmentData);
        }
    }
}

void Rasterizer::computeShadow(){
    Vec3 lightPos = sceen -> light -> lightPos;
    // std::cout << lightPos << std::endl;
    Vec3 center = sceen -> camera -> center;
    Vec3 up = sceen -> camera -> up;

    float near = -0.1, far = -50, right = 3, top = 3;
    Mat4 view = lookat(lightPos, center, up);
    Mat4 model = Mat4::Identity();
    Mat4 projection = orthographic(near, far, right, top);
    Mat4 viewportMatrix = viewport(width, height, sceen -> camera -> near, sceen -> camera -> far);

    shadowShader->setModel(model);
    shadowShader->setView(view);
    shadowShader->setProjection(projection);
    shadowShader->setViewport(viewportMatrix);
    shadowShader->calMVP();

    for(Model& model: *(sceen -> modelList)){
        for(Triangle& triangle: *(model.triangleList)){
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
                    Vec3 color;
                    float zInterpolation = alpha * triangle.screen[0](2) + beta * triangle.screen[1](2) + gamma * triangle.screen[2](2);
                    Vec4 posInterpolation = triangle.screen[0] * alpha + triangle.screen[1] * beta + triangle.screen[2] * gamma;
                    fragmentData.postion = posInterpolation;
                    color = shadowShader -> fragmentShader(fragmentData);
                    // int y = height - j - 1; // 由于obj文件里的坐标系中y轴是向上的，而SDL2中y轴是向下的，故这里将y进行翻转.
                    int y = j;
                    int x = i;
                    int idx = y * width + x;
                    if(color(0) < shadowMap -> shadowmap[idx]){
                        // std::cout << x << " " << y << " " << color(0) << " " << shadowMap -> shadowmap[idx] << std::endl;
                        shadowMap -> shadowmap[idx] = color(0);
                    }
                    
                }
            }
        }
    }
}
