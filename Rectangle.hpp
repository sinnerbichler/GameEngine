#include "Physics.hpp"

namespace Engine {

/*
rect points are stored so:
1--------0
|        |
|        |
2--------3
*/
enum bRotation {
	ROTATION_ABSOLUTE, //if the rotation flag is absolute,
	ROTATION_RELATIVE
};

class Rectangle {
public:
	Rectangle(int width, int height);
	void rotate(double degrees);
	void rotate(double degrees, bool rotation_flag);

	void set(int width, int	height);

	void move_absolute(Coordinates<int>position);
	void move_relative(Coordinates<int>position);

//protected:
	Engine::Coordinates<double> corner[4];
	Engine::Coordinates<int>    dim;
	Engine::Coordinates<int>    pos;

	double radius; //radius value |corner0 corner2| / 2 or half the diameter
	double alpha; //alpha value is just atan(h / w) of unrotated rect.
						//gets reset when set() is called
};

} //namespace Engine
