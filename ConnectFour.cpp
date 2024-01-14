#include "ConnectFour.h"

ConnectFour::ConnectFour() :BoardGame(6, 7) 
{ 
    curr_x = 0; curr_y = 0; 
    getPlayers('R', 'Y');
}
void ConnectFour::makeMove(Player* p, int y, bool &b)
{
    int i = 0;
    if (y > 6 || y < 0)
    {
		cout << "Please enter a valid column number." << endl;
		b = false;
		return;
	}
    if (game_grid[0][y] != nullptr)
    {
		cout << "This column is full, please choose another one." << endl;
		b = false;
		return;
	}
    while(i < 5 && game_grid[i + 1][y] == nullptr)
    {
        i++;
    }
    curr_x = i; curr_y = y;
    setPos(p, curr_x, curr_y, b);
}
//bool ConnectFour::isGameOver()
//{
//    //Down
//    bool isOver = false;
//    if(curr_x < 3 && game_grid[curr_x][curr_y] == game_grid[curr_x + 1][curr_y] && game_grid[curr_x + 1][curr_y] == game_grid[curr_x + 2][curr_y] && game_grid[curr_x + 2][curr_y] == game_grid[curr_x + 3][curr_y])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }//Left
//    else if(curr_y > 2 && game_grid[curr_x][curr_y] == game_grid[curr_x][curr_y - 1] && game_grid[curr_x][curr_y - 1] == game_grid[curr_x][curr_y - 2] && game_grid[curr_x][curr_y - 2] == game_grid[curr_x][curr_y - 3])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }
//    //Right
//    else if(curr_y < 4 && game_grid[curr_x][curr_y] == game_grid[curr_x][curr_y + 1] && game_grid[curr_x][curr_y + 1] == game_grid[curr_x][curr_y + 2] && game_grid[curr_x][curr_y + 2] == game_grid[curr_x][curr_y + 3])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }
//    //Left Diagonal down
//    else if(curr_y > 2 && curr_x < 3 && game_grid[curr_x][curr_y] == game_grid[curr_x - 1][curr_y + 1] && game_grid[curr_x - 1][curr_y + 1] == game_grid[curr_x - 2][curr_y + 2] && game_grid[curr_x - 2][curr_y + 2] == game_grid[curr_x - 3][curr_y + 3])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }
//    //Right Diagonal
//    else if(curr_y < 4 && curr_x < 3 && game_grid[curr_x-1][curr_y-1] != nullptr && game_grid[curr_x][curr_y] == game_grid[curr_x + 1][curr_y + 1] && game_grid[curr_x + 1][curr_y + 1] == game_grid[curr_x + 2][curr_y + 2] && game_grid[curr_x + 2][curr_y + 2] == game_grid[curr_x + 3][curr_y + 3])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }
//    //Left UP
//    else if(curr_y > 2 && curr_x > 2 && game_grid[curr_x][curr_y] == game_grid[curr_x - 1][curr_y - 1] && game_grid[curr_x - 1][curr_y - 1] == game_grid[curr_x - 2][curr_y - 2] && game_grid[curr_x - 2][curr_y - 2] == game_grid[curr_x - 3][curr_y - 3])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }
//    //Right UP
//    else if(curr_x > 2 && curr_y < 4 && game_grid[curr_x + 1][curr_y - 1] != nullptr && game_grid[curr_x][curr_y] == game_grid[curr_x + 1][curr_y - 1] && game_grid[curr_x + 1][curr_y - 1] == game_grid[curr_x + 2][curr_y - 2] && game_grid[curr_x + 2][curr_y - 2] == game_grid[curr_x + 3][curr_y - 3])
//    {
//        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
//        isOver = true;
//    }  
//    else if(gridFull())
//    {
//        cout << "It is a draw!" << endl;
//        isOver = true;
//    }
//    if(isOver)
//        return true;
//    else 
//        return false;
//}
 bool ConnectFour::isGameOver()
 {
    if((left(curr_x, curr_y) + right(curr_x, curr_y)) >= 3)
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        return true;
    }
    else if((dia_up_left(curr_x, curr_y) + dia_down_right(curr_x, curr_y)) >= 3)
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        return true;
    }
    else if((dia_up_right(curr_x, curr_y) + dia_down_left(curr_x, curr_y)) >= 3)
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        return true;
    }
    else if(down(curr_x, curr_y) >= 3)
    {
        cout << game_grid[curr_x][curr_y]->getName() << " wins!" << endl;
        return true;
    }
    else if(gridFull())
    {
        cout << "It is a draw!" << endl;
        return true;
    }
    else
        return false;
}
int ConnectFour::left(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((y-i) >= 0 && game_grid[x][y - i] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}
int ConnectFour::right(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((y + i) <= 6 && game_g       rid[x][y + i] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}       
int ConnectFour::dia_up_right(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((y + i) <= 6 && (x - i) >= 0 && game_grid[x - i][y + i] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}
int ConnectFour::dia_up_left(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((y - i) >= 0 && (x - i) > 0 && game_grid[x - i][y - i] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}
int ConnectFour::dia_down_right(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((y + i) < 7 && (x + i) < 6 && game_grid[x + i][y + i] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}  
int ConnectFour::dia_down_left(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((y - i) >= 0 && (x + i) <= 5 && game_grid[x + i][y - i] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}  
int ConnectFour::down(int x, int y)
{
    int c = 0;
    int i = 1;
    while ((x + i) <= 5 && game_grid[x + i][y] == game_grid[x][y] && game_grid[x][y] != nullptr)
    {
        c++;
        i++;
    }
    return c;
}  