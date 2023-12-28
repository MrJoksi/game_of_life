#include "variables.h"
/*********************************************************************
 NAME:life_cell
 DESCRIPTION:asks user place of cells
	Input:table[ROWS][COLUMNS]
	Output:
  Used global variables: BOARD_SIZE
 REMARKS when using this function:
*********************************************************************/
void life_cell(struct cell table[ROWS][COLUMNS], int amount){

    int x, y;
    for (int i = 0; i < amount; i++) {
        move(3,10);
        refresh();
        printw("Enter coordinates for cell %d", i+1);
        move(4,10);
        printw("in the form 'x y': ");
        refresh();
        scanw("%d %d", &x, &y);
        refresh();
        move(3,10);
        printw("                                  ");
        refresh();
        move(4,10);
        printw("                                    ");
        refresh();
        table[x][y].current = 1;
    }
    /*for (int i = 1; i < ROWS - 1; i++)
    {
        for (int j = 1; j < COLUMNS - 1; j++)
        {
          printw("%d ",table[i][j].current);
          refresh();  
        }
        printw("\n");
        refresh();
    }*/
}

int creature_placement(struct cell table[ROWS][COLUMNS])
{
    for (int i = 1; i < ROWS - 1; i++)
    {
        for (int j = 1; j <= COLUMNS - 1; j++)
        {
            

        }
        
    }
}

/*********************************************************************
 NAME:life_calculate
 DESCRIPTION:caculates neigbourgh cells
	Input:table[ROWS][COLUMNS]
	Output:NONE
  Used global variables:BOARD_SIZE , GAME_SIZE
 REMARKS when using this function:
*********************************************************************/
void life_calculate(struct cell table[ROWS][COLUMNS]){
    
    for (int i = 1; i < ROWS - 1; i++)
    {
        for (int j = 1; j <= COLUMNS - 1; j++)
        {
           int f = 0;
           int n = 0; 
            n = table[i+1][j-1].current + 
                table[i+1][j  ].current + 
                table[i+1][j+1].current + 
                table[i  ][j-1].current + 
                table[i  ][j+1].current + 
                table[i-1][j-1].current +
                table[i-1][j  ].current + 
                table[i-1][j+1].current;

            f = table[i+1][j-1].enemy + 
                table[i+1][j  ].enemy + 
                table[i+1][j+1].enemy + 
                table[i  ][j-1].enemy + 
                table[i  ][j+1].enemy + 
                table[i-1][j-1].enemy +
                table[i-1][j  ].enemy + 
                table[i-1][j+1].enemy;
                           
            if(table[i][j].land == 1)
            {
                if(table[i][j].current == 1)
                {
                    if(n > 3 || n < 2 || f >= 1)
                    {
                        table[i][j].future = 0;
                    } 

                    else if (n == 2 || n == 3 || f == 0)
                    {
                        table[i][j].future = 1;
                    }
                }  

                else if(table[i][j].current == 0)
                {
                    if (n == 2|| n == 3)
                    {
                         table[i][j].future = 1;
                    }
                    else if(f > 0)
                    {
                        table[i][j].future = 0;
                    }
                    
                }

                if(table[i][j].enemy == 1)
                {
                    if(table[i][j].enemy == table[i][j].current)
                    {
                        table[i][j].future = 0;
                    }
                    if(f > 2 || f < 1)
                    {
                        table[i][j].enemyfuture = 0;
                    }
                    else if(f > 1)
                    {
                        table[i][j].enemyfuture = 1;
                    }
                    
                }
                else if(table[i][j].enemy == 0)
                {
                    if(f > 1)
                    {
                        table[i][j].enemyfuture = 1;
                    }
                    else{
                        table[i][j].enemyfuture = 0;
                    }
                }

            else if(table[i][j].land == 0)
            {
                table[i][j].future = 0;
                table[i][j].enemyfuture = 0;
            }
            }

            
            
        }
    }
    
    for (int i = 1; i < ROWS - 1; i++)
    {
        for (int j = 1; j <= COLUMNS - 1; j++)
        {
        table[i][j].current = table[i][j].future;
        table[i][j].enemy = table[i][j].enemyfuture;
        }
    }
}
/*int a = 0;
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

*/