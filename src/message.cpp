#include "message.h"

//BaseMessage:

BaseMessage::BaseMessage(eCommand command) : m_command(command)
{
}

BaseMessage::~BaseMessage()
{
}

BaseMessage* BaseMessage::setCommand(eCommand command)
{
	m_command = command;
	return this;
}

BaseMessage* BaseMessage::addArgument(std::string argument)
{
	m_arguments.push_back( argument );
	return this;
}

//InputMessage:

InputMessage::InputMessage(eCommand command) : BaseMessage(command)
{
	m_valid = true;
}

InputMessage::~InputMessage()
{
}

InputMessage* InputMessage::setValid(bool valid)
{
	m_valid = valid;
	return this;
}

//EngineMessage:

EngineMessage::EngineMessage(eCommand command) : BaseMessage(command)
{
	m_success = false;
}

EngineMessage::~EngineMessage()
{
}

EngineMessage* EngineMessage::setPlayer(Player player)
{
	m_player = player;
	return this;
}

EngineMessage* EngineMessage::setRoom(Room room)
{
	m_room = room;
	return this;
}

EngineMessage* EngineMessage::setSuccess(bool success)
{
	m_success = success;
	return this;
}

EngineMessage* EngineMessage::setGod(bool godmode)
{
	m_godmode = godmode;
	return this;
}
