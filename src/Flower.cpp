#include "Flower.h"

Flower::Flower(){}

void Flower::setName(std::string n)
{
	name = n;
}

std::string Flower::getName()
{
	return name;
}

void Flower::setHealth(int h)
{
	health = h;
}

int Flower::getHealth()
{
	return health;
}

void Flower::setShootingDamage(int sd)
{
	shootingDamage = sd;
}

int Flower::getShootingDamage()
{
	return shootingDamage;
}

void Flower::setShootingRange(int sr)
{
	shootingRange = sr;
}

int Flower::getShootingRange()
{
	return shootingRange;
}

void Flower::setPrice(int p)
{
	price = p;
}

int Flower::getPrice()
{
	return price;
}