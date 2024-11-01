#pragma once
#include "../include/Sprite.hpp"
#include "../include/Music.hpp"
#include "../include/GameObject.hpp"
#include "../include/SpriteRenderer.hpp"
#include <iostream>
#include <string>
#include "SDL.h"

class State
{
private:
    Sprite bg;
    Music music;
    bool quitRequested;

    vector< unique_ptr<GameObject> > objectArray;

public:
    State();
    ~State();


    void LoadAssets();
    bool QuitRequested();
    void Update(float dt);
    void Render();


    void AddObject (GameObject*  go);

};

