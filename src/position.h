#ifndef POSITION_H
#define POSITION_H

struct Position
{
public:
  int x,y;
  Position(int _x = 0, int _y = 0);
  
  Position operator+ (Position&);
  Position operator- (Position&);
  bool operator< (Position&);
  bool operator> (Position&);
  bool operator== (Position&);
};

#endif
