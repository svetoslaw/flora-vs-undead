#include "Zombie.h"

Zombie::Zombie(SDL_Rect position) : GameObject(position) {}

void Zombie::setType(std::string t)
{
	type = t;

	if (type == "worker")
	{
		health = 200;
	}
	else if (type == "cone")
	{
		health = 400;
	}
	else
	{
		health = 500;
	}
}

std::string Zombie::getType()
{
	return type;
}

void Zombie::updateHealth(int h)
{
	health += h;
}

int Zombie::getHealth()
{
	return health;
}