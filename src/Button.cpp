#include "Button.h"
#include <iostream>

Button::Button(SDL_Rect pos) : GameObject(pos) {}

Button::Button(SDL_Rect pos, std::function<void()> func) : GameObject(pos)
{
	onClickEvent = func;
}

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
		onClick();
	}
}

void Button::onClick()
{
	onClickEvent();
}