#pragma once
#include<Eigen/Dense>
#include"texture.h"
#include"light.h"
#include"shadowmap.h"
#include"define.h"
#include<memory>
class ShadowShader;

class FragmentData{
public:
    Vec4 postion;
    Vec3 viewPos;
    Vec3 normal;
    Vec2 uv;
    Mat4 lightSpaceMatrix;
    Mat4 lightViewportMatrix;
    std::shared_ptr<Light> light;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<ShadowMap> shadowMap; 
    std::shared_ptr<ShadowShader> shadowShader;       
};

class VertexData{
public:
    Vec4 position;
};

class Shader{
public:
    Mat4 model;
    Mat4 view;
    Mat4 projection;
    Mat4 viewport;
    Mat4 mvp;

    virtual Vec4 vertexShader(VertexData& vertexData) = 0;
    virtual Color fragmentShader(FragmentData& fragmentData) = 0;

    void setModel(Mat4& model){
        this -> model = model;
    }
    void setView(Mat4& view){
        this -> view = view;
    }
    void setProjection(Mat4& projection){
        this -> projection = projection;
    }
    void setViewport(Mat4& viewport){
        this -> viewport = viewport;
    }
    void calMVP(){
        mvp = projection * view * model;
    }
};