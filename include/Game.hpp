#pragma once

#include "../include/State.hpp"
#include <iostream>
#include <string>
#include "SDL.h"

using namespace std;

class Game
{

private:
    // instaciar a classe
    static Game *instance;
    static SDL_Window *window;
    static SDL_Renderer *renderer;
    static State *state;

    // construtor
    Game(string title, int width, int height);

    void Run();

public:
    // metódo static para instanciar que retorna o objeto criado
    static Game &GetInstance();
    SDL_Renderer *GetRenderer();
    State &GetState();
    ~Game();
};

