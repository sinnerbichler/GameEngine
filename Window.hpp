#include <SDL2/SDL.h>

namespace Engine{

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
