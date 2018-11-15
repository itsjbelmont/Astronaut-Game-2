#include <iostream>

#include "Astronaut.h"
#include "Person.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Medic_Station.h"


//Default constructor for Astronaut class
Astronaut::Astronaut() : Person('A')
{
	amount_moonstones = 0;
	amount_oxygen = 20;
	this -> depot = NULL;
	this -> home = NULL;
	this -> medic = NULL;
	std::cout << "Astronaut default constructed." << std::endl;

	return;
}


//Constructor for Astronaut class
Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Person(in_loc, in_id, 'A')
{
	amount_moonstones = 0;
	amount_oxygen = 20;
	this -> depot = NULL;
	this -> home = NULL;
	this -> medic = NULL;
	std::cout << "Astronaut constructed." << std:: endl;

	return;
}


Astronaut::~Astronaut()
{
	std::cout << "Astronaut destructed." << std::endl;

	return;
}


//Update function:
//Returns true when the state is changed.
//Updates the status of the object on each time unit 
//If the object is moving and has not reached the destination, increment the
//amount of moonstones and decrement the amount of oxygen.
bool Astronaut::update()
{
	Cart_Point location1 = Game_Object::get_location();

	if ( get_display_code() == 'A' && health < 3 ) {
		display_code_case_lower();
	}
	
	switch ( state ){

		case 'x':
			{
				return false;

				break;
			}
		case 's': 
			{ //Return false or true if does nothing??
				return false;

				break;
			}
		case 'm':
			{
				if (amount_oxygen <= 0){
					state = 'x';
					return true;
				}
				else if ( Person::update_location() ) {
					state = 's';
					amount_moonstones++;
					amount_oxygen--;
					return true;
				}
				else {
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}

				break;
			}
		case 'o': 
			{
				if (amount_oxygen <= 0){
					state = 'x';
					return true;
				}
				else if ( Person::update_location() ) {
					state = 'g';
					amount_moonstones++;
					amount_oxygen--;
					return true;
				}
				else {
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}

				break;
			}
		case 'g':
			{
				double oxygenExtracted = depot->extract_oxygen();
				amount_oxygen = amount_oxygen + oxygenExtracted;
				std::cout << display_code << id_num << ": got " << oxygenExtracted << " oxygen." << std::endl;
				state = 's';

				return true;

				break;
			}
		case 'i':
			{
				if (amount_oxygen <= 0){
					state = 'x';
					return true;
				}
				else if ( Person::update_location() ) {
					state = 'd';
					amount_moonstones++;
					amount_oxygen--;
					return true;
				}
				else {
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}

				break;
			}
		case 'd':
			{
				std::cout << display_code << id_num << ": Deposit " << amount_moonstones << " of moonstones." << std::endl;
				home->deposit_moonstones(amount_moonstones);
				amount_moonstones = 0;
				state = 's';

				return true;

				break;
			}
		case 'r': // The state of moving to a Medic station 
			{
				if (amount_oxygen <= 0){
					state = 'x';
					return true;
				}
				else if ( Person::update_location() ) {
					state = 'h';
					amount_moonstones++;
					amount_oxygen--;
					return true;
				}
				else {
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}

				break;
			}
		case 'h': // the state of healing at a medic station. 
			{
				if ( heal() ) {
					std::cout << display_code << id_num << ": Traded 5 moonstones and got full health." << std::endl;
					display_code_case_raise();
				}
				else {
					std::cout << display_code << id_num << ": Did not have enough moonstones to get healed." << std::endl;
				}

				state = 's';

				return true;

				break;
			}
		case 'l': 
			{
				if ( ( amount_oxygen <= 0 || state == 'x' ) && this->home == NULL){
					std::cout << display_code << id_num << " is dead and cant move." << std::endl;

					return false;
				}
				else if ( (home->get_location()).x != (get_location()).x && (home->get_location()).y != (get_location()).y && (amount_oxygen <= 0 || state == 'x')) {
					std::cout << display_code << id_num << " is dead and cant move." << std::endl;

					return false;
				}
				else if ( (Game_Object::get_location()).x != (home->get_location()).x || (Game_Object::get_location()).y != (home->get_location()).y ) {

					if ( Person::update_location() && amount_oxygen > 0 ) {
						std::cout << display_code << id_num << ": I'm there!" << std::endl;
						home->add_astronaut();
					}
					else {
						amount_oxygen--;
						//std::cout << display_code << id_num << ": step..." << std::endl;
					}
					return false;
				}
				else if ( (home->get_location()).x == (get_location()).x && (home->get_location()).y == (get_location()).y && amount_oxygen > 0) {

					if ( home->get_astronauts() != 0){
						Cart_Point location2 = get_location();
						if ( (location2.x != location1.x) || (location2.y != location1.y) ) {
							home->add_astronaut();
							return true;
						}
						else {
							return false;
						}

					}
					else if( (Game_Object::get_location()).x == location1.x && (Game_Object::get_location()).y == location1.y && home->get_astronauts() == 0) {
						home->add_astronaut();
					}
					else {
						home->add_astronaut();
						amount_moonstones++;
						amount_oxygen--;
					}


					return false;
				}
				else if	( (home->get_location()).x == (get_location()).x && (home->get_location()).y == (get_location()).y ) {

					return false;
				}
				else {
					return false;
				}



				break;
			}
		default:
			{
				return false;
				break;
			}
	}
}



