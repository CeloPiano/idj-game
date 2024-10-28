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

public:
    Sprite();
    Sprite(string file);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};
