//Object.cpp
#include "Object.hpp"

namespace Engine {

Object::Object () {
	mRenderer = nullptr;
}

Object::~Object() {
	mRenderer = nullptr;
}

void Object::renderer (SDL_Renderer * Renderer)
{
	mRenderer = Renderer;
}

}//namespace Engine
