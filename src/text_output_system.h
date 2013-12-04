#ifndef TEXT_OUTPUT_SYSTEM_H_INCLUDED
#define TEXT_OUTPUT_SYSTEM_H_INCLUDED

#include "output_system.h"
#include <unordered_map>
#include "message.h"
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
    {EngineMessage::cunknown,"Invalid command"},// Default Message string
    {EngineMessage::chelp,"Player Commands: _list, go, eat, _throw, take, save Create World: makeroom, make, _delete, destroy, jump, rooms"},
    {EngineMessage::clist,"Your inventory: "}, //specialfall
    {EngineMessage::cgo,"You go"}, // <arg0> är argumentet som ska kompletteras, ex: You go west
    {EngineMessage::cgo,"You can´t go that direction!"},
    {EngineMessage::ceat,"You´re eating"},
    {EngineMessage::ceat,"You can´t eat That! You crazy?"},
    {EngineMessage::cthrow,"You threw"},
    {EngineMessage::cthrow,"You can´t throw that item!"},
    {EngineMessage::ctake,"You got this item:"},
    {EngineMessage::ctake,"You can´t take this item!"},
    {EngineMessage::csave,"You have saved your game!"},
    {EngineMessage::csave,"You can´t save now!"},
    {EngineMessage::cmakeroom,"You created the room:"},
    {EngineMessage::cmakeroom,"You can't create the room:"},
    {EngineMessage::cmake,"You created the item:"},
    {EngineMessage::cmake,"You can't create that item!"},
    {EngineMessage::cdelete,"You deleted the item:"},
    {EngineMessage::cdelete,"You can't delete that item!"},
    {EngineMessage::cdestroy,"You destroyed the room to the"},
    {EngineMessage::cdestroy,"You can't destroy that room!"},
    {EngineMessage::cjump,"You jumped to"},
    {EngineMessage::cjump,"You can't jump to"},
    //cjump
    {EngineMessage::crooms,"Existing rooms:"} //specialfall
  };
};

#endif // TEXT_OUTPUT_SYSTEM_H_INCLUDED
