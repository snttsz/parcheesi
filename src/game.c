#include "game.h"

void InitGame(Player (*players), int playersNumber)
{
    constructBoard();
    InitPlayers(players, playersNumber);
    PlacePlayersName(players, playersNumber);

    return;
}

void InitPlayers(Player (*players), int playersNumber)
{
    for (int j = 0; j <= playersNumber; j++)
    {
        for (int i = 0; i<= 3; i++)
        {
            players[j].pieces[i] = (Piece)
            {
                .number = i+1,
                .square = {
                    .line = 3,
                    .column = 7 + (16 * i),
                    .squareLine = i + 1,
                    .squareNumber = 0}};
        }
    }

    return;
}

void writePlayerTurn(Player *(player))
{
    writeString(BoardMatrix, player->name, 11, 103);
    writeString(BoardMatrix, player->name, 29, 103);

    writeString(BoardMatrix, "Press any key to roll the dice", 32, 84);

    return;
}

void clean_dice()
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

void clean_actualSquare(Player *player, int column)
{
}

void clean_gameStatePlayerMessages()
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

void printMatrix()
{
    for (int j = 0; j <= LINE - 2; j++)
    {
        for (int i = 0; i <= COLUMN - 2; i++)
        {
            printf("%c", BoardMatrix[j][i]);
        }
        printf("\n");
    }

    return;
}

void PlacePlayersName(Player players[], int playersNumber)
{
    writeString(BoardMatrix, players[0].name, 21, 91);
    writeString(BoardMatrix, players[1].name, 23, 91);
    writeString(BoardMatrix, players[2].name, 25, 91);
    writeString(BoardMatrix, players[3].name, 27, 91);

    writeString(BoardMatrix, players[0].name, 48, 13);
    writeString(BoardMatrix, players[1].name, 48, 25);
    writeString(BoardMatrix, players[2].name, 48, 37);
    writeString(BoardMatrix, players[3].name, 48, 49);

    return;
}

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
    if (playerTurn <= 3)
    {
        playerTurn++;
    }

    return;
}

void runPlayerTurn(Player (*player))
{
    int dice_result;
    char piece_message[43];

    clean_dice();
    clean_gameStatePlayerMessages();
    
    writePlayerTurn(player);
    system("clear");
    printMatrix();
    getchar();
    dice_result = roll_dice(BoardMatrix);
    sprintf(piece_message, "Which piece you want to move %d", dice_result);
    writeString(BoardMatrix, piece_message, 32, 84);
    writeString(BoardMatrix, "square(s)?", 34, 94);

    system("clear");
    printMatrix();

    return;
}

void printPlayers(Player players[], int playersNumber, int piece)
{
    for (int i = 0; i<= playersNumber; i++)
    {
        printf("PLAYER %d --> \n", i);
        printf("PLAYER NAME: %s\n", players[i].name);
        printf("PLAYER PIECE NUMBER: %d\n", players[i].pieces[piece].number);
        printf("PLAYER PIECE COLUMN: %d\n", players[i].pieces[piece].square.column);
        printf("PLAYER PIECE LINE: %d\n",  players[i].pieces[piece].square.line);
        printf("PLAYER PIECE SQUARELINE: %d\n",  players[i].pieces[piece].square.squareLine);
        printf("PLAYER PIECE SQUARENUMBER: %d\n",  players[i].pieces[piece].square.squareNumber);
        printf("PLAYER END <-- \n");
    }

    return;
}
