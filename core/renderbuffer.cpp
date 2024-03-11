#include"renderbuffer.h"
#include <string.h>
#include<iostream>

RenderBuffer::RenderBuffer(int width, int height):width(width), height(height){
    frameBuffer = new unsigned char[width * height * 4];
    depthBuffer = new float[width * height];
    for(int i = 0; i < width * height; i ++)depthBuffer[i] = -999999;
}

RenderBuffer::~RenderBuffer(){
    delete[] frameBuffer;
    delete[] depthBuffer;
}

void RenderBuffer::clearDepthBuffer(){
    for(int i = 0; i < width * height; i ++)depthBuffer[i] = -999999;
}

void RenderBuffer::clearFrameBuffer(){
    memset(frameBuffer, 0, sizeof frameBuffer);
}

void RenderBuffer::setDepthBuffer(float* depthBuffer){
    this -> depthBuffer = depthBuffer;   
}

void RenderBuffer::setFrameBuffer(unsigned char* frameBuffer){
    this -> frameBuffer = frameBuffer;
}

float* RenderBuffer::getDepthBuffer(){
    return depthBuffer;
}

unsigned char* RenderBuffer::getFrameBuffer(){
    return frameBuffer;
}

void RenderBuffer::setPixel(int x, int y, float z, Eigen::Vector3f color){
    if(x < 0 || x >= width || y < 0 || y >= height)return;
    y = height - y - 1; // 由于obj文件里的坐标系中y轴是向上的，而SDL2中y轴是向下的，故这里将y进行翻转.
    int idx = y * width + x;
    if(z < depthBuffer[idx])return ;
    depthBuffer[idx] = z; // 更新深度缓冲
    frameBuffer[idx * 4 + 0] = (unsigned char)color(0);
    frameBuffer[idx * 4 + 1] = (unsigned char)color(1);
    frameBuffer[idx * 4 + 2] = (unsigned char)color(2);
}