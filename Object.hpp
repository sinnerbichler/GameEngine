//object
#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SDL2/SDL.h>

namespace Engine {

class Object {
public:
	Object();
	~Object();

	void renderer(SDL_Renderer * Renderer);
protected:
	SDL_Renderer * mRenderer;
};
}

#endif
