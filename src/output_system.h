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
<<<<<<< HEAD
  virtual void retrieveOutput(EngineMessage* ) = 0;
=======
  virtual void retrieveOutput(const EngineMessage& ) = 0;
>>>>>>> f9c5e86008b6560439f8a8bc9522fbdd9249b5ee

 protected:
    OutputSystem() : m_message(nullptr){}
    EngineMessage* m_message;

};


#endif

