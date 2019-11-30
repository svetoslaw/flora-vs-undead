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

	state.setState("main menu");

	initLabels();

	initButtons();
}

void Game::initLabels()
{
	Label* sunlightLabel = new Label(SUNLIGHT_LABEL_POSITION, SOLID_BLACK, "Sunlight: " + std::to_string(player.getSunlight()));
	labels[SUNLIGHT_LABEL_ID] = sunlightLabel;

	textureManager.loadFromText(SUNLIGHT_LABEL_ID, sunlightLabel->getText(), font, sunlightLabel->getTextColor(), renderer);
}

void Game::initButtons()
{
	std::function<void()> func;

	textureManager.load("assets/playbutton.bmp", PLAY_BUTTON_ID, renderer);
	func = [this]() { std::cout << "play" << std::endl; state.setState("play"); };
	Button* playButton = new Button(PLAY_BUTTON_POSITION, func, "inactive");
	buttons[PLAY_BUTTON_ID] = playButton;

	textureManager.load("assets/exitbutton.bmp", EXIT_BUTTON_ID, renderer);
	func = [this]() { std::cout << "exit" << std::endl; running = false; };
	Button* exitButton = new Button(EXIT_BUTTON_POSITION, func, "inactive");
	buttons[EXIT_BUTTON_ID] = exitButton;

	textureManager.load("assets/pausebutton.bmp", PAUSE_BUTTON_ID, renderer);
	func = [this]() { std::cout << "pause" << std::endl; state.setState("pause"); };
	Button* pauseButton = new Button(PAUSE_BUTTON_POSITION, func, "inactive");
	buttons[PAUSE_BUTTON_ID] = pauseButton;

	textureManager.load("assets/resumebutton.bmp", RESUME_BUTTON_ID, renderer);
	func = [this]() { std::cout << "resume" << std::endl; state.setState("play"); };
	Button* resumeButton = new Button(RESUME_BUTTON_POSITION, func, "inactive");
	buttons[RESUME_BUTTON_ID] = resumeButton;

	textureManager.load("assets/exitbutton2.bmp", EXIT_BUTTON_2_ID, renderer);
	func = [this]() { std::cout << "exit2" << std::endl; running = false; };
	Button* exitButton2 = new Button(EXIT_BUTTON_2_POSITION, func, "inactive");
	buttons[EXIT_BUTTON_2_ID] = exitButton2;
}

void Game::drawButtons(std::string s)
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
		textureManager.draw(SUNLIGHT_LABEL_ID, renderer, &labels[SUNLIGHT_LABEL_ID]->getPosition());
		textureManager.draw(PAUSE_BUTTON_ID, renderer, &buttons[PAUSE_BUTTON_ID]->getPosition());
		buttons[PLAY_BUTTON_ID]->setButtonState("inactive");
		buttons[EXIT_BUTTON_ID]->setButtonState("inactive");
		buttons[PAUSE_BUTTON_ID]->setButtonState("active");
		buttons[RESUME_BUTTON_ID]->setButtonState("inactive");
		buttons[EXIT_BUTTON_2_ID]->setButtonState("inactive");
	}
	else if (s == "pause")
	{
		textureManager.draw(RESUME_BUTTON_ID, renderer, &buttons[RESUME_BUTTON_ID]->getPosition());
		textureManager.draw(EXIT_BUTTON_2_ID, renderer, &buttons[EXIT_BUTTON_2_ID]->getPosition());
		buttons[PAUSE_BUTTON_ID]->setButtonState("inactive");
		buttons[RESUME_BUTTON_ID]->setButtonState("active");
		buttons[EXIT_BUTTON_2_ID]->setButtonState("active");
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	std::string s = state.getState();
	drawButtons(s);

	SDL_RenderPresent(renderer);
}

void Game::update()
{
	//currentFrame = int((SDL_GetTicks() / 100) % 6);
	if (state.getState() == "play")
	{
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