#include "Player.h"
Player::Player(string name, string symbol)
{
    this->name = name;
    this->symbol = symbol;
}
string Player::getName() {return name;}
string Player::getSymbol() {return symbol;}
void Player::setName(string n) {name = n;}
void Player::setSymbol(string s) {symbol = s;}

