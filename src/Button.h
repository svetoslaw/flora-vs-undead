#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "SDL.h"
#include "GameObject.h"
#include "State.h"
#include <string>
#include <functional>

class Button : public GameObject
{
public:
	Button(SDL_Rect position);
	Button(SDL_Rect position, std::function<void()> onClickEvent, std::string st);
	void handleEvent(SDL_Event* e);
	void onClick();
	void setButtonState(std::string s);
	std::string getButtonState();
private:
	std::function<void()> onClickEvent;
	std::string state;
};

#endif // !__BUTTON_H__