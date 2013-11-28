#include "position.h"
#include <iostream>

int main()
{
  Position s(10,11);
  Position y(55,3);

  std::cout << s.x << " " << s.y << std::endl;
  
  std::cout << s.x << " " << s.y << std::endl;
  std::cout << s.x << " " << s.y << std::endl;
  std::cout << y.x << " " << y.y << std::endl;
  
  if( y == s )
    std::cout << "lika!!!\n";
  else
    std::cout << "olika,,,\n";

  if( y > s )
    std::cout << "y är större\n";
  
  if( y < s )
    std::cout << "y är mindre\n";

  return 0;
}
