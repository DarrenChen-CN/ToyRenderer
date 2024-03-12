#pragma once
#include<vector>
#include"texture.h"
#include"triangle.h"
#include"shader.h"
#include"define.h"
#include <memory>
class Model{
public:
    int vertexNum, faceNum;
    std::shared_ptr<std::vector<Triangle>> triangleList;
    std::shared_ptr<Texture> texture;
    Mat4 modelMatrix;
    std::shared_ptr<Shader> shader;
    Model(const char* filename, const char* textureFilename = NULL);
    ~Model();
    void setShader(std::shared_ptr<Shader> shader);
};