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

public:
    // metódo static para instanciar que retorna o objeto criado
    static Game &GetInstance();
    SDL_Renderer *GetRenderer();
    State &GetState();
    ~Game();
    void Run();
    // 1. Verifica, controla e carrega as telas de jogo;
    // 2. Os dados de input são recebidos e processados;
    // 3. Os objetos tem seus respectivos estados (posição, HP…)
    // atualizados;
    // 4. Os objetos são desenhados na tela.
};
