#pragma once
#include "shader.h"
#include <Eigen/Dense>
#include "light.h"
#include<SDL.h>
#include"texture.h"
#include"shadowShader.h"
class BlinnPhoneShader: public Shader{
public:
    virtual Eigen::Vector4f vertexShader(VertexData& vertexData);
    virtual Eigen::Vector3f fragmentShader(FragmentData& fragmentData);
};