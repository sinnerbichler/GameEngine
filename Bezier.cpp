//Bezier.cpp
#include "Bezier.hpp"

namespace Engine {

BezierCurve::BezierCurve()
{
	if (lut.size() == 1)
		for (int i; i < 5;) //finish
			i++;
}

}//namespace Engine
