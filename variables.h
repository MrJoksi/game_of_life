#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
#define BOARD_SIZE 32
#define ROWS 10
#define COLUMNS 24
#define GAME_SIZE BOARD_SIZE-2
   struct cell{
    int future;
    int current;
    };
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int file_read(struct cell table[ROWS][COLUMNS]);

void life_cell(struct cell table[ROWS][COLUMNS],int amount);

void life_calculate(struct cell table[ROWS][COLUMNS]);