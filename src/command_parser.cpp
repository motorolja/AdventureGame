#include "command_parser.h"

CommandParser::CommandParser():
{ 
 /* 
     initiera m_command_table
     samma ordning på kommandon som i kravdokumentet
     Spelarkommandon kommer först sedan världskaparkommandon
   */
  //Spelarkommandon
  m_command_table.push_back("help");
  m_command_table.push_back("list");
  m_command_table.push_back("go");
  m_command_table.push_back("eat");
  m_command_table.push_back("throw");
  m_command_table.push_back("take"); 
  m_command_table.push_back("equip");
  m_command_table.push_back("attack");
  m_command_table.push_back("sleep");
  m_command_table.push_back("defend");
  m_command_table.push_back("save");
  //Världskaparkommandon
  m_command_table.push_back("makeroom");
  m_command_table.push_back("make");
  m_command_table.push_back("delete");
  m_command_table.push_back("destroy");
  m_command_table.push_back("jump");
  m_command_table.push_back("rooms");
  m_command_table.push_back("save");
}

InputMessage CommandParser::getdata(std::string& command, std::vector<std::string>& arguments)const
{

}

bool CommandParser::validCommand(std::string& command) const
{
  for(int i = 0; i < m_command_table.size(); ++i)
    {
      if( m_command_table.at(i) == command )
	return true;
    }
  return false;
}

bool CommandParser::validArguments(std::vector<std::string>& arguments)
{

}
