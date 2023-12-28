#include "variables.h"



int file_read_cell(struct cell table[ROWS][COLUMNS]){
    FILE *fptr;
    char state_c;
    int state, c, r;
    fptr = fopen("cell_life.txt", "r");
    if(fptr == NULL){
      printf("Error!");   
      return 0;
      }
    else{
    c = 0;
    r = 0;
    while (fscanf(fptr, "%c", &state_c) == 1)
        {
            state = state_c - '0';
            table[r][c].current = state;
            c++;
            if (c >= COLUMNS)
                {
                r++;
                c = 0;
                /* reads the newline characters away */
                fscanf(fptr, "%c", &state_c); /* reads newline from file */
                }
        }
        fclose(fptr);
    } 
}

int file_read_map(struct cell table[ROWS][COLUMNS]){
   FILE *fptr;
    char state_c;
    int state, c, r;
    fptr = fopen("MAP.txt", "r");
    if(fptr == NULL){
      printf("Error!");   
      return 0;
      }
    else{
    c = 0;
    r = 0;
    while (fscanf(fptr, "%c", &state_c) == 1)
        {
            state = state_c - '0';
            table[r][c].land = state;
            c++;
            if (c >= COLUMNS)
                {
                r++;
                c = 0;
                fscanf(fptr, "%c", &state_c);
                }
        }
        fclose(fptr);
    } 
} 


int file_read_enemy(struct cell table[ROWS][COLUMNS]){
   FILE *fptr;
    char state_c;
    int state, c, r;
    fptr = fopen("enemy.txt", "r");
    if(fptr == NULL){
      printf("Error!");   
      return 0;
      }
    else{
    c = 0;
    r = 0;
    while (fscanf(fptr, "%c", &state_c) == 1)
        {
            state = state_c - '0';
            table[r][c].enemy = state;
            c++;
            if (c >= COLUMNS)
                {
                r++;
                c = 0;
                fscanf(fptr, "%c", &state_c); 
                }
        }
        fclose(fptr);
    } 
} 
