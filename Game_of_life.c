/***************************************************************************
 *   Copyright (C) $Year$ by $Author$   *
 *   $Email$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 /*********************************************************************

 1.  GAME_OF_LIFE



 3.  VERSIONS
       Original:
         12.4.2023 / ELMERI S.

       Version history:

**********************************************************************/
/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
#define BOARD_SIZE 11
#define GAME_SIZE 9
   struct cell{
    int future;
    int current;
    };
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void life_cell(struct cell table[BOARD_SIZE][BOARD_SIZE],int amount);
void life_calculate(struct cell table[BOARD_SIZE][BOARD_SIZE]);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
int main(void){

    struct cell table[BOARD_SIZE][BOARD_SIZE] = {0,0};
    int amount;
    printf("Enter the number of live cells: ");
    scanf("%d", &amount);
    life_cell(table, amount);
    
    while(1){
        system("clear");
        
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
          printf("%d ",table[i][j].current);  
        }
        printf("\n");
    }
    usleep(500000);
    life_calculate(table);
    }
}

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
 NAME:life_cell
 DESCRIPTION:asks user place of cells
	Input:table[BOARD_SIZE][BOARD_SIZE]
	Output:
  Used global variables: BOARD_SIZE
 REMARKS when using this function:
*********************************************************************/
void life_cell(struct cell table[BOARD_SIZE][BOARD_SIZE], int amount){
<<<<<<< HEAD
    int x, y;
=======
    /*int x, y;
>>>>>>> 290a6927b367fbf78cb8dec3ecac33704867fb09
    for (int i = 0; i < amount; i++) {
        printf("Enter coordinates for cell %d in the form 'x y': ", i+1);
        scanf("%d %d", &x, &y);
        table[x][y].current = 1;
        
<<<<<<< HEAD
    }
    
    
=======
    }*/
    table[3][3].current = 1;
    table[4][3].current = 1;
    table[4][4].current = 1;
>>>>>>> 290a6927b367fbf78cb8dec3ecac33704867fb09
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
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

    for (int i = 1; i < GAME_SIZE; i++)
    {
        for (int j = 1; j < GAME_SIZE; j++)
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
<<<<<<< HEAD
                else if (n == 2 || n == 3){
=======
                else{
>>>>>>> 290a6927b367fbf78cb8dec3ecac33704867fb09
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
    
}}