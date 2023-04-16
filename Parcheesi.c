#include "game.h"


int main()
{
    /* THIS SHOULD NOT BE HERE -> THIS SOULD BE MOVED TO THE MENU DISPLAY */
    int players_size = 3;
    int max_length = (players_size+1) * 10 + 1;
    char playersName[max_length];
    Player players[players_size+1];

    for (int i = 0; i <= players_size; i++)
    {
        printf("Nome do jogador %d: ", i);
        scanf("%9[^\n]", &playersName[i*10]);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        players[i].name = &playersName[i*10];
    }
    players[0].PieceLetter = 'R';
    players[1].PieceLetter = 'B';    
    players[2].PieceLetter = 'G';
    players[3].PieceLetter = 'Y';
    
    /* ^ THIS SHOULD NOT BE HERE  ^ */


    InitGame(players, players_size);    

    while(1)
    {
        runPlayerTurn(&players[getPlayerTurn()]);
        printf("Went to the end of runPlayer\n");
        getchar();
        updatePlayer(players);
        getchar();
        system(command);
        nextPlayerTurn();
        
    }

    return 0;
}