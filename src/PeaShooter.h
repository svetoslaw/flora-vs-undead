#ifndef __PEA__SHOOTER_H__
#define __PEA_SHOOTER_H__
#include "SDL.h"
#include "Flower.h"

class PeaShooter : public Flower
{
public:
	PeaShooter();
	SDL_Rect getInventoryPosition();
	int getPrice();
private:
	SDL_Rect position;
};

#endif // !__PEA__SHOOTER_H__