#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <list>
#include <cmath>
#include <ctime>

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Medic_Station.h"
#include "Astronaut.h"
#include "Alien.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include "Input_Handling.h"


//Model Default constructor
Model::Model()
{
///////////////////////////////////////////////////////////////////////////////
//Set Clock/Time Variables

	time = 0;

	count_down = 10;

///////////////////////////////////////////////////////////////////////////////
//Set pointers:
	//Make the pointers to Astronauts
	Astronaut* astro1 = new Astronaut(1, Cart_Point(5,1));
	object_ptrs.push_back(astro1);
	active_ptrs.push_back(astro1);
	person_ptrs.push_back(astro1);


	Astronaut* astro2 = new Astronaut(2, Cart_Point(10,1));
	object_ptrs.push_back(astro2);
	active_ptrs.push_back(astro2);
	person_ptrs.push_back(astro2);



	//make the pointers to Aliens
	Alien* alien1 = new Alien(1, Cart_Point(7, 14));
	object_ptrs.push_back(alien1);
	active_ptrs.push_back(alien1);
	alien_ptrs.push_back(alien1);


	Alien* alien2 = new Alien(2, Cart_Point(7,5));
	object_ptrs.push_back(alien2);
	active_ptrs.push_back(alien2);
	alien_ptrs.push_back(alien2);



	//Make the pointers to the Oxygen_depots
	Oxygen_Depot* depot1 = new Oxygen_Depot(Cart_Point(1,20), 1);
	object_ptrs.push_back(depot1);
	active_ptrs.push_back(depot1);
	depot_ptrs.push_back(depot1);


	Oxygen_Depot* depot2 = new Oxygen_Depot(Cart_Point(10, 20), 2);
	object_ptrs.push_back(depot2);
	active_ptrs.push_back(depot2);
	depot_ptrs.push_back(depot2);



	//Make the pointers to the Space_Stations
	Space_Station* station1 = new Space_Station();
	object_ptrs.push_back(station1);
	active_ptrs.push_back(station1);
	station_ptrs.push_back(station1);


	Space_Station* station2 = new Space_Station(Cart_Point(5,5), 2);
	object_ptrs.push_back(station2);
	active_ptrs.push_back(station2);
	station_ptrs.push_back(station2);

	//Make the pointers to the Medic_Stations
	Medic_Station* medic1 = new Medic_Station(Cart_Point(15, 15), 1);
	object_ptrs.push_back(medic1);
	active_ptrs.push_back(medic1);
	medic_ptrs.push_back(medic1);



///////////////////////////////////////////////////////////////////////////////
//Set Number Variables:

	num_objects = 9;

	num_persons = 2;

	num_aliens = 2;

	num_depots = 2;

	num_stations = 2;

	num_medics = 1;


///////////////////////////////////////////////////////////////////////////////
	gravity = 0;

	std::cout << "Model Default constructed." << std::endl;

	return;
}


Model::~Model()
{
	std::list<Person*>::iterator it;
	for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
		Person* person = (*it);
		delete person;
	}

	std::list<Oxygen_Depot*>::iterator it2;
	for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
		Oxygen_Depot* depot = (*it2);
		delete depot;
	}

	std::list<Space_Station*>::iterator it3;
	for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
		Space_Station* station = (*it3);
		delete station;
	}

	std::list<Medic_Station*>::iterator it5;
	for ( it5 = medic_ptrs.begin(); it5 != medic_ptrs.end(); it5++ ) {
		Medic_Station* medic = (*it5);
		delete medic;
	}

	std::list<Alien*>::iterator it4;
	for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
		Alien* alien = (*it4);
		delete alien;
	}

	


	std::cout << "Model destructed." << std::endl;
	return;
}


