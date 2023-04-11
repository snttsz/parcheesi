#ifndef GAME_CONSTRUCTOR
#define GAME_CONSTRUCTOR

#include "gameLogic.h"
#include "board.h"


/* Init game functions */
/* Will work like a constructor */
void InitGame(Player(*PlayerRed),
              Player(*PlayerBlue),
              Player(*PlayerYellow),
              Player(*PlayerGreen)
             );

/* Will work like a constructor */
/* void InitGameSocket(char *PlayerRedName,
                    char *PlayerBlueName,
                    char *PlayerYellowName,
                    char *PlayerGreenName,
                    char *host,
                    unsigned int port); */

/* The board constructor -> draws the board */
extern void constructBoard();

/* Initialize all the players */
void InitPlayers(); 

/* Place all the players name inside the board */
void PlacePlayersName();


/* Logic Functions */
extern void walk(char (*matrix)[MAX_COLUMNS], Player * player, int additional_squares, int column);
extern void clean_dice(char (*matrix)[MAX_COLUMNS]);
extern int roll_dice(char (*matrix)[MAX_COLUMNS]);
extern void clean_actualSquare(char (*matrix)[MAX_COLUMNS], Player * player, int column);
extern void check_square(char (*matrix)[MAX_COLUMNS], int line, int column);
extern void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column);


/* Objects */
/* The board Matrix */
extern char BoardMatrix[LINE][COLUMN];

/* Players objects */
extern Player * playerRed;
extern Player * playerYellow;
extern Player * playerGreen;
extern Player * playerBlue;


/* Utils */
/* write inside the Board */
extern void writeString(char (*matrix)[120], char *text, int line, int column);


/* =========== */
/* THIS MUST BE REMOVED, IT'S JUST FOR DEBUG PURPOSES */
void printPlayers(int piece);
/* =========== */


#endif
