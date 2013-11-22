#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include "command_parser.h"
//#include "message.h"
#include <vector>

#define InputMessage std::string

class InputSystem
{
 public:
  InputSystem() = default;
  virtual ~InputSystem() noexcept
    {}

  virtual InputMessage getData() = 0; // pure virtual

 protected:
  std::string m_command;
  std::vector<std::string> m_arguments;
  CommandParser m_parser;
};

#endif
