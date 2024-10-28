#pragma once

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_mixer.h"

using namespace std;

class Music
{
private:
    Mix_Music *music;

public:
    Music();
    Music(string file);
    ~Music();

    void Play(int times);
    void Stop(int msToStop);
    void Open(string file);
    bool IsOpen();
};
