#pragma once


#include <iostream>
#include <string>
#include "SDL.h"

using namespace std;


class Animation
{

public:
    Animation(int frameStart, int frameEnd, float frameTime);

    int frameStart;
    int frameEnd;
    float frameTime;
};
