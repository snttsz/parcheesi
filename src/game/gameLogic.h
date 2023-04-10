/* The structures of the players and pieces */
#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <stdio.h>
#include "gameStructure.h"

#define MAX_COLUMNS 120

/*  */
void walk(char (*matrix)[MAX_COLUMNS], Player * player, int additional_squares, int column);

/*  */
void clean_dice(char (*matrix)[MAX_COLUMNS]);

/*  */
int roll_dice(char (*matrix)[MAX_COLUMNS]);

/*  */
void clean_actualSquare(char (*matrix)[MAX_COLUMNS], Player * player, int column);

/*  */
void check_square(char (*matrix)[MAX_COLUMNS], int line, int column);

/*  */
void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column);

#endif