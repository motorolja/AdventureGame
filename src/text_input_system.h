#ifndef TEXT_INPUT_SYSTEM_H
#define TEXT_INPUT_SYSTEM_H

#include "input_system.h"

class TextInputSystem : public InputSystem
{
 public:
 TextInputSystem() : InputSystem()
    {}
  
  InputMessage getData() const;

 private:
};

#endif
