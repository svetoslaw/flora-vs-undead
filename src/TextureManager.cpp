#include "TextureManager.h"

void TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	m_textureMap[id] = pTexture;
}

void TextureManager::loadFromText(std::string text_to_render, TTF_Font* font, SDL_Color text_color, SDL_Color background_color,
	std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text_to_render.c_str(), text_color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);

	SDL_FreeSurface(textSurface);
	m_textureMap[id] = textTexture;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopy(pRenderer, m_textureMap[id], &srcRect, &destRect);
}