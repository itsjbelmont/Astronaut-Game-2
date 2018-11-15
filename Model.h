#ifndef MODEL_H
#define MODEL_H

#include <list>

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Medic_Station.h"
#include "Astronaut.h"
#include "Model.h"
#include "View.h"
#include "Alien.h"

//added function computer_attack to decide how the aliens behave when the computer is controling them.
//added members for the medic stations added.
//added members for the gravity changing randomly.

class Model
{
protected:
	//simulated time
	int time;
	int count_down;

	//Game_Objects
	//Game_Object* object_ptrs[10];
	std::list<Game_Object*> object_ptrs;
	std::list<Game_Object*> active_ptrs;
	int num_objects;

	//Persons
	//Person* person_ptrs[10];
	std::list<Person*> person_ptrs;
	int num_persons;

	//Aliens
	//Alien* alien_ptrs[10];
	std::list<Alien*> alien_ptrs;
	int num_aliens;

	//Oxygen_Depots
	//Oxygen_Depot* depot_ptrs[10];
	std::list<Oxygen_Depot*> depot_ptrs;
	int num_depots;

	//Space_stations
	//Space_Station* station_ptrs[10];
	std::list<Space_Station*> station_ptrs;
	int num_stations;

	//Medic_Stations
	//Used for Medic Station Extra credit (Personal choice add.)
	std::list<Medic_Station*> medic_ptrs;
	int num_medics;


	//PA4 step 7 for changing gravity
	double gravity;


public:
	//constructor and destructor
	Model(); 
	~Model();

	//get functions
	Person* get_Person_ptr(int inputId);

	Oxygen_Depot* get_Oxygen_Depot_ptr(int inputId);

	Space_Station* get_Space_Station_ptr(int inputId);

	Medic_Station* get_Medic_Station_ptr(int inputId);

	Alien* get_Alien_ptr(int inputId);

	//Function to handle adding new objects
	void handle_new_command(char type, int id1, Cart_Point location);

	//Main update function for the game
	bool update();

	//Generates the view display for the Game_Objects
	void display(View &view);

	//Outputs the status for all game objects
	void show_status();

	//Decides how the computer controled aliens attacks the astronauts
	bool computer_attack();

	//PA4 step 7 changing gravity
	void change_gravity();

};












#endif
