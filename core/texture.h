#pragma once
#include "define.h"

class Texture{
public:
    virtual ~Texture() = default;
    virtual Color getColor(float u, float v){
        return Color(0, 0, 0);
    };
};