#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <vector>
#include <string>

//#include "message.h"
#define InputMessage std::string

class CommandParser
{
 public:
  CommandParser();
  ~CommandParser() = default;

  // om strängen är en riktning
  bool direction(std::string& );
  // kommandon utan argument
  bool noArguments(std::vector<std::string>& );
  // alla kommandon som tar 1 argument
  bool oneArgument(std::vector<std::string>& );
  // om jump <int> <int> har rätt typ
  bool jumpIntInt(std::vector<std::string>& );
  //om kommandot finns i listan
  bool validCommand(std::string&);
  //om kommandot har rätt antal argument och rätt typ
  bool validArguments(std::vector<std::string>& );

  InputMessage getData(std::string&, std::vector<std::string>& );

 private:
  std::vector<std::string> m_command_table;
  int m_command_index; // används för att hålla koll på vilket kommando som hittats, -1 om inget
};

#endif
