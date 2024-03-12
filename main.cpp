#include "ui.h"
#include "renderbuffer.h"
#include "rasterizer.h"
#include<SDL.h>
#include<SDL_image.h>
#include"light.h"
#include"define.h"
#include"blinnphoneshader.h"

const int WINDOW_WIDTH = 1200;
const float WINDOW_ASPECT = 16.0 / 9;
const int WINDOW_HEIGHT = WINDOW_WIDTH / WINDOW_ASPECT;
const char* WINDOW_NAME = "ToyRenderer";
const float NEAR = -0.1f;
const float FAR = -50.f;
const float ASPECT = 4.f / 3.f;
const float FOVY = 45.f;
Vec3 CAMERA_POS(1, 1, 3.5);
Vec3 CENTER(0, 0, 0);
Vec3 UP(0, 1, 0); 
Vec3 lightPos(1, 1, 1);
Vec3 lightColor(0.15 * 255, 0.15 * 255, 0.15 * 255);

int main(int argc, char* argv[]){
    // 初始化
    if(SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("can not init video %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL){
        SDL_Log("can not create window %s\n", SDL_GetError());
        return 2;
    }

    std::shared_ptr<Camera> camera = std::make_shared<Camera>(CAMERA_POS, CENTER, UP, NEAR, FAR, ASPECT, FOVY);
    std::shared_ptr<Sceen> sceen = std::make_shared<Sceen>(camera);
    // sceen.loadModel("../model/obj/diablo3_pose/diablo3_pose.obj", "../model/obj/diablo3_pose/diablo3_pose_diffuse.tga"); 
    // sceen -> loadModel("../model/obj/african_head/african_head.obj", "../model/obj/african_head/african_head_diffuse.tga"); 
    sceen -> loadModel("../model/Red/Red.obj", "../model/Red/Red.png"); 
    // sceen.loadModel("../model/spot/spot_triangulated_good.obj", "../model/spot/spot_texture.png");
    Mat4 model = Mat4::Identity();
    Mat4 view = sceen -> camera -> viewMatrix;
    Mat4 projection = sceen -> camera -> perspectiveMatrix;
    Mat4 viewportMatrix = viewport(WINDOW_WIDTH, WINDOW_HEIGHT, sceen -> camera -> near, sceen -> camera -> far);
    std::shared_ptr<Light> light = std::make_shared<Light>(lightPos);
    sceen -> setLight(light);
    std::shared_ptr<Shader> shader = std::make_shared<BlinnPhoneShader>();
    shader->setModel(model);
    shader->setView(view);
    shader->setProjection(projection);
    shader->setViewport(viewportMatrix);
    shader->calMVP();
    auto &modelList = *(sceen -> modelList);
    modelList[0].setShader(shader);
    Rasterizer* rasterizer = new Rasterizer(WINDOW_WIDTH, WINDOW_HEIGHT, sceen);
    
    rasterizer->draw();

    bool quit = false;
    SDL_Event event;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
            updateScreen(window, rasterizer-> renderbuffer->getFrameBuffer());
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}