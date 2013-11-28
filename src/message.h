#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <string>

class BaseMessage
{
public:
	enum eCommand{help=0, list, go, eat, throw, take, save, makeroom, make, delete, destroy, jump, rooms};

	BaseMessage(eCommand command);
	virtual ~BaseMessage();
	
	BaseMessage* setCommand(eCommand command);
	BaseMessage* addArgument(std::string argument);
	
	std::vector<std::string> getArguments() const
	{
		return m_arguments;
	}
	eCommand getCommand() const
	{
		return m_command;
	}
protected:
	std::vector<std::string> 	m_arguments;
	eCommand 					m_command;
};

class InputMessage : public BaseMessage
{
public:
	//enum eSpecialCommand{load=0};
	InputMessage(eCommand command);
	virtual	~InputMessage();
	
	//InputMessage* setSpecialCommand(eSpecialCommand special_command);
	
protected:
	
};

class EngineMessage : public BaseMessage
{
public:
	EngineMessage(eCommand command);
	virtual ~EngineMessage();
	
	EngineMessage* setSuccess(bool success);
	
	bool getSuccess() const
	{
		return m_success;
	}
	Player getPlayer() const
	{
		return m_player;
	}
	Room getRoom() const
	{
		return m_room;
	}
protected:
	bool 						m_success;
	Player 						m_player;
	Room 						m_room;
};

#endif