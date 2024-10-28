#pragma once
#include "../include/Sprite.hpp"
#include "../include/Music.hpp"
#include <iostream>
#include <string>
#include "SDL.h"

class State
{
private:
    Sprite bg;
    bool quitRequested;
    Music music;

public:
    State();
    void LoadAssets();
    bool QuitRequested();
    void Update(float dt);
    void Render();
};

