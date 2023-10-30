#include <iostream>
#include <stack>
#include "Player.h"
#include "TicTacToe.h"
#include "BoardGame.h"
#include <map>
#include <utility>
using namespace std;
int main()
{
    cout << "Welcome to GameToGo!" << endl;
    cout << "To play Enter the number of the game:"<<endl;
    cout << "1- Tic Tac Toe"<< endl;
    cout << "2- Connect Four" <<endl;
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
                cin >> c;
                XO->makeMove(XO->P1, connecter[c].first, connecter[c].second);
                pl1.pop();
                pl2.push(1);
            }
            else
            {
                cout << XO->P2->getName() << "'s turn." <<endl;
                cout << "Enter the number of the square you want to play: ";
                cin >> c;
                XO->makeMove(XO->P2, connecter[c].first, connecter[c].second);
                pl2.pop();
                pl1.push(1);
            }
            cout << "Updated Board: " <<endl; 
            XO->printBoard();
        } while (!(XO->isGameOver()));
        
    }
}