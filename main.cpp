#include <iostream>
#include "TicTacToe.cpp"
#include "validate-input.hpp"

using namespace std;

bool showMenu();
int input();
int validateInput(string);

int main()
{
    bool willPlay = showMenu();
    if (willPlay)
    {
        TicTacToe game = TicTacToe();
        game.start();
    }

    return 0;
}

/** Shows TicTacToe home menu
 *
 * @return true if the players will play, false otherwise
 */
bool showMenu()
{
    int answer;
    do
    {
        system("cls");
        cout << "\tTicTacToe - Made by Erick Sena" << endl
             << endl;
        cout << "1-Play" << endl;
        cout << "2-Exit" << endl;

        answer = input();
    } while (answer <= 0 || answer > 2);
    return answer == 1;
}