#include "TicTacToe.hpp"

/** Creates a TicTacToe game.
 */
TicTacToe::TicTacToe()
{
    mPlayer_1 = Player(Symbol::X);
    mPlayer_2 = Player(Symbol::O);
    registerPlayers();
    clearBoard();
}

/** Starts the TicTacToe game.
 *
 * Processes the main logic of TicTacToe.
 */
void TicTacToe::start()
{
    do
    {
        showGame();
        pair<unsigned int, unsigned int> position = askPosition();
        position = processPosition(position);

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

/** Registers players in the game.
 *
 * @see Player::Player()
 * @see Player::setSymbol
 * @see Player::setName
 */
void TicTacToe::registerPlayers()
{
    clearTerminal();

    string player_1_name, player_2_name;
    char player_1_symbol = (char)mPlayer_1.getSymbol();
    char player_2_symbol = (char)mPlayer_2.getSymbol();
    cout << "Enter player 1 name (" << player_1_symbol << "):" << endl;
    cin >> player_1_name;
    cout << "Enter player 2 name (" << player_2_symbol << "):" << endl;
    cin >> player_2_name;

    mPlayer_1.setName(player_1_name);
    mPlayer_2.setName(player_2_name);

    clearTerminal();
}

/** Cleans the terminal.
 */
void TicTacToe::clearTerminal()
{
    system("cls");
}

/** Resets the TicTacToe Board.
 *
 * All positions of board turn into a space character.
 */
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

/** Prints the TicTacToe Game in the terminal.
 *
 * The game is comprised by the score board and game board.
 *
 * @see showScoreBoard
 * @see showBoard
 */
void TicTacToe::showGame()
{
    showScoreBoard();
    showBoard();
}

/** Prints the TicTacToe board in the terminal.
 *
 * @see showGame
 * @see showScoreBoard
 */
void TicTacToe::showBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << "\t";

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << " " << mBoard[i][j] << " ";
            j == BOARD_SIZE - 1 ? cout << "\n" : cout << "|";
        }

        if (i < BOARD_SIZE - 1)
        {
            cout << "\t-----------" << endl;
        }
    }
}

/** Prints the game score board in the terminal.
 *
 * @see showGame
 * @see showBoard
 * @see Player::getName
 * @see Player::getScore
 */
void TicTacToe::showScoreBoard()
{
    cout << mPlayer_1.getName() << " " << mPlayer_1.getScore() << " | " << mPlayer_2.getName() << " " << mPlayer_2.getScore()
         << " | Draw " << mDraw_Score << endl;
}

/** Asks the position to make the play.
 *
 * @return a pair, with it's member pair::first is the row and the pair::second is the column
 *
 * @see pair
 * @see processPosition
 * @see isPositionAvaible
 */
pair<unsigned int, unsigned int> TicTacToe::askPosition()
{
    unsigned int row, col;
    cout << "Player: " << getCurrentPlayerName() << endl;
    cout << "Row: ";
    row = input();
    cout << "Col: ";
    col = input();
    pair<unsigned int, unsigned int> position = make_pair(row, col);
    return position;
}

/** Gets the current player name.
 *
 * @return the name of the current player
 *
 * @see Player::getName
 */
string TicTacToe::getCurrentPlayerName()
{
    return mIs_player_1_time ? mPlayer_1.getName() : mPlayer_2.getName();
}

/** Processes the position the player chose by turning into an index.
 *
 * @param position position that the player chose
 *
 * @return a position with processed values
 *
 * @see askPosition
 * @see isPositionAvaible
 */
pair<unsigned int, unsigned int> TicTacToe::processPosition(pair<unsigned int, unsigned int> position)
{
    position.first--;
    position.second--;
    return position;
}

/** Determines whether the position is avaible in the board.
 *
 * @param position processed position that the player chose
 *
 * @see processPosition
 *
 * @return true if the position is empty in the board, false otherwise
 */
bool TicTacToe::isPositionAvaible(pair<unsigned int, unsigned int> position)
{
    unsigned int row = position.first;
    unsigned int col = position.second;
    if (row > BOARD_SIZE || col > BOARD_SIZE || mBoard[row][col] != ' ')
    {
        return false;
    }
    return true;
}

/** Fills the position with the current player's symbol in the chosen position.
 *
 * @param position processed position that the player chose
 *
 * @see processPosition
 */
void TicTacToe::makePlay(pair<unsigned int, unsigned int> position)
{
    unsigned int row = position.first;
    unsigned int col = position.second;
    mBoard[row][col] = (char)getCurrentPlayerSymbol();
    mPlays++;
}

/** Gets the symbol of the current player.
 *
 * @see Player::getSymbol
 *
 * @return symbol of the current player
 */
Symbol TicTacToe::getCurrentPlayerSymbol()
{
    return mIs_player_1_time ? mPlayer_1.getSymbol() : mPlayer_2.getSymbol();
}

