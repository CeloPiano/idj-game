#pragma once
#include <iostream>
#include <string>
#include "SDL.h"

class State
{
private:
    // Sprite bg;
    // Music music
    bool quitRequested;

public:
    State();
    void LoadAssets();
    bool QuitRequested();
    void Update(float dt);
    void Render();
};

