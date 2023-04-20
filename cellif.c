#include "variables.h"
/*********************************************************************
 NAME:life_cell
 DESCRIPTION:asks user place of cells
	Input:table[BOARD_SIZE][BOARD_SIZE]
	Output:
  Used global variables: BOARD_SIZE
 REMARKS when using this function:
*********************************************************************/
void life_cell(struct cell table[BOARD_SIZE][BOARD_SIZE], int amount){

    int x, y;
    for (int i = 0; i < amount; i++) {
        printf("Enter coordinates for cell %d in the form 'x y': ", i+1);
        scanf("%d %d", &x, &y);
        table[x][y].current = 1;
        

    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
          printf("%d ",table[i][j].current);  
        }
        printf("\n");}
}

/*********************************************************************
 NAME:life_calculate
 DESCRIPTION:caculates neigbourgh cells
	Input:table[BOARD_SIZE][BOARD_SIZE]
	Output:NONE
  Used global variables:BOARD_SIZE , GAME_SIZE
 REMARKS when using this function:
*********************************************************************/
void life_calculate(struct cell table[BOARD_SIZE][BOARD_SIZE]){

    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= COLUMNS; j++)
        {
            int n = 0;
            int a = 0;
            for (a = i - 1; a <= i + 1; a++)
            {
                int b = 0;
                 for(b = j - 1; b <= j + 1; b++)
                 {
                    if(table[a][b].current == 1)
                    {
                        n+=1;
                    }
                 }
            }


            if(table[i][j].current == 1)
            {
                n -= 1;
                if(n > 3)
                {
                    table[i][j].future = 0;
                } 
                 else if (n < 2)
                {
                     table[i][j].future = 0;
                }
                else if (n == 2 || n == 3){

                    table[i][j].future = 1;
                }
            }  

                //else if jotta ymmärrän mitä teen
            else if(table[i][j].current == 0)
            {
                if (n == 3)
                {
                    table[i][j].future = 1;
                }
                else{
                    table[i][j].future = 0;
                }
            }
            table[i][j].current = table[i][j].future;
        }
    }
    
}