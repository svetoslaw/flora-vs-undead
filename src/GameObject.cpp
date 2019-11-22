#include "GameObject.h"

GameObject::GameObject(SDL_Rect p)
{
	position = p;
}

SDL_Rect GameObject::getPosition() { return position; }

void GameObject::setPosition(SDL_Rect p)
{
	position = p;
}

void GameObject::setX(int x)
{
	position.x = x;
}

void GameObject::setY(int y)
{
	position.y = y;
}

void GameObject::setW(int w)
{
	position.w = w;
}

void GameObject::setH(int h)
{
	position.h = h;
}
