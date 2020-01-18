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

void Grid::spawnProjectiles()
{
	for (int i = 0;  i < cells.size();  i++)
	{
		std::string cellType = cells.at(i).getType();
		if (cellType == "peashooter1" || cellType == "peashooter2" || cellType == "snowpea1"
			|| cellType == "snowpea2" || cellType == "cactus1" || cellType == "cactus2")
		{
			SDL_Rect projectileSpawnPosition = { cells.at(i).getPosition().x + 30, cells.at(i).getPosition().y + 30, 60, 60};
			Projectile projectile(projectileSpawnPosition);
			projectiles.push_back(projectile);
		}
	}
}

void Grid::drawProjectiles(TextureManager textureManager, SDL_Renderer* renderer)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		textureManager.draw(PROJECTILE_ID, renderer, &projectiles.at(i).getPosition());
	}
}

void Grid::moveProjectiles(int projectileSpeed)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		int newX = projectiles.at(i).getPosition().x + projectileSpeed;
		projectiles.at(i).setX(newX);
	}
}

void Grid::destroyProjectiles()
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		if (projectiles.at(i).getPosition().x > WINDOW_WIDTH)
		{
			projectiles.erase(projectiles.begin() + i);
		}
	}
}
