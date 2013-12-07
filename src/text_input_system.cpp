#include "text_input_system.h"
#include <cctype>

InputMessage* TextInputSystem::getData()
{

  m_command.clear();
  m_arguments.clear();// tömmer för att det alltid ska finnas senaste inmatningen
  char ncurses_input[254]; // för att getstr() vill har char[] och inte tar string
  getnstr( ncurses_input,254 );
  std::string input = ncurses_input; 
  inputSlicer(input);

  return m_parser.getData(m_command,m_arguments);
}

void TextInputSystem::inputSlicer(std::string& input)
{
  std::string temp;
  std::size_t end_of_word;
  
  while( !input.empty() )
    {
      while( input.front() == ' ' )
	input.erase(0,1); // tar bort första elementet om det är ett mellanrum

      end_of_word = findEndOfLine(input);
      if( input.front() == '\"' )
	  temp = chooseLine(input,end_of_word);
      else
	  temp = chooseLine(input,end_of_word);
       
      if( m_command.empty() )
	m_command = temp;
      else
	m_arguments.push_back(temp);

      if( end_of_word == std::string::npos )
	input.clear();
      else if( input.front() != '\"' )
	input.erase(0,end_of_word);
      else
	input.erase(0,end_of_word + 1);
   }
}

std::string TextInputSystem::chooseLine(std::string& input, std::size_t end_of_word )
{
  std::string temp;
  if( input.front() == '\"' )
    {
      if( end_of_word == std::string::npos )
	temp = input;
      else
	temp.assign( input, 1, end_of_word - 1 ); // tar bort inledande och avslutande citattecken
    }
  else // kollar efter första ' ' eller npos
    {
      if( end_of_word == std::string::npos )
	temp = input;
      else
	temp.assign( input, 0, end_of_word );
    }
  return temp;
}

std::size_t TextInputSystem::findEndOfLine(std::string& input)
{
  if( input.front() == '\"' )
    return input.find_first_of('\"',1); 
  return input.find_first_of(' '); //returnerar std::string::npos om det inte finns
}
