#include "board.h"

int main()
{
    int i, j;
    int vez = 1; int result = 0;
    int escolha;
    
    board();

    int i, j;

    printf("\n\n\n\n\n\n");

    for (j = 0; j <= LINE - 2; j++) {
        for (i = 0; i<= COLUMN - 2; i++) {
            printf("%c", Board[j][i]);
    }
        printf("\n");}
}