#ifndef __GRID_H__
#define __GRID_H__

#include "SDL.h"
#include "Cell.h"
#include "Player.h"
#include "PeaShooter.h"
#include "SnowPea.h"
#include "Cactus.h"
#include <vector>
#include <iostream>

class Grid
{
public:
	Grid();
	void setGrid();
	void drawGrid(TextureManager textureManager, SDL_Renderer* renderer);
	void clearGrid();
	void handleEvent(SDL_Event* e, std::string selected, Player* player, TextureManager textureManager, SDL_Renderer* renderer);
private:
	std::vector<Cell> cells;
	std::vector<Cell> cellsStart;
	int startX = 40;
	int startY = 60;
	PeaShooter peashooter;
	SnowPea snowpea;
	Cactus cactus;
};

#endif // !__GRID_H__