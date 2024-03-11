#pragma once
class ShadowMap{
public:
    int width, height;
    unsigned char* shadowmap;
    float* depthBuffer;

    ShadowMap(int width, int height);
    float queryDepth(int x, int y);
};