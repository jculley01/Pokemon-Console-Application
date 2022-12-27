#ifndef BUILDING_H
#define BUILDING_H

#include "Point2D.h"
#include "GameObject.h"

class Building : public GameObject {
private:
	unsigned int trainer_count;
public:
	//constructors
	Building();
	Building(char in_code, int in_Id, Point2D in_loc);
	//member functions
	void AddOneTrainer();
	void RemoveOneTrainer();
	void ShowStatus();
	bool ShouldBeVisible();
};

#endif