#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

class InputSystem
{
 public:
  InputSystem() = default;
  virtual ~InputSystem() noexcept
    {}

  virtual InputMessage* getData() = 0; // pure virtual

};

#endif
