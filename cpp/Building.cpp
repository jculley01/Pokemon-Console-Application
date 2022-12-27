
#include "Building.h"
#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
using namespace std;

//constructors
Building::Building() : GameObject('B') {
	trainer_count = 0;
	cout << "Building default constructed" << endl;
}
Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code) {
	id_num = in_Id;
	display_code = in_code;
	location = in_loc;
	trainer_count = 0;
	state = 0;
	cout << "Building constructed" << endl;
}

//member functions
//adds one to the count when a trainer arrives at a building
void Building::AddOneTrainer() {
	trainer_count++;
	return;
}
//removes one from the count when a trainer arrives at a building
void Building::RemoveOneTrainer() {
	trainer_count--;
	return;
}
//prints the status of building objects
void Building::ShowStatus() {
		cout << display_code << id_num << " at " << location << endl;
		if (trainer_count == 1) {
			cout << trainer_count << " trainers is located within this building" << endl;
		}
		else {
			cout << trainer_count << " trainers are located within this building";
		}
	return;
}
//returns true because buildings are always visible
bool Building::ShouldBeVisible() {
	return true;
}





