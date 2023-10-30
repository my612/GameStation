#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        char symbol;
    
    public:
        Player(string name, char symbol);
        string getName();
        char getSymbol();
        friend ostream& operator<<(ostream &os, Player *p)
        {
            os << p->name << " " << p->symbol <<endl;
            return os;
        }
        void setName(string n);
        void setSymbol(char s);
};

