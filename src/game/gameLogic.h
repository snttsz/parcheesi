#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "player.h"

#define MAX_COLUMNS 120

/*  */
void walk(char (*matrix)[MAX_COLUMNS], Player (*player), int additional_squares, int column);

/*  */
int roll_dice(char (*matrix)[MAX_COLUMNS]);

/*  */
void check_square(char (*matrix)[MAX_COLUMNS], int line, int column);

/*  */
void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column);

/* Checks if the piece is still in the game */
bool check_piece(Player (*player), int piece);

#endif