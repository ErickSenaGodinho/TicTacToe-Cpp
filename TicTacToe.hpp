#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include "Player.cpp"
#include "Symbol.hpp"

using namespace std;

class TicTacToe
{

#define BOARD_SIZE 3

public:
    TicTacToe();
    void start();

private:
    Player mPlayer_1;
    Player mPlayer_2;
    char mBoard[BOARD_SIZE][BOARD_SIZE];
    bool mIs_player_1_time = true;
    bool mIs_game_over = false;
    unsigned int mPlays = 0;

    void registerPlayers();
    void clearTerminal();
    void clearBoard();
    void showGame();
    void showBoard();
    void showScoreBoard();
    pair<unsigned int, unsigned int> askPosition();
    string getCurrentPlayerName();
    void processPosition(pair<unsigned int, unsigned int> &);
    bool isPositionAvaible(pair<unsigned int, unsigned int>);
    void makePlay(pair<unsigned int, unsigned int>);
    Symbol getCurrentPlayerSymbol();
    void checkWin(pair<unsigned int, unsigned int>);
    bool hasAWinner(pair<unsigned int, unsigned int>);
    bool checkRow(unsigned int, Symbol);
    bool checkCol(unsigned int, Symbol);
    bool checkMainDiagonal(pair<unsigned int, unsigned int>, Symbol);
    bool checkSecondaryDiagonal(pair<unsigned int, unsigned int>, Symbol);
    void addScoreToCurrentPlayer();
    void checkPlayAgain();
    bool askPlayAgain();
    void changePlayerTime();
    bool isGameOver();
};

#endif