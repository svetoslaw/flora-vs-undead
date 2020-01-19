#include "Projectile.h"

Projectile::Projectile(SDL_Rect position) : GameObject(position) {}

void Projectile::setType(std::string t)
{
	type = t;
}

std::string Projectile::getType()
{
	return type;
}