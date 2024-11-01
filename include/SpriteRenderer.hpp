#pragma once

#include <iostream>
#include <string>
#include "SDL.h"

#include "GameObject.hpp"
#include "Component.hpp"
#include "Sprite.hpp"


using namespace std;
class Component;

class SpriteRenderer : public Component
{

private:
    Sprite sprite;

public:
    SpriteRenderer(GameObject &associated);
    SpriteRenderer(GameObject &associated, string file, int frameCountW, int frameCountH);
    void Open(float dt);
    void SetFrameCount(int frameCountW, int frameCountH);
    void Update(float dt);
    void Render();
    bool Is(string type);
    void SetFrame(int frame);

};
