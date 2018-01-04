#include <math.h>
#include "Rectangle.hpp"

#define PI 3.14159

namespace Engine {

Rectangle::Rectangle(int width, int height)
{
	alpha = 0.0;
	radius = 0.0;
	set(width, height);
}

//rotates the rect in degrees aligned with its upper edge
//when it was still unrotated. Meaning: middle of rect to
//corner 1 is the radius, the angle of the radius is NOT
//the angle of rotation, it's the angle corner1 - corner0
void Rectangle::rotate(double degrees)
{
	corner[0].x = cos((alpha + degrees) * PI / 180.0) * radius;
	corner[0].y = sin((alpha + degrees) * PI / 180.0) * radius;

	corner[1].x = cos((180.0 - alpha + degrees) * PI / 180.0) * radius;
	corner[1].y = sin((180.0 - alpha + degrees) * PI / 180.0) * radius;

	corner[2].x = cos((180.0 + alpha + degrees) * PI / 180.0) * radius;
	corner[2].y = sin((180.0 + alpha + degrees) * PI / 180.0) * radius;

	corner[3].x = cos((degrees - alpha) * PI / 180.0) * radius;
	corner[3].y = sin((degrees - alpha) * PI / 180.0) * radius;

	alpha += degrees;
}

void Rectangle::rotate(double degrees, bool rotation_flag)
{
	//if (rotation_flag)

}

void Rectangle::set(int width, int height)
{
	dim.x = width;
	dim.y = height;

	pos.x = 0.0;
	pos.y = 0.0;

	alpha  = atan(height / width);
	radius = static_cast<double>(sqrt((width * width) + (height * height))) / 2;

	corner[0].x = width  /  2.0;
	corner[0].y = height /  2.0;
	corner[1].x = width  / -2.0;
	corner[1].y = height /  2.0;
	corner[2].x = width  / -2.0;
	corner[2].y = height / -2.0;
	corner[3].x = width  /  2.0;
	corner[3].y = height / -2.0;
}

void Rectangle::move_relative(Engine::Coordinates<int>position)
{


	for (int i = 0; i < 4; i++) {
		corner[i].x += static_cast<double>(position.x);
		corner[i].y += static_cast<double>(position.y);
	}
}

void Rectangle::move_absolute(Engine::Coordinates<int>position)
{

}

} //namespace Engine
