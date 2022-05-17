#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include "Player.cpp"

using namespace std;

class TicTacToe
{

#define BOARD_SIZE 3

public:
    TicTacToe();

    void showBoard();
    string getCurrentPlayerName();
    pair<unsigned int, unsigned int> askPosition();
    void processPosition(pair<unsigned int, unsigned int> &);
    bool isPositionAvaible(pair<unsigned int, unsigned int>);
    void makePlay(pair<unsigned int, unsigned int>);
    void checkWin(pair<unsigned int, unsigned int>);
    void clearTerminal();
    bool isGameOver();

private:
    Player mPlayer_1;
    Player mPlayer_2;
    char mBoard[BOARD_SIZE][BOARD_SIZE];
    bool mIs_player_1_time = true;
    bool mIs_game_over = false;

    void registerPlayers();
    void clearBoard();
    char getCurrentPlayerCharacter();
    bool hasAWinner(pair<unsigned int, unsigned int>);
    bool checkRow(unsigned int, char);
    bool checkCol(unsigned int, char);
    bool checkMainDiagonal(pair<unsigned int, unsigned int>, char);
    bool checkSecondaryDiagonal(pair<unsigned int, unsigned int>, char);
    void changePlayerTime();
};

#endif