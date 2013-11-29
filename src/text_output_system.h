#ifndef TEXT_OUTPUT_SYSTEM_H_INCLUDED
#define TEXT_OUTPUT_SYSTEM_H_INCLUDED

#include "output_system.h"
#include <unordered_map>
#include <string>
#include "curses.h"
class TextOutputSystem : public OutputSystem
{
 public:
  virtual ~TextOutputSystem() noexcept { endwin();}
 TextOutputSystem() : OutputSystem()
    {
      initscr();                                 // initsierar screen
      printw("Welcome to the Adventure Game");
      printw("\n");
      scrollok(stdscr,TRUE);
      refresh();

    }

  virtual void writeOutput();
  virtual void retrieveOutput(EngineMessage* message) { m_message = message;}
  std::string completeString( const std::string& );
 private:
  std::string getDefstring() const ;

  //std::unordered_multimap<int,std::string> m_defaultstrings;
  const std::unordered_multimap<int,std::string> m_defaultstrings{
    {EngineMessage::help,"Player Commands: _list, go, eat, _throw, take, save Create World: makeroom, make, _delete, destroy, jump, rooms"},
    {EngineMessage::_list,"Your inventory: "}, //specialfall
	{EngineMessage::go,"You go <arg0>"}, // <arg0> är argumentet som ska kompletteras, ex: You go west
    {EngineMessage::go,"You can´t go that direction!"},
    {EngineMessage::eat,"You´re eating <arg0>"},
    {EngineMessage::eat,"You can´t eat That! You crazy?"},
    {EngineMessage::jump,"You jumped to (<arg0>,arg<1>)"},
    {EngineMessage::_throw,"You threw <arg0>"},
    {EngineMessage::_throw,"You can´t throw that item!"},
    {EngineMessage::take,"You got this item: <arg0>"},
    {EngineMessage::take,"You can´t take this item!"},
    {EngineMessage::unknown,"Invalid command"}// Default Message string
			  //{EngineMessage::none,"testing2"}
  };
};

#endif // TEXT_OUTPUT_SYSTEM_H_INCLUDED
