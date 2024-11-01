#pragma once

#include "../include/GameObject.hpp"

#include <iostream>
#include <string>
#include "SDL.h"

using namespace std;

class GameObject;

class Component
{
protected:
    GameObject& associated;

public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void Update(float dt);
    virtual void Render();
    virtual bool Is(string type) = 0;
};
