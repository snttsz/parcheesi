#include "board.h"

void board()
{
    horizontal_squares(LINE - 2, COLUMN - 2);
    vertical_squares(4, 9);
    vertical_squares(4, 25);
    vertical_squares(4, 41);
    vertical_squares(4, 57);
    final_square();
    write_insideMatrix("R1 B1 G1 Y1", 3, 7);
    write_insideMatrix("R2 B2 G2 Y2", 3, 23);
    write_insideMatrix("R3 B3 G3 Y3", 3, 39);
    write_insideMatrix("R4 B4 G4 Y4", 3, 55);
    log_drawing();
    draw_dices();
    specialSquares_drawing();
}

void log_drawing()
{
    int j;

    write_insideMatrix("MENU DE JOGADAS", 18, 92);
    write_insideMatrix("JOGADOR ", 21, 82);
    write_insideMatrix("RED", 21, 110);
    write_insideMatrix("JOGADOR ", 23, 82);
    write_insideMatrix("BLUE", 23, 110);
    write_insideMatrix("JOGADOR ", 25, 82);
    write_insideMatrix("GREEN", 25, 110);
    write_insideMatrix("JOGADOR ", 27, 82);
    write_insideMatrix("YELLOW", 27, 110);
    write_insideMatrix("VEZ DO JOGADOR ", 11, 88);
    write_insideMatrix("VEZ DO JOGADOR ", 29, 88);

    for (j = 81; j <= COLUMN - 2; j++)
    {
        Board[16][j] = '#';
    }

    for (j = 1; j <= LINE - 3; j++)
    {
        Board[j][80] = '#';
    }
}

void specialSquares_drawing()
{
    if (Board[5][11] == ' ' || Board[23][11] == ' ' || Board[44][11] == ' ')
    {
        Board[5][11] = '*';
        Board[5][12] = '*';
        Board[23][11] = '*';
        Board[23][12] = '*';
        Board[44][11] = '*';
        Board[44][12] = '*';
    }
    if (Board[5][27] == ' ' || Board[23][27] == ' ' || Board[44][27] == ' ')
    {
        Board[5][27] = '*';
        Board[5][28] = '*';
        Board[23][27] = '*';
        Board[23][28] = '*';
        Board[44][27] = '*';
        Board[44][28] = '*';
    }
    if (Board[5][43] == ' ' || Board[23][43] == ' ' || Board[44][43] == ' ')
    {
        Board[5][43] = '*';
        Board[5][44] = '*';
        Board[23][43] = '*';
        Board[23][44] = '*';
        Board[44][43] = '*';
        Board[44][44] = '*';
    }
    if (Board[5][59] == ' ' || Board[23][59] == ' ' || Board[44][59] == ' ')
    {
        Board[5][59] = '*';
        Board[5][60] = '*';
        Board[23][59] = '*';
        Board[23][60] = '*';
        Board[44][59] = '*';
        Board[44][60] = '*';
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
                Board[j][i] = '#';
            }
        }
        else
        {
            for (i = 0; i < 1; i++)
            {
                Board[j][i] = '#';
                Board[j][column] = '#';
            }
            for (i = 1; i < column; i++)
            {
                Board[j][i] = ' ';
            }
        }
    }
}

void vertical_squares(int line, int column)
{

    for (int j = line; j <= line + 40; j = j + 3)
    {
        Board[j][column + 2] = '-';
        Board[j][column + 3] = '-';
        Board[j + 1][column + 1] = '|';
        Board[j + 1][column + 4] = '|';
        Board[j + 2][column + 2] = '-';
        Board[j + 2][column + 3] = '-';
    }
}

void draw_dices()
{
    int i, j;

    for (j = 5; j <= 9; j++)
    {
        for (i = 95; i <= 103; i++)
        {
            if (j == 5 || j == 9)
            {
                Board[j][i] = '-';
            }
            else if (i == 95 || i == 103)
            {
                Board[j][i] = '|';
            }
        }
    }
}

void final_square()
{
    int i, j;

    for (j = 10; j <= 59; j++)
    {
        Board[47][j] = '-';
        Board[54][j] = '-';
    }
    for (j = 48; j <= 53; j++)
    {
        Board[j][10] = '|';
        Board[j][59] = '|';
    }

    for (i = 22; i <= 48; i = i + 12)
    {
        for (j = 48; j <= 53; j++)
        {
            Board[j][i] = '|';
        }
    }

    for (j = 49; j <= 52; j++)
    {
        write_insideMatrix("__", j, 15);
        write_insideMatrix("__", j, 27);
        write_insideMatrix("__", j, 38);
        write_insideMatrix("__", j, 50);
    }

    write_insideMatrix("RED", 48, 15);
    write_insideMatrix("BLUE", 48, 27);
    write_insideMatrix("GREEN", 48, 38);
    write_insideMatrix("YELLOW", 48, 50);
}

void write_insideMatrix(char *text, int line, int column)
{
    int i, j, size;

    size = strlen(text) - 1;

    for (i = column, j = 0; i <= column + size; i++, j++)
    {
        Board[line][i] = text[j];
    }
}