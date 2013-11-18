#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

//#include "message.h"
#include <vector>

#define InputMessage std::string

class InputSystem
{
 public:
  InputSystem();
  ~InputSystem();

  InputMessage getData() const;

 private:
  std::string m_command;
  std::vector<std::string> m_arguments;
};

#endif
