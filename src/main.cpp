#include "adventure_game.h"

int main(int argc, char *argv[])
{
	AdventureGame *adventureGame;
	adventureGame->Run();
	delete adventureGame();
	
	return 0;
}