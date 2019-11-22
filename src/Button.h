#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "SDL.h"
#include "GameObject.h"
#include <string>

class Button : public GameObject
{
public:
	Button(SDL_Rect position);
	void handleEvent(SDL_Event* e);
private:
	
};

#endif // !__BUTTON_H__