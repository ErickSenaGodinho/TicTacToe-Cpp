#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include "Player.cpp"
#include "Symbol.hpp"
#include "validate-input.hpp"

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
    bool mHas_a_winner = false;
    unsigned int mPlays = 0;
    unsigned int mDraw_Score = 0;

    void registerPlayers();
    void clearTerminal();
    void clearBoard();
    void showGame();
    void showBoard();
    void showScoreBoard();
    pair<unsigned int, unsigned int> askPosition();
    string getCurrentPlayerName();
    pair<unsigned int, unsigned int> processPosition(pair<unsigned int, unsigned int>);
    bool isPositionAvaible(pair<unsigned int, unsigned int>);
    void makePlay(pair<unsigned int, unsigned int>);
    Symbol getCurrentPlayerSymbol();
    void checkWin(pair<unsigned int, unsigned int>);
    void checkWinner(pair<unsigned int, unsigned int>);
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