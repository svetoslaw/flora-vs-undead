#include "Button.h"
#include <iostream>

Button::Button(SDL_Rect pos) : GameObject(pos) {}

void Button::handleEvent(SDL_Event* e)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	bool inside = true;

	if (x < position.x || x > position.x + position.w || y < position.y || y > position.y + position.h)
	{
		inside = false;
	}
	if (inside)
	{
		std::cout << "User clicked on: " << "!refactor button interaction" << std::endl;
	}
}