#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "SDL.h"

#include "../include/Component.hpp"

using namespace std;

class Component;

class GameObject
{
private:
    bool isDead;
    vector<shared_ptr<Component> > components;

public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();

    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *cpt);
    void RemoveComponent(Component *cpt);
    weak_ptr<Component> GetComponent(string type);
};
