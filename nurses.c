#include <ncurses.h>

int main() {
  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  start_color();

  // Define color pairs
  init_pair(1, COLOR_WHITE, COLOR_BLUE);  // pair 1: white text on blue background
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);  // pair 2: black text on yellow background

  // Create a new window for the box
  WINDOW* win = newwin(10, 20, 5, 5);

  // Set the background color of the window
  wbkgd(win, COLOR_PAIR(1));

  // Draw the box and text inside the window
  box(win, '*', '*');
  wattron(win, COLOR_PAIR(2));
  mvwprintw(win, 1, 1, "Hello, world!");
  wattroff(win, COLOR_PAIR(2));

  // Refresh the window and the screen
  wrefresh(win);
  refresh();

  // Wait for user input before exiting
  getch();

  // Clean up ncurses
  delwin(win);
  endwin();
  return 0;
}
