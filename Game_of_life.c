#include <stdio.h>
#include <string.h>
    struct cell{
    int future;
    int current;
    };
void life_cell(struct cell table[9][9]);

int main(void){

    struct cell board[9][9] = {0,0};
    life_cell(board);
}
void life_cell(struct cell table[9][9]){
    table[4][4].current = 1;  
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
          printf("%d ",table[i][j].current);  
        }
        printf("\n");
    }
    
}