#pragma once 
#include"define.h"
#include"mathutil.h"
class RenderBuffer{
private:
    int width, height;
    float* frameBuffer;
    float* depthBuffer;

public:
    RenderBuffer(int width, int height);
    ~RenderBuffer();

    void clearFrameBuffer();
    void clearDepthBuffer();

    float* getFrameBuffer();
    float* getDepthBuffer();
    void setFrameBuffer(float* frameBuffer);
    void setDepthBuffer(float* depthBuffer);
    void setPixel(int x, int y, float z, Vec3 &color);
};