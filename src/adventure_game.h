#ifndef ADVENTURE_GAME_H
#define ADVENTURE_GAME_H
#include "message.h"
#include "text_output_system.h"
#include "text_input_system.h"
#include "engine.h"
#include <string>

class AdventureGame
{
public:
	AdventureGame(int argc, char*argv[]);
	~AdventureGame();
	
	void Run();
private:
	void Update();

	TextInputSystem* 	input;
	TextOutputSystem* 	output;
	Engine*				engine;
	bool				m_running;
};

#endif