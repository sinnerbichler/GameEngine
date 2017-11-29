//Texture.cpp
#include "Texture.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

namespace Engine {

Texture::Texture()
{
	IMG_Init(IMG_INIT_PNG);
}

Texture::~Texture()
{
	SDL_DestroyTexture(mTexture);
}

void Texture::load(const char * path)
{
	SDL_Surface * temp_surf = saveLoadSurf(path);

	saveSetTexture(SDL_CreateTextureFromSurface(mRenderer, temp_surf));
	SDL_FreeSurface(temp_surf);
}

void Texture::load(const char * path, SDL_Color * mask)
{
	SDL_Surface * temp_surf = saveLoadSurf(path);

	SDL_SetColorKey( temp_surf, SDL_TRUE, SDL_MapRGB( temp_surf->format, mask->r, mask->g, mask->b ));

	saveSetTexture(SDL_CreateTextureFromSurface(mRenderer, temp_surf));
	SDL_FreeSurface(temp_surf);
}

void Texture::load(const char * path, SDL_PixelFormat * format)
{
	SDL_Surface * temp_surf = saveLoadSurf(path);

	temp_surf = SDL_ConvertSurface( temp_surf, format, 0 );

	saveSetTexture(SDL_CreateTextureFromSurface(mRenderer, temp_surf));
	SDL_FreeSurface(temp_surf);
}

void Texture::load(const char * path, SDL_PixelFormat * format, SDL_Color * mask)
{
	SDL_Surface * temp_surf = saveLoadSurf(path);

	temp_surf = SDL_ConvertSurface(temp_surf, format, 0 );

	SDL_SetColorKey( temp_surf, SDL_TRUE, SDL_MapRGB( temp_surf->format, mask->r, mask->g, mask->b ));

	saveSetTexture(SDL_CreateTextureFromSurface(mRenderer, temp_surf));
	SDL_FreeSurface(temp_surf);
}

SDL_Surface * Texture::saveLoadSurf(const char * path)
{
	SDL_Surface * temp_surf = IMG_Load(path);
	if(temp_surf == nullptr)
	{
		std::cout << "unable to load image: " << path << SDL_GetError() << std::endl;
		exit;
	}

	return temp_surf;
}

void Texture::saveSetTexture(SDL_Texture * tex)
{
	if (mTexture == nullptr)
	{
		mTexture = tex;
	} else {
		SDL_DestroyTexture(mTexture);
		mTexture = tex;
	}
}

SDL_Texture * Texture::texture()
{
	return mTexture;
}

SDL_Rect * Texture::src()
{
	return &mSrc;
}

SDL_Rect * Texture::dst()
{
	return &mDst;
}

SDL_Renderer * Texture::renderer()
{
	return mRenderer;
}

}//namespace Engine
