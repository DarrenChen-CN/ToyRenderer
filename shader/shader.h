#pragma once
#include<Eigen/Dense>
#include"texture.h"
#include"light.h"
#include"shadowmap.h"
class FragmentData{
public:
    Eigen::Vector4f postion;
    Eigen::Vector3f viewPos;
    Eigen::Vector3f normal;
    Eigen::Vector2f uv;
    Light* light;
    Texture* texture;
    float shadow;        
};

class VertexData{
public:
    Eigen::Vector4f position;
};

class Shader{
public:
    Eigen::Matrix4f model;
    Eigen::Matrix4f view;
    Eigen::Matrix4f projection;
    Eigen::Matrix4f viewport;
    Eigen::Matrix4f mvp;

    virtual Eigen::Vector4f vertexShader(VertexData& vertexData) = 0;
    virtual Eigen::Vector3f fragmentShader(FragmentData& fragmentData) = 0;

    void setModel(Eigen::Matrix4f model){
        this -> model = model;
    }
    void setView(Eigen::Matrix4f view){
        this -> view = view;
    }
    void setProjection(Eigen::Matrix4f projection){
        this -> projection = projection;
    }
    void setViewport(Eigen::Matrix4f viewport){
        this -> viewport = viewport;
    }
    void calMVP(){
        mvp = projection * view * model;
    }
};