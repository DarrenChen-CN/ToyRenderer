#include"triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(const Triangle &otherTriangle){
    for(int i = 0; i < 3; i ++){
        points[i] = otherTriangle.points[i];
        normals[i] = otherTriangle.normals[i];
        texCoords[i] = otherTriangle.texCoords[i];
        colors[i] = otherTriangle.colors[i];
        screen[i] = otherTriangle.screen[i];
    }
}

Triangle::~Triangle(){}