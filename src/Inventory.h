#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include "SDL.h"
#include "Cell.h"
#include "PeaShooter.h"
#include <vector>

class Inventory
{
public:
	Inventory();
	void setInventory();
	void drawInventory(int sun, TextureManager textureManager, SDL_Renderer* renderer);
private:
	std::vector<Flower> flowers;
	std::vector<Cell> cells;
};

#endif // !__INVENTORY_H__