#include "position.h"

Position::Position()
{
  x = 0;
  y = 0;
}

Position Position::operator + (Position& param)
{
  Position temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

Position Position::operator - (Position& param)
{
  Position temp;
  temp.x = x - param.x;
  temp.y = y - param.y;
  return temp;
}
