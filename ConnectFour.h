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
    using BoardGame::makeMove;
    void makeMove(Player* p, int y);
    int left(int x, int y);
    int right(int x, int y);
    int dia_up_right(int x, int y);
    int dia_up_left(int x, int y);
    int dia_down_right(int x, int y);
    int dia_down_left(int x, int y);
    int down(int x, int y);
    bool isGameOver();
};

