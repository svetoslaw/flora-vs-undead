#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__
#include "SDL.h"

class GameObject
{
public:
	GameObject(SDL_Rect position);
	void setPosition(SDL_Rect position);
	SDL_Rect getPosition();
	void setX(int x);
	void setY(int y);
	void setW(int w);
	void setH(int h);

	virtual void onClick() {}
protected:
	SDL_Rect position;
};

#endif //__GAME_OBJECT_H__