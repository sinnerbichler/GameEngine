//Engine::Physics.hpp
#ifndef PHYSICS_HPP
#define PHYSICS_HPP
#include <SDL2/SDL.h>

namespace Engine {

template <class T>
struct Coordinates {
	T x, y;
};

//parabel function whose value is
//parabola(0) = 0; parabola(1) = 0
//parabola(0.5) = 1
//concepted for calculating jumps
double downwards_parabola(double t);
double upwards_parabola  (double t);
double falling_parabola  (double t);
double ascending_parabola(double t);

}//namespace Engine

#endif
