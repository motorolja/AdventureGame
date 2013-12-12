#include "engine.h"

using namespace std;

Engine::Engine(string filename, bool godmode) : m_filename(filename), m_godmode(godmode), m_filehandler(m_filename)
{
	m_enginemessage = nullptr;
	m_inputmessage  = nullptr;
	m_running = true;
}

Engine::~Engine()
{
	//delete m_enginemessage;
	//delete m_inputmessage;
}

void Engine::setInput(InputMessage* input_message)
{
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
	{
		if(m_godmode == false)
			m_player.update();
		m_player.setPosition( m_player.getPosition() + pos );
	}
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
	bool edible = false;
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

bool Engine::PlayerSave()
{
	return m_filehandler.savePlayer(m_filename, m_player) && m_filehandler.saveWorld(m_filename, m_world);
}

bool Engine::GodSave(string path)
{
	return m_filehandler.savePlayer(m_filename, m_player) && m_filehandler.saveWorld(m_filename, m_world);
}

bool Engine::MakeRoom(string direction, string room_name, string room_description)
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
	
	if(m_world.hasRoom( m_player.getPosition() + pos ) == true)
		return false;
	else
	{
		m_world.setRoom( m_player.getPosition() + pos, new Room(room_name, room_description) );
		return true;
	}
}

bool Engine::MakeItem(vector<string> arg_list)
{
	string item_name = arg_list[0];
	Item temp(item_name);
	for(int i=1;i<arg_list.size();++i)
	{
		switch(arg_list[i][0])
		{
			case 'e'://edible
				temp.addProperty(eProperty::edible);
			break;
			case 'p'://poisonous
				temp.addProperty(eProperty::poisonous);
			break;
			case 'j'://junk
				temp.addProperty(eProperty::junk);
			break;
			default:
			break;
		}
	}
	m_world.getRoom( m_player.getPosition() )->addItem( temp );
	return true;
}

bool Engine::DeleteItem(string item_name)
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
	m_world.getRoom( m_player.getPosition() )->removeItem( index );
	return true;
}

bool Engine::DestroyRoom(std::string direction)
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
	{
		m_world.removeRoom( m_player.getPosition() + pos );
	}
}

void Engine::ListRooms()
{
	vector<string> room_names = m_world.getRoomNames();
	for(int i=0;i<room_names.size();++i)
	{
		m_enginemessage->addArgument( room_names[i] );
	}
}

bool Engine::Jump(string x, string y)
{
	Position pos(0,0);
	try
	{
		pos.x = stoi( x );
		pos.y = stoi( y );
	}
	catch(...)
	{
		return false;
	}

	if(m_world.hasRoom( pos ) == false)
		return false;
	else
		m_player.setPosition( pos );
	return true;
}

bool Engine::Jump(string room_name)
{
	vector<string> room_names = m_world.getRoomNames();
	vector<Position> room_pos = m_world.getRoomPositions();
	int index = -1;
	for(int i=0;i<room_names.size();++i)
	{
		if(room_name == room_names[i])
		{
			index = i;
			break;
		}
	}
	if(index == -1)
		return false;
	else if(m_world.hasRoom( room_pos[index] ) == true )
	{
		m_player.setPosition( room_pos[index] );
		return true;
	}
	return false;
}

/*void Engine::startRoom() //ska bort snart
{
	Room* newroom = nullptr;
	newroom = new Room( "The beginning", "Once upon a time.." );
	Item t1("spoon");
	Item t2("green lego-brick");
	Item t3("old banana");
	t3.addProperty(eProperty::edible);
	t3.addProperty(eProperty::poisonous);
	newroom->addItem(t1);
	newroom->addItem(t2);
	newroom->addItem(t3);
	m_world.setRoom( m_player.getPosition(), newroom );
}*/

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
					m_filehandler.loadWorld(m_filename, m_world);
					m_filehandler.loadPlayer(m_filename, m_player);
					//startRoom();
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
							m_enginemessage->setSuccess( GodSave( args[0] ) );
						}
						else
							m_enginemessage->setSuccess( false );
					}
					else
					{
						if(args.size() == 0)
						{
							m_enginemessage->setSuccess( PlayerSave() );
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
							m_enginemessage->setSuccess( MakeRoom( args[0], args[1], args[2] ) );
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
							m_enginemessage->setSuccess( MakeItem( args ) );
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
							m_enginemessage->setSuccess( DeleteItem( args[0] ) );
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
							m_enginemessage->setSuccess( DestroyRoom( args[0] ) );
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
						if(args.size() == 1)
						{
							m_enginemessage->setSuccess( Jump( args[0] ) );
						}
						else if(args.size() == 2)
						{
							m_enginemessage->setSuccess( Jump( args[0], args[1] ) );
						}
						else
							m_enginemessage->setSuccess( false );
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
							ListRooms();
							m_enginemessage->setSuccess( true );
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
			for(int i=0;i<args.size();++i)
			{
				m_enginemessage->addArgument( args[i] );
			}
		}
		else
		{
			//hantera invalid command
			m_enginemessage->setSuccess( false );
		}
		//set resulting player and room
		m_enginemessage-> setPlayer( m_player )-> setRoom( *(m_world.getRoom( m_player.getPosition() )) ) -> setGod( m_godmode );
	}
	if(m_player.getHealth() == 0)
		m_running = false;
	return m_running;
}