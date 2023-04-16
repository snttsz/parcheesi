#include "gameState.h"


int getPlayerTurn()
{
    return playerTurn;
}

void resetPlayerTurn()
{
    playerTurn = 0;

    return;
}

void nextPlayerTurn()
{
    if (playerTurn < 3)
    {
        playerTurn++;
    }
    else
    {
        resetPlayerTurn();
    }

    return;
}

void writePlayerTurn(char (*BoardMatrix)[MAX_COLUMNS], Player *(player))
{
    writeString(BoardMatrix, player->name, 11, 103);
    writeString(BoardMatrix, player->name, 29, 103);

    writeString(BoardMatrix, "Press any key to roll the dice", 32, 84);

    return;
}

void clean_dice(char (*BoardMatrix)[MAX_COLUMNS])
{

    for (int j = 6; j <= 8; j++)
    {
        for (int i = 97; i <= 101; i++)
        {
            BoardMatrix[j][i] = ' ';
        }
    }

    return;
}

void clean_actualSquare(char (*BoardMatrix)[MAX_COLUMNS], Piece (*piece), char playerLetter)
{
    int squareNumber = piece->square.squareNumber;
    int initcolumn = piece->square.initcolumn;
    int init0column = piece->square.init0column;
    int line = getLine(squareNumber);

    /* Cleans the init square of the player */
    BoardMatrix[3][init0column] = ' ';
    BoardMatrix[3][init0column+1] = ' ';

    if (squareNumber != 1 && squareNumber != 7 && squareNumber != 14)
    {
        BoardMatrix[line][initcolumn] = ' ';
        BoardMatrix[line][initcolumn+1] = ' ';
    }
    else
    {
        BoardMatrix[line][initcolumn] = '*';
        BoardMatrix[line][initcolumn+1] = '*';
    }

    return;   
}

void clean_gameStatePlayerMessages(char (*BoardMatrix)[MAX_COLUMNS])
{
    
    for (int i = 103; i <= 113; i++)
    {
        BoardMatrix[11][i] = ' ';
        BoardMatrix[29][i] = ' ';
    }

    for (int j = 31; j <= LINE - 3; j++)
    {
        for (int i = 81; i <= 117; i++)
        {
            BoardMatrix[j][i] = ' ';
        }
    }

    return;
}

void reDraw_specialSquares(char (*BoardMatrix)[MAX_COLUMNS], int squareNumber, int column)
{


    return;
}

int getLine(int squareNumber)
{
    return (3 * squareNumber -1) + 3;;
}

bool check_piece(Player (*player), int piece)
{
    if (player->pieces[piece].square.squareNumber <= 15)
    {
        return true;
    }

    return false;
}