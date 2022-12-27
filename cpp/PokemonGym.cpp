#ifndef PokeGym
#define PokeGym
#include "PokemonGym.h"
#include "Building.h"

//constructors
PokemonGym::PokemonGym() : Building() {
	display_code = 'G';
	state = NOT_DEFEATED;
	max_number_of_battles = 10;
	num_battle_remaining = max_number_of_battles;
	health_cost_per_battle = 1;
	PokeDollar_cost_per_battle = 1.0;
	experience_per_battle = 2;
	cout << "Pokemon Gym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc) {
	display_code = 'G';
	id_num = in_id;
	location = in_loc;
	max_number_of_battles = max_battle;
	health_cost_per_battle = health_loss;
	experience_per_battle = exp_per_battle;
	PokeDollar_cost_per_battle = PokeDollar_cost;
	num_battle_remaining = max_number_of_battles;
	cout << "Pokemon Gym constructed" << endl;
}
//destructor
PokemonGym::~PokemonGym() {
	cout << "PokemonGym destructed." << endl;
}
//function to get cost to battle
double PokemonGym::GetPokeDollarCost(unsigned int battle_qty) {
	return battle_qty * PokeDollar_cost_per_battle;
}
//function to get health cost per battle
unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty) {
	return battle_qty * health_cost_per_battle;
}
//function to get amount of battles left at the gym
unsigned int PokemonGym::GetNumBattlesRemaining() {
	return num_battle_remaining;
}
//function to see if the trainer is able to battle by checking the constraints
bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) {
	if ((battle_qty * PokeDollar_cost_per_battle) < budget && (battle_qty * health_cost_per_battle) < health) {
		return true;
	}
	else {
		return false;
	}
}
//function that awards experience and modifies remaining battles count
unsigned int PokemonGym::TrainPokemon(unsigned int battle_units) {
	if (num_battle_remaining > battle_units) {
		num_battle_remaining = num_battle_remaining - battle_units;
	}
	else {
		battle_units = num_battle_remaining;
		num_battle_remaining = 0;
	}
	return battle_units * experience_per_battle;
}
//function that gets the exp per battle
unsigned int PokemonGym::GetExperiencePerBattle() {
	return experience_per_battle;
}
//function that updates the gym
bool PokemonGym::Update() {
	if (num_battle_remaining == 0 && display_code != 'g') {
		state = DEFEATED;
		display_code = 'g';
		cout << display_code << id_num << " has been beaten." << endl;
		return true;
	}
	else if (display_code == 'g') {
		return false;
	}
	else {
		return false;
	}
}
//function that tells you when a gym has been completed
bool PokemonGym::passed() {
	if (num_battle_remaining == 0) {
		return true;
	}
	else {
		return false;
	}
}
//function that prints the status of the gym
void PokemonGym::ShowStatus() {
	cout << endl << "Pokemon Gym status: ";
	Building::ShowStatus();
	cout << endl << "Max number of battles: " << max_number_of_battles << endl << "Health cost per battle: " << health_cost_per_battle << endl << "PokeDollar per battle: " << PokeDollar_cost_per_battle << endl << "Experience per battle: " << experience_per_battle << endl << num_battle_remaining << " battle(s) are remaining for this PokeGym" << endl;
}


#endif