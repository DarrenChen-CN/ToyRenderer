#pragma once 
#include"define.h"

class Light{
public:
    Vec3 lightPos;

    Light();
    Light(Vec3& lightPos);
};