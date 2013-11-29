#include "command_parser.h"
#include <cctype>

CommandParser::CommandParser()
{ 
 /* 
     initiera m_command_table
     samma ordning på kommandon som i kravdokumentet
     Spelarkommandon kommer först sedan världskaparkommandon
   */
  //Spelarkommandon                   Index:   antal argument och typ
  m_command_table.push_back("help");    // 0    0
  m_command_table.push_back("list");    // 1    0
  m_command_table.push_back("go");      // 2    1, string (riktning)
  m_command_table.push_back("eat");     // 3    1, string
  m_command_table.push_back("throw");   // 4    1, string
  m_command_table.push_back("take");    // 5    1, string
  m_command_table.push_back("equip");   // 6    ?, ?
  m_command_table.push_back("attack");  // 7    ?, ?
  m_command_table.push_back("sleep");   // 8    ?, ?
  m_command_table.push_back("defend");  // 9    ?, ?
  m_command_table.push_back("save");    // 10   0
  //Världskaparkommandon
  m_command_table.push_back("makeroom");// 11   2, <string>(riktning), <string>
  m_command_table.push_back("make");    // 12   1+, <string>,.<.><.> mellan 1 till max antal egenskaper+1
  m_command_table.push_back("delete");  // 13   1, string    
  m_command_table.push_back("destroy"); // 14   1, string (riktning)
  m_command_table.push_back("jump");    // 15   1/2, string/(<int> <int>)
  m_command_table.push_back("rooms");   // 16   0
  m_command_table.push_back("save");    // 17   1, string
}

bool CommandParser::direction(std::string& argument)
{
  return ( argument == "east" || argument == "west" || 
	   argument == "north" || argument == "south" );
}

bool CommandParser::noArguments(std::vector<std::string> & arguments)
{
  return  ( arguments.size() == 0 && ( m_command_index == 0 ||
				       m_command_index == 1 ||
				       m_command_index == 10||
				       m_command_index == 16 ));
}

bool CommandParser::oneArgument(std::vector<std::string>& arguments)
{
  return (arguments.size() == 1 && ( m_command_index == 2 || m_command_index == 3 ||
				     m_command_index == 4 || m_command_index == 5 || 
				     m_command_index == 12|| m_command_index == 13||
				     m_command_index == 14|| m_command_index == 15||
				     m_command_index == 17 ));
}

bool CommandParser::jumpIntInt(std::vector<std::string>& arguments)
{
  for( int i = 0; i < arguments.size(); ++i ) // antal argument
    {
      for( int y = 0; y < arguments.at(i).size(); ++y ) // storleken på argumentet
	{
	  if( !isdigit( arguments.at(i).at(y) ) ) // om det inte är en siffra
	    return false;
	}
    }
  return true;
}

bool CommandParser::validCommand(std::string& command)
{
  for(int i = 0; i < m_command_table.size(); ++i)
    {
      if( m_command_table.at(i) == command )
	{
	  m_command_index = i; // sparar det hittade kommandots index
	  return true;
	}
    }
  m_command_index = -1; // -1 = inget kommando
  return false;
}

bool CommandParser::validArguments(std::vector<std::string>& arguments)
{  
  if( noArguments( arguments ) )
    {
      return true;
    }
  else if( arguments.size() == 2 ) // kommandon med 2 argument
    {
      if( m_command_index == 15 )  // jump <int> <int>
	return jumpIntInt( arguments );
      else if( m_command_index == 12 )  // make
	return true;
      else if( m_command_index == 11 )  // makeroom
	return direction( arguments.front() );
    }
  else if( arguments.size() > 2 && m_command_index == 12 ) // make
    return true;
  else if( oneArgument( arguments )) // kommandon med 1 argument
    {
      if( m_command_index == 2 || m_command_index == 14 ) // go och destroy
	return direction( arguments.front() );
      return true;
    }

  return false;
}

InputMessage* CommandParser::getData(std::string& command, std::vector<std::string>& arguments)
{
  InputMessage* msg = new InputMessage();
  // om vi har ett giltligt kommando och argument
  if( validCommand(command) && validArguments(arguments) )
    {
      msg->setValid( true );
      //return "valid command"; // Test
    }
  else
    {
      msg->setValid( false );
      //return "invalid command"; // Test
    }
  if( m_command_index == 17 )// för det finns 2 olika saves
    m_command_index = 10;
  msg->setCommand( (BaseMessage::eCommand)m_command_index );
  for(int i = 0; i < arguments.size(); ++i )
    msg->addArgument( arguments.at(i) );
  return msg;
}
