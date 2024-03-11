#include"shadowShader.h"
#include<iostream>
Eigen::Vector4f ShadowShader::vertexShader(VertexData &vertexData)
{
    Eigen::Vector4f res = mvp * vertexData.position;
    for(int i = 0; i < 4; i ++)res(i) /= res(3); // 透视除法
    return viewport * res;
}

Eigen::Vector3f ShadowShader::fragmentShader(FragmentData &fragmentData)
{
    float z = fragmentData.postion(2) / 2 + .5f;
    return Eigen::Vector3f(255, 255, 255) * z;
}
