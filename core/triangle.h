#pragma once
#include"define.h"
class Triangle{
public:
    Vec4 points[3]; // 坐标使用齐次坐标
    Vec3 normals[3];
    Vec2 texCoords[3];
    Vec3 colors[3];
    Vec4 screen[3]; // 屏幕坐标

    Triangle();
    Triangle(const Triangle& otherTriangle);
    ~Triangle();
};