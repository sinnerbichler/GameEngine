//Physics.cpp

namespace Engine {

double downwards_parabola(double t)
{
	return ((-4 * t * t) + (4 * t));
}

double upwards_parabola(double t)
{
	return ((4 * t * t)- (4 * t + 1));
}

}//namespace Engine