Person* Model::get_Person_ptr(int inputId)
{
	bool found = false;
	Person* returnPerson_ptr = NULL;

	std::list<Person*>::iterator it;
	for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ){

		if ( (*it)->get_id() == inputId ) {

			found = true;
			returnPerson_ptr = (*it);
		}

	}

	return returnPerson_ptr;

}


Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int inputId)
{
	bool found = false;
	Oxygen_Depot* returnDepot_ptr = NULL;

	std::list<Oxygen_Depot*>::iterator it;
	for ( it = depot_ptrs.begin(); it != depot_ptrs.end(); it++ ) {

		if ( (*it)->get_id() == inputId ) {
			found = true;
			returnDepot_ptr = (*it);
		}

	}

	return returnDepot_ptr;

}


Space_Station* Model::get_Space_Station_ptr(int inputId)
{
	bool found = false;
	Space_Station* returnStation_ptr = NULL;

	std::list<Space_Station*>::iterator it;
	for ( it = station_ptrs.begin(); it != station_ptrs.end(); it++ ){

		if ( (*it)->get_id() == inputId ) {
			found = true;
			returnStation_ptr = (*it);
		}

	}

	return returnStation_ptr;

}


Alien* Model::get_Alien_ptr(int inputId)
{
	bool found = false;
	Alien* returnAlien_ptr = NULL;

	std::list<Alien*>::iterator it;
	for ( it = alien_ptrs.begin(); it != alien_ptrs.end(); it++ ){

		if ( (*it)->get_id() == inputId ) {
			found = true;
			returnAlien_ptr = (*it);
		}

	}

	return returnAlien_ptr;
}

Medic_Station* Model::get_Medic_Station_ptr(int inputId)
{
	bool found = false;
	Medic_Station* returnMedic_ptr = NULL;

	std::list<Medic_Station*>::iterator it;
	for ( it = medic_ptrs.begin(); it != medic_ptrs.end(); it++ ) {

		if( (*it)->get_id() == inputId ) {
			found = true;
			returnMedic_ptr = (*it);
		}

	}



	return returnMedic_ptr;
}


void Model::show_status()
{
	std::cout << "Time: " << time << std::endl;

	if (gravity >= 0 ) {
		std::cout << "Gravity changes speed: +" << abs(gravity) << std::endl;
	}
	else {
		std::cout << "Gravity changes speed: -" << abs(gravity) << std::endl;
	}

	std::list<Person*>::iterator it1;
	for ( it1 = person_ptrs.begin(); it1 != person_ptrs.end(); it1++ ) {
		(*it1)->show_status();
	}

	std::list<Oxygen_Depot*>::iterator it2;
	for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
		(*it2)->show_status();
	}

	std::list<Space_Station*>::iterator it3;
	for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
		(*it3)->show_status();
	}

	std::list<Medic_Station*>::iterator it5;
	for ( it5 = medic_ptrs.begin(); it5 != medic_ptrs.end(); it5++ ) {
		(*it5)->show_status();
	}

	std::list<Alien*>::iterator it4;
	for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
		(*it4)->show_status();
	}


	return;
}


