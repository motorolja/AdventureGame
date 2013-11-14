// Test fil
#include <iostream>
#include "player.h"

using namespace std;

int main()
{
    Item* item = new Item(123456789);
    Position pos = 22;
    Status status = 9;
    Player p(7 ,pos);
    
    cout << "Health: " << p.getHealth() 
        << ", Position: " << p.getPosition()
        << endl;

    p.addStatus(status);
    p.clearStatus();
    
    pos = 3;
    p.setPosition(pos);
    cout << "Position: " << p.getPosition()
        << endl;
    
    for( int i = 7; i <= 0; --i )
        p.update();
        
    p.setHealth(88);
    cout << "Health: " << p.getHealth() << endl;
    
    vector<Item*> temp = p.getInventory();
    for(Item* it : temp)
        cout << "Item: " << it* << endl;
    p.removeItem(-1);
    p.removeItem(100);
    p.removeItem(2);
    p.removeItem(1);
    temp = p.getInventory();
    for(Item* it : temp)
        cout << "Item: " << it* << endl;
    p.removeItem(0);
    temp = p.getInventory();
    for(Item* it : temp)
        cout << "Item: " << it* << endl;
    
    
  return 0;
}