#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
//#include "item.h"
//#include "status.h"
//#include "position.h"

#define Item int
#define Status int
#define Position int

class Player
{
public:
    Player(int, Position);
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