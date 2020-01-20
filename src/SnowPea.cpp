#include "SnowPea.h"

SnowPea::SnowPea()
{
	name = "Snow Pea";
	health = 5;
	shootingDamage = 3;
	shootingRange = 10;
	price = 40;
}

SDL_Rect SnowPea::getInventoryPosition()
{
	position = { 548, 623, 82, 84 };
	return position;
}

int SnowPea::getPrice()
{
	return price;
}