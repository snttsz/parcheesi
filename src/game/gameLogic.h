/* The structures of the players and pieces */
#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <stdio.h>
#include "gameStructure.h"
#include "board.h"

/*  */
void walk(Player * player, int additional_squares, int column);

/*  */
void clean_dice();

/*  */
int roll_dice();

/*  */
void clean_actualSquare(Player * player, int column);

/*  */
void check_square(int line, int column);

/*  */
void check_special_squares(int column, int final_column);

/*  */
extern char Board[LINE][COLUMN];

#endif