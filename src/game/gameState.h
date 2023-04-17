#ifndef GAME_STATE
#define GAME_STATE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "String_utils.h"

#define MAX_COLUMNS 120
#define LINE 60
#define COLUMN 120

/* Stores the player turn */
static int playerTurn;

/* Returns of which player is the turn */
int getPlayerTurn();
/* Resets the player turn to 0 (back to the first player) */
void resetPlayerTurn();
/* Increments the playerTurn variable to +1 until the fourth player play, then resets calls the resetPlayer function */
void nextPlayerTurn();

/* Writes the player's name where's indicate of which player is the turn */
void writePlayerTurn(char (*BoardMatrix)[MAX_COLUMNS], Player player);
/* Cleans the dice */
void clean_dice(char (*BoardMatrix)[MAX_COLUMNS]);
/* Cleans the square where the playe left */
void clean_actualSquare(char (*BoardMatrix)[MAX_COLUMNS], Piece piece, char PlayerLetter);
/* Cleans the messages of the player's turn from the GameState Panel */
void clean_gameStatePlayerMessages(char (*BoardMatrix)[MAX_COLUMNS]);
/* Returns the number of the matrix line based on a square number */
int getLine(int squareNumber);
/* Checks if the player is still available to play the game */
bool checkPlayer(Player player);
/* Checks if all the players are available to play the game, if there's none, then returns 0 */
bool checkPlayers(Player players[], int numPlayers);
/* Checks if the piece is still in the game */
bool check_piece(Player player, int piece);
/* Checks if the player can move one specific piece without exceed the square's limit */
bool check_squareQuantity(Piece piece, int diceResult);
/* Place the piece at the final square when needed */
void placeFinalSquares(char (*matrix)[MAX_COLUMNS], Piece piece, int playerNumber); 

extern void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column);

#endif