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
    void printBoard();
    void makeMove(Player* p, int x, int y, bool &b);
    void setPos(Player* p, int x, int y, bool &b);
    bool validateBoundries(int l, int m);
    virtual bool isGameOver() = 0;
    void getPlayers(char first, char sec);
    bool gridFull();


};

