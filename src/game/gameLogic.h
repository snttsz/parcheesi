#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "player.h"

#define MAX_COLUMNS 120

/* Makes the player walk through the board */
void walk(char (*matrix)[MAX_COLUMNS], Player (*player), int additional_squares, int column);

/* Rolls the dice */
int roll_dice(char (*matrix)[MAX_COLUMNS]);

/* TODO review this function */
void check_square(char (*matrix)[MAX_COLUMNS], int line, int column);

/* TODO review this function */
void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column);



#endif