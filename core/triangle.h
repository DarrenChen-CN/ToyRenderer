#pragma once
#include<Eigen/Dense>
class Triangle{
public:
    Eigen::Vector4f points[3]; // 坐标使用齐次坐标
    Eigen::Vector3f normals[3];
    Eigen::Vector2f texCoords[3];
    Eigen::Vector3f colors[3];
    Eigen::Vector4f screen[3]; // 屏幕坐标

    Triangle();
    Triangle(const Triangle& otherTriangle);
    ~Triangle();
};