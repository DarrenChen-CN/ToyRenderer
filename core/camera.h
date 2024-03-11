#pragma once 
#include "mathutil.h"
#include "define.h"
#include <Eigen/Dense>
class Camera{
public:
    Vec3 position; // 相机位置
    Vec3 center; // 观察点
    Vec3 up; // y坐标参考方向 一般取(0, 1, 0)

    float near, far, aspect, fovY;

    Mat4 viewMatrix;
    Mat4 orthographicMatrix;
    Mat4 perspectiveMatrix;
    
    Camera(Vec3 &position, Vec3 &center, Vec3 &up, float near, float far, float aspect, float fovY);
    Camera(Camera& otherCamera);
    Camera();
};