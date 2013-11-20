#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

//#include "message.h"
#include <vector>

#define InputMessage std::string

class InputSystem
{
 public:
  InputSystem();
  virtual ~InputSystem() noexcept
    {}

  virtual InputMessage getData() const = 0; // pure virtual

 private:
  std::string m_command;
  std::vector<std::string> m_arguments;
};

#endif
