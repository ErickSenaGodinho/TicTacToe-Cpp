#include <iostream>
#include <string>
#include "TicTacToe.cpp"

using namespace std;

bool showMenu();

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