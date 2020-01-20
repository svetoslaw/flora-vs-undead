#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <map>

class TextureManager
{
public:
	void load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void loadAlpha(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void loadFromText(std::string id, std::string text_to_render, TTF_Font* font, SDL_Color text_color, SDL_Renderer* pRenderer);
	void draw(std::string id, SDL_Renderer* pRenderer, const SDL_Rect* destination, const SDL_Rect* source = NULL);
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif // !__TEXTURE_MANAGER_H__