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
	textureManager.load("assets/play_background.bmp", PLAY_BACKGROUND_ID, renderer);
	textureManager.load("assets/pause_background.bmp", PAUSE_BACKGROUND_ID, renderer);
	textureManager.load("assets/sunlight.bmp", SUNLIGHT_ID, renderer);
	textureManager.load("assets/grass1.bmp", GRASS_1_ID, renderer);
	textureManager.load("assets/grass2.bmp", GRASS_2_ID, renderer);
	textureManager.load("assets/inventory.bmp", INVENTORY_ID, renderer);
	textureManager.load("assets/peashooter.bmp", PEA_SHOOTER_ID, renderer);
	textureManager.load("assets/peashooter1.bmp", PEA_SHOOTER_1_ID, renderer);
	textureManager.load("assets/peashooter2.bmp", PEA_SHOOTER_2_ID, renderer);
	textureManager.load("assets/snowpea.bmp", SNOW_PEA_ID, renderer);
	textureManager.load("assets/snowpea1.bmp", SNOW_PEA_1_ID, renderer);
	textureManager.load("assets/snowpea2.bmp", SNOW_PEA_2_ID, renderer);
	textureManager.load("assets/cactus.bmp", CACTUS_ID, renderer);
	textureManager.load("assets/cactus1.bmp", CACTUS_1_ID, renderer);
	textureManager.load("assets/cactus2.bmp", CACTUS_2_ID, renderer);
	textureManager.load(PROJECTILE_SPRITE_FILEPATH, PROJECTILE_ID, renderer);

	player.createPlayer(PLAYER_NAME, 10, 10);

	state.setState("main menu");

	initLabels();

	initButtons();
}

void Game::initLabels()
{
	Label* sunlightLabel = new Label(SUNLIGHT_LABEL_POSITION, YELLOW, std::to_string(player.getSunlight()));
	labels[SUNLIGHT_LABEL_ID] = sunlightLabel;

	textureManager.loadFromText(SUNLIGHT_LABEL_ID, sunlightLabel->getText(), font, sunlightLabel->getTextColor(), renderer);
}

void Game::initButtons()
{
	std::function<void()> func;

	textureManager.load("assets/playbutton.bmp", PLAY_BUTTON_ID, renderer);
	func = [this]() { state.setState("play"); };
	Button* playButton = new Button(PLAY_BUTTON_POSITION, func, "inactive");
	buttons[PLAY_BUTTON_ID] = playButton;

	textureManager.load("assets/exitbutton.bmp", EXIT_BUTTON_ID, renderer);
	func = [this]() { running = false; };
	Button* exitButton = new Button(EXIT_BUTTON_POSITION, func, "inactive");
	buttons[EXIT_BUTTON_ID] = exitButton;

	textureManager.load("assets/pausebutton.bmp", PAUSE_BUTTON_ID, renderer);
	func = [this]() { state.setState("pause"); };
	Button* pauseButton = new Button(PAUSE_BUTTON_POSITION, func, "inactive");
	buttons[PAUSE_BUTTON_ID] = pauseButton;

	textureManager.load("assets/resumebutton.bmp", RESUME_BUTTON_ID, renderer);
	func = [this]() { state.setState("play"); };
	Button* resumeButton = new Button(RESUME_BUTTON_POSITION, func, "inactive");
	buttons[RESUME_BUTTON_ID] = resumeButton;

	textureManager.load("assets/restartbutton.bmp", RESTART_BUTTON_ID, renderer);
	func = [this]() { state.setState("restart"); };
	Button* restartButton = new Button(RESTART_BUTTON_POSITION, func, "inactive");
	buttons[RESTART_BUTTON_ID] = restartButton;

	textureManager.load("assets/exitbutton2.bmp", EXIT_BUTTON_2_ID, renderer);
	func = [this]() { running = false; };
	Button* exitButton2 = new Button(EXIT_BUTTON_2_POSITION, func, "inactive");
	buttons[EXIT_BUTTON_2_ID] = exitButton2;
}

