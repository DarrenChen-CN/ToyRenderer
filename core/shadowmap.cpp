#include "shadowmap.h"
#include<iostream>

ShadowMap::ShadowMap(int width, int height):width(width), height(height){
    shadowmap = new float[width * height];
    for(int i = 0; i < width * height; i ++)shadowmap[i] = 999;
}
