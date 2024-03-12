#pragma once
class ShadowMap{
public:
    int width, height;
    float* shadowmap;

    ShadowMap(int width, int height);
};