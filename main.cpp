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

    Camera camera(CAMERA_POS, CENTER, UP, NEAR, FAR, ASPECT, FOVY);
    Sceen sceen(camera);
    // sceen.loadModel("../model/obj/diablo3_pose/diablo3_pose.obj", "../model/obj/diablo3_pose/diablo3_pose_diffuse.tga"); 
    // sceen.loadModel("../model/obj/african_head/african_head.obj", "../model/obj/african_head/african_head_diffuse.tga"); 
    sceen.loadModel("../model/Red/Red.obj", "../model/Red/Red.png"); 
    // sceen.loadModel("../model/spot/spot_triangulated_good.obj", "../model/spot/spot_texture.png");
    Eigen::Matrix4f model = sceen.modelList[0].modelMatrix;
    Eigen::Matrix4f view = sceen.camera.viewMatrix;
    Eigen::Matrix4f projection = sceen.camera.perspectiveMatrix;
    Eigen::Matrix4f viewportMatrix = viewport(WINDOW_WIDTH, WINDOW_HEIGHT, sceen.camera.near, sceen.camera.far);
    Light* light = new Light(lightPos, lightColor);
    // std::cout << lightColor << std::endl;
    sceen.setLight(light);
    BlinnPhoneShader* shader = new BlinnPhoneShader();
    shader->setModel(model);
    shader->setView(view);
    shader->setProjection(projection);
    shader->setViewport(viewportMatrix);
    shader->calMVP();
    sceen.modelList[0].setShader(shader);
    SDL_Surface* image = sceen.modelList[0].texture->texImage;
    Rasterizer* rasterizer = new Rasterizer(WINDOW_WIDTH, WINDOW_HEIGHT, sceen);
    // rasterizer->computeShadow();
    rasterizer->draw();

    bool quit = false;
    SDL_Event event;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
            // updateScreen(window, rasterizer->renderbuffer->getFrameBuffer());
            updateScreen(window, rasterizer-> renderbuffer->getFrameBuffer());
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}