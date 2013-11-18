#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

//#include "message.h"
#include <vector>

#define InputMessage std::string

class CommandParser
{
 public:
  CommandParser();
  ~CommandParser();

  InputMessage getData(std::string&, std::vector<std::string>&) const;
  //om kommandot finns i listan
  bool validCommand(std::string&) const;
  //om kommandot har rätt antal argument och rätt typ
  bool validArguments(std::vector<std::string>& ) const;

 private:
  std::vector<std::string> m_command_table;
};

#endif
