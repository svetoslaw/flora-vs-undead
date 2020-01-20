#include "Zombie.h"

Zombie::Zombie(SDL_Rect position) : GameObject(position) {}

void Zombie::setType(std::string t)
{
	type = t;
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