void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
	if (state == 'l') {
		std::cout << "Object Is Locked." << std::endl;
	}
	else if ( state == 'x' ) {
		std::cout << "Astronaut is dead." << std::endl;
	}
	else {
		Person::setup_destination(inputDepot->get_location());

		depot = inputDepot;

		state = 'o';

		std::cout << "Astronaut (" << id_num << ") supplying from Oxygen_Depot (" << inputDepot->get_id() << ")." << std::endl;
		std::cout << display_code << id_num << ": Yes, my lord." << std::endl;
	}
	return;
}



void Astronaut::start_depositing(Space_Station* inputStation)
{
	if (state == 'l'){
		std::cout << "Object Is Locked." << std::endl;
	}
	else if ( state == 'x' ) {
		std::cout << "Astronaut is dead." << std::endl;
	}
	else {
		Person::setup_destination(inputStation->get_location());

		home = inputStation;

		state = 'i';

		std::cout << "Astronaut (" << id_num << ") depositing to Space_Station (" << inputStation->get_id() << ")." << std::endl;
		std::cout << display_code << id_num << ": Yes, my lord." << std::endl;
	}
	return;
}



void Astronaut::go_to_station(Space_Station* inputStation)
{

	if( state == 'l' ){
		std::cout << "Object Is Locked." << std::endl;
	}
	else if ( state == 'x' ) {
		std::cout << "Astronaut is dead." << std::endl;
	}
	else if ( inputStation->get_state() != 'u' ) {
		std::cout << "Station not yet upgraded." << std::endl;
	}
	else {
		std::cout << "Astronaut " << id_num << " locking in at Space_Station " << inputStation->get_id() << std::endl;
		
		state = 'l';

		home = inputStation;

		if ((home->get_location()).x != (get_location()).x && (home->get_location()).y != (get_location()).y) {
			Person::setup_destination(home->get_location());
		}
	}

	return;
}

void Astronaut::show_status()
{
	std::cout << "Astronaut status: ";
	Person::show_status();

	switch ( state ){

		case 's':
			{
				std::cout << " with " << amount_oxygen << " oxygen and " 
							<< amount_moonstones << " moon stones." << std::endl;

				break;
			}
		case 'm':
			{
				std::cout << " with " << amount_oxygen << " oxygen and " 
							<< amount_moonstones << " moon stones." << std::endl;
				break;
			}
		case 'o':
			{
				std::cout << " is outbound to a depot with " << amount_oxygen << " oxygen and " 
							<< amount_moonstones << " moon stones." << std::endl;

				break;
			}
		case 'g':
			{
				std::cout << " Getting oxygen from Depot." << std::endl;

				break;
			}
		case 'i':
			{
				std::cout << " is inbound to home with load: " << amount_moonstones 
							<< " moon stones and " << amount_oxygen << " oxygen." << std::endl;

				break;
			}
		case 'd':
			{
				std::cout << " Depositing " << amount_moonstones << " moon stones." << std::endl;

				break;
			}
		case 'r':
			{
				std::cout << " is heading to medic with " << amount_oxygen << " oxygen and " 
							<< amount_moonstones << " moon stones." << std::endl;

				break;
			}
		case 'h':
			{
				std::cout << " Healing at Medic Station." << std::endl;

				break;
			}
		case 'x':
			{
				//doesnt need anything here

				break;
			}
		case 'l':
			{

				
				if (amount_oxygen <= 0 && this->depot == NULL) {
					std::cout << " and is out of oxygen." <<std::endl;

					return;
				}
				else if (amount_oxygen <= 0 ){
					std::cout << " and is out of oxygen." <<std::endl;

					return;
				}
				else if ( (home->get_location()).x == (get_location()).x && (home->get_location()).y == (get_location()).y ) {
					std::cout << " at Space_Station(" << home->get_id() << ")" << std::endl;

					return;
				}
				else {
					std::cout << " and is moving to Space_Station(" << home->get_id() << ")" << std::endl;
					
					return;
				}


				break;
			}
		default:
			{
				break;
			}
	}

		




	return;
}

//added for medic statioin.
bool Astronaut::heal()
{
	if (amount_moonstones >= 5){
		amount_moonstones -= 5;
		health = 5;

		return true;
	}
	else {
		return false;
	}

}

void Astronaut::go_to_medic(Medic_Station* inputMedic)
{
	if( state == 'l' ){
		std::cout << "Object Is Locked." << std::endl;
	}
	else if ( state == 'x' ) {
		std::cout << "Astronaut is dead." << std::endl;
	}
	else {
		Person::setup_destination(inputMedic->get_location());
		medic = inputMedic;

		state = 'r';

		std::cout << "Astronaut (" << id_num << ") healing at Medic_Station (" << inputMedic->get_id() << ")." << std::endl;
		std::cout << display_code << id_num << ": Yes, my lord." << std::endl;

	}


	return;
}




/*		QUESTIONS:
	





*/





