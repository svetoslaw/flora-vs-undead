#include "Inventory.h"

Inventory::Inventory()
{
	setInventory();
}

void Inventory::setInventory()
{
	int startX = 410;
	int startY = 620;
	for (int i = 0; i < 3; i++)
	{
		SDL_Rect temp = { startX, startY, 90, 90 };
		Cell tmp(temp);
		tmp.setType(2);
		startX += 135;
		cells.push_back(tmp);
	}
}

void Inventory::drawInventory(int sun, TextureManager textureManager, SDL_Renderer* renderer)
{
	for (int j = 0; j < cells.size(); j++)
	{
		cells.at(j).drawCell(textureManager, renderer);
	}
}