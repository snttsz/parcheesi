#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameState.h"
#include "gameLogic.h"

#define MAX_COLUMNS 120
#define INITIAL_LINE 3

/* Makes the player walk through the board */
void walk(char (*matrix)[MAX_COLUMNS], Player (*player), int piece, int additional_squares, int column);

/* Rolls the dice */
int roll_dice(char (*matrix)[MAX_COLUMNS]);

/* TODO review this function */
char * check_square(char (*matrix)[MAX_COLUMNS], int squareNumber, int column);

/* TODO review this function */
bool check_special_squares(char matrix[][MAX_COLUMNS], int actualSquare, int diceResult, int column);

extern void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column);


#endif