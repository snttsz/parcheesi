#include "game.h"

int main()
{
    Player* playerRed = malloc(sizeof(Player));
    Player* playerYellow = malloc(sizeof(Player));
    Player* playerGreen = malloc(sizeof(Player));
    Player* playerBlue = malloc(sizeof(Player));
    playerRed->name = "RED";
    playerYellow->name = "YELLOW";
    playerBlue->name = "BLUE";
    playerGreen->name = "GREEN";
    InitGame(playerRed, playerBlue, playerYellow, playerGreen);


/*     printf("\n\n\n\n\n\n");

    for (int j = 0; j <= LINE - 2; j++)
    {
        for (int i = 0; i <= COLUMN - 2; i++)
        {
            printf("%c", BoardMatrix[j][i]);
        }
        printf("\n");
    } */

    return 0;
}