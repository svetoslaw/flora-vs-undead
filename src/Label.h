#ifndef __LABEL_H__
#define __LABEL_H__

#include "SDL.h"
#include "GameObject.h"
#include <string>

class Label : public GameObject
{
public:
	Label(SDL_Rect position, SDL_Color text_color, std::string initial_text);
	SDL_Color getTextColor();
	std::string getText();
	void setText(std::string text);

private:
	SDL_Color textColor;
	std::string text;
};

#endif // !__LABEL_H__

