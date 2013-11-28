#include "position.h"
#include <iostream>

int main()
{
  Position s;
  Position y;
  s.x = 10;
  s.y = 11;
  std::cout << s.x << " " << s.y << std::endl;
  y.x = 5;
  s = s + y;
  std::cout << s.x << " " << s.y << std::endl;
  s.x = -2;
  std::cout << s.x << " " << s.y << std::endl;
  y.y = 12;
  y = s - y;
  std::cout << y.x << " " << y.y << std::endl;

  return 0;
}
