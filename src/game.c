#include "game.h"

void InitGame(Player(*PlayerRedRef), Player(*PlayerBlueRef), Player(*PlayerYellowRef), Player(*PlayerGreenRef))
{
    playerRed = PlayerRedRef;
    playerBlue = PlayerBlueRef;
    playerYellow = PlayerYellowRef;
    playerGreen = PlayerGreenRef;
    
    constructBoard();
    InitPlayers(); 
    PlacePlayersName();

    return;
}

void InitPlayers()
{
    playerRed->color = RED;
    for (int i = 0; i <= 3; i++)
    {
        playerRed->pieces[i] = (Piece){
            .number = i+1,
            .square = {
                .line = 3,
                .column = 7 + (16 * i),
                .squareLine = i + 1,
                .squareNumber = 0}};
    }

    playerBlue->color = BLUE;
    for (int i = 0; i <= 3; i++)
    {
        playerBlue->pieces[i] = (Piece){
            .number = i+1,
            .square = {
                .line = 3,
                .column = 7 + (16 * i),
                .squareLine = i + 1,
                .squareNumber = 0}};
    }

    playerYellow->color = YELLOW;
    for (int i = 0; i <= 3; i++)
    {
        playerYellow->pieces[i] = (Piece){
            .number = i+1,
            .square = {
                .line = 3,
                .column = 7 + (16 * i),
                .squareLine = i + 1,
                .squareNumber = 0}};
    }

    playerGreen->color = GREEN;
    for (int i = 0; i <= 3; i++)
    {
        playerGreen->pieces[i] = (Piece){
            .number = i+1,
            .square = {
                .line = 3,
                .column = 7 + (16 * i),
                .squareLine = i + 1,
                .squareNumber = 0}};
    }

    return;
}

void PlacePlayersName()
{
    writeString(BoardMatrix, playerRed->name, 21, 91);
    writeString(BoardMatrix, playerBlue->name, 23, 91);
    writeString(BoardMatrix, playerYellow->name, 25, 91);
    writeString(BoardMatrix, playerGreen->name, 27, 91);

    return;
}

void printPlayers(int piece)
{
    printf("PLAYER RED --> \n");
    printf("PLAYER NAME: %s\n", playerRed->name);
    printf("PLAYER COLOR: %d\n", playerRed->color);
    printf("PLAYER PIECE NUMBER: %d\n", playerRed->pieces[piece].number);
    printf("PLAYER PIECE COLUMN: %d\n", playerRed->pieces[piece].square.column);
    printf("PLAYER PIECE LINE: %d\n",  playerRed->pieces[piece].square.line);
    printf("PLAYER PIECE SQUARELINE: %d\n",  playerRed->pieces[piece].square.squareLine);
    printf("PLAYER PIECE SQUARENUMBER: %d\n",  playerRed->pieces[piece].square.squareNumber);
    printf("PLAYER RED <-- ");

    printf("\n\nPLAYER BLUE -->\n");
    printf("PLAYER NAME: %s\n", playerBlue->name);
    printf("PLAYER COLOR: %d\n", playerBlue->color);
    printf("PLAYER PIECE NUMBER: %d\n", playerBlue->pieces[piece].number);
    printf("PLAYER PIECE COLUMN: %d\n", playerBlue->pieces[piece].square.column);
    printf("PLAYER PIECE LINE: %d\n",  playerBlue->pieces[piece].square.line);
    printf("PLAYER PIECE SQUARELINE: %d\n",  playerBlue->pieces[piece].square.squareLine);
    printf("PLAYER PIECE SQUARENUMBER: %d\n",  playerBlue->pieces[piece].square.squareNumber);
    printf("PLAYER BLUE <-- ");

    printf("\n\nPLAYER YELLOW -->\n");
    printf("PLAYER NAME: %s\n", playerYellow->name);
    printf("PLAYER COLOR: %d\n", playerYellow->color);
    printf("PLAYER PIECE NUMBER: %d\n", playerYellow->pieces[piece].number);
    printf("PLAYER PIECE COLUMN: %d\n", playerYellow->pieces[piece].square.column);
    printf("PLAYER PIECE LINE: %d\n",  playerYellow->pieces[piece].square.line);
    printf("PLAYER PIECE SQUARELINE: %d\n",  playerYellow->pieces[piece].square.squareLine);
    printf("PLAYER PIECE SQUARENUMBER: %d\n",  playerYellow->pieces[piece].square.squareNumber);
    printf("PLAYER YELLOW <-- ");

    printf("\n\nPLAYER GREEN -->\n");
    printf("PLAYER NAME: %s\n", playerGreen->name);
    printf("PLAYER COLOR: %d\n", playerGreen->color);
    printf("PLAYER PIECE NUMBER: %d\n", playerGreen->pieces[piece].number);
    printf("PLAYER PIECE COLUMN: %d\n", playerGreen->pieces[piece].square.column);
    printf("PLAYER PIECE LINE: %d\n",  playerGreen->pieces[piece].square.line);
    printf("PLAYER PIECE SQUARELINE: %d\n",  playerGreen->pieces[piece].square.squareLine);
    printf("PLAYER PIECE SQUARENUMBER: %d\n",  playerGreen->pieces[piece].square.squareNumber);
    printf("PLAYER GREEN <-- \n");

    return;
}
