#include "input_system.h"
#include "command_parser.h"
#include <iostream>

InputSystem::InputSystem():
{}

InputMessage InputSystem::getData() const
{
  // Inläsnings funktion testad
  m_arguments.clear();// tömmer för att det alltid ska finnas senaste inmatningen
  std::cin >> m_command;
  if( std::cin.peek() != '\n' )
    {
      std::string temp;
      while(std::cin >> temp)
	{
	  m_arguments.push_back(temp);
	  if(std::cin.peek() == '\n')
	    break;
	}
    }
  return CommandParser::getData(m_command,m_arguments);
}
