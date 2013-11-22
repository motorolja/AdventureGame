#include <iostream>
#include <ncurses.h>
#include "text_input_system.h"

bool curses_started = false;

void endCurses() {
  if (curses_started && !isendwin())
    endwin();
}


void startCurses() {
  if (curses_started) {
    refresh();
  }
  else {
    initscr();
    cbreak();
    echo();
    intrflush(stdscr, false);
    keypad(stdscr, true);
    atexit(endCurses);
    curses_started = true;
  }
}

int main()
{
  TextInputSystem s;
  startCurses();
  InputMessage i = s.getData();
  endCurses();
  
  std::cout << i << std::endl;
  
  return 0;
}
