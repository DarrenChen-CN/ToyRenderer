#pragma once
#include<SDL_image.h>
#include<SDL.h>
#include"texture.h"

class ImageTexture: public Texture{
public:
    SDL_Surface* texImage;
    int width, height;

    ImageTexture(const char* filename);
    virtual Color getColor(float u, float v) override;
};