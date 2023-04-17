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