void Game::drawHUD(std::string s)
{
	if (s == "main menu")
	{
		textureManager.draw(MAIN_MENU_BACKGROUND_ID, renderer, &BACKGROUND_POSITION);
		textureManager.draw(PLAY_BUTTON_ID, renderer, &buttons[PLAY_BUTTON_ID]->getPosition());
		textureManager.draw(EXIT_BUTTON_ID, renderer, &buttons[EXIT_BUTTON_ID]->getPosition());
		
		buttons[PLAY_BUTTON_ID]->setButtonState("active");
		buttons[EXIT_BUTTON_ID]->setButtonState("active");
	}
	else if (s == "play")
	{
		textureManager.draw(PLAY_BACKGROUND_ID, renderer, &BACKGROUND_POSITION);
		textureManager.draw(SUNLIGHT_ID, renderer, &SUNLIGHT_POSITION);
		textureManager.draw(SUNLIGHT_LABEL_ID, renderer, &labels[SUNLIGHT_LABEL_ID]->getPosition());
		textureManager.draw(PAUSE_BUTTON_ID, renderer, &buttons[PAUSE_BUTTON_ID]->getPosition());
		grid.drawGrid(textureManager, renderer);
		inventory.drawInventory(player.getSunlight(), textureManager, renderer);

		grid.drawProjectiles(textureManager, renderer);

		buttons[PLAY_BUTTON_ID]->setButtonState("inactive");
		buttons[EXIT_BUTTON_ID]->setButtonState("inactive");
		buttons[PAUSE_BUTTON_ID]->setButtonState("active");
		buttons[RESUME_BUTTON_ID]->setButtonState("inactive");
		buttons[RESTART_BUTTON_ID]->setButtonState("inactive");
		buttons[EXIT_BUTTON_2_ID]->setButtonState("inactive");
		
	}
	else if (s == "pause")
	{
		textureManager.draw(PAUSE_BACKGROUND_ID, renderer, &BACKGROUND_POSITION);
		textureManager.draw(RESUME_BUTTON_ID, renderer, &buttons[RESUME_BUTTON_ID]->getPosition());
		textureManager.draw(RESTART_BUTTON_ID, renderer, &buttons[RESTART_BUTTON_ID]->getPosition());
		textureManager.draw(EXIT_BUTTON_2_ID, renderer, &buttons[EXIT_BUTTON_2_ID]->getPosition());
		
		buttons[PAUSE_BUTTON_ID]->setButtonState("inactive");
		buttons[RESUME_BUTTON_ID]->setButtonState("active");
		buttons[RESTART_BUTTON_ID]->setButtonState("active");
		buttons[EXIT_BUTTON_2_ID]->setButtonState("active");
	}
	else if (s == "restart")
	{
		player.setSunlight(10);
		grid.clearGrid();
		state.setState("play");
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	std::string s = state.getState();
	drawHUD(s);

	SDL_RenderPresent(renderer);
}

void Game::update()
{
	if (state.getState() == "play")
	{
		int currentTime = SDL_GetTicks();
		if (currentTime - lastTime > UPDATE_INTERVAL_MILLIS)
		{
			player.updateSunlight(10);
			labels[SUNLIGHT_LABEL_ID]->setText(std::to_string(player.getSunlight()));
			lastTime = currentTime;
			textureManager.loadFromText(SUNLIGHT_LABEL_ID, labels[SUNLIGHT_LABEL_ID]->getText(), font, YELLOW, renderer);

			grid.spawnProjectiles();
		}
		grid.moveProjectiles(PROJECTILE_SPEED);
		grid.destroyProjectiles();
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
				inventory.handleEvent(&event);
				grid.handleEvent(&event, inventory.getSelected(&player), &player, textureManager, renderer);
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