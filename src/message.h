#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <string>

class BaseMessage
{
public:
	enum eCommand{help=0, list, go, eat, throw, take, save, makeroom, make, delete, destroy, jump, rooms};

	BaseMessage(eCommand command, std::vector<std::string> arguments);
	virtual ~BaseMessage();
	
	BaseMessage* setCommand(eCommand command);
	BaseMessage* addArgument(std::string argument);
private:
	std::vector<std::string> 	m_arguments;
	eCommand 					m_command;
};

class InputMessage : public BaseMessage
{
public:
	//enum eSpecialCommand{load=0};
	InputMessage(eCommand command, std::vector<std::string> arguments);
	virtual	~InputMessage();
	
	//InputMessage* setSpecialCommand(eSpecialCommand special_command);
	
private:
	
};

class EngineMessage : public BaseMessage
{
public:
	EngineMessage(eCommand command, std::vector<std::string> arguments);
	virtual ~EngineMessage();
private:
	//Player 					m_player;
	//Room 						m_room;
};

#endif