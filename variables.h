#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
#define BOARD_SIZE 32
#define ROWS 8
#define COLUMNS 24
#define GAME_SIZE BOARD_SIZE-2
   struct cell{
    int future;
    int current;
    };
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void life_cell(struct cell table[BOARD_SIZE][BOARD_SIZE],int amount);
void life_calculate(struct cell table[BOARD_SIZE][BOARD_SIZE]);