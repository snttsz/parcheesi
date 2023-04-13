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

void clean_actualSquare(char (*BoardMatrix)[MAX_COLUMNS], Player *player, int column)
{
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

bool check_piece(Player (*player), int piece)
{
    if (player->pieces[piece].square.squareNumber <= 15)
    {
        return true;
    }

    return false;
}