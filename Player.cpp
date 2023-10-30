#include "Player.h"
Player::Player(string name, char symbol)
{
    this->name = name;
    this->symbol = symbol;
}
string Player::getName() {return name;}
char Player::getSymbol() {return symbol;}
void Player::setName(string n) {name = n;}
void Player::setSymbol(char s) {symbol = s;}

