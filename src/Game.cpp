#include "../include/Game.hpp"

#include "SDL_image.h"
#include "SDL_mixer.h"

// Temos que declarar a variável estáticas
Game *Game::instance = nullptr;
State *Game::state = nullptr;
SDL_Window *Game::window = nullptr;
SDL_Renderer *Game::renderer = nullptr;

Game::Game(string title, int width, int height)
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        cout << "Erro ao inicializar o SDL" << endl;
        throw std::invalid_argument("Error initializing SDL");
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
        cout << "Erro ao inicializar o SDL_image" << endl;
        throw std::invalid_argument("Error initializing SDL_image");
    }

    if (Mix_Init(MIX_INIT_MP3) == 0)
    {
        cout << "Erro ao inicializar o SDL_init" << endl;
        throw std::invalid_argument("Error initializing SDL_init");
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
        cout << "Erro ao inicializar o SDL_mixer" << endl;
        throw std::invalid_argument("Error initializing SDL_mixer");
    }

    if (Mix_AllocateChannels(32) == 0)
    {
        cout << "Erro ao inicializar o SDL_mixer" << endl;
        throw std::invalid_argument("Error initializing SDL_mixer");
    }

    SDL_Window *window_created = SDL_CreateWindow("Hello SDL2",
                                                  SDL_WINDOWPOS_CENTERED,
                                                  SDL_WINDOWPOS_CENTERED,
                                                  640, 480, SDL_WINDOW_SHOWN);
    if (window_created == nullptr)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
    }
    window = window_created;

    // Create a renderer
    SDL_Renderer *renderer_created = SDL_CreateRenderer(window_created, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer_created == nullptr)
    {
        SDL_DestroyWindow(window_created);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
    }
    renderer = renderer_created;

    // Instanciar o state
    State *state_created = new State();
    state = state_created;
};

SDL_Renderer *Game::GetRenderer()
{
    return renderer;
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State &Game::GetState()
{
    return *state;
}

Game &Game::GetInstance()
{
    if (instance != nullptr)
    {
        cout << "já existe instância" << endl;
        return *instance;
    }

    Game *game = new Game("Teste", 800, 600);
    instance = game;

    return *game;
}

void Game::Run()
{
    while (state->QuitRequested() == false)
    {
        state->Update(0.0);
        state->Render();

        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}
