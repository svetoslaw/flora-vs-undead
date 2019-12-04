#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include "SDL.h"
#include "Cell.h"
#include "Flower.h"
#include "PeaShooter.h"
#include <vector>

class Inventory
{
public:
	Inventory();
	void setInventory();
	void updateInventory(int sun, TextureManager textureManager, SDL_Renderer* renderer);
	void drawInventory(int sun, TextureManager textureManager, SDL_Renderer* renderer);
private:
	std::vector<Flower> flowers;
	std::vector<Cell> cells;
	PeaShooter* peashooter = new PeaShooter;
};

#endif // !__INVENTORY_H__