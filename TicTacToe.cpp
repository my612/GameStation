#include "TicTacToe.h"
TicTacToe::TicTacToe() : BoardGame(3, 3)
{
    cout << "Game ON" << endl;
}
void TicTacToe::printBoard()
{
    for(int i = 0; i < game_grid.size(); i++)
    {
        for(int j = 0; j < game_grid[i].size(); j++)
        {

            if(game_grid[i][j] == nullptr)
                cout << '#' << " ";
            else
                cout << game_grid[i][j]->getSymbol() << " ";
        }
        cout << endl;
    }
}
bool TicTacToe::isGameOver()
{
    bool over = false;
    for(int i = 0; i < 3; i++)
    {
        if(game_grid[i][0] == game_grid[i][1] && game_grid[i][1] == game_grid[i][2] && game_grid[i][1]!=nullptr)
        {
            cout << game_grid[i][0]->getName() << " wins!" <<endl;
            over = true;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(game_grid[0][i] == game_grid[1][i] && game_grid[1][i] == game_grid[2][i] && game_grid[1][i]!=nullptr)
        {
            cout << game_grid[0][i]->getName() << " wins!" <<endl;
            over = true;
        }
    }
    if(game_grid[0][0] == game_grid[1][1] && game_grid[1][1] == game_grid[2][2] && game_grid[1][1]!=nullptr)
    {
        cout << game_grid[0][0]->getName() << " wins!" <<endl;
        over = true;
    }
    if(game_grid[0][2] == game_grid[1][1] && game_grid[1][1] == game_grid[2][0] && game_grid[1][1]!=nullptr)
    {
        cout << game_grid[0][2]->getName() << " wins!" <<endl;
        over = true;
    }
    if(gridFull() && !over)
    {
        cout << "It is a draw!" << endl;
        over = true;
    }
    return over;

}
