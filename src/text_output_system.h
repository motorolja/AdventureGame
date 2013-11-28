#ifndef TEXT_OUTPUT_SYSTEM_H_INCLUDED
#define TEXT_OUTPUT_SYSTEM_H_INCLUDED

#include "output_system.h"
#include <string>

class TextOutputSystem : public OutputSystem
{
    public:
    virtual ~TextOutputSystem() noexcept { /*endwin();*/}
    TextOutputSystem() : OutputSystem() , m_defaultstrings(defaultstrings)
    {
      /*initscr();                                 // initsierar screen
      printw("Welcome to the Adventure Game");
      scrollok(stdscr,TRUE);
      refresh();*/

        }

    void writeOutput();
    void retrieveOutput(EngineMessage* message) { m_message = message;}

    private:
    std::string getDefstring() const ;
    std::string completeString( const std::string& );
    std::unordered_multimap<int,std::string> m_defaultstrings;
    };

#endif // TEXT_OUTPUT_SYSTEM_H_INCLUDED
