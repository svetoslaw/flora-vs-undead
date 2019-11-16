#ifndef __LABEL_H__
#define __LABEL_H__

#include "SDL.h"
#include "TextureManager.h"
#include <string>

class Label
{
public:
	Label(std::string id, int x_position, int y_position, int width, int heigth,
		SDL_Color background_color, SDL_Color text_color, std::string initial_text);
	void setText(std::string text);
	SDL_Rect getPosition();
	SDL_Color getBackgroundColor();
	SDL_Color getTextColor();
	std::string getText();
private:
	SDL_Rect position;
	SDL_Color backgroundColor;
	SDL_Color textColor;
	std::string text;
};

#endif // !__LABEL_H__

