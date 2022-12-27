#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;
class Vector2D {

public:
	//member variables
	double x;
	double y;
	//constructor
	Vector2D();
	Vector2D(double in_x, double in_y);


	//operators
	friend Vector2D operator*(Vector2D v1, double d);
	friend Vector2D operator/(Vector2D v1, double d);
	friend ostream& operator<<(ostream& os, Vector2D v1);
};


#endif