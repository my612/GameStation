#pragma once
#include <iostream>
#include "BoardGame.h"
#include "Player.h"
using namespace std;
class ConnectFour :
    public BoardGame
{
    private:
    int curr_x, curr_y;
    public:
    ConnectFour();
    void makeMove(Player* p, int y);
    bool isGameOver();
    void printBoard();
};

