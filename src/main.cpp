#include "adventure_game.h"

int main(int argc, char *argv[])
{
	AdventureGame *adventureGame = new AdventureGame(argc, argv);
	adventureGame->Run();
	delete adventureGame;
	return 0;
}