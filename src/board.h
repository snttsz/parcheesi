/* drawing of the board */

#ifndef TABULEIRO
#define TABULEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 60
#define COLUMN 120

/* Draws the complete board (like a constructor, call all functions bellow) */
void board();

/* Draws the game state panel (turns, dices, instructions) */
void log_drawing();

/* Draws the markers of the squares that the player can't be affected */
void specialSquares_drawing();

/* Draws horizontal and vertical lines */
void horizontal_squares(int line, int column);
void vertical_squares(int line, int column);

/* Draws the dice of the game */
void draw_dices();

/* Draws the endline points of each player's pieces */
void final_square();

/* Writes a text inside the board */
void write_insideMatrix(char *text, int line, int column);

/* Board matrix */
char Board[LINE][COLUMN];

#endif