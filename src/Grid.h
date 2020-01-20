#ifndef __GRID_H__
#define __GRID_H__

#include "SDL.h"
#include "Cell.h"
#include "Player.h"
#include "PeaShooter.h"
#include "SnowPea.h"
#include "Cactus.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Constants.cpp"
#include "Level.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <cmath>

class Grid
{
public:
	Grid();
	void setGrid();
	void drawGrid(TextureManager textureManager, SDL_Renderer* renderer);
	void clearGrid();
	void clearCell(int k);
	void handleEvent(SDL_Event* e, std::string selected, Player* player, TextureManager textureManager, SDL_Renderer* renderer);
	int checkCollision(Player* player);

	void spawnProjectiles();
	void drawProjectiles(TextureManager textureManager, SDL_Renderer* renderer);
	void moveProjectiles(int projectileSpeed);
	void destroyProjectiles();

	void spawnZombies(Level level);
	void drawZombies(TextureManager textureManager, SDL_Renderer* renderer);
	void moveZombies(int zombieSpeed);
	void destroyZombies();
	void destroyZombie(int p);
	int getNumberOfZombies();
private:
	std::vector<Projectile> projectiles;
	std::vector<Zombie> zombies;
	std::vector<Cell> cells;
	int startX = 40;
	int startY = 60;
	PeaShooter peashooter;
	SnowPea snowpea;
	Cactus cactus;
	int numOfZombies = 0;
	int defeatedZombies = 0;
};

#endif // !__GRID_H__