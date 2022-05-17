#include <iostream>
#include <string>
#include "TicTacToe.cpp"

using namespace std;

void showMenu();

int main()
{

    TicTacToe game = TicTacToe();
    game.start();

    return 0;
}