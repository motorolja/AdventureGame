#include <iostream>
#include <curses.h>
#include "text_input_system.h"

bool curses_started = false;

void endCurses() {
  if (curses_started && !isendwin())
    endwin();
}


void startCurses() 
{
  if (curses_started) 
    {
      refresh();
    }
  else 
    {
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
  InputMessage* i = s.getData();
  endCurses();
  
  std::vector<std::string> temp = i->getArguments();
  std::cout << i->getCommand() << std::endl;
  for( int i = 0; i < temp.size(); ++i )
    std::cout << temp.at(i) << std::endl;
  if( i->getValid() )
    std::cout << "Valid command\n";
  else
    std::cout << "Invalid command\n";
  
  return 0;
}