bool Model::update()
{	
	time++;
	bool retTrue = false;
	bool testingTrue;


//Find if all the stations are upgraded and if all stations have an astronaut
	bool allUpgraded = false;
	bool allHaveAstro = false;

	std::list<Space_Station*>::iterator it1;
	int upgraded_stations = 0;
	int hasAstro_stations = 0;
	for ( it1 = station_ptrs.begin(); it1 != station_ptrs.end(); it1++ ) {
		if ( (*it1)->get_state() == 'u' ){ // if station is upgraded increment
			upgraded_stations++;
		}
		if ( (*it1)->get_astronauts() > 0 ) { //if station has an astronaut increment
			hasAstro_stations++;
		}
	}

	if (upgraded_stations == num_stations) { //if every station was upgraded these should be the same.
		allUpgraded = true;
	}

	if (hasAstro_stations == num_stations) { //if every station had an astronaut these should be the same.
		allHaveAstro = true;
	}

//Find if all the astronauts are locked at stations or if all the astronauts are dead.
	bool allDead = false;
	bool allLocked = false;

	std::list<Person*>::iterator it2;
	int dead_astronauts = 0;
	int locked_astronauts = 0;
	int alive_astronauts = 0;
	for ( it2 = person_ptrs.begin(); it2 != person_ptrs.end(); it2++ ) {
		if ( (*it2)->get_state() == 'l' ) { //if astronaut is locked increment.
			locked_astronauts++;
		}

		if ( (*it2)->get_state() == 'x' ) { //if astronaut is dead increment.
			dead_astronauts++;
		}
		else { //if astronaut is not dead increment.
			alive_astronauts++;
		}
	}

	if (locked_astronauts == alive_astronauts) { // if locked_astronauts = alive_astronauts that means all astronauts are locked.
		allLocked = true;
	}

	if (dead_astronauts == num_persons) { // if all people are dead you can not win and they are all dead.
		allDead = true;
	}


	if ( allUpgraded ) {
		std::cout << "Ready for takeoff? " << count_down << "..." << std::endl;

		if ( count_down > 0 && allHaveAstro && allLocked ) {
			std::cout << "Blast off! You win!" << std::endl;

			//Delete all the objects
			std::list<Person*>::iterator it;
			for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
				Person* person = (*it);
				delete person;
			}

			std::list<Oxygen_Depot*>::iterator it2;
			for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
				Oxygen_Depot* depot = (*it2);
				delete depot;
			}

			std::list<Space_Station*>::iterator it3;
			for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
				Space_Station* station = (*it3);
				delete station;
			}

			std::list<Alien*>::iterator it4;
			for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
				Alien* alien = (*it4);
				delete alien;
			}

			//Exit the program
			exit(EXIT_SUCCESS);
		}
		else if ( count_down == 0 && !allHaveAstro ) { //if countdown runs out and not all stations have astronauts, user looses game
			std::cout << "Unmaned Blast off! You Lose!" << std::endl;

			//Delete all the objects
		 	std::list<Person*>::iterator it;
			for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
				Person* person = (*it);
				delete person;
			}

			std::list<Oxygen_Depot*>::iterator it2;
			for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
				Oxygen_Depot* depot = (*it2);
				delete depot;
			}

			std::list<Space_Station*>::iterator it3;
			for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
				Space_Station* station = (*it3);
				delete station;
			}

			std::list<Alien*>::iterator it4;
			for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
				Alien* alien = (*it4);
				delete alien;
			}

			//Exit the program
			exit(EXIT_SUCCESS);
		}
		else if ( count_down == 0 && allHaveAstro && !allLocked ) {
			std::cout << "You left an astronaut behind! You Lose!" << std::endl;

			//Delete all the objects
		 	std::list<Person*>::iterator it;
			for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
				Person* person = (*it);
				delete person;
			}

			std::list<Oxygen_Depot*>::iterator it2;
			for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
				Oxygen_Depot* depot = (*it2);
				delete depot;
			}

			std::list<Space_Station*>::iterator it3;
			for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
				Space_Station* station = (*it3);
				delete station;
			}

			std::list<Alien*>::iterator it4;
			for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
				Alien* alien = (*it4);
				delete alien;
			}

			//Exit the program
			exit(EXIT_SUCCESS);
		}
		else if ( count_down == 0 && !allHaveAstro && !allLocked ) {
			std::cout << "Unmaned Blast Off! You Lose!" << std::endl;

			//Delete all the objects
		 	std::list<Person*>::iterator it;
			for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
				Person* person = (*it);
				delete person;
			}

			std::list<Oxygen_Depot*>::iterator it2;
			for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
				Oxygen_Depot* depot = (*it2);
				delete depot;
			}

			std::list<Space_Station*>::iterator it3;
			for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
				Space_Station* station = (*it3);
				delete station;
			}

			std::list<Alien*>::iterator it4;
			for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
				Alien* alien = (*it4);
				delete alien;
			}

			//Exit the program
			exit(EXIT_SUCCESS);
		}
		else {
			count_down--;

			//Update the Persons
			std::list<Person*>::iterator it1;
			for ( it1 = person_ptrs.begin(); it1 != person_ptrs.end(); it1++ ) {
				testingTrue = (*it1)->update();

				if ( testingTrue && retTrue == false ) {
					retTrue = true;
				}

			}

			//update the Space_Stations
			std::list<Space_Station*>::iterator it2;
			for ( it2 = station_ptrs.begin(); it2 != station_ptrs.end(); it2++ ) {
				testingTrue = (*it2)->update();

				if ( testingTrue && retTrue == false ) {
					retTrue = true;
				}

			}

			//update the Oxygen_Depot's
			std::list<Oxygen_Depot*>::iterator it3;
			for ( it3 = depot_ptrs.begin(); it3 != depot_ptrs.end(); it3++ ) {
				testingTrue = (*it3)->update();

				if ( testingTrue && retTrue == false ) {
					retTrue = true;
				}

			}

			//update the Medic_Stations
			std::list<Medic_Station*>::iterator it5;
			for ( it5 = medic_ptrs.begin(); it5 != medic_ptrs.end(); it5++ ) {
				testingTrue = (*it5)->update();

				if (testingTrue && retTrue == false) {
					retTrue = true;
				}
			}

			//update the Alien's
			std::list<Alien*>::iterator it4;
			for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
				testingTrue = (*it4)->update();

				if ( testingTrue && retTrue == false ) {
					retTrue = true;
				}

			}

		}
	}
	else if ( allDead ) {
		std::cout << "All astronauts are dead. You lose." << std::endl;

		std::list<Person*>::iterator it;
		for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
			Person* person = (*it);
			delete person;
		}

		std::list<Oxygen_Depot*>::iterator it2;
		for ( it2 = depot_ptrs.begin(); it2 != depot_ptrs.end(); it2++ ) {
			Oxygen_Depot* depot = (*it2);
			delete depot;
		}

		std::list<Space_Station*>::iterator it3;
		for ( it3 = station_ptrs.begin(); it3 != station_ptrs.end(); it3++ ) {
			Space_Station* station = (*it3);
			delete station;
		}

		std::list<Alien*>::iterator it4;
		for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
			Alien* alien = (*it4);
			delete alien;
		}

		exit(EXIT_SUCCESS);
	}
	else {
		//Update the Persons
		std::list<Person*>::iterator it1;
		for ( it1 = person_ptrs.begin(); it1 != person_ptrs.end(); it1++ ) {
			testingTrue = (*it1)->update();

			if ( testingTrue && retTrue == false ) {
				retTrue = true;
			}

		}

		//update the Space_Stations
		std::list<Space_Station*>::iterator it2;
		for ( it2 = station_ptrs.begin(); it2 != station_ptrs.end(); it2++ ) {
			testingTrue = (*it2)->update();

			if ( testingTrue && retTrue == false ) {
				retTrue = true;
			}

		}

		//update the Oxygen_Depot's
		std::list<Oxygen_Depot*>::iterator it3;
		for ( it3 = depot_ptrs.begin(); it3 != depot_ptrs.end(); it3++ ) {
			testingTrue = (*it3)->update();

			if ( testingTrue && retTrue == false ) {
				retTrue = true;
			}

		}

		//update the Medic_Stations
		std::list<Medic_Station*>::iterator it5;
		for ( it5 = medic_ptrs.begin(); it5 != medic_ptrs.end(); it5++ ) {
			testingTrue = (*it5)->update();

			if (testingTrue && retTrue == false) {
				retTrue = true;
			}
		}

		//update the Alien's
		std::list<Alien*>::iterator it4;
		for ( it4 = alien_ptrs.begin(); it4 != alien_ptrs.end(); it4++ ) {
			testingTrue = (*it4)->update();

			if ( testingTrue && retTrue == false ) {
				retTrue = true;
			}

		}


	}


	std::list<Game_Object*>::iterator it5;
	for ( it5 = active_ptrs.begin(); it5 != active_ptrs.end(); ++it5 ) {
		char retState = (*it5)->get_state();

		if ( retState == 'x' ){
			(it5) = active_ptrs.erase(it5);
		}

	}


	std::list<Person*>::iterator it6;
	for ( it6 = person_ptrs.begin(); it6 != person_ptrs.end(); it6++ ) {
		if( (*it6)->get_health() < 3 ) {
			(*it6)->display_code_case_lower();
		}
	}


	//Decide whether or not the function should return true or not;
	if ( retTrue ) {
		return true;
	}
	else {
		return false;
	}
}


