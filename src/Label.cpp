#include "Label.h"

Label::Label(std::string id, int x, int y, int w, int h, SDL_Color txt_color, std::string init_text)
{
	position.x = x;
	position.y = y;
	position.w = w;
	position.h = h;
	textColor = txt_color;
	text = init_text;
}

SDL_Rect Label::getPosition() { return position; }
SDL_Color Label::getTextColor() { return textColor; }
std::string Label::getText() { return text; }

void Label::setText(std::string t)
{
	text = t;
}