#include <iostream>
#include <stdlib.h>

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Medic_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "Input_Handling.h"


void do_move_command(Model& model, char mode, int id, double x, double y)
{
	try {
		char decision = ' ';
		if (mode == 'c') {
			decision = 'a';
		}
		else {
			while ( decision != 'a' && decision != 'x' ) {
				std::cout << "Move Astronaut (enter 'a') or move Alien (enter 'x'): ";
				std::cin >> decision;
				decision = tolower(decision);
			
			}
		}

		if ( decision == 'a' ) {
			Person* person_ptr = model.get_Person_ptr(id);

			//check for valid ID
			if ( person_ptr == NULL ) {
				throw Invalid_Input("Invalid ID entered.");
			}
			else {
				person_ptr -> start_moving(Cart_Point(x,y));
			}
		}
		else if ( decision == 'x' ) {
			Alien* alien_ptr = model.get_Alien_ptr(id);

			//check for valid ID
			if ( alien_ptr == NULL ) {
				throw Invalid_Input("Invalid ID entered.");
			}
			else {
				alien_ptr -> start_moving(Cart_Point(x,y));
			}
		}
		else {
			throw Invalid_Input("Something went wrong with the command.");
		}
		
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

	}
		return;
}

void do_work_a_depot_command(Model& model, int id1, int id2)
{
	try {
		Person* person_ptr = model.get_Person_ptr(id1);
		Oxygen_Depot* depot_ptr = model.get_Oxygen_Depot_ptr(id2);

		if( person_ptr == NULL || depot_ptr == NULL ){
			throw Invalid_Input("Invalid ID entered.");
		}
		else{
			person_ptr -> start_supplying(depot_ptr);
		}
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;
	}

	return;
}

void do_deposit_moon_stones_command(Model& model, int id1, int id2)
{
	try {
		Person* person_ptr = model.get_Person_ptr(id1);
		Space_Station* station_ptr = model.get_Space_Station_ptr(id2);

		if ( person_ptr == NULL || station_ptr == NULL ) {
			throw Invalid_Input("Invalid ID entered.");
		}
		else {
			person_ptr -> start_depositing(station_ptr);
		}
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

	}

	return;
}


void do_stop_command(Model& model, char mode, int id)
{
	try {
		char decision = ' ';
		if (mode == 'c') {
			decision = 'a';
		}
		else {
			while ( decision != 'a' && decision != 'x' ) {
				std::cout << "Move Astronaut (enter 'a') or move Alien (enter 'x'): ";
				std::cin >> decision;
				decision = tolower(decision);
			
			}
		}

		if (decision == 'a') {
			Person* person_ptr = model.get_Person_ptr(id);
			

			if ( person_ptr == NULL ) {
				throw Invalid_Input("Invalid ID entered.");
			}
			else {
				person_ptr ->stop();
			}
		}
		else if (decision == 'c') {
			Alien* alien_ptr = model.get_Alien_ptr(id);


			if (alien_ptr == NULL) {
				throw Invalid_Input("Invalid ID entered.");
			}
			else {
				alien_ptr->stop();
			}
		}
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

	}

	return;
}

void do_lock_in_at_station_command(Model& model, int id1, int id2)
{
	try {
		Person* person_ptr = model.get_Person_ptr(id1);
		Space_Station* station_ptr = model.get_Space_Station_ptr(id2);

		if (person_ptr == NULL || station_ptr == NULL ){
			throw Invalid_Input("Invalid ID entered.");
		}
		else {
			person_ptr -> go_to_station(station_ptr);
		}
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

	}
	
	return;
}

void do_attack_command(Model& model, int id1, int id2)
{
	try {
		Alien* alien_ptr = model.get_Alien_ptr(id1);
		Person* person_ptr = model.get_Person_ptr(id2);

		if ( alien_ptr == NULL || person_ptr == NULL ) {
			throw Invalid_Input("Invalid ID entered.");
		}
		else {
			alien_ptr->start_attack( person_ptr );
		}
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

	}

	return;
}

void do_heal_command(Model& model, int id1, int id2)
{
	try {
		Person* person_ptr = model.get_Person_ptr(id1);
		Medic_Station* medic_ptr = model.get_Medic_Station_ptr(id2);

		if (person_ptr == NULL || medic_ptr == NULL) {
			throw Invalid_Input("Invalid ID entered.");
		}
		else if (person_ptr->get_health() == 5) {
			std::cout << "Astronaut (" << person_ptr->get_id() << ") already has full health." << std::endl;
		}
		else {
			person_ptr->go_to_medic( medic_ptr );
		}

	}
	catch(Invalid_Input& except) {
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;
	}

	return;
}

void do_go_command(Model& model, char mode)
{
	std::cout << "Advancing one tick." << std::endl << std::endl;

	model.change_gravity();

	model.update();
	if (mode == 'c') {
		model.computer_attack();
	}


	return;
}

void do_run_command(Model& model, char mode)
{
	std::cout << "Advancing to next event." << std::endl << std::endl;

	bool funcReturn = false;
	bool computerAttack = false;
	int i = 0;

	while (!funcReturn && !computerAttack && i < 5) {
		model.change_gravity();
		funcReturn = model.update();
		if (mode == 'c') {
			computerAttack = model.computer_attack();
		}

		i++;
	}


	return;
}

void do_quit_command(Model& model)
{
	std::cout << "Quiting..." << std::endl;

	model.~Model(); //destruct the objects

	exit(EXIT_SUCCESS);

	return;
}

