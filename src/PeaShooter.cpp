#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	name = "Pea Shooter";
	health = 5;
	shootingDamage = 3;
	shootingRange = 10;
}

SDL_Rect PeaShooter::getInventoryPosition()
{
	position = { 413, 623, 82, 84 };
	return position;
}