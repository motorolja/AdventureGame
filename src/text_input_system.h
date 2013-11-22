#ifndef TEXT_INPUT_SYSTEM_H
#define TEXT_INPUT_SYSTEM_H

#include "input_system.h"

class TextInputSystem : public InputSystem
{
 public:
  TextInputSystem() = default;
  
  InputMessage getData();

 private:
};

#endif
