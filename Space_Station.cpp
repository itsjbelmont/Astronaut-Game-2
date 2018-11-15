#include <iostream>
#include "Space_Station.h"
#include "Game_Object.h"
#include "Cart_Point.h"

//Default constructor
Space_Station::Space_Station() : Game_Object('s')
{
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;

	std::cout << "Space_Station default constructed." << std::endl;
	return;
}

//Constructor with user input location and id
Space_Station::Space_Station(Cart_Point inputLoc, int inputId) : Game_Object('s')
{
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;

	location = inputLoc;
	id_num = inputId;

	std::cout << "Space_Station constructed." << std::endl;
	return;
}


Space_Station::~Space_Station()
{
	std::cout << "Space_Station destructed." << std::endl;

	return;
}


//Function to add a specified amount of stones to the space station
void Space_Station::deposit_moonstones(double deposit_amount)
{
	amount_moonstones += deposit_amount;
	return;
}


//Function to add a new astronaut to the station
bool Space_Station::add_astronaut()
{
	if (state == 'u') {
		number_astronauts++;
		return true;
	}
	else{
		return false;
	}
}


//Function returns the number of astronauts at the station
int Space_Station::get_astronauts()
{
	return number_astronauts;
}


//Updates the station.
bool Space_Station::update()
{	//Edit this to only return true once for each object.
	if (amount_moonstones >= 10 && state != 'u'){
		state = 'u';
		display_code = 'S';
		std::cout << display_code << id_num << " has been upgraded." << std::endl;

		return true;
	}
	else {
		return false;
	}
}


//Shows the status of the station
void Space_Station::show_status()
{
	std::cout << "Space Station Status: ";
	//calls Game object's show_status
	Game_Object::show_status();
	std::cout << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts.";
	if( state == 'u') {
		std::cout << " Upgraded." << std::endl;
	}
	else {
		std::cout << " Not yet upgraded." << std::endl;
	} 

	return;
}




