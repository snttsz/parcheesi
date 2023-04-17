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

void writePlayerTurn(char (*BoardMatrix)[MAX_COLUMNS], Player player)
{
    writeString(BoardMatrix, player.name, 11, 103);
    writeString(BoardMatrix, player.name, 29, 103);

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

void clean_actualSquare(char (*BoardMatrix)[MAX_COLUMNS], Piece piece, char playerLetter)
{
    int squareNumber = piece.square.squareNumber;
    int initcolumn = piece.square.initcolumn;
    int init0column = piece.square.init0column;
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

int getLine(int squareNumber)
{
    return 3 * squareNumber + 2;;
}

bool checkPlayer(Player player)
{
    int counter = 0;

    for(int i = 0; i <= 3; i++)
    {
        if(!check_piece(player, i))
        {
            counter++;
        }
    }

    return false ? counter == 4 : true;
}

bool checkPlayers(Player players[], int numPlayers)
{
    int counter = 0;

    for(int i = 0; i <= numPlayers; i++)
    {
        if(!checkPlayer(players[i]))
        {
            counter++;
        }
    }

    return false ? counter == 4 : true;
}

bool check_piece(Player player, int piece)
{
    if (player.pieces[piece].square.squareNumber < 15)
    {
        return true;
    }

    return false;
}

bool check_squareQuantity(Piece piece, int diceResult)
{
    int actualSquare = piece.square.squareNumber;
    if (actualSquare >= 8)
    {
        if (actualSquare + diceResult > 15)
        {
            return true;
        }
    }

    return false;
}

void placeFinalSquares(char (*matrix)[MAX_COLUMNS], Piece piece, char playerLetter)
{
    int playerNumber = 0;
    int pieceNumber = piece.number-1;


    if (playerLetter == 'B')
    {
        playerNumber = 1;
    }
    else if (playerLetter == 'G')
    {  
        playerNumber = 2;
    }
    else if (playerLetter == 'Y')
    {
        playerNumber = 3;
    }

    
    int line = 49 + pieceNumber; 
    int column = 14 + (12 * playerNumber);

    matrix[line][column] = playerLetter;
    matrix[line][column+1] = (char) piece.number + '0';

    return;
}