/** Checks if the player win.
 *
 * @param position processed position that the player chose
 *
 * @see processPosition
 * @see checkWinner
 */
void TicTacToe::checkWin(pair<unsigned int, unsigned int> position)
{
    checkWinner(position);
    if (mHas_a_winner)
    {
        addScoreToCurrentPlayer();
        checkPlayAgain();
    }
    else if (mPlays < 9)
    {
        changePlayerTime();
        clearTerminal();
    }
    else
    {
        mDraw_Score++;
        checkPlayAgain();
    }
}

/** Determines whether the game has a winner.
 *
 * @param position processed position that the player chose
 *
 * @see processPosition
 * @see checkWin
 * @see checkRow
 * @see checkCol
 * @see checkMainDiagonal
 * @see checkSecondaryDiagonal
 */
void TicTacToe::checkWinner(pair<unsigned int, unsigned int> position)
{
    Symbol symbol = getCurrentPlayerSymbol();
    mHas_a_winner = checkRow(position.first, symbol) || checkCol(position.second, symbol) || checkMainDiagonal(position, symbol) || checkSecondaryDiagonal(position, symbol);
}

/** Determines whether the selected row is filled with the same symbol.
 *
 * @param row row that the player chose
 * @param symbol symbol of the current player
 *
 * @see checkWin
 * @see checkCol
 * @see checkMainDiagonal
 * @see checkSecondaryDiagonal
 *
 * @return true if the selected row is filled with the same symbol, false otherwise
 */
bool TicTacToe::checkRow(unsigned int row, Symbol symbol)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (mBoard[row][i] != (char)symbol)
        {
            return false;
        }
    }
    return true;
}

/** Determines whether the selected column is filled with the same symbol.
 *
 * @param col column that the player chose
 * @param symbol symbol of the current player
 *
 * @see checkWin
 * @see checkRow
 * @see checkMainDiagonal
 * @see checkSecondaryDiagonal
 *
 * @return true if the selected column is filled with the same symbol, false otherwise
 */
bool TicTacToe::checkCol(unsigned int col, Symbol symbol)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (mBoard[i][col] != (char)symbol)
        {
            return false;
        }
    }
    return true;
}

/** Determines whether the main diagonal is filled with the same symbol, if the position belongs to the main diagonal.
 *
 * @param position processed position that the player chose
 * @param symbol symbol of the current player
 *
 * @see checkWin
 * @see checkRow
 * @see checkCol
 * @see checkSecondaryDiagonal
 *
 * @return true if the main diagonal is filled with the sames symbol, false otherwise
 */
bool TicTacToe::checkMainDiagonal(pair<unsigned int, unsigned int> position, Symbol symbol)
{
    if (position.first == position.second)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (mBoard[i][i] != (char)symbol)
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

/** Determines whether the secondary diagonal is filled with the same symbol, if the position belongs to the secondary diagonal.
 *
 * @param position processed position that the player chose
 * @param symbol symbol of the current player
 *
 * @see checkWin
 * @see checkRow
 * @see checkCol
 * @see checkMainDiagonal
 *
 * @return true if the secondary diagonal is filled with the sames symbol, false otherwise
 */
bool TicTacToe::checkSecondaryDiagonal(pair<unsigned int, unsigned int> position, Symbol symbol)
{
    if (position.first + position.second == BOARD_SIZE - 1)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (mBoard[i][BOARD_SIZE - 1 - i] != (char)symbol)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

/** Increases the score to the current player.
 *
 * @see Player::addScore
 */
void TicTacToe::addScoreToCurrentPlayer()
{
    mIs_player_1_time ? mPlayer_1.addScore() : mPlayer_2.addScore();
}

/** Checks if the players will play again.
 *
 * If the players will play again, start another game, otherwise the game is over.
 *
 * @see askPlayAgain
 */
void TicTacToe::checkPlayAgain()
{
    bool willPlayAgain = askPlayAgain();

    if (willPlayAgain)
    {
        clearBoard();
        clearTerminal();
        mPlays = 0;
    }
    else
    {
        mIs_game_over = true;
    }
}

/** Determines whether the players will play again.
 *
 * @return true if the players will play again, false otherwise
 */
bool TicTacToe::askPlayAgain()
{
    int answer;
    do
    {
        clearTerminal();
        showGame();

        cout << (mHas_a_winner ? "Winner: " + getCurrentPlayerName()
                               : "Draw")
             << endl;
        cout << "Do you wanna play again?" << endl;
        cout << "1-Yes" << endl;
        cout << "2-Exit" << endl;
        answer = input();
    } while (answer != 1 && answer != 2);

    return answer == 1;
}

/** Changes the player's turn.
 *
 * If it's player 1's turn, it turns to player 2's turn and vice versa.
 */
void TicTacToe::changePlayerTime()
{
    mIs_player_1_time = !mIs_player_1_time;
}

/** Determines whether the game is over.
 *
 * @return true if the game is over, false otherwise
 */
bool TicTacToe::isGameOver()
{
    return mIs_game_over;
}