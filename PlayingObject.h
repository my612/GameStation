#pragma once
#include <iostream>
#include "Player.h"
using namespace std;
class PlayingObject
{
    protected:
        Player* p;
    public:
        PlayingObject(Player *p);
        bool operator==(PlayingObject o);
        
};

