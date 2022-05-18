#include "Player.hpp"

Player::Player()
{
    mName = "";
    mScore = 0;
}

Player::Player(Symbol symbol)
{
    mName = "";
    mSymbol = symbol;
    mScore = 0;
}

void Player::addScore()
{
    mScore++;
}