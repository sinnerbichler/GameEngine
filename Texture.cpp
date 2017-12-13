//Texture.cpp
#include "Texture.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

namespace Engine {

Texture::Texture()
{
	mTexture = nullptr;
	mRenderer = nullptr;

	mDst = { 0, 0, 0, 0 };
	mSrc = { 0, 0, 0, 0 };
}

Texture::~Texture()
{
	SDL_DestroyTexture(mTexture);
}

void Texture::load(const char * path)
{
	SDL_Surface * temp_surf = saveLoadSurf(path);

	mDst = setRect(temp_surf);
	mSrc = mDst;

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
		return nullptr;
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

void Texture::render()
{
	SDL_RenderCopy(mRenderer, mTexture, &mSrc, &mDst);
}

SDL_Texture * 	Texture::texture() 		{ return mTexture; }
SDL_Rect * 		Texture::src() 			{ return &mSrc; }
SDL_Rect * 		Texture::dst() 			{ return &mDst; }
SDL_Renderer * Texture::renderer() 		{ return mRenderer; }
SDL_Renderer * Texture::renderer(SDL_Renderer * r) { mRenderer = r; return mRenderer; }

SDL_Rect  Texture::setRect(SDL_Surface * surf)
{
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = surf->w;
	r.h = surf->h;

	return r;
}

}//namespace Engine
