#include "blinnphoneshader.h"
#include<iostream>

Eigen::Vector4f BlinnPhoneShader::vertexShader(VertexData& vertexData){
    Eigen::Vector4f res = mvp * vertexData.position;
    for(int i = 0; i < 4; i ++)res(i) /= res(3); // 透视除法
    return viewport * res;
}

Eigen::Vector3f BlinnPhoneShader::fragmentShader(FragmentData& fragmentData){
    float Ka = 0.3f, Ks = 1.f, Kd = 0.5f;

    // ambient
    Eigen::Vector3f ambient = fragmentData.texture -> getColor(fragmentData.uv(0), fragmentData.uv(1));

    // diffuse
    Eigen::Vector3f lightPos = fragmentData.light -> lightPos;
    Eigen::Vector4f position = fragmentData.postion;
    Eigen::Vector3f lightDir = (lightPos - position.head(3)).normalized();
    float r = (lightPos - position.head(3)).norm();
    Eigen::Vector3f diffuseTex = fragmentData.texture -> getColor(fragmentData.uv(0), fragmentData.uv(1));
    Eigen::Vector3f diffuse = diffuseTex / (r * r)* std::max(0.f, fragmentData.normal.dot(lightDir));

    // specular
    Eigen::Vector3f viewPos = fragmentData.viewPos;
    Eigen::Vector3f viewDir = (viewPos - position.head(3)).normalized();
    Eigen::Vector3f half = (lightDir + viewDir).normalized();
    Eigen::Vector3f specular = fragmentData.light -> lightColor / (r * r) * std::pow(std::max(0.f, fragmentData.normal.dot(half)), 32);
    // std::cout << fragmentData.shadow << std::endl;
    return Ka * ambient + (Kd * diffuse + Ks * specular) * (1 - fragmentData.shadow);
}
