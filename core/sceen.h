#pragma once 
#include<vector>
#include"model.h"
#include"camera.h"
#include"light.h"
class Sceen{
public:
    std::vector<Model> modelList;
    Camera camera;
    Light* light;
    void loadModel(const char* filename, const char* textureFilename = NULL);
    void setLight(Light* light);

    Sceen(Camera camera);
    Sceen();
    Sceen(Sceen& otherSceen);
};