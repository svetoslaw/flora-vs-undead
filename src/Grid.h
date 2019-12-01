#ifndef __GRID_H__
#define __GRID_H__
#include "Cell.h"
#include <vector>
class Grid
{
public:
	Grid();
	void setGrid();
	void drawGrid(TextureManager textureManager, SDL_Renderer* renderer);
private:
	std::vector<Cell> cells;
	int startX = 40;
	int startY = 60;
};

#endif // !__GRID_H__