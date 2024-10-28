#include "../include/State.hpp"
#include "SDL_image.h"
#include "SDL_mixer.h"


State::State()
{
    quitRequested = false;


    // Instanciando as sprites
    Sprite *spriteBg = new Sprite("../Recursos/img/Background.png");

    bg = *spriteBg;
}

// O LoadAssets é uma método que cuida de pré-carregar os assets do state do jogo
void State::LoadAssets()
{
}

void State::Update(float dt)
{
    if(SDL_QuitRequested()){
        quitRequested = true;
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::Render(){

    bg.Render(0, 0);
}
