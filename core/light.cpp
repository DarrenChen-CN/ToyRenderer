#include "light.h"

Light::Light(){}

Light::Light(Vec3& lightPos){
    this -> lightPos = lightPos;
}