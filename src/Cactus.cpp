#include "Cactus.h"

Cactus::Cactus()
{
	name = "Cactus";
	health = 5;
	shootingDamage = 3;
	shootingRange = 10;
	price = 90;
}

SDL_Rect Cactus::getInventoryPosition()
{
	position = { 683, 623, 82, 84 };
	return position;
}

int Cactus::getPrice()
{
	return price;
}