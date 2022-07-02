#include "Player.hpp"

/** Creates a Player.
 */
Player::Player()
{
    mName = "";
    mScore = 0;
}

/** Creates a Player.
 * 
 * @param symbol symbol used to represent the player in the game
 */
Player::Player(Symbol symbol) : Player()
{
    mSymbol = symbol;
}

/** Increases the score of player.
 */
void Player::addScore()
{
    mScore++;
}