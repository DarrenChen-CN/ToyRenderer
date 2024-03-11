#pragma once 
#include"sceen.h"

void Sceen::loadModel(const char* filename, const char* textureFilename){
    Model model(filename, textureFilename);
    modelList.push_back(model);
}

void Sceen::setLight(Light *light){
    this -> light = light;
}

Sceen::Sceen(Camera camera){
    this -> camera = camera;
}

Sceen::Sceen(){}

Sceen::Sceen(Sceen& otherSceen){
    camera = otherSceen.camera;
    for(Model model: otherSceen.modelList){
        modelList.push_back(model);
    }
    light = otherSceen.light;
}