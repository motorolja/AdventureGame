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
      initscr();                     // initsierar screen
      start_color();
      scrollok(stdscr,TRUE);
      init_pair(1, COLOR_GREEN, COLOR_BLACK);

      wbkgd(stdscr, COLOR_PAIR(1));
      printw("|--------------------The Adventure Game--------------------|");
      printw("\n>");
      refresh();

    }

  virtual void writeOutput();
  virtual void retrieveOutput(EngineMessage* message) { m_message = message;}
  std::string completeString( const std::string& );
 private:
  std::string getDefstring() const ;

  //std::unordered_multimap<int,std::string> m_defaultstrings;
  const std::unordered_multimap<int,std::string> m_defaultstrings{
    {EngineMessage::cunknown,"Invalid command"},
    {EngineMessage::chelp,"Player Commands: help, list, go, eat, throw, take, save"},
    {EngineMessage::chelp,"God Commands: makeroom, make, delete, destroy, jump, rooms"},
    {EngineMessage::clist,"Your inventory:"},
    {EngineMessage::clist,"Your inventory: Empty"},
    {EngineMessage::cgo,"You go"},
    {EngineMessage::cgo,"You can´t go that direction!"},
    {EngineMessage::ceat,"You´re eating"},
    {EngineMessage::ceat,"You can´t eat That! You crazy?"},
    {EngineMessage::cthrow,"You threw the"},
    {EngineMessage::cthrow,"You can´t throw that!"},
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
    {EngineMessage::oload,"Welcome player, to a world filled with adventures!\nAnd this is where your journey begins..."},
    {EngineMessage::crooms,"Existing rooms:"}
  };
};

#endif // TEXT_OUTPUT_SYSTEM_H_INCLUDED
