#ifndef GAME_CONSTRUCTOR
#define GAME_CONSTRUCTOR

#include <gameLogic.h>

void InitGame();
void InitGameSocket();
void InitPlayers();

Player playerRed;
Player playerYellow;
Player playerGreen;
Player playerBlue;

/* The board constructor -> draws the board */
extern void board();

#endif