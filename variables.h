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
#define ROWS 23
#define COLUMNS 100
#define GAME_SIZE BOARD_SIZE-2
   struct cell{
    int future;
    int current;
    int land;
    int enemy;
    int enemyfuture;
    };
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int file_read_cell(struct cell table[ROWS][COLUMNS]);

void life_cell(struct cell table[ROWS][COLUMNS],int amount);

void life_calculate(struct cell table[ROWS][COLUMNS]);

int file_read_map(struct cell table[ROWS][COLUMNS]);

int file_read_enemy(struct cell table[ROWS][COLUMNS]);