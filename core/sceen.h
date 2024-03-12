#pragma once 
#include<vector>
#include"model.h"
#include"camera.h"
#include"light.h"
#include<memory>
class Sceen{
public:
    std::shared_ptr<std::vector<Model>> modelList;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Light> light;
    void loadModel(const char* filename, const char* textureFilename = NULL);
    void setLight(std::shared_ptr<Light> light);

    Sceen(std::shared_ptr<Camera> camera);
    Sceen();
};