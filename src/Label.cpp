#include "Label.h"

Label::Label(SDL_Rect pos, SDL_Color txt_color, std::string init_text) : GameObject(pos)
{
	textColor = txt_color;
	text = init_text;
}

SDL_Color Label::getTextColor() { return textColor; }

std::string Label::getText() { return text; }

void Label::setText(std::string t)
{
	text = t;
}