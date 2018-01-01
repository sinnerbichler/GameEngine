//Timer.hpp
#ifndef TIMER_HPP
#define TIMER_HPP
#include <SDL2/SDL.h>

namespace Engine {

class Timer{
public:
	Timer();

	int      current();
	int 		elapsed();
	void  	update();
	void 		speed(double t);
	double 	speed();
private:
	Uint32 mElapsed, mCurrent, mLast;

	double mspeed;
};

}//namespace Engine

#endif
