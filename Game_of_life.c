/***************************************************************************/
/*   Copyright (C) 2023 by Elmeri   *
 *   e2203113@edu.vamk.fi   *
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
#include "variables.h"


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
        system("cls");
        
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
          printf("%d ",table[i][j].current);  
        }
        printf("\n");
    }
    
    usleep(500000);
    life_calculate(table);
    }
}

