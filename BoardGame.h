#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;
class BoardGame
{
protected:
    vector<vector<Player*>> game_grid;
    int x, y;
public:
    Player* P1; 
    Player* P2;
    BoardGame(int r, int c);
    virtual void printBoard();
    virtual void makeMove(Player* p, int x, int y);
    virtual void setPos(Player* p, int x, int y);
    virtual bool validateBoundries(int l, int m);
    virtual bool isGameOver() = 0;
    virtual void getPlayers(char first, char sec);
    bool gridFull();


};

