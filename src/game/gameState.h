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
void writePlayerTurn(char (*BoardMatrix)[MAX_COLUMNS], Player *(player));
/* Cleans the dice */
void clean_dice(char (*BoardMatrix)[MAX_COLUMNS]);
/* Cleans the square where the playe left */
void clean_actualSquare(char (*BoardMatrix)[MAX_COLUMNS], Piece (*piece), char PlayerLetter);
/* Cleans the messages of the player's turn from the GameState Panel */
void clean_gameStatePlayerMessages(char (*BoardMatrix)[MAX_COLUMNS]);
/*  */
void reDraw_specialSquares(char (*BoardMatrix)[MAX_COLUMNS], int squareNumber, int column);
/*  */
int getLine(int squareNumber);

/* Checks if the piece is still in the game */
bool check_piece(Player (*player), int piece);

extern void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column);

#endif