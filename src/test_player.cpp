// Test fil
#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

int main()
{
  Item item("blingThing");
  Item item2("ofc my horse");
  Position pos(3,8);
  Status status(poisoned, 5);
  Player p(10, pos);

  cout << item.getName() << endl;

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
    
  p.addItem(item);
  p.addItem(item2);
    
  vector<Item> temp = p.getInventory();
  for(int i = 0; i < temp.size(); ++i)
    cout << "Item: " << temp.at(i).getName() << endl;

  p.removeItem(1);
  // bara ett item kvar nu "blingThing"
  temp = p.getInventory();
  for(int i = 0; i < temp.size(); ++i)
    cout << "Item: " << temp.at(i).getName() << endl;
  p.removeItem(0);
  temp = p.getInventory();
  for(int i = 0; i < temp.size(); ++i)
    cout << "Item: " << temp.at(i).getName() << endl;
    
  // kastar ett exception sist, out of range
  p.removeItem(2);
    
  return 0;
}
