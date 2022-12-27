
#include "Point2D.h"
#include <math.h>
#include <cmath>
#include "Vector2D.h"
#include <iostream>
using namespace std;

//constructors
Point2D::Point2D() {
	x = 0.0;
	y = 0.0;
}
Point2D::Point2D(double x_in, double y_in) {
x = x_in;
y = y_in;
}

//member functions
double GetDistanceBetween(const Point2D p1, const Point2D p2) {
	double distance = 0.0;
	distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	return distance;
}

//overloaded operators
Vector2D operator-(const Point2D& p1, const Point2D& p2) {
	Vector2D v1;
	v1.x = p1.x - p2.x;
	v1.y = p1.y - p2.y;

	return v1;
}

Point2D operator+(Point2D p1, Vector2D v1) {
	Point2D p2;
	p2.x = p1.x + v1.x;
	p2.y = p1.y + v1.y;

	return p2;
}

ostream& operator<<(ostream& os, const Point2D p1)
{
	cout << "(" << p1.x << ", " << p1.y << ") ";
	return os;
}


