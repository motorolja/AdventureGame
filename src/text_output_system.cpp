#ifndef TEXT_OUTPUT_SYSTEM_CPP_INCLUDED
#define TEXT_OUTPUT_SYSTEM_CPP_INCLUDED

<<<<<<< HEAD
#include <iostream>
#include "text_output_system.h"
#include <string>
#include <algorithm>
=======
#include "text_output_system.h"

>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee
using namespace std;

void TextOutputSystem::writeOutput()
{
    std::string def_string = getDefstring();
    std::string res = completeString(def_string);

    //skriv ut
<<<<<<< HEAD

    // cout<<res;
    printw(res.c_str());
    printw("\n>>");
    refresh();
    getch();
=======
    /*printw(out_string.c_str());
    printw("\n>>");
    refresh();*/
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee

    }

std::string TextOutputSystem::getDefstring() const
    {
  string res;
<<<<<<< HEAD
  auto range = m_defaultstrings.equal_range( m_message->getCommand() ); //range = pair<const unordered_multimap<int,string>::iterator, const unordered_multimap<int,string>::iterator>
=======
  auto range = defaultstrings.equal_range( m_message->getCommand() ); //range = pair<const unordered_multimap<int,string>::iterator, const unordered_multimap<int,string>::iterator>
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee

  // kolla om det bara finns 1 standardsträng, ex: kommando help eller _list
  //Om kommandot har 2 standradsträngar, så hittar man den rätta med hjälp av check
  auto temp = range.first;
  if((++temp) == range.second)
    {
<<<<<<< HEAD
      unordered_multimap<int,std::string>::value_type x = *range.first;
=======
      unordered_multimap<int,std::string>::value_type& x = *range.first;
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee
      res = x.second;
    }
  //
  else{

    if(m_message->getSuccess() )
      {
<<<<<<< HEAD
	std::unordered_multimap<int,std::string>::value_type x = *(++range.first);
=======
	std::unordered_multimap<int,std::string>::value_type& x = *(++range.first);
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee
	res = x.second;
      }
    else
      {
<<<<<<< HEAD
	std::unordered_multimap<int,std::string>::value_type x = *(range.first);
=======
	std::unordered_multimap<int,std::string>::value_type& x = *(range.first);
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee
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
<<<<<<< HEAD
            temp = " " + i->getName();
=======
            temp = " " + i.getName();
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee
            _complete_string.append(temp);
       }
    }

    else
    {
        vector<string> args = m_message->getArguments();
        for(int i = 0; i < args.size(); ++i)
        {
            temp = "<arg";
<<<<<<< HEAD
            temp += (std::to_string(i) + ">");
=======
            temp += (to_string(i) + ">");
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee

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




#endif // TEXT_OUTPUT_SYSTEM_CPP_INCLUDED
