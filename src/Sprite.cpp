#include "../include/Sprite.hpp"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include "../include/Game.hpp"

Sprite::Sprite()
{
    texture = nullptr;
};

Sprite::Sprite(string file, int frameCountW = 1, int frameCountH = 1)
{

    texture = nullptr;

    Open(file);
};

void Sprite::Open(string file)
{
    cout << "Sprite::Open - Criando Sprite" << endl;

    if (texture != nullptr)
    {
        cout << "Destruindo textura" << endl;
        SDL_DestroyTexture(texture);
    };

    Game &game = Game::GetInstance();

    cout << game.GetRenderer() << endl;

    // Carregar textura
    SDL_Texture *loadedTexture = IMG_LoadTexture(game.GetRenderer(), file.c_str());

    if (loadedTexture == nullptr)
    {
        printf("IMG_LoadTexture Error: %s\n", SDL_GetError());
        SDL_Quit();
    };

    texture = loadedTexture;

    // Descobrir dimensões da textura
    int dimension = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    if (dimension != 0)
    {
        printf("SDL_QueryTexture Error: %s\n", SDL_GetError());
        SDL_Quit();
    };

    SetClip(0, 0, width, height);
    cout << "Sprite::Open - Textura criada" << endl;
};

void Sprite::Render(int x, int y, int w, int h)
{
    cout << "Sprite::Render - Rendenizando Sprite" << endl;

    Game &game = Game::GetInstance();

    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

    SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, &dstrect);
};

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
};

int Sprite::GetHeight()
{
    return height/frameCountH;
};

int Sprite::GetWidth()
{
    return width/frameCountW;
};

bool Sprite::IsOpen()
{
    return texture != nullptr;
};

Sprite::~Sprite()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    };
};

void Sprite::setFrame(int frame)
{
    SetClip((frame % frameCountW) * (width/frameCountW), (frame / frameCountW) * height/frameCountH, (width / frameCountW), (height / frameCountH));
};

void Sprite::setFrameCount(int frameCountW, int frameCountH)
{
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
}
