#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include <iostream>

Game* g_game = NULL;

int main(int argc, char* args[])
{
	g_game = new Game();

	g_game->init();

	while (g_game->isrunning())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();

	return 0;
}