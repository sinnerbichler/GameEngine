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

double falling_parabola(double t)
{
	return (-(t * t) + 1);
}

double ascending_parabola(double t)
{
	return (t * t);
}

}//namespace Engine
