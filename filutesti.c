#include "variables.h"



int file_read(struct cell table[BOARD_SIZE][BOARD_SIZE])
{
    FILE *fptr;
    char state_c;
    int state, c, r;
    if(fptr == NULL)
   {
      printf("Error!");   
      return 0;
    c = 0;
    r = 0;
    fptr = fopen("cell_life.txt", "r");
    while (fscanf(fptr, "%c", &state_c) == 1)
        {
            state = state_c - '0';
            table[r][c].current = state;
            c++;
            if (c >= COLUMNS)
                {
                r++;
                c = 1;
                /* reads the newline characters away */
                fscanf(fptr, "%c", &state_c); /* reads newline from file */
                #if defined(_WIN32) && (!defined(__unix__) || !defined(__unix) || (!defined(__APPLE__) && !defined(__MACH__)))
                fscanf(fptr, "%c", &state_c); /* reads carriage return from file in case of Windows */
                #endif
                }
        }
        fclose(fptr);
    } 
}