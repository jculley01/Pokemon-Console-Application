#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "Vector2D.h"
using namespace std;
class Point2D {

public:
	//member variables
	double x;
	double y;
	//constructor
	Point2D();
	Point2D(double in_x, double in_y);
	

	
};

//non-member overloaded operators and functions
Vector2D operator-(const Point2D& p1, const Point2D& p2);
Point2D operator+(Point2D p1, Vector2D v1);
ostream& operator<<(ostream& os, Point2D p1);
double GetDistanceBetween(Point2D p1, Point2D p2);


#endif