#ifndef __GAME_H__
#define __GAME_H__
#include "SDL.h"
#include "SDL_ttf.h"
#include "TextureManager.h"
#include "Label.h"
#include "Button.h"
#include "Constants.cpp"
#include <vector>

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
	bool running;
	std::vector <Button*> buttons;
	std::vector <Label*> labels;
};

#endif // !__GAME_H__