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

void Grid::clearGrid()
{
	for (int k = 0; k < cells.size(); k++)
	{
		if (cells.at(k).getType() == "peashooter1")
		{
			cells.at(k).setType(0);
		}
		else if (cells.at(k).getType() == "peashooter2")
		{
			cells.at(k).setType(1);
		}
		else if (cells.at(k).getType() == "snowpea1")
		{
			cells.at(k).setType(0);
		}
		else if (cells.at(k).getType() == "snowpea2")
		{
			cells.at(k).setType(1);
		}
		else if (cells.at(k).getType() == "cactus1")
		{
			cells.at(k).setType(0);
		}
		else if (cells.at(k).getType() == "cactus2")
		{
			cells.at(k).setType(1);
		}
	}
}

void Grid::handleEvent(SDL_Event* e, std::string selected, Player* player, TextureManager textureManager, SDL_Renderer* renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	bool inside = true;
	for (int i = 0; i < cells.size(); i++)
	{
		if (x < cells.at(i).getPosition().x || x > cells.at(i).getPosition().x + cells.at(i).getPosition().w
			|| y < cells.at(i).getPosition().y || y > cells.at(i).getPosition().y + cells.at(i).getPosition().h)
		{
			inside = false;
		}

		else
		{
			if (selected == "peashooter" && !cells.at(i).isFull())
			{
				int sun = peashooter.getPrice();
				if (cells.at(i).getType() == "one")
				{
					cells.at(i).setType(3);
					cells.at(i).drawCell(textureManager, renderer);
					player->updateSunlight(-sun);
				}
				else
				{
					cells.at(i).setType(4);
					cells.at(i).drawCell(textureManager, renderer);
					player->updateSunlight(-sun);
				}
			}
			else if (selected == "snowpea" && !cells.at(i).isFull())
			{
				int sun = snowpea.getPrice();
				if (cells.at(i).getType() == "one")
				{
					cells.at(i).setType(5);
					cells.at(i).drawCell(textureManager, renderer);
					player->updateSunlight(-sun);
				}
				else
				{
					cells.at(i).setType(6);
					cells.at(i).drawCell(textureManager, renderer);
					player->updateSunlight(-sun);
				}
			}
			else if (selected == "cactus" && !cells.at(i).isFull())
			{
				int sun = cactus.getPrice();
				if (cells.at(i).getType() == "one")
				{
					cells.at(i).setType(7);
					cells.at(i).drawCell(textureManager, renderer);
					player->updateSunlight(-sun);
				}
				else
				{
					cells.at(i).setType(8);
					cells.at(i).drawCell(textureManager, renderer);
					player->updateSunlight(-sun);
				}
			}
		}
	}
}