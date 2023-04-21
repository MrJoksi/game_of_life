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
int main(){

    struct cell table[ROWS][COLUMNS] = {0,0};
    int amount;
    char ab;
    initscr();
    clear();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_GREEN);
    bkgd(COLOR_PAIR(1));
    move(2,10);
    printw("Read from file: A ");
    move(3,10);
    printw("Input cells: B");
    move(4,10);
    printw("What to do: ");
    refresh();
    scanw("%c", &ab);
    move(2,10);
    printw("                  ");
    move(3,10);
    printw("                  ");
    move(4,10);
    printw("                  ");
    refresh();
    if (ab == 'B' || ab == 'b')
      {
        move(2,10);
        printw("Enter the number of live cells: ");
        refresh();
        scanw("%d", &amount);
        life_cell(table, amount);
      }
    else if (ab == 'A' || ab == 'a')
    {
      file_read(table);
    }
    
    while(1){
      curs_set(0);
      bkgd(COLOR_PAIR(2));
        
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 1; j < COLUMNS; j++)
        {
          if(table[i][j].current == 1){
          printw("#");
          }
          else{
            printw("   ");
          }
        }
        printw("\n");
    }
    
    usleep(5000000);
    life_calculate(table);
    

    }
    nodelay(stdscr, FALSE);
    getch();  
    endwin();
}

