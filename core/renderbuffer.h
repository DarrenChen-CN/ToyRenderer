#pragma once 
#include <Eigen/Dense>
class RenderBuffer{
private:
    int width, height;
    unsigned char* frameBuffer;
    float* depthBuffer;

public:
    RenderBuffer(int width, int height);
    ~RenderBuffer();

    void clearFrameBuffer();
    void clearDepthBuffer();

    unsigned char* getFrameBuffer();
    float* getDepthBuffer();
    void setFrameBuffer(unsigned char* frameBuffer);
    void setDepthBuffer(float* depthBuffer);
    void setPixel(int x, int y, float z, Eigen::Vector3f color);
};