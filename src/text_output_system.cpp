#include <iostream>
#include "text_output_system.h"
#include <string>
#include <algorithm>
//#include <ncurses.h>
using namespace std;

void TextOutputSystem::writeOutput()
{
  std::string def_string = getDefstring();
  std::string res = completeString(def_string);

  //skriv ut

  // cout<<res;
  printw(res.c_str());
  printw("\n>>");
  refresh();
  getch();

}

std::string TextOutputSystem::getDefstring() const
{
  string res;
  auto range = m_defaultstrings.equal_range( m_message->getCommand() ); //range = pair<const unordered_multimap<int,string>::iterator, const unordered_multimap<int,string>::iterator>

  // kolla om det bara finns 1 standardsträng, ex: kommando help eller _list
  //Om kommandot har 2 standradsträngar, så hittar man den rätta med hjälp av check
  auto temp = range.first;
  if((++temp) == range.second)
    {
      unordered_multimap<int,std::string>::value_type x = *range.first;
      res = x.second;
    }
  //
  else{

    if(m_message->getSuccess() )
      {
	std::unordered_multimap<int,std::string>::value_type x = *(++range.first);
	res = x.second;
      }
    else
      {
	std::unordered_multimap<int,std::string>::value_type x = *(range.first);
	res = x.second;
      }

  }
  return res;
}

//INTE färdig!!
std::string TextOutputSystem::completeString( const std::string& defstring)
{
  std::string _complete_string = defstring;
  string temp;

  //Utmatingssträng för kommando: list
  if(m_message->getCommand() == EngineMessage::_list)
    {
      for(auto i : m_message->getPlayer().getInventory())
	{
	  temp = " " + i->getName();
	  _complete_string.append(temp);
	}
    }

  else
    {
      vector<string> args = m_message->getArguments();
      for(int i = 0; i < args.size(); ++i)
        {
	  temp = "<arg";
	  temp += (std::to_string(i) + ">");

	  size_t pos = _complete_string.find(temp);

	  //Är vi säkra på att den kommer att finnas? Behöver vi kolla detta?
	  if(pos != string::npos)
            {
	      _complete_string.replace(pos,temp.length(),args.at(i));
            }

        }
    }

  return _complete_string;
}

