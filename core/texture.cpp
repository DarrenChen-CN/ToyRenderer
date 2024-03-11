#include"texture.h"
#include<iostream>
Texture::Texture(const char* filename){
    texImage = IMG_Load(filename);
    if(texImage == NULL){
        std::cout << "Load texture " + std::string(filename) + " failed." << std::endl;
    }
    width = texImage -> w;
    height = texImage -> h;
    texImage = SDL_ConvertSurfaceFormat(texImage, SDL_PIXELFORMAT_RGB24, 0); // 转化为3通道RGB格式
}

Eigen::Vector3f Texture::getColor(float u, float v){
    int x = u * width, y = v * height;
    y = height - y;
    Uint8 r, g, b;
    SDL_LockSurface(texImage);
    Uint8* pixels = (Uint8*)texImage -> pixels;
    int idx = height * y + x;
    r = pixels[idx * 3 + 0];
    g = pixels[idx * 3 + 1];
    b = pixels[idx * 3 + 2];
    SDL_UnlockSurface(texImage);
    return Eigen::Vector3f(r, g ,b);
}
