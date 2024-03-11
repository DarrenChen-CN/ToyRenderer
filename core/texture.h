#pragma once
#include<SDL_image.h>
#include<SDL.h>
#include<Eigen/Dense>

class Texture{
public:
    SDL_Surface* texImage;
    int width, height;

    Texture(const char* filename);
    Eigen::Vector3f getColor(float u, float v);
};