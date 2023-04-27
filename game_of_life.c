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

    struct cell table[ROWS][COLUMNS] = {0};
    int amount;
    char ab;
    initscr();
    clear();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_GREEN);
    init_pair(3,COLOR_BLUE,COLOR_BLUE);
    init_pair(4,COLOR_BLACK,COLOR_GREEN);
    bkgd(COLOR_PAIR(1));
    file_read_map(table);
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
      file_read_cell(table);
      file_read_enemy(table);
    } 
    char cont;
    clear();
    
    nodelay(stdscr, TRUE);
    while(cont != 'x')
    {
      
      curs_set(0);
       
      move(1,1);
        
    for (int i = 1; i < ROWS; i++)
      {
        for (int j = 1; j < COLUMNS; j++)
        {
          move(i,j);
          
          if(table[i][j].land == 1)
          {
            if(table[i][j].current == 1)
            {
              attron(COLOR_PAIR(2));
              printw("*");
              attroff(COLOR_PAIR(2));
              refresh();
            }
            else if(table[i][j].enemy == 1)
            {
              move(i,j);
              attron(COLOR_PAIR(4));
              printw("#");
              attroff(COLOR_PAIR(4));
              refresh();
            }
            else if(table[i][j].current == 0 && table[i][j].enemy == 0)
            {
              attron(COLOR_PAIR(2));
              printw(" ");
              attroff(COLOR_PAIR(2));
              refresh();
            }
          }

          else if(table[i][j].land == 0){
              attron(COLOR_PAIR(3));
              printw(" ");
              attroff(COLOR_PAIR(3));
              refresh();
            }
          }
        }
      //move(0 + i,1);
      refresh();
      //clear();
      sleep(1);
      life_calculate(table);
      cont = getch(); 
    }


    nodelay(stdscr, FALSE);
    getch(); 
    endwin();
}