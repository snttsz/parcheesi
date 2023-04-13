#include "game.h"

void set_OS(void)
{
    #ifdef _WIN32
        command = "cls";
    #elif defined(__APPLE__)
        command = "clear";
    #elif defined(__linux__)
        command = "clear";
    #endif
}

void InitGame(Player(*players), int playersNumber)
{
    set_OS();
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


int selectPiece(char(*buffer), Player(*player))
{
    /* The piece choosen by the user to move x squares */
    int choosen_piece;
    while(1)
    {
        for (int i = 1; i <= 4; i++)
        {
            /* 
            Messages about which piece the player wants to move x squares 
            It is at first checked if the piece number i is available (if the piece is not out of the game yet)
            */
            if (check_piece(player, i-1))
            {
                sprintf(buffer, "Press %d to move piece %c%d", i, player->PieceLetter, i);
                writeString(BoardMatrix, buffer, 36+i, 87);
            }
        }
        /* Clenas the terminal and print the updated board */
        system(command);
        printMatrix();
        
        /* Asks for the user answer */
        printf("\t\t\t\t\t\t\t\t\t\t\t    Answer: ");
        scanf("%d", &choosen_piece);

        /* 
        If the user selects an invalid piece, then it shows a message accusing the mistake
        and waits for the user to input a valid piece
        */
        if (!check_piece(player, choosen_piece-1))
        {
            writeString(BoardMatrix, "You can't move this piece!", 45, 85);
            system(command);
            printMatrix();

            continue;
        }

        break;
    }

    /* Cleans the line where the invalid piece message could be */
    writeString(BoardMatrix, "                          ", 45, 85);
    /* Minus 1 because the piece's index starts with 0 */
    return choosen_piece-1;
}

void runPlayerTurn(Player (*player))
{
    /* Will keep the result of the dice */
    int dice_result;
    /* Will keep the messages that should be printed inside the GameState Panel */
    char buffer[43];

    /* Will clean the dice, in case it had already been rolled and there's a past number drawed */
    clean_dice(BoardMatrix);
    /* Will clean the messages of the last player's turn of the gamestate panel */
    clean_gameStatePlayerMessages(BoardMatrix);
    /* Will write the player's name inside the board where it's needed */
    writePlayerTurn(BoardMatrix, player);

    /* Clears the terminal */
    system(command);
    /* Prints the Board with the updated informations and ask to the player to press any key to roll the dice */
    printMatrix();
    getchar();

    /* Rolls the dice and store the result inside a variable */
    dice_result = roll_dice(BoardMatrix);

    /* Copies a default message with the value of the dice */
    sprintf(buffer, "Which piece you want to move %d", dice_result);
    /* Writes inside the board */
    writeString(BoardMatrix, buffer, 32, 84);
    writeString(BoardMatrix, "square(s)?", 34, 94);

    /* Cleans the buffer to store a new message */
    memset(buffer, 0, sizeof(buffer));
    
    /* Increment the squareNumber at the player's structure with the value of the dice */
    player->pieces[selectPiece(buffer, player)].square.squareNumber += dice_result;

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
