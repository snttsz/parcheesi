#ifndef GAME_CONSTRUCTOR
#define GAME_CONSTRUCTOR

#include "gameLogic.h"
#include "board.h"
#include <stdlib.h>

/* The board Matrix */
extern char BoardMatrix[LINE][COLUMN];

/* Command for cleaning the terminal */
static const char * command;

/* Sets the OS of the player to adapt system commands and socket */
void set_OS(void);

/* Will work like a constructor */
void InitGame(Player (*players), int playersNumber);

/* Will work like a constructor */
/* void InitGameSocket(char *PlayerRedName,
                    char *PlayerBlueName,
                    char *PlayerYellowName,
                    char *PlayerGreenName,
                    char *host,
                    unsigned int port); */

/* Initialize all the players */
void InitPlayers(Player (*players), int playersNumber); 

/* Place all the players name inside the board */
void PlacePlayersName(Player players[] , int playersNumber);

/* Prints the board */
void printMatrix();

/* Construct and runs all the steps of the player's turn */
void runPlayerTurn(Player (*player));

/* Handles with the piece choosing during the player's turn */
int selectPiece(char (*buffer), Player (*player), int diceResult);

/* Updates the player and board when the some player is caught by another */
void updatePlayer(Player (*players));

/* If one player is caught by another, returns the index of the player. Otherwise, returns -1 */
int getPlayer();

/* Variable that will store a player caught by another */
static char playerInsideSquare[3];

/* EXTERN FUNCTIONS */

/* The board constructor -> draws the board (Declared at board.h) */
extern void constructBoard();

/* GameState functions -> Declared at gameState.c */
extern int getPlayerTurn();
extern void resetPlayerTurn();
extern void nextPlayerTurn();
extern void writePlayerTurn(char (*BoardMatrix)[MAX_COLUMNS], Player player);
extern void clean_dice(char (*BoardMatrix)[MAX_COLUMNS]);
extern void clean_actualSquare(char (*BoardMatrix)[MAX_COLUMNS], Piece piece, char PlayerLetter);
extern void clean_gameStatePlayerMessages(char (*BoardMatrix)[MAX_COLUMNS]);
extern bool check_piece(Player player, int piece);
extern bool checkPlayer(Player player);
extern bool checkPlayers(Player players[], int numPlayers);
extern bool check_squareQuantity(Piece piece, int diceResult);


/* Logic Functions -> Declared at gameLogic.c */
extern void walk(char (*matrix)[MAX_COLUMNS], Player player, int piece, int additional_squares, int column);
extern int roll_dice(char (*matrix)[MAX_COLUMNS]);
extern char * check_square(char (*matrix)[MAX_COLUMNS], int squareNumber, int column);
extern bool check_special_squares(char matrix[][MAX_COLUMNS], int actualSquare, int diceResult, int column);
extern void placeFinalSquares(char (*matrix)[MAX_COLUMNS], Piece piece, char playerLetter);

/* Utils -> Declared at String_Utils.c */
/* write inside the Board */
extern void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column);

#endif
