
#include "Vector2D.h"
#include <iostream>
using namespace std;

//constructors
Vector2D::Vector2D() {
	x = 0.0;
	y = 0.0;
}
Vector2D::Vector2D(double x_in, double y_in) {
	x = x_in;
	y = y_in;
}
//overloaded operators
Vector2D operator*(Vector2D v1, double d) {
	Vector2D v2;
	v2.x = v1.x * d;
	v2.y = v1.y * d;

	return v2;
}
Vector2D operator/(Vector2D v1, double d) {
	Vector2D v2;
	v2.x = v1.x / d;
	v2.y = v1.y / d;

	return v2;
}
ostream& operator<<(ostream& os, const Vector2D v1)
{
	cout << "<" << v1.x << ", " << v1.y << "> ";
	return os;
}

