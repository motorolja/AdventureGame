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
}

BaseMessage* BaseMessage::addArgument(std::string argument)
{
	arguments.push_back( argument );
}

//InputMessage:

InputMessage::InputMessage(eCommand command) : BaseMessage(command)
{
}

InputMessage::~InputMessage()
{
}

//EngineMessage:

EngineMessage::EngineMessage(eCommand command) : BaseMessage(command)
{
	m_success = false;
}

EngineMessage::~EngineMessage()
{
}

EngineMessage* EngineMessage::EngineMessage(bool success)
{
	m_success = success;
}
