#include "String_utils.h"

void writeString(char (*matrix)[MAX_COLUMNS], char text[], int line, int column)
{
    int i, j, size;

    size = strlen(text);

    for (i = column, j = 0; i < column + size; i++, j++)
    {
        matrix[line][i] = text[j];
    }

    return;
}

void writeStringDebug(char (*matrix)[MAX_COLUMNS], char text[], int line, int column)
{
    writeString(matrix, "                         ", line, column);

    writeString(matrix, text, line, column);

    return;
}
