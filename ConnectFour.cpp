#include "ConnectFour.h"

ConnectFour::ConnectFour():BoardGame(6, 7){}
void ConnectFour::makeMove(Player* p, int y)
{
    int i = 0;
    while(game_grid[i + 1][y] == nullptr)
    {
        i++;
    }
    curr_x = i; curr_y = y;
    setPos(p, curr_x, curr_y);
}
bool ConnectFour::isGameOver()
{
    //Down
    bool isOver = false;
    if(curr_y < 3 && game_grid[curr_x][curr_y] == game_grid[curr_x + 1][curr_y] && game_grid[curr_x + 1][curr_y] == game_grid[curr_x + 2][curr_y] && game_grid[curr_x + 2][curr_y] == game_grid[curr_x + 3][curr_y])
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        isOver = true;
    }//Left
    else if(curr_x > 2 && game_grid[curr_x][curr_y] == game_grid[curr_x][curr_y - 1] && game_grid[curr_x][curr_y - 1] == game_grid[curr_x][curr_y - 2] && game_grid[curr_x][curr_y - 2] == game_grid[curr_x][curr_y - 3])
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        isOver = true;
    }
    //Right
    else if(curr_x < 4 && game_grid[curr_x][curr_y] == game_grid[curr_x][curr_y + 1] && game_grid[curr_x][curr_y + 1] == game_grid[curr_x][curr_y + 2] && game_grid[curr_x][curr_y + 2] == game_grid[curr_x][curr_y + 3])
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        isOver = true;
    }
    //Left Diagonal
    else if(curr_x > 2 && curr_y < 3 && game_grid[curr_x][curr_y] == game_grid[curr_x - 1][curr_y + 1] && game_grid[curr_x - 1][curr_y + 1] == game_grid[curr_x - 2][curr_y + 2] && game_grid[curr_x - 2][curr_y + 2] == game_grid[curr_x - 3][curr_y + 3])
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        isOver = true;
    }
    //Right Diagonal
    else if(curr_x < 4 && curr_y < 3 && game_grid[curr_x][curr_y] == game_grid[curr_x + 1][curr_y + 1] && game_grid[curr_x + 1][curr_y + 1] == game_grid[curr_x + 2][curr_y + 2] && game_grid[curr_x + 2][curr_y + 2] == game_grid[curr_x + 3][curr_y + 3])
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        isOver = true;
    }
    else if(gridFull())
    {
        cout << "It is a draw!" << endl;
        isOver = true;
    }
    if(isOver)
        return true;
    else 
        return false;
}
// bool ConnectFour::isGameOver()
// {
//     int c = 1;
//     int i = 0;
//     //Down
//     if(curr_y < 3)
//     {
//     while(game_grid[curr_x + i][curr_y] == game_grid[curr_x + i + 1][curr_y] || c!=4)
//     {
//         i++;
//         c++;
//     }
//     if(c == 4)
//         {
//             cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//             return true;
//         }
//     else 
//         {
//             c = 1;
//             i = 0;
//         }
//     }//Left
//     if(curr_x > 2)
//     {
//         while (game_grid[curr_x][curr_y - i] == game_grid[curr_x][curr_y - i - 1] || c!=4)
//         {
//             i++;
//             c++;
//         }
//         if(c == 4)
//         {
//             cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//             return true;
//         }
//         else
//         {
//             c = 1;
//             i = 0;
//         }
//     }//Right
//     if(curr_x < 4)
//     {
//         while (game_grid[curr_x][curr_y + i] == game_grid[curr_x][curr_y + i + 1] || c!=4)
//         {
//             i++;
//             c++;
//         }
//         if(c == 4)
//         {
//             cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//             return true;
//         }
//         else
//         {
//             c = 1;
//             i = 0;
//         }
//     }//Left Diagonal
//     if(curr_x > 2 && curr_y < 3)
//     {
//         while (game_grid[curr_x - i][curr_y + i] == game_grid[curr_x - i - 1][curr_y + i + 1] || c!=4)
//         {
//             i++;
//             c++;
//         }
//         if(c == 4)
//         {
//             cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//             return true;
//         }
//         else
//         {
//             c = 1;
//             i = 0;
//         }
//     }//Right Diagonal
//     if(curr_x < 4 && curr_y < 3)
//     {
//         while (game_grid[curr_x + i][curr_y + i] == game_grid[curr_x + i + 1][curr_y + i + 1] || c!=4)
//         {
//             i++;
//             c++;
//         }
//         if(c == 4)
//         {
//             cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//             return true;
//         }
//         else
//         {
//             c = 1;
//             i = 0;
//         }
//     }
//     if(gridFull())
//         {
//             cout << "It is a draw!" << endl;
//             return true;
//         }
//     else
//         return false;
// }
void ConnectFour::printBoard()
{
    for(int i = 0)
}