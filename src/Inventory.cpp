#include "Inventory.h"
#include <iostream>

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

void Inventory::updateInventory(int sun, int level, TextureManager textureManager, SDL_Renderer* renderer)
{
	if (sun >= peashooter.getPrice())
	{
		textureManager.draw("peashooter", renderer, &peashooter.getInventoryPosition());
	}
	if (sun >= snowpea.getPrice() && level >= 2)
	{
		textureManager.draw("snowpea", renderer, &snowpea.getInventoryPosition());
	}
	if (sun >= cactus.getPrice() && level >= 3)
	{
		textureManager.draw("cactus", renderer, &cactus.getInventoryPosition());
	}
}

void Inventory::drawInventory(int sun, Level level, TextureManager textureManager, SDL_Renderer* renderer)
{
	for (int j = 0; j < cells.size(); j++)
	{
		cells.at(j).drawCell(textureManager, renderer);
	}

	updateInventory(sun, level.getLevel(), textureManager, renderer);
}

void Inventory::handleEvent(SDL_Event* e)
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
			onClick(i);
		}
	}
}

void Inventory::onClick(int s)
{
	setSelected(s);
	
}

void Inventory::setSelected(int sel)
{
	selected = sel;
}

std::string Inventory::getSelected(Player* player)
{
	if (selected == 0 && player->getSunlight() >= peashooter.getPrice())
	{
		return "peashooter";
	}
	else if (selected == 1 && player->getSunlight() >= snowpea.getPrice())
	{
		return "snowpea";
	}
	else if (selected == 2 && player->getSunlight() >= cactus.getPrice())
	{
		return "cactus";
	}
	else
	{
		return "none";
	}
}