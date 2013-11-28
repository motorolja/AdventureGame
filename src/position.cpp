#include "position.h"

Position::Position(int _x = 0, int _y = 0): x(_x), y(_y)
{}

Position Position::operator+ (Position& param)
{
  Position temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

Position Position::operator- (Position& param)
{
  Position temp;
  temp.x = x - param.x;
  temp.y = y - param.y;
  return temp;
}

bool Position::operator> (Position& param)
{
  if( x > param.x )
    return true;
  else if( x == param.x && y > param.y )
    return true;
  return false;
}
bool Position::operator< (Position& param)
{
  if( x < param.x )
    return true;
  else if( x == param.x && y < param.y )
    return true;
  return false;
}

bool Position::operator== (Position& param)
{
  if( x == param.x && y == param.y )
    return true;
  return false;
}