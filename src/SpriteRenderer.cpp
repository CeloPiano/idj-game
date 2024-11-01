
#include "../include/SpriteRenderer.hpp"


SpriteRenderer::SpriteRenderer (GameObject &associated) : Component(*this)
{ 
};

SpriteRenderer::SpriteRenderer(GameObject &associated, string file, int frameCountW = 1, int frameCountH = 1)   : Component(*this)
{

    this->sprite = Sprite(file, frameCountW, frameCountH);

};

void SpriteRenderer::Open(float dt)
{
    sprite.Open("file");
};

void SpriteRenderer::SetFrameCount(int frameCountW, int frameCountH)
{
    sprite.setFrameCount(frameCountW, frameCountH);
};

void SpriteRenderer::Update(float dt)
{
    cout << "SpriteRenderer::Update - Atualizando Sprite" << endl;
    this->sprite.setFrame(dt);
};


void SpriteRenderer::Render(){
    this->sprite.Render(0, 0, 0,0);
}

bool SpriteRenderer::Is(string type){
    return type == "SpriteRenderer";
}