void Model::display(View &view)
{
	view.clear();

	std::list<Game_Object*>::iterator it;
	for ( it = active_ptrs.begin(); it != active_ptrs.end(); it++ ) {
		view.plot( (*it) );
	}

	view.draw();


	return;
}

//			ADD EXCEPTIONS TO THIS FUNCTION FOR INVALID TYPE, ID AND LOCATION
//			ID CAN NOT BE GRETTER THAN 9 OR LESS THAN 0. CHECK THIS.
void Model::handle_new_command(char type, int id1, Cart_Point location)
{
	try {
		switch ( type ) {

			case 'm':
				{
					throw Invalid_Input("Can not add another Medic_Station.");

					break;
				}
			case 'd':
				{
					if ( get_Oxygen_Depot_ptr(id1) == NULL && id1 < 10 && id1 > 0 ) {



						Oxygen_Depot* depot = new Oxygen_Depot( location, id1 );

						depot_ptrs.push_back(depot);
						num_depots++;

						object_ptrs.push_back(depot);
						active_ptrs.push_back(depot);
						num_objects++;

					}
					else if ( id1 > 9 || id1 < 1 ) {
						throw Invalid_Input("ID must be within [1,9].");
					}
					else {
						std::cout << "O" << id1 << " already exists." << std::endl;
					}

					break;
				}
			case 's':
				{
					if ( get_Space_Station_ptr(id1) == NULL && id1 < 10 && id1 > 0 ) {

						Space_Station* station = new Space_Station( location, id1 );

						station_ptrs.push_back(station);
						num_stations++;

						object_ptrs.push_back(station);
						active_ptrs.push_back(station);
						num_objects++;

					}
					else if ( id1 > 9 || id1 < 1 ) {
						throw Invalid_Input("ID must be within [1,9].");
					}
					else {
						std::cout << "s" << id1 << " already exists." << std::endl;
					}

					break;
				}
			case 'a':
				{
					if ( get_Person_ptr(id1) == NULL && id1 < 10 && id1 > 0 ) {

						Person* person = new Astronaut( id1, location );

						person_ptrs.push_back(person);
						num_persons++;

						object_ptrs.push_back(person);
						active_ptrs.push_back(person);
						num_objects++;
					}
					else if ( id1 > 9 || id1 < 1 ) {
						throw Invalid_Input("ID must be within [1,9].");
					}
					else {
						std::cout << "A" << id1 << " already exists." << std::endl;
					}

					break;
				}
			case 'x':
				{
					if( get_Alien_ptr(id1) == NULL && id1 < 10 && id1 > 0 ) {

						Alien* alien = new Alien( id1, location );

						alien_ptrs.push_back(alien);
						num_aliens++;

						object_ptrs.push_back(alien);
						active_ptrs.push_back(alien);
						num_objects++;

					}
					else if ( id1 > 9 || id1 < 1 ) {
						throw Invalid_Input("ID must be within [1,9].");
					}
					else {
						std::cout << "X" << id1 << " already exists." << std::endl;
					}

					break;
				}
			default:
				{
					throw Invalid_Input("Invalid type entered.");
					break;
				}
		}
	}
	catch(Invalid_Input& except){
		std::cin.ignore(1000,'\n');
		std::cout << "Invalid Input - " << except.msg_ptr << std::endl;
	}

	return;
}

