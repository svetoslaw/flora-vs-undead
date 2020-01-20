#include "Grid.h"

Grid::Grid()
{
	setGrid();
	srand(time(NULL));
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

void Grid::clearCell(int k)
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
		SDL_Rect projectileSpawnPosition = { cells.at(i).getPosition().x + 30, cells.at(i).getPosition().y + 30, PROJECTILE_SIZE, PROJECTILE_SIZE };

		if (cellType == "peashooter1" || cellType == "peashooter2")
		{
			Projectile projectile(projectileSpawnPosition);
			projectile.setType("pea");
			projectiles.push_back(projectile);
		}
		else if (cellType == "snowpea1" || cellType == "snowpea2")
		{
			Projectile projectile(projectileSpawnPosition);
			projectile.setType("ice");
			projectiles.push_back(projectile);
		}
		else if(cellType == "cactus1" || cellType == "cactus2")
		{
			Projectile projectile(projectileSpawnPosition);
			projectile.setType("spike");
			projectiles.push_back(projectile);
		}
	}
}

void Grid::drawProjectiles(TextureManager textureManager, SDL_Renderer* renderer)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		textureManager.draw(projectiles.at(i).getType(), renderer, &projectiles.at(i).getPosition());
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
	projectiles.clear();
}

void Grid::spawnZombies(Level level)
{
	int pos = rand() % 340 + 20;
	if (level.getLevel() == 1)
	{
		SDL_Rect zombieSpawnPosition = { cells.at(9).getPosition().x, cells.at(9).getPosition().y + pos, 100, 160 };
		Zombie zombie(zombieSpawnPosition);
		zombie.setType("worker");
		zombies.push_back(zombie);
	}
	else if (level.getLevel() == 2)
	{
		SDL_Rect zombieSpawnPosition = { cells.at(9).getPosition().x, cells.at(9).getPosition().y + pos, 109, 188 };
		Zombie zombie(zombieSpawnPosition);
		zombie.setType("cone");
		zombies.push_back(zombie);
	}
	else
	{
		SDL_Rect zombieSpawnPosition = { cells.at(9).getPosition().x, cells.at(9).getPosition().y + pos, 109, 188 };
		Zombie zombie(zombieSpawnPosition);
		zombie.setType("bucket");
		zombies.push_back(zombie);
	}
	numOfZombies++;
}

void Grid::drawZombies(TextureManager textureManager, SDL_Renderer* renderer)
{
	for (int i = 0; i < zombies.size(); i++)
	{
		textureManager.draw(zombies.at(i).getType(), renderer, &zombies.at(i).getPosition());
	}
}

void Grid::moveZombies(int zombieSpeed)
{
	for (int i = 0; i < zombies.size(); i++)
	{
		int newX = zombies.at(i).getPosition().x - zombieSpeed;
		zombies.at(i).setX(newX);
	}
}

void Grid::destroyZombies()
{
	zombies.clear();
	numOfZombies = 0;
}

void Grid::destroyZombie(int p)
{
	zombies.erase(zombies.begin() + p);
}

int Grid::getNumberOfZombies()
{
	return numOfZombies;
}

int Grid::checkCollision(Player* player)
{
	for (int i = 0; i < cells.size(); i++)
	{
		if (cells.at(i).isFull())
		{
			for (int j = 0; j < zombies.size(); j++) 
			{
				int leftA = cells.at(i).getPosition().x;
				int rightA = cells.at(i).getPosition().x + cells.at(i).getPosition().w;
				int topA = cells.at(i).getPosition().y;
				int bottomA = cells.at(i).getPosition().y + cells.at(i).getPosition().h;
				
				int leftB = zombies.at(j).getPosition().x;
				int rightB = zombies.at(j).getPosition().x + zombies.at(j).getPosition().w;
				int topB = zombies.at(j).getPosition().y;
				int bottomB = zombies.at(j).getPosition().y + zombies.at(j).getPosition().h;

				if (!(bottomA <= topB) && !(topA >= bottomB) && !(rightA <= leftB) && !(leftA >= rightB))
				{
					clearCell(i);
				}
			}
		}
	}

	for (int k = 0; k < projectiles.size(); k++)
	{
		for (int t = 0; t < zombies.size(); t++)
		{
			int leftA = zombies.at(t).getPosition().x;
			int rightA = zombies.at(t).getPosition().x + zombies.at(t).getPosition().w;
			int topA = zombies.at(t).getPosition().y;
			int bottomA = zombies.at(t).getPosition().y + zombies.at(t).getPosition().h;

			int leftB = projectiles.at(k).getPosition().x;
			int rightB = projectiles.at(k).getPosition().x + projectiles.at(k).getPosition().w;
			int topB = projectiles.at(k).getPosition().y;
			int bottomB = projectiles.at(k).getPosition().y + projectiles.at(k).getPosition().h;

			if (!(bottomA <= topB) && !(topA >= bottomB) && !(rightA <= leftB) && !(leftA >= rightB))
			{
				std::string typ = projectiles.at(k).getType();
				if(typ == "pea") zombies.at(t).updateHealth(-25);
				else if(typ == "ice") zombies.at(t).updateHealth(-50);
				else zombies.at(t).updateHealth(-100);
				
				if (zombies.at(t).getHealth() <= 0)
				{
					destroyZombie(t);
					defeatedZombies++;
					if (defeatedZombies == 5)
					{
						defeatedZombies = 0;
						return 1;
					}
				}
				projectiles.erase(projectiles.begin() + k);
				break;
			}
		}
	}

	for (int m = 0; m < zombies.size(); m++)
	{
		if (zombies.at(m).getPosition().x <= 40)
		{
			destroyZombie(m);
			player->updateHealth(-50);
			if (player->getHealth() <= 0)
			{
				player->setHealth(150);
				return 2;
			}
		}
	}

	return 0;
}