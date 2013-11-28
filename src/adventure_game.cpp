#include "adventure_game.h"

AdventureGame::AdventureGame()
{
	input = new TextInputSystem();
	output = new TextOutputSystem();
	engnie = new Engine();
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
	//engine->update();
	/*
		Uppdatera Engine och ta reda på m_running!
	*/
	delete imessage;
	
	EngineMessage* emessage = engine->getOutput();
	output->retrieveOutput( emessage );
	output->writeOutput();
	delete emessage;
}