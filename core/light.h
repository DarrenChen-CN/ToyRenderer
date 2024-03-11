#pragma once 
#include"define.h"

class Light{
public:
    Vec3 lightPos;
    Vec3 lightColor;

    Light();
    Light(Vec3& lightPos, Vec3& lightColor);
};