#include "Cell.h"

Cell::Cell(SDL_Rect pos) : GameObject(pos){}

void Cell::setType(int t)
{
	if (t == 0)
	{
		type = "one";
	}
	else if (t == 1)
	{
		type = "two";
	}
	else
	{
		type = "inventory";
	}
}

std::string Cell::getType()
{
	return type;
}

void Cell::drawCell(TextureManager textureManager, SDL_Renderer* renderer)
{
	if (type == "one")
	{
		textureManager.draw("grass1", renderer, &position);
	}
	else if (type == "two")
	{
		textureManager.draw("grass2", renderer, &position);
	}
	else if (type == "inventory")
	{
		textureManager.draw("inventory", renderer, &position);
	}
}