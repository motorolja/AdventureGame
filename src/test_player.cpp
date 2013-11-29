// Test fil
#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

int main()
{
    Item* item = new Item("blingThing");
    Position pos(3,8);
    Status status(poisoned, 5);
    Player p(10, pos);
    
    cout << "Health: " << p.getHealth() 
	 << ", Position: " << pos.x << "," << pos.y 
        << endl;

    p.addStatus(status);
    
    Position pos2(1,3);
    p.setPosition(pos2);
    cout << "Position: " << pos2.x << "," << pos2.y 
        << endl;
    
    pos = p.getPosition();
    cout << "Position: " << pos.x << "," << pos.y 
        << endl;

    for( int i = 0; i < 7; ++i )
        p.update();
    cout << "Health: " << p.getHealth() << endl;    

    p.setHealth(88);
    cout << "Health: " << p.getHealth() << endl;

    Status sta2(poisoned, 10);
    p.addStatus(sta2);
    p.setHealth(100);
    for(int i=0;i<30;++i)
    {
	p.update();
	cout << "Health: " << p.getHealth() << endl;
    }
    
    vector<Item*> temp = p.getInventory();
    for(Item* it : temp)
        cout << "Item: " << endl;
    p.removeItem(-1);
    p.removeItem(100);
    p.removeItem(2);
    p.removeItem(1);
    temp = p.getInventory();
    for(Item* it : temp)
        cout << "Item: " << endl;
    p.removeItem(0);
    temp = p.getInventory();
    for(Item* it : temp)
        cout << "Item: " << endl;
    
    
  return 0;
}
