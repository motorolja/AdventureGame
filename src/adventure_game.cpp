#include "adventure_game.h"

AdventureGame::AdventureGame(int argc, char*argv[])
{
	bool god_mode = false;
	if(argc >= 1)
	{
		if(argv[1] == "-god")
			god_mode = true;
	}
	if(argc >= 2)
	{
		//load the game from file
	}
	input = new TextInputSystem();
	output = new TextOutputSystem();
	engnie = new Engine(god_mode);
	m_running = true;
}

AdventureGame::~AdventureGame()
{
	delete input;
	delete output;
	delete engine;
}

void AdventureGame::Run()
{
	while(m_running)
	{
		Update();
	}
}

void AdventureGame::Update()
{
	InputMessage* imessage = input->getData();
	engine->setInput( imessage );
	//Uppdatera Engine och ta reda på m_running!
	m_running = engine->update();
	delete imessage;
	imessage = nullptr;
	
	EngineMessage* emessage = engine->getOutput();
	output->retrieveOutput( emessage );
	output->writeOutput();
	delete emessage;
	emessage = nullptr;
}