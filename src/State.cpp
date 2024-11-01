#include "../include/State.hpp"
#include "SDL_image.h"
#include "SDL_mixer.h"


State::State()
{
    quitRequested = false;

    // Instanciando as sprites
    // Sprite *spriteBg = new Sprite("../Recursos/img/Background.png", 0, 0);

    // bg = *spriteBg;


    GameObject *gameObject = new GameObject();

    SpriteRenderer *spriteRenderer = new SpriteRenderer(*gameObject,"../Recursos/img/Background.png", 0, 0);

    gameObject->AddComponent(spriteRenderer);

    this->AddObject(gameObject);

}

State::~State()
{

    this->objectArray.clear();

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

    for(int i = 0; i < objectArray.size(); i++){
        cout << "objectArray[i] go" << endl;
        cout << objectArray[i] << endl;
        objectArray[i]->Update(dt);
    }

    cout << "chegou aqui" << endl;

    for(int i = 0; i < objectArray.size(); i++){
        if(objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin() + i);
        };
    }

}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::Render(){

    // bg.Render(0, 0, 0, 0);

    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }

}


void State::AddObject(GameObject* go){
    unique_ptr<GameObject> ptr(go);
    objectArray.emplace_back(go);
    cout << "go added" << endl;
    cout << objectArray[0] << endl;
}