#include <iostream>
#include "Game.h"



Game::Game(){
	window = NULL;
	renderer = NULL;
	running = true;
}

void Game::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	lastTime = SDL_GetTicks();

	window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Init();
	font = TTF_OpenFont("assets/arial.ttf", GAME_FONT_SIZE);

	textureManager.load("assets/fvu_main_menu.bmp", MAIN_MENU_BACKGROUND_ID, renderer);

	player.createPlayer(PLAYER_NAME, 0, 10);

	initButtons();

	initLabels();
}

void Game::initLabels()
{
	Label* sunlightLabel = new Label(SUNLIGHT_LABEL_POSITION, SOLID_BLACK, "Sunlight: " + std::to_string(player.getSunlight()));
	labels[SUNLIGHT_LABEL_ID] = sunlightLabel;

	textureManager.loadFromText(SUNLIGHT_LABEL_ID, sunlightLabel->getText(), font, sunlightLabel->getTextColor(), renderer);
}

void Game::initButtons()
{
	textureManager.load("assets/playbutton.bmp", PLAY_BUTTON_ID, renderer);
	Button* playButton = new Button(PLAY_BUTTON_POSITION);
	buttons[PLAY_BUTTON_ID] = playButton;

	textureManager.load("assets/exitbutton.bmp", EXIT_BUTTON_ID, renderer);
	Button* exitButton = new Button(EXIT_BUTTON_POSITION);
	buttons[EXIT_BUTTON_ID] = exitButton;
}


void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	textureManager.draw(MAIN_MENU_BACKGROUND_ID, renderer, &BACKGROUND_POSITION);
	textureManager.draw(PLAY_BUTTON_ID, renderer, &buttons[PLAY_BUTTON_ID]->getPosition());
	textureManager.draw(EXIT_BUTTON_ID, renderer, &buttons[EXIT_BUTTON_ID]->getPosition());
	textureManager.draw(SUNLIGHT_LABEL_ID, renderer, &labels[SUNLIGHT_LABEL_ID]->getPosition());

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

		textureManager.loadFromText(SUNLIGHT_LABEL_ID, labels[SUNLIGHT_LABEL_ID]->getText(), font, SOLID_BLACK, renderer);
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
				for(auto const& but : buttons)
				{
					but.second->handleEvent(&event);
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