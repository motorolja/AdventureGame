#ifndef TEXT_INPUT_SYSTEM_H
#define TEXT_INPUT_SYSTEM_H

#include "command_parser.h"
#include "input_system.h"
#include <curses.h>

class TextInputSystem : public InputSystem
{
 public:
  TextInputSystem() = default;
  
  InputMessage* getData();

 private:
  std::string m_command;
  std::vector<std::string> m_arguments;
  CommandParser m_parser;
};

#endif
