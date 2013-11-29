#ifndef TEXT_OUTPUT_SYSTEM_H_INCLUDED
#define TEXT_OUTPUT_SYSTEM_H_INCLUDED

#include "output_system.h"
#include <string>
#include "curses.h"
class TextOutputSystem : public OutputSystem
{
    public:
    virtual ~TextOutputSystem() noexcept { endwin();}
    TextOutputSystem() : OutputSystem() , m_defaultstrings(defaultstrings)
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

    std::unordered_multimap<int,std::string> m_defaultstrings;
    };

#endif // TEXT_OUTPUT_SYSTEM_H_INCLUDED
