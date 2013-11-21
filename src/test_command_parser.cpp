#include "command_parser.h"
#include <iostream>

using namespace std;

int main()
{
  vector<string> v;
  string command = "help";

  CommandParser c;
  // help
  cout << c.getData(command,v) << endl;

  v.push_back( "lalal" ); // invalid 
  cout << c.getData(command,v) << endl;

  command = "go"; // invalid
  cout << c.getData(command,v) << endl;

  v.at(0) = "east"; // go east
  cout << c.getData(command,v) << endl;

  command = "jump"; // jump string
  cout << c.getData(command,v) << endl;
  
  v.at(0) = "7"; // jump int int
  v.push_back("2");
  cout << c.getData(command,v) << endl;
  
  v.at(1) = "invalid"; // invalid
  cout << c.getData(command,v) << endl;

  command = "make"; // make string string
  cout << c.getData(command,v) << endl;
  
  v.push_back("dada"); // make string string string
  cout << c.getData(command,v) << endl;

  command = "save"; // invalid
  cout << c.getData(command,v) << endl;
  

  return 0;
}
