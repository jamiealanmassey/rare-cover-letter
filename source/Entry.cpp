#include <iostream>

#include "Game.h"

int main(int argc, char* argv[])
{
	auto game = new Game();
	game->initialise();
	game->execute();
	return 0;
}
