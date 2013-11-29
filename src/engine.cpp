#include "engine.h"

Engine::Engine(bool godmode) : m_godmode(godmode)
{
	m_enginemessage = nullptr;
	m_inputmessage  = nullptr;
	m_running = true;
}

Engine::~Engine()
{
	delete m_enginemessage;
	delete m_inputmessage;
}

void Engine::setInput(InputMessage* input_message)
{
	if(m_inputmessage != nullptr)
		delete m_inputmessage;
	m_inputmessage = input_message;
}

bool Engine::update()
{
	if(m_inputmessage == nullptr)
	{
		//should not happen
	}
	else
	{
		//begin constructing EngineMessage here
		m_enginemessage = new EngineMessage( m_inputmessage->getCommand() );
		
		if(m_inputmessage->getValid() == true)
		{
			switch(m_inputmessage->getCommand())
			{
				case cunknown:
				break;
				case chelp:
				break;
				case clist:
				break;
				case cgo:
					//
				break;
				case ceat:
					//
				break;
				case cthrow:
					//
				break;
				case ctake:
					//
				break;
				case csave:
					if(m_godmode)
					{
					}
					else
					{
					}
					//
				break;
				case cmakeroom:
					if(m_godmode)
					{
					}
					//
				break;
				case cmake:
					if(m_godmode)
					{
					}
					//
				break;
				case cdelete:
					if(m_godmode)
					{
					}
					//
				break;
				case cdestroy:
					if(m_godmode)
					{
					}
					//
				break;
				case cjump:
					if(m_godmode)
					{
					}
					//
				break;
				case crooms:
					if(m_godmode)
					{
					}
					//
				break;
				default:
				break;
			}
		}
		else
		{
			//hantera invalid command
			m_enginemessage->setSuccess( false );
		}
	}
	return m_running;
}