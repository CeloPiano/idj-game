#include "../include/Music.hpp"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include "../include/Game.hpp"

Music::Music()
{
    music = nullptr;
};

Music::Music(string file)
{

    music = nullptr;

    Open(file);
};

Music::~Music(){
    Mix_FreeMusic(music);
}

// recebe uma música e quantas vezes ela deve ser tocada. Se loops for -1, a música repete infinitamente. Se loops for 0, a música não é tocada.
void Music::Play(int times = (-1))
{
    if (music != nullptr)
    {
        Mix_PlayMusic(music, times);
    }
};

// para a música atual dando um efeito de fade, isto é, diminuindo gradualmente o volume até chegar em 0
void Music::Stop (int msToStop = 1500)
{
    Mix_FadeOutMusic(msToStop);
};

void Music::Open(string file)
{
    cout << "Music::Open - Criando Música" << endl;

    if (music != nullptr)
    {
        cout << "Destruindo música" << endl;
        Mix_FreeMusic(music);
    };

    Mix_Music *loadedMusic = Mix_LoadMUS(file.c_str());

    if (loadedMusic == nullptr)
    {
        printf("Mix_LoadMUS Error: %s\n", SDL_GetError());
        SDL_Quit();
    };

    music = loadedMusic;

    cout << "Music::Open - Música criada" << endl;
};

bool Music::IsOpen(){
    return music != nullptr;
}

