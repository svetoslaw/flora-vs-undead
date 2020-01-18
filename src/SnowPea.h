#ifndef __SNOW_PEA_H__
#define __SNOW_PEA_H__
#pragma once 

#include "SDL.h"
#include "Flower.h"

class SnowPea : public Flower
{
public:
	SnowPea();
	SDL_Rect getInventoryPosition();
	int getPrice();
private:
	SDL_Rect position;
};

#endif // !__SNOW_PEA_H__