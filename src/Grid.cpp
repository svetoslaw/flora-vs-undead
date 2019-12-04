#include "Grid.h"

Grid::Grid()
{
	setGrid();
}

void Grid::setGrid()
{
	for (int i = 0; i < 5; i++)
	{
		if (i != 0)
		{
			startY += 110;
		}
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				startX = 40;
			}
			else
			{
				startX += 120;
			}

			SDL_Rect temp = { startX, startY, 120, 110 };
			Cell tmp(temp);
			tmp.setType((i+j) % 2);
			cells.push_back(tmp);
		}
	}
}

void Grid::drawGrid(TextureManager textureManager, SDL_Renderer* renderer)
{
	for (int k = 0; k < cells.size(); k++)
	{
		cells.at(k).drawCell(textureManager, renderer);
	}
}