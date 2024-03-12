#pragma once
#include"shader.h"

class ShadowShader: public Shader{
public:
    virtual Vec4 vertexShader(VertexData& vertexData) override;
    virtual Color fragmentShader(FragmentData& fragmentData) override;
};