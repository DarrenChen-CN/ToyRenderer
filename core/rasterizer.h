#pragma once
#include"renderbuffer.h"
#include<Eigen/Dense>
#include"triangle.h"
#include"sceen.h"
#include "texture.h"
#include"shadowmap.h"
#include"shadowShader.h"
#include"memory"
class Rasterizer{
public:
    int width, height;
    std::shared_ptr<RenderBuffer> renderbuffer;
    std::shared_ptr<ShadowMap> shadowMap;
    std::shared_ptr<ShadowShader> shadowShader;
    std::shared_ptr<Sceen> sceen;
    Rasterizer(int width, int height); 
    Rasterizer(int width, int height, std::shared_ptr<Sceen> sceen);
    ~Rasterizer();
    void drawTriangle(Triangle& triangle, std::shared_ptr<Shader> shader, FragmentData& fragmentData);
    void draw();
    void computeShadow();
};