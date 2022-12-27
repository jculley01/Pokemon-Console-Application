#ifndef PokeCenter
#define PokeCenter
#include "PokemonCenter.h"
#include <iostream>
#include "Building.h"
using namespace std;

//constructors
PokemonCenter::PokemonCenter() : Building() {
	display_code = 'C';
	potion_capacity = 100;
	num_potions_remaining = potion_capacity;
	pokedollar_cost_per_potion = 5;
	state = POTIONS_AVAILABLE;
	cout << "Pokemon Center default constructed" << endl;
}
PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc) {
	id_num = in_id;
	display_code = 'C';
	location = in_loc;
	pokedollar_cost_per_potion = potion_cost;
	potion_capacity = potion_cap;
	num_potions_remaining = potion_capacity;
	state = POTIONS_AVAILABLE;
	cout << "Pokemon Center constructed" << endl;
}
//function to return if there are potions in the center
bool PokemonCenter::HasPotions() {
	if (state == POTIONS_AVAILABLE) {
		return true;
	}
	else {
		return false;
	}
}
//function to see how many potions there are left
unsigned int PokemonCenter::GetNumPotionRemaining() {
	return num_potions_remaining;
}
//function that checks if you have enough money for the potions
bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget) {
	if (budget >= (potion * pokedollar_cost_per_potion)) {
		return true;
	}
	else {
		return false;
	}
}
//function that gets the cost per potion
double PokemonCenter::GetPokeDollarCost(unsigned int potion) {
	return potion * pokedollar_cost_per_potion;
}
//function that accounts for the used potions in the amount remaining
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed) {
	if (num_potions_remaining >= potion_needed) {
		num_potions_remaining = num_potions_remaining - potion_needed;
		return potion_needed;
	}
	else {
		unsigned int out_potion = num_potions_remaining;
		num_potions_remaining = 0;
		return out_potion;
	}
}
//function that updates the pokemon center
bool PokemonCenter::Update() {
	if (num_potions_remaining == 0 && display_code != 'c') {
		state = NO_POTIONS_AVAILABLE;
		display_code = 'c';
		cout << "Pokemon Center " << id_num << " has ran out of potions." << endl;
		return true;
	}
	else if (display_code == 'c') {
		return false;
	}
	else {
		return false;
	}
}

//prints that status of the pokemon center
void PokemonCenter::ShowStatus(){
	cout << endl << "Pokemon Center status: ";
	Building::ShowStatus();
	cout << endl << "PokeDollars per potion: " << pokedollar_cost_per_potion << endl << "Has " << num_potions_remaining << " potion(s) remaining." << endl;
}
//destructor
PokemonCenter::~PokemonCenter() {
	cout << "PokemonCenter destructed" << endl;
}

#endif