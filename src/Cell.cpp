#include "Cell.h"

Cell::Cell(SDL_Rect pos) : GameObject(pos) {}

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
	else if (t == 2)
	{
		type = "inventory";
	}
	else if (t == 3)
	{
		type = "peashooter1";
	}
	else if (t == 4)
	{
		type = "peashooter2";
	}
	else if (t == 5)
	{
		type = "snowpea1";
	}
	else if (t == 6)
	{
		type = "snowpea2";
	}
	else if (t == 7)
	{
		type = "cactus1";
	}
	else if (t == 8)
	{
		type = "cactus2";
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
	else if (type == "peashooter1")
	{
		textureManager.draw("peashooter1", renderer, &position);
	}
	else if (type == "peashooter2")
	{
		textureManager.draw("peashooter2", renderer, &position);
	}
	else if (type == "snowpea1")
	{
		textureManager.draw("snowpea1", renderer, &position);
	}
	else if (type == "snowpea2")
	{
		textureManager.draw("snowpea2", renderer, &position);
	}
	else if (type == "cactus1")
	{
		textureManager.draw("cactus1", renderer, &position);
	}
	else if (type == "cactus2")
	{
		textureManager.draw("cactus2", renderer, &position);
	}
}

SDL_Rect Cell::getPosition()
{
	return position;
}

bool Cell::isFull()
{
	if (type == "peashooter1" || type == "peashooter2" || type == "snowpea1"
		|| type == "snowpea2" || type == "cactus1" || type == "cactus2")
	{
		return true;
	}
	else
	{
		return false;
	}
}