#include "gameConstructor.h"

void InitGame()
{
    board();
    InitPlayers();
    
    return;
}

void InitGameSocket()
{
    board();
    InitPlayers();

    return;
}

void InitPlayers()
{
    /* TODO Fix the columns, lines and names (Probably won't be possible to use a loop to fill all the attributes) */

    playerRed.color = RED;
    playerRed.name = "RED";
    for (int i = 0; i <= 3; i++)
    {
        playerRed.pieces[i] = (Piece) {
            .number = i,
            .square = {
                .column = 0,
                .line = 0,
                .squareLine = 0,
                .squareNumber = 0
            }
        };  
    }

    playerBlue.color = BLUE;
    playerBlue.name = "BLUE";
    for (int i = 0; i <= 3; i++)
    {
        playerBlue.pieces[i] = (Piece) {
            .number = i,
            .square = {
                .column = 0,
                .line = 0,
                .squareLine = 0,
                .squareNumber = 0
            }
        };  
    }

    playerYellow.color = YELLOW;
    playerYellow.name = "YELLOW";
    for (int i = 0; i <= 3; i++)
    {
        playerYellow.pieces[i] = (Piece) {
            .number = i,
            .square = {
                .column = 0,
                .line = 0,
                .squareLine = 0,
                .squareNumber = 0
            }
        };  
    }


    playerGreen.color = GREEN;
    playerGreen.name = "GREEN";
    for (int i = 0; i <= 3; i++)
    {
        playerGreen.pieces[i] = (Piece) {
            .number = i,
            .square = {
                .column = 0,
                .line = 0,
                .squareLine = 0,
                .squareNumber = 0
            }
        };  
    }

    return;
}


