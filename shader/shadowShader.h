#pragma once
#include"shader.h"

class ShadowShader: public Shader{
public:
    virtual Eigen::Vector4f vertexShader(VertexData& vertexData);
    virtual Eigen::Vector3f fragmentShader(FragmentData& fragmentData);
};