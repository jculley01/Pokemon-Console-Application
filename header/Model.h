#pragma once

#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include <list>
#include "WildPokemon.h"
#include "Input_Handling.h"
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
class Model {
private:
	bool gameover;
	int time;
	int count;
	//GameObject* object_ptrs[10];
	vector<GameObject*> object_ptrs;
	vector<GameObject*> active_ptrs;
	int num_objects;
	//Trainer* trainer_ptrs[10];
	vector<Trainer*> trainer_ptrs;
	int num_trainers;
	//PokemonCenter* center_ptrs[10];
	vector<PokemonCenter*> center_ptrs;
	int num_centers;
	//PokemonGym* gym_ptrs[10];
	vector<PokemonGym*> gym_ptrs;
	int num_gyms;
	vector<WildPokemon*> wildpokemon_ptrs;
	int num_wildpokemon;
public:
	//constructor
	Model();
	//destructor
	~Model();
	//member functions
	Trainer* GetTrainerPtr(int id);
	PokemonCenter* GetPokemonCenterPtr(int id);
	PokemonGym* GetPokemonGymPtr(int id);
	WildPokemon* GetWildPokemonPtr(int id);
	bool GameOver();
	bool Update();
	void Display(View& view);
	void ShowStatus();
	virtual void NewCommand(char type, int in_id, Point2D in_loc);
};

