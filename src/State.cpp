#include "../include/State.hpp"
#include "SDL_image.h"
#include "SDL_mixer.h"


State::State()
{
    quitRequested = false;
}

// O LoadAssets é uma método que cuida de pré-carregar os assets do state do jogo
void State::LoadAssets()
{
}

void State::Update(float dt)
{
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::Render(){


}
