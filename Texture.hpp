//Engine::Texture
#include <SDL2/SDL.h>

namespace Engine {

class Texture {
public:
	Texture();
	~Texture();

	void load(const char * path);
	void load(const char * path, SDL_Color * mask);
	void load(const char * path, SDL_PixelFormat * format);
	void load(const char * path, SDL_PixelFormat * format, SDL_Color * mask);

	SDL_Surface * saveLoadSurf(const char * path);
	void saveSetTexture(SDL_Texture * tex);

	SDL_Texture * texture();
	SDL_Rect * src();
	SDL_Rect * dst();

	SDL_Renderer * renderer();

protected:
	SDL_Texture * mTexture;
	SDL_Rect mSrc, mDst;
	SDL_Renderer * mRenderer;
};

}//namespace Engine
