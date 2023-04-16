#include "gameLogic.h"

void walk(char (*matrix)[MAX_COLUMNS], Player (*player), int piece, int additional_squares, int column)
{
    int final_square = player->pieces[piece].square.squareNumber + additional_squares;
    int result = getLine(final_square);
    int pieceM = piece+1;

    matrix[result][column] = player->PieceLetter;
    matrix[result][column+1] = (char) (pieceM)+'0';

    return;
}

int roll_dice(char (*matrix)[MAX_COLUMNS])
{
    int n_random;

    srand(time(NULL));
    n_random = rand() % 6 + 1;

    switch (n_random)
    {
    case 1:
        matrix[7][99] = '#';
        break;
    case 2:
        matrix[6][97] = '#';
        matrix[8][101] = '#';
        break;
    case 3:
        matrix[6][97] = '#';
        matrix[8][101] = '#';
        matrix[7][99] = '#';
        break;
    case 4:
        matrix[6][97] = '#';
        matrix[8][101] = '#';
        matrix[8][97] = '#';
        matrix[6][101] = '#';
        break;
    case 5:
        matrix[6][97] = '#';
        matrix[8][101] = '#';
        matrix[8][97] = '#';
        matrix[6][101] = '#';
        matrix[7][99] = '#';
        break;
    case 6:
        matrix[6][97] = '#';
        matrix[8][101] = '#';
        matrix[8][97] = '#';
        matrix[6][101] = '#';
        matrix[7][97] = '#';
        matrix[7][101] = '#';
        break;
    }

    return n_random;
}

char * check_square(char (*matrix)[MAX_COLUMNS], int squareNumber, int column)
{
    int line = getLine(squareNumber);
    char playerLetter = ' ';
    char playerNumber = ' ';
    char* playerInfo = malloc(3 * sizeof(char));

    if (matrix[line][column] != ' ')
    {
        playerLetter = matrix[line][column];
        playerNumber = matrix[line][column+1];
        matrix[line][column] = ' ';
        matrix[line][column+1] = ' ';
        sprintf(playerInfo, "%c%c", playerLetter, playerNumber);
    }
    else
    {
        sprintf(playerInfo, "%s", "");
    }


    return playerInfo;
}

void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column)
{
    return;
}

