#include "TicTacToe.hpp"

TicTacToe::TicTacToe()
{
    mPlayer_1 = Player();
    mPlayer_2 = Player();
    registerPlayers();
    clearBoard();
}

void TicTacToe::start()
{
    do
    {
        showBoard();
        pair<unsigned int, unsigned int> position = askPosition();
        processPosition(position);

        if (isPositionAvaible(position))
        {
            makePlay(position);
            checkWin(position);
        }
        else
        {
            clearTerminal();
            cout << "This position is unavaible" << endl;
        }

    } while (!isGameOver());
}

void TicTacToe::registerPlayers()
{
    string player_1_name, player_2_name;
    cout << "Enter player 1 name (x):" << endl;
    cin >> player_1_name;
    cout << "Enter player 2 name (O):" << endl;
    cin >> player_2_name;

    mPlayer_1.setName(player_1_name);
    mPlayer_2.setName(player_2_name);

    clearTerminal();
}

void TicTacToe::clearTerminal()
{
    system("cls");
}

void TicTacToe::clearBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            mBoard[i][j] = ' ';
        }
    }
}

void TicTacToe::showBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << "\t";

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << mBoard[i][j];
            j == BOARD_SIZE - 1 ? cout << "\n" : cout << " | ";
        }

        if (i < BOARD_SIZE - 1)
        {
            cout << "\t---------" << endl;
        }
    }
}

pair<unsigned int, unsigned int> TicTacToe::askPosition()
{
    unsigned int row, col;
    cout << "Player: " << getCurrentPlayerName() << endl;
    cout << "Row: ";
    cin >> row;
    cout << "Col: ";
    cin >> col;
    pair<unsigned int, unsigned int> position = make_pair(row, col);
    return position;
}

string TicTacToe::getCurrentPlayerName()
{
    return mIs_player_1_time ? mPlayer_1.getName() : mPlayer_2.getName();
}

void TicTacToe::processPosition(pair<unsigned int, unsigned int> &position)
{
    position.first--;
    position.second--;
}

bool TicTacToe::isPositionAvaible(pair<unsigned int, unsigned int> position)
{
    unsigned int row = position.first;
    unsigned int col = position.second;
    if (row > BOARD_SIZE || col > BOARD_SIZE)
    {
        return false;
    }
    if (mBoard[row][col] != ' ')
    {
        return false;
    }
    return true;
}

void TicTacToe::makePlay(pair<unsigned int, unsigned int> position)
{
    unsigned int row = position.first;
    unsigned int col = position.second;
    mBoard[row][col] = getCurrentPlayerCharacter();
}

char TicTacToe::getCurrentPlayerCharacter()
{
    return mIs_player_1_time ? 'X' : 'O';
}

void TicTacToe::checkWin(pair<unsigned int, unsigned int> position)
{
    if (hasAWinner(position))
    {
        clearTerminal();
        showBoard();

        cout << "Winner: " << getCurrentPlayerName();
        mIs_game_over = true;
    }
    else
    {
        changePlayerTime();
        clearTerminal();
    }
}

bool TicTacToe::hasAWinner(pair<unsigned int, unsigned int> position)
{
    char player = getCurrentPlayerCharacter();
    bool has_a_winner = checkRow(position.first, player) || checkCol(position.second, player) || checkMainDiagonal(position, player) || checkSecondaryDiagonal(position, player);
    return has_a_winner;
}

bool TicTacToe::checkRow(unsigned int row, char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (mBoard[row][i] != player)
        {
            return false;
        }
    }
    return true;
}

bool TicTacToe::checkCol(unsigned int col, char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (mBoard[i][col] != player)
        {
            return false;
        }
    }
    return true;
}

bool TicTacToe::checkMainDiagonal(pair<unsigned int, unsigned int> position, char player)
{
    if (position.first == position.second)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (mBoard[i][i] != player)
            {
                return false;
            }
            if (i == BOARD_SIZE - 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool TicTacToe::checkSecondaryDiagonal(pair<unsigned int, unsigned int> position, char player)
{
    if (position.first + position.second == BOARD_SIZE - 1)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (mBoard[i][BOARD_SIZE - 1 - i] != player)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

void TicTacToe::changePlayerTime()
{
    mIs_player_1_time = !mIs_player_1_time;
}

bool TicTacToe::isGameOver()
{
    return mIs_game_over;
}