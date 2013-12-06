//--
#ifndef TEXT_OUTPUT_SYSTEM_CPP_INCLUDED
#define TEXT_OUTPUT_SYSTEM_CPP_INCLUDED

#include <iostream>
#include "text_output_system.h"
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void TextOutputSystem::writeOutput()
{
  std::string def_string = getDefstring();

  if(m_message->getSuccess() && m_message->getCommand() != EngineMessage::chelp && m_message->getCommand() != EngineMessage::oload )
    {
      //skriv ut defaultstring med argument
      std::string res = completeString(def_string);
      printw(res.c_str());
    }

  else
    {
      //skriv ut defaultstring om command inte lyckades
      printw(def_string.c_str());
    }

  printw("\n");

  if(m_message->getCommand() == EngineMessage::cgo && m_message->getSuccess() || m_message->getCommand() == EngineMessage::oload && m_message->getSuccess())
    {
      //Skriv ut namnet på rummet
      string s =  m_message->getRoom().getName() + ": " + m_message->getRoom().getDescription();

      printw(s.c_str());

      //Skriv ut alla items i det nya rummet
      s = "you see the following items:";
      vector<Item> items  = m_message->getRoom().getItems();
      for(int i = 0; i < items.size(); ++i)
	{
	  s += " " + items.at(i).getName();
	}
      printw("\n");
      printw(s.c_str());
      printw("\n");
      //skriv ut spelarens hälsa
      if(m_message->getPlayer().getHealth() == 0)
	{
	  printw("You died!\n");
	}
      else
	{
	  stringstream ss;
	  ss<< m_message->getPlayer().getHealth();
	  s = "Your Health: " + ss.str();
	  printw(s.c_str());
	  printw("\n");
	}
    }
  printw(">>");
  refresh();
  getchar(); // för testning av output och ska tas bort när man testar med input
}

std::string TextOutputSystem::getDefstring() const
{
  string res;
  auto range = m_defaultstrings.equal_range( m_message->getCommand() ); //range = pair<const unordered_multimap<int,string>::iterator, const unordered_multimap<int,string>::iterator>

  // kolla om det bara finns 1 standardsträng, ex: kommando chelp
  //Om kommandot har 2 standradsträngar,så hittar man den rätta med hjälp av getSucces
  auto temp = range.first;
  if((++temp) == range.second)
    {
      unordered_multimap<int,std::string>::value_type x = *range.first;
      res = x.second;
    }

  else{

    if(m_message->getSuccess() )
      {
	if(m_message->getGod())
	  {
	    if(m_message->getCommand() == EngineMessage::chelp)
	      {
		std::unordered_multimap<int,std::string>::value_type x = *(range.first);
		res = x.second;
	      }
	    else
	      {
		std::unordered_multimap<int,std::string>::value_type x = *(++range.first);
		res = x.second;
	      }
	  }
	else
	  {
	    std::unordered_multimap<int,std::string>::value_type x = *(++range.first);
	    res = x.second;
	  }
      }
    else
      {
	std::unordered_multimap<int,std::string>::value_type x = *(range.first);
	res = x.second;
      }

  }
  return res;
}

std::string TextOutputSystem::completeString( const std::string& defstring)
{
  std::string _complete_string = defstring;
  string temp;

  //Utmatingssträng för kommando: list
  if(m_message->getCommand() == EngineMessage::clist)
    {
      for(auto i : m_message->getPlayer().getInventory())
	{
	  temp = i.getName() + " ";
	  _complete_string.append(temp);
	}
    }

  else
    {

      vector<string> args = m_message->getArguments();
      for(int i = 0; i < args.size(); ++i)
        {
          temp = " " + args.at(i);
          _complete_string.append(temp);

        }
    }
  return _complete_string;
}




#endif // TEXT_OUTPUT_SYSTEM_CPP_INCLUDED