//Function is used when the user wants to play agains the computer
//Function decides if aliens attack the people or not
bool Model::computer_attack()
{
	std::srand(std::time(0));

	bool retTrue = false;
	//set up iterators
	std::list<Alien*>::iterator itAlien;
	std::list<Person*>::iterator itPerson;

	//iterate through each alien
	for ( itAlien = alien_ptrs.begin(); itAlien != alien_ptrs.end(); itAlien++ ) {

		//check if the alien is already doing something. If its stopped, it can get a new command.
		if ( (*itAlien)->get_state() == 's' ) {

			//iterate through each person for the alien to see if the alien can attack the person.
			for ( itPerson = person_ptrs.begin(); itPerson != person_ptrs.end(); itPerson++ ) {

				//set up the target for the alien as the person. Makes the code more clear.
				Person* target = (*itPerson);
				//as long as the target is not null continue.
				if ( target != NULL) {

					//determine the distance between the target and alien
					Cart_Point target_loc = target -> get_location();
					Cart_Point alien_loc = (*itAlien)->get_location();
					double a_squared = pow( abs(target_loc.x - alien_loc.x), 2 );
					double b_squared = pow( abs(target_loc.y - alien_loc.y), 2 );

					double dist_between = sqrt(a_squared + b_squared);

					//Determines if the target is already under attack
					bool alreadyTarget = false;
					std::list<Alien*>::iterator itAlien2;
					for ( itAlien2 = alien_ptrs.begin(); itAlien2 != alien_ptrs.end(); itAlien2++ ) {
						if (target == (*itAlien2)->get_target() && (*itAlien2)->get_state() != 's' ){
							alreadyTarget = true;
						}
					}

					//Randomly 50:50 decides if the alien should attack or not when conditions are met
  					
  					int randValue = rand() % 10 + 1;
  					bool shouldAttack = false;
  					if ( randValue % 2 == 0 ) {
  						shouldAttack = true;
  					}

  					//if target is in range, stationary, isnt already a target, and 
  					//computer randomly decided the alien should attack or it is angry and willAttack, then execute.
					if ( (*itAlien)->get_state() == 's' && target->get_state() == 's' && dist_between <= 2 && !alreadyTarget && (shouldAttack || (*itAlien)->willAttack) ) {
						std::cout << "X" << (*itAlien)->get_id() << ": will start to attack person (" << (*itPerson)->get_id() << ")." << std::endl;
						(*itAlien)->start_attack( (*itPerson) );
						if (!retTrue) {
							retTrue = true;
						}
						break;
					}
					//if Alien is stationary, target is stationary, isnt already a target, is within 8 units
					//and thecomputer randomly decided the alien should attack, then execute.
					else if ( (*itAlien)->get_state() == 's' && target->get_state() == 's' && !alreadyTarget && dist_between <= 10 && shouldAttack ) {
						std::cout << "X" << (*itAlien)->get_id() << ": will start moving towards person (" << (*itPerson)->get_id() << ") - ";
						(*itAlien)->willAttack = true;
						(*itAlien)->give_new_target(target);
						(*itAlien)->start_moving(target->get_location());
						if (!retTrue) {
							retTrue = true;
						}
						break;
					}
					else if ( (*itAlien)->get_state() == 's' && target->get_state() == 'm' && !alreadyTarget && dist_between <= 3 && shouldAttack ) {
						std::cout << "X" << (*itAlien)->get_id() << ": Person(" << target->get_id() << ") got too close to an Alien. Its ANGRY and wants to attack - ";
						std::cout << "X" << (*itAlien)->get_id() << " will follow person (" << (*itPerson)->get_id() << ") to its destination - ";
						(*itAlien)->willAttack = true;
						(*itAlien)->give_new_target(target);
						(*itAlien)->start_moving(target->get_destination());
						if (!retTrue) {
							retTrue = true;
						}
						break;
					}

				}

			}

		}

	}

	if (retTrue) {
		return true;
	}
	else {
		return false;
	}

}


void Model::change_gravity() 
{
	std::srand(std::time(0));
	double randGravity = rand() % 8 + 3;

	double gravityTemp = 5 - randGravity;
	
	if ( (gravityTemp == -2 && gravity != gravityTemp) || (gravityTemp == 0 && gravity != gravityTemp) || (gravityTemp == 2 && gravity != gravityTemp) ) {
		std::cout << "Gravity changed." << std::endl;
		gravity = gravityTemp;
	}

	std::list<Person*>::iterator it;
	for ( it = person_ptrs.begin(); it != person_ptrs.end(); it++ ) {
		(*it)->change_speed(gravity);
	}


	return;
}


























