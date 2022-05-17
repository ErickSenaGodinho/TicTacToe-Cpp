#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    Player();

    void setName(string name)
    {
        mName = name;
    }

    string getName()
    {
        return mName;
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
    unsigned int mScore;
};

#endif