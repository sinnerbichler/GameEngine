#include "Window.hpp"


namespace Engine{
  Window::Window()
  {
    mWin = nullptr;
    mWinRenderer = nullptr;
  }

  Window::~Window()
  {
    SDL_DestroyRenderer(mWinRenderer);
    SDL_DestroyWindow(mWin);
  }

  bool Window::create_window(const char * title, SDL_Rect * dim)
  {
    mWin = SDL_CreateWindow(title, dim->x, dim->y, dim->w, dim->h, SDL_WINDOW_SHOWN);
    mWinRenderer = SDL_CreateRenderer(mWin, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(mWinRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(mWinRenderer);

    if (mWin == nullptr){
      return false;
    } else if (mWinRenderer == nullptr){
      return false;
    }

    return true;
  }

  void Window::render()
  {
    SDL_RenderPresent(mWinRenderer);
  }

  void Window::clear()
  {
	  SDL_SetRenderDrawColor(mWinRenderer, 0x33, 0x33, 0x33, 0xFF);
     SDL_RenderClear(mWinRenderer);
  }

  SDL_Renderer * Window::renderer()
  {
    if (mWinRenderer == nullptr)
    {
      //TODO: handle error message
    }

    return mWinRenderer;
  }

  SDL_Window * Window::window()
  {
    return mWin;
  }

}//namespace Engine


int factorial(int a)
{
  if (a > 0)
    return (a + factorial(--a));
  else
    return a;
}
