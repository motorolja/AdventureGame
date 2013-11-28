#ifndef POSITION_H
#define POSITION_H

struct Position
{
public:
  Position();
  int x,y;
  
  Position operator + (Position&);
  Position operator - (Position&);
};

#endif
