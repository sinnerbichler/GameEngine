//Engine::Physics.hpp
#include <SDL2/SDL.h>

namespace Engine {

template <class T>
struct Coordinates {
	T x, y;
}

//parabel function whose value is
//parabola(0) = 0; parabola(1) = 0
//parabola(0.5) = 1
//concepted for calculating jumps
double parabola(double t);

}//namespace Engine
