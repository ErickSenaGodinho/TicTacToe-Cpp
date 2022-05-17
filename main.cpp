#include <iostream>
#include <string>
#include "TicTacToe.cpp"

using namespace std;

int main()
{
    TicTacToe game = TicTacToe();

    do
    {
        game.showBoard();
        pair<unsigned int, unsigned int> position = game.askPosition();
        game.processPosition(position);

        if (game.isPositionAvaible(position))
        {
            game.makePlay(position);
            game.checkWin(position);
        }
        else
        {
            game.clearTerminal();
            cout << "This position is unavaible" << endl;
        }

    } while (!game.isGameOver());

    return 0;
}