#ifndef ADVENTURE_GAME_H
#define ADVENTURE_GAME_H
#include "message.h"
#include "text_ouput_system.h"
#include "text_input_system.h"
#include "engine.h"

class AdventureGame
{
public:
	AdventureGame();
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