#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "item.h"
#include "position.h"

enum eStatus
  {
    poisoned
  };

struct Status
{
  Status(eStatus, unsigned short );
  eStatus m_status;
  unsigned short m_duration;
};


class Player
{
public:
  Player(int starting_health = 10, Position starting_position = Position(0,0) );
    ~Player();
    
    int getHealth() const;
    void setHealth(int);
    
    void addItem(Item*);
    void removeItem(int index);
    std::vector<Item*> getInventory();
    
    void addStatus(Status);
    void clearStatus();
    
    void setPosition(Position);
    Position getPosition() const;
    
    void update();
private:
    std::vector<Item*> m_inventory;
    std::vector<Status> m_statuses;
    unsigned int m_health;
    Position m_position;
};

#endif
