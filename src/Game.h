#ifndef __GAME_H__
#define __GAME_H__
#include "SDL.h"
#include "SDL_ttf.h"
#include "TextureManager.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Constants.cpp"
#include "State.h"
#include "Grid.h"
#include "Inventory.h"
#include "Level.h"
#include <functional>
#include <vector>
#include <string>

class Game
{
public:
	Game();
	void init();
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isrunning() { return running; }
	void initLabels();
	void initButtons();
	void drawHUD(std::string s);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	TextureManager textureManager;
	int currentFrame;
	int lastTime, lastTime2;
	bool running;
	std::map <std::string, Button*> buttons;
	std::map <std::string, Label*> labels;
	Player player;
	State state;
	Grid grid;
	Inventory inventory;
	Level level;
};

#endif // !__GAME_H__