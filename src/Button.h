#ifndef __BUTTON_H__
#define __BUTTON_H__
#include "SDL.h"
#include <string>

class Button
{
public:
	Button(std::string id, int width, int height, int x, int y);
	void handleEvent(SDL_Event* e);
private:
	SDL_Point mPosition;
	std::string buttonID;
	int buttonWidth, buttonHeight;
};

#endif // !__BUTTON_H__