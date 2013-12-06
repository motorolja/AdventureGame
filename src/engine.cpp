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

bool Engine::Go(std::string direction)
{
	short dir;
	if(direction == "west")
		dir = 0;
	else if(direction == "east")
		dir = 1;
	else if(direction == "north")
		dir = 2;
	else if(direction == "south")
		dir = 3;
	else return false;
	
	Position pos(0,0);
	
	switch(dir)
	{
		case 0://west, left
			pos.x--;
		break;
		case 1://east, right
			pos.x++;
		break;
		case 2://north, up
			pos.y--;
		break;
		case 3://south, down
			pos.y++;
		break;
		default:
			return false;
		break;
	}
	
	if(m_world.hasRoom( m_player.getPosition() + pos ) == false)
		return false;
	else
		m_player.setPosition( m_player.getPosition() + pos );
	return true;
}

bool Engine::Eat(std::string item_name)
{
	vector<Item> p_items = m_player.getInventory();
	int index = -1;
	for(int i=0;i<p_items.size();++i)
	{
		if(p_items[i].getName() == item_name)
		{
			index = i;
			break;
		}
	}
	if(index == -1)
		return false;
	vector<eProperty> properties = p_items[index].getProperties();
	bool poison = false;
	bool edible = true; //false; !! ADD EDIBLE TO PROPERTIES OF ITEM !!
	for(int i=0;i<properties.size();++i)
	{
		if(properties[i] == poisonous)
			poison = true;
	}
	if(edible == true)
	{
		if(poison == true)
			m_player.addStatus( Status(poisoned, 3) );
		m_player.removeItem( index );
		return true;
	}
	else
		return false;
}

bool Engine::Throw(std::string item_name)
{
	vector<Item> p_items = m_player.getInventory();
	int index = -1;
	for(int i=0;i<p_items.size();++i)
	{
		if(p_items[i].getName() == item_name)
		{
			index = i;
			break;
		}
	}
	if(index == -1)
		return false;
	m_world.getRoom( m_player.getPosition() )->addItem( p_items[index] );
	m_player.removeItem( index );
	return true;
}

bool Engine::Take(std::string item_name)
{
	vector<Item> r_items = m_world.getRoom( m_player.getPosition() )->getItems();
	int index = -1;
	for(int i=0;i<r_items.size();++i)
	{
		if(r_items[i].getName() == item_name)
		{
			index = i;
			break;
		}
	}
	if(index == -1)
		return false;
	m_player.addItem( r_items[index] );
	m_world.getRoom( m_player.getPosition() )->removeItem( index );
	return true;
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
				case BaseMessage::eCommand::oload: //this should never come from TextInputSystem
					//
				break;
				case BaseMessage::eCommand::cunknown:
				break;
				case BaseMessage::eCommand::chelp:
					m_enginemessage->setSuccess( true );
				break;
				case BaseMessage::eCommand::clist:
					m_enginemessage->setSuccess( true );
				break;
				case BaseMessage::eCommand::cgo:
					m_enginemessage->setSuccess( Go( args[0] ) );
					//
				break;
				case BaseMessage::eCommand::ceat:
					m_enginemessage->setSuccess( Eat( args[0] ) );
					//
				break;
				case BaseMessage::eCommand::cthrow:
					m_enginemessage->setSuccess( Throw( args[0] ) );
					//
				break;
				case BaseMessage::eCommand::ctake:
					m_enginemessage->setSuccess( Take( args[0] ) );
					//
				break;
				case BaseMessage::eCommand::csave:
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
				case BaseMessage::eCommand::cmakeroom:
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
				case BaseMessage::eCommand::cmake:
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
				case BaseMessage::eCommand::cdelete:
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
				case BaseMessage::eCommand::cdestroy:
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
				case BaseMessage::eCommand::cjump:
					if(m_godmode)
					{
					}
					else
						m_enginemessage->setSuccess( false );
					//
				break;
				case BaseMessage::eCommand::crooms:
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
		m_enginemessage-> setPlayer( m_player )-> setRoom( m_world.getRoom( m_player.getPosition() ) ) -> setGod( m_godmode );
	}
	return m_running;
}