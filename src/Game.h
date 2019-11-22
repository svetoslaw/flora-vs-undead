#ifndef __GAME_H__
#define __GAME_H__
#include "SDL.h"
#include "SDL_ttf.h"
#include "TextureManager.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Constants.cpp"
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

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	TextureManager textureManager;
	int currentFrame;
	int lastTime;
	bool running;
	std::map <std::string, Button*> buttons;
	std::map <std::string, Label*> labels;
	Player player;

	void initLabels();
	void initButtons();
};

#endif // !__GAME_H__