#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <string>
#include "player.h"
#include "room.h"

class BaseMessage
{
public:
	enum eCommand{cunknown=-1, chelp=0, clist, cgo, ceat, cthrow, ctake, cequip, cattack, csleep, cdefend, csave, cmakeroom, cmake, cdelete, cdestroy, cjump, crooms};

	BaseMessage(eCommand command = cunknown);
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
	InputMessage(eCommand command = cunknown);
	virtual	~InputMessage();
	
	InputMessage* setValid(bool valid);
	
	bool getValid() const
	{
		return m_valid;
	}
protected:
	bool 						m_valid;
	
};

class EngineMessage : public BaseMessage
{
public:
	enum eOutputCommand{ocnone=0, ocgamestart, ocgamestop, ocload, ocsave};
	EngineMessage(eCommand command = cunknown);
	virtual ~EngineMessage();
	
	EngineMessage* setSuccess(bool success);
	EngineMessage* setOutputCommand(eOutputCommand);
	EngineMessage* addOutputArgument(std::string argument);
	
	std::vector<std::string> getOutputArguments() const
	{
		return m_outputarguments;
	}
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
	eOutputCommand getOutputCommand() const
	{
		return m_outputcommand;
	}
protected:
	std::vector<std::string>    m_outputarguments;
	eOutputCommand				m_outputcommand;
	bool 						m_success;
	Player 						m_player;
	Room 						m_room;
};

#endif