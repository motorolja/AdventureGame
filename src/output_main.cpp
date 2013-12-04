#include <iostream>
#include "text_output_system.h"
#include <string>
using namespace std;

int main()
{
 Item it("Sword");
  string str = "meat";
  bool check = true;
  EngineMessage* message = new EngineMessage(EngineMessage::ceat);
  Player p;
  p.addItem(it);
  message->addArgument(str); //
  message->setSuccess(check); //
  message->setPlayer(p);
  vector<Item> items = message->getPlayer().getInventory();

    TextOutputSystem TOS;
    TOS.retrieveOutput(message);
    TOS.writeOutput();
    return 0;

}
