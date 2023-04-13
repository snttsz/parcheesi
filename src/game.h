#ifndef GAME_CONSTRUCTOR
#define GAME_CONSTRUCTOR

#include "gameLogic.h"
#include "board.h"

/* Init game functions */
/* Will work like a constructor */
void InitGame(Player (*players), int playersNumber);

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
void InitPlayers(Player (*players), int playersNumber); 

/* Place all the players name inside the board */
void PlacePlayersName(Player players[] , int playersNumber);


/* GameState functions */
int getPlayerTurn();
void resetPlayerTurn();
void nextPlayerTurn();
void runPlayerTurn(Player (*player));

/* Intermediary Functions -> Clean, print and write functions */
void writePlayerTurn(Player *(player));
void clean_dice();
void clean_actualSquare(Player * player, int column);
void clean_gameStatePlayerMessages();
void printMatrix();

/* Logic Functions -> Declared at gameLogic.c */
extern void walk(char (*matrix)[MAX_COLUMNS], Player * player, int additional_squares, int column);
extern int roll_dice(char (*matrix)[MAX_COLUMNS]);
extern void check_square(char (*matrix)[MAX_COLUMNS], int line, int column);
extern void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column);
extern bool check_piece(Player (*player), int piece);


/* Objects */
/* The board Matrix */
extern char BoardMatrix[LINE][COLUMN];
static int playerTurn;


/* Utils */
/* write inside the Board */
extern void writeString(char (*matrix)[120], char *text, int line, int column);


/* =========== */
/* THIS MUST BE REMOVED, IT'S JUST FOR DEBUG PURPOSES */
void printPlayers(Player players[], int playersNumber, int piece);
/* =========== */


#endif
