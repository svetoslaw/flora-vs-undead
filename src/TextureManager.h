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
	void loadFromText(std::string text_to_render, TTF_Font* font, SDL_Color text_color, SDL_Color background_color,
		std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer);
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif // !__TEXTURE_MANAGER_H__