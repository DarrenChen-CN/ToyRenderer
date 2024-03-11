#include "shadowmap.h"
#include<iostream>

ShadowMap::ShadowMap(int width, int height):width(width), height(height){
    shadowmap = new unsigned char[width * height * 4];
    depthBuffer = new float[width * height];
    for(int i = 0; i < width * height; i ++)depthBuffer[i] = -999999;
}

float ShadowMap::queryDepth(int x, int y){
    int idx = y * width + x;
    // std::cout << x << " " << y << " " << std::endl;
    // std::cout << idx << " " << depthBuffer[idx] << std::endl;
    return depthBuffer[idx];
}
