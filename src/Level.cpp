#include "Level.h"

Level::Level()
{
	level = 1;
}

void Level::setLevel(int lvl)
{
	level = lvl;
}

int Level::getLevel()
{
	return level;
}