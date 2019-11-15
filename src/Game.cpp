#include <iostream>
#include "Game.h"

const int windowWidth = 1280;
const int windowHeight = 720;

Game::Game(){
	window = NULL;
	renderer = NULL;
	running = true;
}
void Game::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Flora vs. Undead", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	textureManager.load("assets/fvu_main_menu.bmp", "mainmenu", renderer);
	textureManager.load("assets/playbutton.bmp", "playbutton", renderer);
	Button* play = new Button("playbutton", 400, 100, 100, 570);
	buttons.push_back(play);
	textureManager.load("assets/exitbutton.bmp", "exitbutton", renderer);
	Button* exit = new Button("exitbutton", 400, 100, 780, 570);
	buttons.push_back(exit);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	textureManager.draw("mainmenu", 0, 0, 1280, 720, renderer);
	textureManager.draw("playbutton", 100, 570, 400, 100, renderer);
	textureManager.draw("exitbutton", 780, 570, 400, 100, renderer);

	SDL_RenderPresent(renderer);
}

void Game::update()
{
	//currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) 
	{
		switch (event.type) 
		{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
			{
				for (int i = 0; i < buttons.size(); ++i)
				{
					buttons.at(i)->handleEvent(&event);
				}
				break;
			}
			default:
				break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}