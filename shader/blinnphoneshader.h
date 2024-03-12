#pragma once
#include "shader.h"
#include <Eigen/Dense>
#include "light.h"
#include<SDL.h>
#include"texture.h"
#include"shadowShader.h"
class BlinnPhoneShader: public Shader{
public:
    virtual Vec4 vertexShader(VertexData& vertexData) override;
    virtual Color fragmentShader(FragmentData& fragmentData) override;
};