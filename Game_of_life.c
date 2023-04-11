#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    struct cell{
    int future;
    int current;
    };
void life_cell(struct cell table[9][9]);
void life_calculate(struct cell table[9][9]);

int main(void){

    struct cell table[9][9] = {0,0};
    life_cell(table);
    life_calculate(table);
}
void life_cell(struct cell table[9][9]){
    table[4][4].current = 1;  
    table[4][5].current = 1;
    table[5][4].current = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
          printf("%d ",table[i][j].current);  
        }
        printf("\n");
    }
    
}
void life_calculate(struct cell table[9][9]){

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int n = 0;
            for (int a = i - 1; a <= i + 1; a++)
            {
                 for(int b = j - 1; b <= j + 1; j++)
                 {
                    n+=table[a][b].current;
                 }

                if(table[i][j].current == 1)
                {
                    if(n >= 4)
                    {
                        table[i][j].future = 0;
                    } 
                    else if (n <= 1)
                    {
                        table[i][j].future = 0;
                    }
                }  

                //else if jotta ymmärrän mitä teen
                else if(table[i][j].current == 0)
                {
                     if (n == 3)
                    {
                    table[i][j].future = 1;
                    }
                }
            
            }
        
    }
    
}
}