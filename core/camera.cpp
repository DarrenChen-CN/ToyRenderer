#include"camera.h"
#include<iostream>
const float RIGHT = 1.5f; //用于正交投影测试
const float TOP = 1.5f;
Camera::Camera(Vec3 &position, Vec3 &center, Vec3 &up, float near, float far, float aspect, float fovY): near(near), far(far), aspect(aspect), fovY(fovY){
    this -> position = position;
    this -> center = center;
    this -> up = up;
    viewMatrix = lookat(position, center, up);
    orthographicMatrix = orthographic(near, far, RIGHT, TOP);
    perspectiveMatrix = perspective(near, far, aspect, fovY);
}

Camera::Camera(Camera& otherCamera){
    position = otherCamera.position;
    center = otherCamera.center;
    up = otherCamera.up;
    near = otherCamera.near;
    far = otherCamera.far;
    aspect = otherCamera.aspect;
    fovY = otherCamera.fovY;
    viewMatrix = lookat(position, center, up);
    orthographicMatrix = orthographic(near, far, RIGHT, TOP);
    perspectiveMatrix = perspective(near, far, aspect, fovY);
}

Camera::Camera(){}