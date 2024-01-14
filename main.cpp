#include <iostream>
#include <stack>
#include "Player.h"
#include "TicTacToe.h"
#include "BoardGame.h"
#include <map>
#include <utility>
#include "ConnectFour.h"
using namespace std;
int main()
{
    cout << "Welcome to GameToGo!" << endl;
    cout << "To play Enter the number of the game:"<<endl;
    cout << "1- Tic Tac Toe"<< endl;
    cout << "2- Connect Four" <<endl;
    bool can_be_played = true;
    int inp;
    cin >> inp;
    if(inp == 1)
    {
        BoardGame* XO = new TicTacToe();
        map<int, pair<int, int>> connecter;
        int c = 1;
        XO->getPlayers('X', 'O');
        XO->printBoard();
        stack<bool> pl1, pl2;
        cout << "Who wants to start? for player 1 enter 1 and for player 2 enter 2: ";
        int n;
        cin >> n;
        if(n == 1)
            pl1.push(1);
        else
            pl2.push(1);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
                {
                    connecter[c] = make_pair(i, j);
                    cout << c++ << " ";
                }
            cout << endl;
        }
        do
        {
            cout << "To choose a square to play, enter the square number: "<<endl;
            if(!pl1.empty())
            {
                cout << XO->P1->getName() << "'s turn." <<endl;
                cout << "Enter the number of the square you want to play: ";
                do
                {
                    cin >> c;
                    XO->makeMove(XO->P1, connecter[c].first, connecter[c].second, can_be_played);
                } while(!can_be_played);
                pl1.pop();
                pl2.push(1);
            }
            else
            {
                cout << XO->P2->getName() << "'s turn." <<endl;
                cout << "Enter the number of the square you want to play: ";
                do
                {
                    cin >> c;
                    XO->makeMove(XO->P2, connecter[c].first, connecter[c].second, can_be_played);
                } while (!can_be_played);
                pl2.pop();
                pl1.push(1);
            }
            cout << "Updated Board: " <<endl; 
            XO->printBoard();
        } while (!(XO->isGameOver()));
    }
    if(inp == 2)
    {
        ConnectFour* CF = new ConnectFour();
        CF->printBoard();
        stack<bool> pl1, pl2;
        cout << "Who wants to start? for player 1 enter 1 and for player 2 enter 2: ";
        int n;
        cin >> n;
        if(n == 1)
            pl1.push(1);
        else
            pl2.push(1);
        int col;
        for(int i = 1; i < 8; i++)
            cout << i << " ";
        cout << endl;
        CF->printBoard();
        do
        {
            if(!pl1.empty())
            {
                cout << CF->P1->getName() << "'s turn." <<endl;
                cout << "Enter the number of the column you want to play in: ";
                do
                {
                    cin >> col;
                    CF->makeMove(CF->P1, col - 1, can_be_played);
                } while(!can_be_played);
                pl1.pop();
                pl2.push(1);
            }
            else
            {
                cout << CF->P2->getName() << "'s turn." <<endl;
                cout << "Enter the number of the column you want to play in: ";
                do
                {
                    cin >> col;
                    CF->makeMove(CF->P2, col - 1, can_be_played);
                } while(!can_be_played);
                pl2.pop();
                pl1.push(1);
            }
            cout << "Updated Board: " <<endl; 
            CF->printBoard();
        } while (!(CF->isGameOver()));
        
    }
    
}