#ifndef GAME_STRUCTURE
#define GAME_STRUCTURE

#include <stdio.h>

enum Color
{
    RED,
    BLUE,
    GREEN,
    YELLOW
};

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
    Piece pieces[3];
    enum Color color;
    char * name;

} Player;


#endif