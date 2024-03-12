#pragma once 
#include"sceen.h"

void Sceen::loadModel(const char* filename, const char* textureFilename){
    Model model(filename, textureFilename);
    // std::cout << "here" << std::endl;
    modelList -> push_back(model);
    // std::cout << "here" << std::endl;
}

void Sceen::setLight(std::shared_ptr<Light> light){
    this -> light = light;
}

Sceen::Sceen(std::shared_ptr<Camera> camera){
    this -> camera = camera;
    modelList = std::make_shared<std::vector<Model>>();
}

Sceen::Sceen(){
    modelList = std::make_shared<std::vector<Model>>();
}
