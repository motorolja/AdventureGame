#ifndef POSITION_H
#define POSITION_H

struct Position
{
public:
  int x,y;
  Position(int, int);
  
  Position operator+ (Position&);
  Position operator- (Position&);
  bool operator< (Position&);
  bool operator> (Position&);
  bool operator== (Position&);
};

#endif
