#ifndef __GAME_H__
#define __GAME_H__
#include "SDL.h"
#include "TextureManager.h"
#include "Button.h"
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
	TextureManager textureManager;
	int currentFrame;
	bool running;
	std::vector <Button*> buttons;
};

#endif // !__GAME_H__