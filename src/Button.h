#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "SDL.h"
#include "GameObject.h"
#include <string>
#include <functional>

class Button : public GameObject
{
public:
	Button(SDL_Rect position);
	Button(SDL_Rect position, std::function<void()> onClickEvent);
	void handleEvent(SDL_Event* e);
	void onClick();
private:
	std::function<void()> onClickEvent;
};

#endif // !__BUTTON_H__