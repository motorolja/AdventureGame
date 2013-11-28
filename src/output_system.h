#ifndef OUTPUT_SYSTEM_H_INCLUDED
#define OUTPUT_SYSTEM_H_INCLUDED

#include <string>
#include "message.h"
#include "def_strings.h"
#include <vector>
//#include <ncurses.h>

class OutputSystem
{
 public:
  virtual ~OutputSystem() noexcept = default; /*{delete m_message;}*/

  virtual void writeOutput() = 0;
  virtual void retrieveOutput(const EngineMessage& ) = 0;

 protected:
    OutputSystem() : m_message(nullptr){}
    EngineMessage* m_message;

};


#endif

