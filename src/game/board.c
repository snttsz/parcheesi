#include "board.h"

char BoardMatrix[LINE][COLUMN];

void constructBoard()
{
    horizontal_squares(LINE - 2, COLUMN - 2);
    vertical_squares(4, 9);
    vertical_squares(4, 25);
    vertical_squares(4, 41);
    vertical_squares(4, 57);
    final_square();
    writeString(BoardMatrix, "R1 B1 G1 Y1", 3, 7);
    writeString(BoardMatrix, "R2 B2 G2 Y2", 3, 23);
    writeString(BoardMatrix, "R3 B3 G3 Y3", 3, 39);
    writeString(BoardMatrix, "R4 B4 G4 Y4", 3, 55);
    log_drawing();
    draw_dice();
    specialSquares_drawing();
}

void log_drawing()
{
    int j;

    writeString(BoardMatrix, "GAMESTATE PANEL", 18, 92);
    writeString(BoardMatrix, "PLAYER ", 21, 82);
    writeString(BoardMatrix, "R1, R2, R3, R4", 21, 100);
    writeString(BoardMatrix, "PLAYER ", 23, 82);
    writeString(BoardMatrix, "B1, B2, B3, B4", 23, 100);
    writeString(BoardMatrix, "PLAYER ", 25, 82);
    writeString(BoardMatrix, "G1, G2, G3, G4", 25, 100);
    writeString(BoardMatrix, "PLAYER ", 27, 82);
    writeString(BoardMatrix, "Y1, Y2, Y3, Y4", 27, 100);
    writeString(BoardMatrix, "PLAYER'S TURN ", 11, 88);
    writeString(BoardMatrix, "PLAYER'S TURN ", 29, 88);

    for (j = 81; j <= COLUMN - 2; j++)
    {
        BoardMatrix[16][j] = '#';
    }

    for (j = 1; j <= LINE - 3; j++)
    {
        BoardMatrix[j][80] = '#';
    }
}

void specialSquares_drawing()
{
    if (BoardMatrix[5][11] == ' ' || BoardMatrix[23][11] == ' ' || BoardMatrix[44][11] == ' ')
    {
        BoardMatrix[5][11] = '*';
        BoardMatrix[5][12] = '*';
        BoardMatrix[23][11] = '*';
        BoardMatrix[23][12] = '*';
        BoardMatrix[44][11] = '*';
        BoardMatrix[44][12] = '*';
    }
    if (BoardMatrix[5][27] == ' ' || BoardMatrix[23][27] == ' ' || BoardMatrix[44][27] == ' ')
    {
        BoardMatrix[5][27] = '*';
        BoardMatrix[5][28] = '*';
        BoardMatrix[23][27] = '*';
        BoardMatrix[23][28] = '*';
        BoardMatrix[44][27] = '*';
        BoardMatrix[44][28] = '*';
    }
    if (BoardMatrix[5][43] == ' ' || BoardMatrix[23][43] == ' ' || BoardMatrix[44][43] == ' ')
    {
        BoardMatrix[5][43] = '*';
        BoardMatrix[5][44] = '*';
        BoardMatrix[23][43] = '*';
        BoardMatrix[23][44] = '*';
        BoardMatrix[44][43] = '*';
        BoardMatrix[44][44] = '*';
    }
    if (BoardMatrix[5][59] == ' ' || BoardMatrix[23][59] == ' ' || BoardMatrix[44][59] == ' ')
    {
        BoardMatrix[5][59] = '*';
        BoardMatrix[5][60] = '*';
        BoardMatrix[23][59] = '*';
        BoardMatrix[23][60] = '*';
        BoardMatrix[44][59] = '*';
        BoardMatrix[44][60] = '*';
    }
}

void horizontal_squares(int line, int column)
{
    int j, i;

    for (j = 0; j <= line; j++)
    {
        if (j == 0 || j == line)
        {
            for (i = 0; i <= column; i++)
            {
                BoardMatrix[j][i] = '#';
            }
        }
        else
        {
            for (i = 0; i < 1; i++)
            {
                BoardMatrix[j][i] = '#';
                BoardMatrix[j][column] = '#';
            }
            for (i = 1; i < column; i++)
            {
                BoardMatrix[j][i] = ' ';
            }
        }
    }
}

void vertical_squares(int line, int column)
{

    for (int j = line; j <= line + 40; j = j + 3)
    {
        BoardMatrix[j][column + 2] = '-';
        BoardMatrix[j][column + 3] = '-';
        BoardMatrix[j + 1][column + 1] = '|';
        BoardMatrix[j + 1][column + 4] = '|';
        BoardMatrix[j + 2][column + 2] = '-';
        BoardMatrix[j + 2][column + 3] = '-';
    }
}

void draw_dice()
{
    int i, j;

    for (j = 5; j <= 9; j++)
    {
        for (i = 95; i <= 103; i++)
        {
            if (j == 5 || j == 9)
            {
                BoardMatrix[j][i] = '-';
            }
            else if (i == 95 || i == 103)
            {
                BoardMatrix[j][i] = '|';
            }
        }
    }
}

void final_square()
{
    int i, j;

    for (j = 10; j <= 59; j++)
    {
        BoardMatrix[47][j] = '-';
        BoardMatrix[54][j] = '-';
    }
    for (j = 48; j <= 53; j++)
    {
        BoardMatrix[j][10] = '|';
        BoardMatrix[j][59] = '|';
    }

    for (i = 22; i <= 48; i = i + 12)
    {
        for (j = 48; j <= 53; j++)
        {
            BoardMatrix[j][i] = '|';
        }
    }

    for (j = 49; j <= 52; j++)
    {
        writeString(BoardMatrix, "__", j, 15);
        writeString(BoardMatrix, "__", j, 27);
        writeString(BoardMatrix, "__", j, 38);
        writeString(BoardMatrix, "__", j, 50);
    }
}