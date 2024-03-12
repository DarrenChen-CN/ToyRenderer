#pragma once
#include<Eigen/Dense>
#include<iostream>
#include<math.h>
#include"interval.h"
#include "define.h"
#define PI 3.1415926 

enum class AXIS{
    AXIS_X, AXIS_Y, AXIS_Z
};

static Vec4 V3ftoV4f(Eigen::Vector3f v, float t){
    Eigen::Vector4f res;
    res(0) = v(0);
    res(1) = v(1);
    res(2) = v(2);
    res(3) = t;
    return res;
}

// 计算重心坐标
static std::tuple<float, float, float> computeBarycentric(const Eigen::Vector4f* pts, float x, float y){
    float xa = pts[0](0);
    float ya = pts[0](1);
    float xb = pts[1](0);
    float yb = pts[1](1);
    float xc = pts[2](0);
    float yc = pts[2](1);

    float gamma = ((ya - yb) * x + (xb - xa) * y + xa * yb - xb * ya) / ((ya - yb) * xc + (xb - xa) * yc + xa * yb - xb * ya);
    if(gamma != gamma) gamma = 0;
    float beta = ((ya - yc) * x + (xc - xa) * y + xa * yc - xc * ya) / ((ya - yc) * xb + (xc - xa) * yb + xa * yc - xc * ya);
    if(beta != beta) beta = 0;
    float alpha = 1 - gamma - beta;

    return { alpha, beta, gamma };
}

// 平移
static Mat4 translate(float x, float y, float z){
    Eigen::Matrix4f matrix = Eigen::Matrix4f::Identity();
    matrix(0, 3) = x;
    matrix(1, 3) = y; 
    matrix(2, 3) = z;
    return matrix;
}

// 缩放
static Mat4 scale(float x, float y, float z){
    Eigen::Matrix4f matrix = Eigen::Matrix4f::Identity();
    matrix(0, 0) = x;
    matrix(1, 1) = y;
    matrix(2, 2) = z;
    return matrix;
}

// 旋转
static Mat4 rotate(float theta, AXIS axis){
    theta = theta * PI / 180.0f; // 转为弧度制
    float cosTheta = cos(theta), sinTheta = sin(theta);
    Eigen::Matrix4f matrix = Eigen::Matrix4f::Identity();
    if(axis == AXIS::AXIS_X){
        matrix(1, 1) = cosTheta;
        matrix(1, 2) = -sinTheta;
        matrix(2, 1) = sinTheta;
        matrix(2, 2) = cosTheta;
    }else if(axis == AXIS::AXIS_Y){
        matrix(0, 0) = cosTheta;
        matrix(0, 2) = sinTheta;
        matrix(2, 0) = -sinTheta;
        matrix(2, 2) = cosTheta;
    }else if(axis == AXIS::AXIS_Z){
        matrix(0, 0) = cosTheta;
        matrix(0, 1) = -sinTheta;
        matrix(1, 0) = sinTheta;
        matrix(1, 1) = cosTheta;
    }
    return matrix;
}

// 视图变换矩阵
static Mat4 lookat(Eigen::Vector3f position, Eigen::Vector3f center, Eigen::Vector3f up){
    Eigen::Vector3f z = (position - center).normalized();
    Eigen::Vector3f x = (up.cross(z)).normalized();
    Eigen::Vector3f y = (z.cross(x)).normalized();
    Eigen::Matrix4f R = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f T = Eigen::Matrix4f::Identity();
    T.col(3) = V3ftoV4f(-position, 1.f);
    R.row(0) = V3ftoV4f(x, 0.f);
    R.row(1) = V3ftoV4f(y, 0.f);
    R.row(2) = V3ftoV4f(z, 0.f);
    return R * T;
}

// 正交投影
// 相机看向z轴负方向 
// 认为left = -right bottom = -top
static Mat4 orthographic(float near, float far, float right, float top){
    float bottom = -top;
    float left = -right;
    Eigen::Matrix4f ortho = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f T = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f S = Eigen::Matrix4f::Identity();
    T(0, 3) = -(left + right) / 2;
    T(1, 3) = -(bottom + top) / 2;
    T(2, 3) = -(near + far) / 2;
    S(0, 0) = 2.f / (right - left);
    S(1, 1) = 2.f / (top - bottom);
    S(2, 2) = 2.f / (near - far);
    ortho = S * T;
    return ortho;
}

// 透视投影
static Mat4 perspective(float near, float far, float aspect, float fovY){
    fovY = fovY * PI / 180.0f; // 转为弧度制
    float top = fabsf(near * tan(fovY / 2));
    float bottom = -top;
    float right = top * aspect;
    float left = -right;
    Eigen::Matrix4f persp2ortho = Eigen::Matrix4f::Identity();
    persp2ortho(0, 0) = persp2ortho(1, 1) = near;
    persp2ortho(2, 2) = near + far;
    persp2ortho(2, 3) = -near * far;
    persp2ortho(3, 2) = 1;
    persp2ortho(3, 3) = 0;
    Eigen::Matrix4f ortho = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f T = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f S = Eigen::Matrix4f::Identity();
    T(0, 3) = -(left + right) / 2;
    T(1, 3) = -(bottom + top) / 2;
    T(2, 3) = -(near + far) / 2;
    S(0, 0) = 2.f / (right - left);
    S(1, 1) = 2.f / (top - bottom);
    S(2, 2) = 2.f / (near - far);
    ortho = S * T;
    return ortho * persp2ortho;
}


// 视口变换矩阵
static Mat4 viewport(float width, float height, float near, float far){
    Eigen::Matrix4f viewportMatrix = Eigen::Matrix4f::Identity();
    viewportMatrix(0, 0) = width / 2;
    viewportMatrix(0, 3) = width / 2;
    viewportMatrix(1, 1) = height / 2;
    viewportMatrix(1, 3) = height / 2;
    viewportMatrix(2, 2) = (near - far) / 2;
    viewportMatrix(2, 3) = (near + far) / 2;
    return viewportMatrix;
}

// 伽马校正
inline double linearToGamma(double linearComponent){
    return sqrt(linearComponent);
}

// 将[0 - 1]的颜色映射到[0-255]
static Color getColor(Color& c){
    auto r = c(0);
    auto g = c(1);
    auto b = c(2);

    r = linearToGamma(r);
    g = linearToGamma(g);
    b = linearToGamma(b);

    static const Interval intensity(0.000, 0.999);
    return Color(static_cast<int>(256 * intensity.clamp(r)), static_cast<int>(256 * intensity.clamp(g)), static_cast<int>(256 * intensity.clamp(b)));
}
