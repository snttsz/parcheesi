#ifndef GAME_CONSTRUCTOR
#define GAME_CONSTRUCTOR

#include "board.h"
#include "gameStructure.h"

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

/* Initialize all the players */
void InitPlayers(); 

/* Place all the players name inside the board */
void PlacePlayersName();

/* Players objects */
Player * playerRed;
Player * playerYellow;
Player * playerGreen;
Player * playerBlue;

/* THIS MUST BE REMOVED, IT'S JUST FOR DEBUG PURPOSES */
void printPlayers(int piece);


/* EXTERN OBJECTS */
/* The board constructor -> draws the board */
extern void board();
/* The board Matrix */
extern char BoardMatrix[LINE][COLUMN];
/* write inside the Board */
extern void writeString(char (*matrix)[120], char *text, int line, int column);

#endif