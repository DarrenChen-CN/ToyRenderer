#include "light.h"

Light::Light(){}

Light::Light(Vec3& lightPos, Vec3& lightColor){
    this -> lightPos = lightPos;
}