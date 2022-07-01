#include "Player.hpp"

Player::Player()
{
    mName = "";
    mScore = 0;
}

Player::Player(Symbol symbol) : Player()
{
    mSymbol = symbol;
}

void Player::addScore()
{
    mScore++;
}