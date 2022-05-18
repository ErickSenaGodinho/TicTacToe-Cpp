#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Symbol.hpp"

using namespace std;

class Player
{
public:
    Player();

    Player(Symbol);

    void setName(string name)
    {
        mName = name;
    }

    string getName()
    {
        return mName;
    }

    void setSymbol(Symbol symbol)
    {
        mSymbol = symbol;
    }

    Symbol getSymbol()
    {
        return mSymbol;
    }

    void setScore(int score)
    {
        mScore = score;
    }

    unsigned int getScore()
    {
        return mScore;
    }

    void addScore();

private:
    string mName;
    Symbol mSymbol;
    unsigned int mScore;
};

#endif