#include "gameLogic.h"

void walk(char (*matrix)[MAX_COLUMNS], Player (*player), int additional_squares, int column)
{
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

void check_square(char (*matrix)[MAX_COLUMNS], int line, int column)
{
    return;
}

void check_special_squares(char (*matrix)[MAX_COLUMNS], int column, int final_column)
{
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