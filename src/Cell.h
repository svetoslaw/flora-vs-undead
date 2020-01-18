#ifndef __CELL_H__
#define __CELL_H__

#include "SDL.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <string>
#include <iostream>

class Cell : public GameObject
{
public:
	Cell(SDL_Rect position);
	void setType(int t);
	std::string getType();
	void drawCell(TextureManager textureManager, SDL_Renderer* renderer);
	SDL_Rect getPosition();
	bool isFull();
private:
	std::string type;
};

#endif // !__CELL_H__