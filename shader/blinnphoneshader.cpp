#include "blinnphoneshader.h"
#include"define.h"
#include<iostream>
class ShadowShader;
int i = 0;
Vec4 BlinnPhoneShader::vertexShader(VertexData& vertexData){
    Vec4 res = mvp * vertexData.position;
    for(int i = 0; i < 4; i ++)res(i) /= res(3); // 透视除法
    return viewport * res;
}

Color BlinnPhoneShader::fragmentShader(FragmentData& fragmentData){
    float Ka = 0.3f, Ks = 1.f, Kd = 0.5f;

    // ambient
    Vec3 ambient = fragmentData.texture -> getColor(fragmentData.uv(0), fragmentData.uv(1));

    // diffuse
    Vec3 lightPos = fragmentData.light -> lightPos;
    Vec4 position = fragmentData.postion;
    Vec3 lightDir = (lightPos - position.head(3)).normalized();
    float r = (lightPos - position.head(3)).norm();
    Vec3 diffuseTex = fragmentData.texture -> getColor(fragmentData.uv(0), fragmentData.uv(1));
    Vec3 diffuse = diffuseTex / (r * r)* std::max(0.f, fragmentData.normal.dot(lightDir));

    // specular
    Vec3 viewPos = fragmentData.viewPos;
    Vec3 viewDir = (viewPos - position.head(3)).normalized();
    Vec3 half = (lightDir + viewDir).normalized();
    Vec3 specular = Vec3(0.15, 0.15, 0.15) / (r * r) * std::pow(std::max(0.f, fragmentData.normal.dot(half)), 32);
    
    int shadow = 0;
    if(fragmentData.shadowShader){
        float bias = 0.1;
        VertexData v;
        v.position = position;
        Vec4 lightScreenPos = fragmentData.shadowShader -> vertexShader(v);
        // std::cout << lightScreenPos(0) << " " << lightScreenPos(1) << " " << lightScreenPos(2) << std::endl;
        float* shadowMap = fragmentData.shadowMap -> shadowmap;
        int idx = (int)lightScreenPos(1) * fragmentData.shadowMap -> width + (int)lightScreenPos(0);
        if(lightScreenPos(2) - bias < shadowMap[idx])shadow = 1;
    }
    return Ka * ambient + (Kd * diffuse + Ks * specular) * (1 - shadow);
}
