#pragma once
#include"renderbuffer.h"
#include<Eigen/Dense>
#include"triangle.h"
#include"sceen.h"
#include "texture.h"
#include"shadowmap.h"
#include"shadowShader.h"
class Rasterizer{
public:
    int width, height;
    RenderBuffer* renderbuffer;
    ShadowMap* shadow;
    ShadowShader* shadowShader;
    Sceen sceen;
    Rasterizer(int width, int height); 
    Rasterizer(int width, int height, Sceen sceen);
    ~Rasterizer();
    void drawTriangle(Triangle triangle, Shader* shader, FragmentData& fragmentData);
    void draw();
    void computeShadow();
};