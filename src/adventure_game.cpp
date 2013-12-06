#include "adventure_game.h"
#include "message.h"

using namespace std;

AdventureGame::AdventureGame(int argc, char*argv[])
{
	bool god_mode = false;//
	if(argc == 3)
	{
		if(argv[2] == "-god")
			god_mode = true;
	}
	input = new TextInputSystem();
	output = new TextOutputSystem();
	engine = new Engine(god_mode);
	m_running = true;
	
	if(argc >= 2)
	{
		InputMessage* im = new InputMessage(BaseMessage::eCommand::oload);
		//im->addArgument(/* argv[2] eller något */)-> setValid( true );
		im->setValid( true );
		engine->setInput( im );
		engine->update();
		delete im;
	}
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

