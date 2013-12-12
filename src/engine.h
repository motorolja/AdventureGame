#ifndef ENGINE_H
#define ENGINE_H
#include "file_handler.h"
#include "message.h"
#include "player.h"
#include "world.h"

class Engine
{
public:
	Engine(std::string filename, bool godmode = false);
	~Engine();
	//enum eEngineStatus{};
	EngineMessage* getOutput() const
	{
		return m_enginemessage;
	}
	
	void 			setInput(InputMessage* input_message);
	bool 			update();
private:
	//helper functions
	bool Go(std::string direction);
	bool Eat(std::string item_name);
	bool Throw(std::string item_name);
	bool Take(std::string item_name);
	
	bool PlayerSave();
	bool GodSave(std::string path);
	bool MakeRoom(std::string direction, std::string room_name, std::string room_description);
	bool MakeItem(std::vector<std::string> arg_list);
	bool DeleteItem(std::string item_name);
	bool DestroyRoom(std::string direction);
	void ListRooms();
	bool Jump(std::string x, std::string y);
	bool Jump(std::string room_name);
	
	//void startRoom();

	std::string		m_filename;
	bool			m_running;
	EngineMessage*	m_enginemessage;	//temporär lagring
	InputMessage*	m_inputmessage;		//temporär lagring
	bool 			m_godmode;
	FileHandler 	m_filehandler;
	World 			m_world;
	Player 			m_player;
};

#endif