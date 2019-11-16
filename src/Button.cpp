#include "Button.h"
#include <iostream>

Button::Button(std::string id, int width, int height, int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
	buttonID = id;
	buttonWidth = width;
	buttonHeight = height;
}

void Button::handleEvent(SDL_Event* e)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	bool inside = true;

	if (x < mPosition.x || x > mPosition.x + buttonWidth || y < mPosition.y || y > mPosition.y + buttonHeight)
	{
		inside = false;

	}
	if (inside)
	{
		std::cout << "User clicked on: " << buttonID << std::endl;
	}
}