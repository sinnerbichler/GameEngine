#ifdef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

namespace Engine {

class Framework {
public:
	//video 1
	//timer 2
	//audio 4
	//everything 8
	Framework(int flag);
	~Framework();
};

class Window
{
public:
  Window();
  ~Window();

  bool create_window(const char * title, SDL_Rect * dim);
  void render();
  void clear();

  SDL_Renderer * renderer();
  SDL_Window * window();
private:
  SDL_Renderer * mWinRenderer;
  SDL_Window * mWin;
};

}//namespace Engine

int factorial(int a);

#endif
