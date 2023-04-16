/* drawing of the board */
#ifndef TABULEIRO
#define TABULEIRO

#include <stdio.h>
#include <stdlib.h>
#include "String_utils.h"


#define LINE 60
#define COLUMN 120

/* Board matrix */
extern char BoardMatrix[LINE][COLUMN];

/* Draws the complete board (like a constructor, call all functions bellow) */
void constructBoard();

/* Draws the game state panel (turns, dices, instructions) */
void log_drawing();

/* Draws the markers of the squares that the player can't be affected */
void specialSquares_drawing();

/* Draws horizontal and vertical lines */
void board_lines(int line, int column);
void squares(int line, int column);

/* Draws the dice of the game */
void draw_dice();

/* Draws the endline points of each player's pieces */
void final_square();

/*  */
extern void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column);

#endif