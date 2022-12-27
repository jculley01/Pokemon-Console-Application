#pragma once
#include "Point2D.h"
#include "GameObject.h"
const int view_maxsize = 20;
class View {
	

private:
	int size;
	double scale;
	Point2D origin;
	char grid[view_maxsize][view_maxsize][2];
	bool GetSubscripts(int& out_x, int& out_y, Point2D location);
public:
	//constructor
	View();
	//member functions
	void Clear();
	void Plot(GameObject* ptr);
	void Draw();

};