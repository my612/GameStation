#include "BoardGame.h"
BoardGame::BoardGame(int r, int c)
{
    
    x = r; y = c;
    for(int i = 0; i < r; i++)
    {
        vector<string> temp;
        for(int j = 0; j < c; j++)
        {
            temp.push_back("none");
        }
        game_grid.push_back(temp);
    }
}
void BoardGame::printBoard()
{
    for(int i = 0; i < game_grid.size(); i++)
    {
        for(int j = 0; j < game_grid[i].size(); j++)
            cout << game_grid[i][j];
        cout << endl;
    }
}
bool BoardGame::validateBoundries(int l, int m)
{
    return (l <= x && l >= 0 && m <= y && m >= 0);
}

void BoardGame::makeMove(Player* p, int x, int y)
{
    if(validateBoundries(x, y))
        setPos(p->getSymbol(), x, y);
    else
        cout << "OUT OF BOUNDS, NOT A POSITION IN THE GAME";
}
void BoardGame::setPos(string s, int x, int y)
{
    for(int i = 0; i < game_grid.size(); i++)
    {
        for(int j = 0; j < game_grid[i].size(); j++)
        {
            if(x == i && y == j && game_grid[i][j] == "none")
            {
                game_grid[i][j] = s;
            }
        }
    }
}