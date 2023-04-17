#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameState.h"

#define MAX_COLUMNS 120
#define INITIAL_LINE 3

/* Makes the player walk through the board */
void walk(char (*matrix)[MAX_COLUMNS], Player player, int piece, int additional_squares, int column);

/* Rolls the dice */
int roll_dice(char (*matrix)[MAX_COLUMNS]);

/* Checks if there's a player inside the square that must be occupated by a new player, if so, cleans the square and returns the "playInfo" of the player caught */
char * check_square(char (*matrix)[MAX_COLUMNS], int squareNumber, int column);

/* Checks if there's a player inside the special square, if so, returns true, otherwise returns false */
bool check_special_squares(char matrix[][MAX_COLUMNS], int actualSquare, int diceResult, int column);

extern void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column);


#endif