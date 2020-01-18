#ifndef __CACTUS_H__
#define __CACTUS_H__
#pragma once 

#include "SDL.h"
#include "Flower.h"

class Cactus : public Flower
{
public:
	Cactus();
	SDL_Rect getInventoryPosition();
	int getPrice();
private:
	SDL_Rect position;
};

#endif // !__CACTUS_H__