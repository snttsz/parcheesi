#ifndef PLAYER_STRUCTURE
#define PLAYER_STRUCTURE

#include <stdio.h>

typedef struct
{
    int column;
    int line;
    int squareNumber;
    int squareLine;
    
} Square;

typedef struct
{
    Square square;
    int number;   
    
} Piece;

typedef struct
{
    Piece pieces[4];
    char * name;
    char PieceLetter;
    
} Player;


#endif