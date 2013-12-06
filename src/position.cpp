#include "position.h"

Position::Position(int _x, int _y): x(_x), y(_y)
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

bool Position::operator> (const Position& param) const
{
  if( x > param.x )
    return true;
  else if( x == param.x && y > param.y )
    return true;
  return false;
}
bool Position::operator< (const Position& param) const
{
  if( x < param.x )
    return true;
  else if( x == param.x && y < param.y )
    return true;
  return false;
}

bool Position::operator== (const Position& param) const
{
  if( x == param.x && y == param.y )
    return true;
  return false;
}
