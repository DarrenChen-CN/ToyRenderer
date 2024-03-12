#include"imagetexture.h"
#include"interval.h"
#include<iostream>
ImageTexture::ImageTexture(const char* filename){
    texImage = IMG_Load(filename);
    if(texImage == NULL){
        std::cout << "Load texture " + std::string(filename) + " failed." << std::endl;
    }
    width = texImage -> w;
    height = texImage -> h;
    texImage = SDL_ConvertSurfaceFormat(texImage, SDL_PIXELFORMAT_RGB24, 0); // 转化为3通道RGB格式
}

Color ImageTexture::getColor(float u, float v){
    int x = u * width, y = v * height;
    y = height - y;
    float r, g, b;
    SDL_LockSurface(texImage);
    Uint8* pixels = (Uint8*)texImage -> pixels;
    int idx = height * y + x;
    r = pixels[idx * 3 + 0] / 255.999;
    g = pixels[idx * 3 + 1] / 255.999;
    b = pixels[idx * 3 + 2] / 255.999;
    static const Interval interval(0, 1);
    // std::cout << r << " " << g << " " << b << std::endl;
    assert(interval.contains(r) && interval.contains(g) && interval.contains(b));
    SDL_UnlockSurface(texImage);
    return Color(r, g ,b);
}
