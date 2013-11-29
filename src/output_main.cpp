#include <iostream>
#include "text_output_system.h"
#include <string>
using namespace std;

int main()
{
  string str = "west";
  bool check = true;
  EngineMessage* message = new EngineMessage(EngineMessage::go);
  message->addArgument(str); // 
  message->setSuccess(check); //
  TextOutputSystem TOS;
    TOS.retrieveOutput(message);
    TOS.writeOutput();
    //cout << "Hello world!" << endl;
    return 0;
}
