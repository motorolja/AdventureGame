#include "engine.h"

using namespace std;

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
		
		vector<string> args = m_inputmessage->getArguments();
		
		if(m_inputmessage->getValid() == true)
		{
			switch(m_inputmessage->getCommand())
			{
				case oload: //this should never come from TextInputSystem
					//
				break;
				case cunknown:
				break;
				case chelp:
					m_enginemessage->setSuccess( true );
				break;
				case clist:
					m_enginemessage->setSuccess( true );
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
						if(args.size() == 1)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
					{
						if(args.size() == 0)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					//
				break;
				case cmakeroom:
					if(m_godmode)
					{
						if(args.size() == 3)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
						m_enginemessage->setSuccess( false );
					//
				break;
				case cmake:
					if(m_godmode)
					{
						if(args.size() >= 1)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
						m_enginemessage->setSuccess( false );
					//
				break;
				case cdelete:
					if(m_godmode)
					{
						if(args.size() == 1)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
						m_enginemessage->setSuccess( false );
					//
				break;
				case cdestroy:
					if(m_godmode)
					{
						if(args.size() == 1)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
						m_enginemessage->setSuccess( false );
					//
				break;
				case cjump:
					if(m_godmode)
					{
					}
					else
						m_enginemessage->setSuccess( false );
					//
				break;
				case crooms:
					if(m_godmode)
					{
						if(args.size() == 0)
						{
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
						m_enginemessage->setSuccess( false );
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
		//set resulting player and room
		m_enginemessage-> setPlayer( m_player )-> setRoom( m_room ) -> setGod( m_godmode );
	}
	return m_running;
}