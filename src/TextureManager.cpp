#include "TextureManager.h"

void TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);
	if (m_textureMap[id] != NULL)
	{
		SDL_DestroyTexture(m_textureMap[id]);
		m_textureMap.erase(id);
	}

	m_textureMap[id] = pTexture;
}

void TextureManager::loadFromText(std::string id, std::string text_to_render, TTF_Font* font, SDL_Color text_color, SDL_Renderer* pRenderer)
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text_to_render.c_str(), text_color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);

	SDL_FreeSurface(textSurface);
	if (m_textureMap[id] != NULL)
	{
		SDL_DestroyTexture(m_textureMap[id]);
		m_textureMap.erase(id);
	}

	m_textureMap[id] = textTexture;
}

void TextureManager::draw(std::string id, SDL_Renderer* pRenderer, const SDL_Rect* destination, const SDL_Rect* source)
{
	SDL_RenderCopy(pRenderer, m_textureMap[id], source, destination);
}