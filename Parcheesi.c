#include "game.h"

int main()
{
    Player* RedPlayer = malloc(sizeof(Player));
    Player* YellowPlayer = malloc(sizeof(Player));
    Player* GreenPlayer = malloc(sizeof(Player));
    Player* BluePlayer = malloc(sizeof(Player));
    RedPlayer->name = "RED";
    YellowPlayer->name = "YELLOW";
    BluePlayer->name = "BLUE";
    GreenPlayer->name = "GREEN";
    InitGame(RedPlayer, BluePlayer, YellowPlayer, GreenPlayer);

    for (int j = 0; j <= LINE - 2; j++)
    {
        for (int i = 0; i <= COLUMN - 2; i++)
        {
            printf("%c", BoardMatrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}