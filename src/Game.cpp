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
	lastTime = SDL_GetTicks();

	window = SDL_CreateWindow("Flora vs. Undead", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Init();
	font = TTF_OpenFont("assets/arial.ttf", GAME_FONT_SIZE);

	textureManager.load("assets/fvu_main_menu.bmp", MAIN_MENU_BACKGROUND_ID, renderer);

	textureManager.load("assets/playbutton.bmp", PLAY_BUTTON_ID, renderer);
	Button* play = new Button(PLAY_BUTTON_ID, 400, 100, 100, 570);
	buttons.push_back(play);

	textureManager.load("assets/exitbutton.bmp", EXIT_BUTTON_ID, renderer);
	Button* exit = new Button(EXIT_BUTTON_ID, 400, 100, 780, 570);
	buttons.push_back(exit);

	player.createPlayer("Gosho", 5, 10);

	Label* sunlight = new Label(SUNLIGHT_LABEL_ID, 100, 100, 100, 50, SOLID_BLACK, "Sunlight: " + std::to_string(player.getSunlight()));
	labels[SUNLIGHT_LABEL_ID] = sunlight;
	textureManager.loadFromText(sunlight->getText(), font, sunlight->getTextColor(), SUNLIGHT_LABEL_ID, renderer);

}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	textureManager.draw(MAIN_MENU_BACKGROUND_ID, 0, 0, 1280, 720, renderer);
	textureManager.draw(PLAY_BUTTON_ID, 100, 570, 400, 100, renderer);
	textureManager.draw(EXIT_BUTTON_ID, 780, 570, 400, 100, renderer);

	textureManager.draw(SUNLIGHT_LABEL_ID, 100, 100, 100, 50, renderer);

	SDL_RenderPresent(renderer);
}

void Game::update()
{
	//currentFrame = int((SDL_GetTicks() / 100) % 6);

	int currentTime = SDL_GetTicks();
	if (currentTime - lastTime > UPDATE_INTERVAL_MILLIS)
	{
		player.updateSunlight(5);
		std::cout << player.getSunlight() << std::endl;
		labels[SUNLIGHT_LABEL_ID]->setText("Sunlight: " + std::to_string(player.getSunlight()));
		lastTime = currentTime;

		textureManager.loadFromText(labels[SUNLIGHT_LABEL_ID]->getText(), font, SOLID_BLACK, SUNLIGHT_LABEL_ID, renderer);
	}
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