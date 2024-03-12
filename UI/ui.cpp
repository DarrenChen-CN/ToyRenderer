#include"ui.h"
#include"define.h"
#include"mathutil.h"
#include<SDL.h>

void updateScreen(SDL_Window* window, float* frameBuffer){
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    // 锁定surface
    SDL_LockSurface(surface);
    // 获取像素数组地址
    Uint32* pixels = (Uint32*)surface -> pixels;
    int cnt = width * height;
    for(int i = 0; i < cnt; i ++){
        float r = frameBuffer[i * 4 + 0];
        float g = frameBuffer[i * 4 + 1];
        float b = frameBuffer[i * 4 + 2];
        Uint32 color = SDL_MapRGB(surface -> format, (Uint8)r, (Uint8)g, (Uint8)b);
        pixels[i] = color;
    }
    // 解锁surface
    SDL_UnlockSurface(surface);
    // 显示
    SDL_UpdateWindowSurface(window);
}