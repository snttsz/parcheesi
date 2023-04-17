#include "game.h"

/* TODO review this because maybe it's not working */
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
                    .initline = 3,
                    .initcolumn = 11 + (16 * i),
                    .init0column = (7 + (16 * i)) + 3 * j,
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


int selectPiece(char(*buffer), Player(*player), int diceResult)
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
            if (check_piece(*player, i-1))
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

        if (player->pieces[choosen_piece-1].square.squareNumber + diceResult == 15)
        {
            placeFinalSquares(BoardMatrix, player->pieces[choosen_piece-1], player->PieceLetter);
            clean_actualSquare(BoardMatrix, player->pieces[choosen_piece-1], player->PieceLetter);
            player->pieces[choosen_piece-1].square.squareNumber = 15;
            return 0;
        }

        /* 
        If the user selects an invalid piece, then it shows a message accusing the mistake
        and waits for the user to input a valid piece
        */
        if (!check_piece(*player, choosen_piece-1) || check_special_squares(BoardMatrix, player->pieces[choosen_piece-1].square.squareNumber, diceResult, player->pieces[choosen_piece-1].square.initcolumn) || check_squareQuantity(player->pieces[choosen_piece-1], diceResult))
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
    return choosen_piece;
}

void updatePlayer(Player(*players))
{
    int player = getPlayer();
    if (player == -1)
    {
        return;
    }

    Player * playerSelected = &players[player];
    int pieceNumber = atoi(&playerInsideSquare[1]) -1;

    playerSelected->pieces[pieceNumber].square.squareNumber = 0;
    BoardMatrix[3][playerSelected->pieces[pieceNumber].square.init0column] = playerSelected->PieceLetter;
    BoardMatrix[3][playerSelected->pieces[pieceNumber].square.init0column+1] = playerInsideSquare[1];

    return;
}

int getPlayer()
{
    int result = -1;
    char PlayerLetter = playerInsideSquare[0];

    if (PlayerLetter == 'R')
    {
        result = 0;
    }
    else if (PlayerLetter == 'B')
    {
        result = 1;
    }
    else if (PlayerLetter == 'G')
    {
        result = 2;
    }
    else if (PlayerLetter == 'Y')
    {
        result = 3;
    }

    return result;
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
    writePlayerTurn(BoardMatrix, *player);

    /* Cleans the terminal */
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
    
    /* Calls the function to let the player select the piece (the function returns the piece which the player choosed) */
    int choosen_piece = selectPiece(buffer, player, dice_result)-1;
    if (choosen_piece == -1)
    {
        return;
    }

    /* Cleans the square which the player actually is */
    clean_actualSquare(BoardMatrix, player->pieces[choosen_piece], player->PieceLetter);

    /* Checks if there's another player in the square which the player will be, if so, sends this player to square 0 */
    char * playerDead = check_square(BoardMatrix, player->pieces[choosen_piece].square.squareNumber + dice_result, player->pieces[choosen_piece].square.initcolumn);

    /* Copies the playerDead to the playerInsideSquare variable */
    memset(playerInsideSquare, 0, sizeof(playerInsideSquare));
    strcpy(playerInsideSquare, playerDead);

    /* Walks the player through the board until the value of it's actual square plus the additional squares */
    walk(BoardMatrix, *player, choosen_piece, dice_result, player->pieces[choosen_piece].square.initcolumn);
    
    /* Increment the squareNumber at the player's structure with the value of the dice */
    player->pieces[choosen_piece].square.squareNumber += dice_result;

    /* free the pointer where playerDead's allocated */
    free(playerDead);

    return;
}
