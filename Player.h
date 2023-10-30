#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        string symbol;
    
    public:
        Player(string name, string symbol);
        string getName();
        string getSymbol();
        friend ostream& operator<<(ostream os, Player p)
        {
            os << p.name << " " << p.symbol;
            return os;
        }
        void setName(string n);
        void setSymbol(string s);
};

