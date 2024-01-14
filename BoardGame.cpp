#include "BoardGame.h"
BoardGame::BoardGame(int r, int c)
{
    
    x = r; y = c;
    for(int i = 0; i < r; i++)
    {
        vector<Player*> temp;
        for(int j = 0; j < c; j++)
        {
            temp.push_back(nullptr);
        }
        game_grid.push_back(temp);
    }
}
void BoardGame::printBoard()
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

bool BoardGame::validateBoundries(int l, int m)
{
    return (l <= x && l >= 0 && m <= y && m >= 0);
}

void BoardGame::makeMove(Player* p, int x, int y, bool &b)
{
    setPos(p, x, y, b);
}
void BoardGame::setPos(Player* p, int x, int y, bool &b)
{
    if(validateBoundries(x, y) && game_grid[x][y] == nullptr)
    {
        b = true;
        game_grid[x][y] = p;
    } 
    else
    {
        b = false;
        cout << "OUT OF BOUNDS, NOT A POSITION IN THE GAME, TRY AGAIN:";
    }
}
bool BoardGame:: gridFull()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            if(game_grid[i][j] == nullptr)
                return false;
    }
    return true;
}
void BoardGame::getPlayers(char first, char sec)
{
    cout << "Enter the name of the first player: ";
    string name;
    cin >> name;
    char sym;
    do{
        cout << "\nDo you want to be " << first << " or " << sec << ": ";
        cin >> sym;
    }
    while(sym != first && sym != sec);
    P1 = new Player(name, sym);
    cout << "Enter the name of the second player: ";
    cin >> name;
    if(sym == first)
        sym = sec;
    else
        sym = first;
    P2 = new Player(name, sym);
    cout << "The players are: " <<endl;
    cout << P1;
    cout << P2;
}