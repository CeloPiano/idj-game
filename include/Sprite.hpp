#pragma once

#include <iostream>
#include <string>
#include "SDL.h"

using namespace std;

class Sprite
{
private:
    SDL_Texture *texture;
    SDL_Rect clipRect;
    int width;
    int height;
    int frameCountW;
    int frameCountH;

public:
    Sprite();
    Sprite(string file, int frameCountW, int frameCountH);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y, int w, int h);
    void setFrame(int frame);
    void setFrameCount(int frameCountW, int frameCountH );
    int GetWidth();
    int GetHeight();    
    bool IsOpen();
};
