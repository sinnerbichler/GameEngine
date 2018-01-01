#include "Timer.hpp"

namespace Engine {

Timer::Timer()
{
	mspeed = 0;
	mCurrent = 0;
}

int Timer::elapsed()
{
	if (mspeed == 0.0)
		return mElapsed;

	return (mElapsed * mspeed);
}

int Timer::current()
{
	return mCurrent;
}

void Timer::update()
{
	mLast = mCurrent;
	mCurrent = SDL_GetTicks();
	mElapsed = (mCurrent - mLast);
}

void Timer::speed(double t)
{
	mspeed = t;
}

double Timer::speed()
{
	return mspeed;
}

}//namespace Engine
