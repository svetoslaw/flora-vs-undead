#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "SDL.h"
#include "Cell.h"
#include "PeaShooter.h"
#include "SnowPea.h"
#include "Cactus.h"
#include "Player.h"
#include "Level.h"
#include <vector>
#include <string>

class Inventory
{
public:
	Inventory();
	void setInventory();
	void updateInventory(int sun, int level, TextureManager textureManager, SDL_Renderer* renderer);
	void drawInventory(int sun, Level level, TextureManager textureManager, SDL_Renderer* renderer);
	void handleEvent(SDL_Event* e);
	void onClick(int s);
	void setSelected(int sel);
	std::string getSelected(Player* player);
private:
	std::vector<Cell> cells;
	std::vector<Flower> flowers;
	PeaShooter peashooter;
	SnowPea snowpea;
	Cactus cactus;
	int selected;
};

#endif // !__INVENTORY_H__