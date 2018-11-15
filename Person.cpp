#include <iostream>
#include <cmath>
#include <stdlib.h>

#include "Person.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Medic_Station.h"

//Default constructor for person
Person::Person() : Game_Object(' ') //Might be wrong argument to pass to Game_Object
{
	speed = 5;
	health = 5;
	std::cout << "Person default constructed." << std::endl;

	return;
}


//Constructor for person with only a display_code passed
Person::Person(char in_code) : Game_Object(in_code)
{
	speed = 5;
	health = 5;
	state = 's';

	std::cout << "Person constructed." << std::endl;

	return;
}


//Constructor for person with location, id_num, and display_code
Person::Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc, in_id, in_code)
{
	speed = 5;
	health = 5;

	std::cout << "Person constructed." << std::endl;

	return;
}


Person::~Person()
{
	std::cout << "Person destructed." << std::endl;

	return;
}


//tells the person to start moving.
void Person::start_moving(Cart_Point dest)
{
	if (state == 'l') {
		std::cout << "Object Is Locked." << std::endl;
	}
	else if ( state == 'x' ) {
		std::cout << "Astronaut is dead." << std::endl;
	}
	else {
		//determines delta value and sets the destination
		Person::setup_destination(dest);

		//person is moving
		state = 'm';

		//output information.
		std::cout << "Moving " << display_code << id_num << " to " << destination << "." << std::endl;
		std::cout << display_code << id_num << ": On my way." << std::endl;
	}

	


	return;
}


//Sets up the object to start moving to destination
void Person::setup_destination(Cart_Point dest)
{
	//if (state != 'l'){
		destination = dest;
		delta = (destination - location) * (speed / cart_distance(destination, location));
	//}

	return;
}


//Tells the person to stop moving or collecting oxygen.
void Person::stop()
{
	if ( state == 'x' ) {
		std::cout << "This Person is dead." << std::endl;
	}
	else if ( state == 'l' ) {
		std::cout << "This person is locked." << std::endl;
	}
	else if ( state == 's' ) {
		std::cout << "This person is already stopped." << std::endl;
	}
	else {
		state = 's';
		std::cout << "Stopping " << id_num << "." << std::endl;
		std::cout << display_code << id_num << ": All Right." << std::endl;
	}

	return;
}


//Updates person's location and determines if it has reached its destination.
bool Person::update_location()
{
	double deltaX = abs(destination.x - location.x);
	double deltaY = abs(destination.y - location.y);

	if(deltaX <= abs(delta.x) && deltaY <= abs(delta.y))
	{

		if ( state == 'l') {
			location = destination;
			return true;
		} 
		else if (state == 'x') {
			return true;
		}
		else {
			std::cout << display_code << id_num << ": I'm there!" << std::endl;
		}

		location = destination;

		return true;
	}
	else {
		location = location + Cart_Point(delta.x, delta.y);
		std::cout << display_code << id_num << ": step..." << std::endl;
		return false;
	}

}


//Shows the status of the person
void Person::show_status()
{
	Game_Object::show_status();

	if (state == 's') {
		std::cout << " with " << health << " health is stopped";
	}
	else if (state == 'l') {
		std::cout << " with " << health << " health is locked";
	}
	else if (state == 'x') {
		std::cout << " is dead." << std::endl;
	}

//state 'r' means the astronaut is heading to the medic station.
	if (state == 'm' || state == 'o' || state == 'i' || state == 'r') {
		std::cout << " with " << health << " health is moving at speed of " << speed << " towards " << destination << " at each step of " << delta;
	}


	

	

	return;
}


void Person::take_hit( int attack_strength )
{
	if (state != 'x') {
		health = health - attack_strength;

		if ( health <= 0 ) {
			std::cout << display_code << id_num << ": Gasp! Im dying..." << std::endl;
			state = 'x';
		}

		else {
			std::cout << display_code << id_num << ": Ouch!" << std::endl;
		}

	}
	else {
		std::cout << display_code << id_num << ": Already dead." << std::endl;
	}
	
	

	return;
}

int Person::get_health()
{
	return health;
}


bool Person::is_alive()
{
	if ( state != 'x' ){
		return true;
	}
	else {
		return false;
	}

}


Cart_Point Person::get_destination()
{
	return destination;
}



void Person::change_speed(double gravity)
{
	//Standard gravity is 0 -> speed = 5
	//gravity is -2 -> speed = 3
	//gravity is 2 -> speed = 7
	if (gravity + 5 != speed && (gravity == -2 || gravity == 0 || gravity == 2)) {
		speed = gravity + 5;
		setup_destination(destination);
	}

	return;
}




//Virtual functions
void Person::start_supplying(Oxygen_Depot* inputDepot)
{
	std::cout << "Sorry, I cant work a depot." << std::endl;
	return;
}


void Person::start_depositing(Space_Station* inputStation)
{
	std::cout << "Sorry, I cant work a station." << std::endl;
	return;
}


void Person::go_to_station(Space_Station* inputStation)
{
	std::cout << "Sorry, I cant lock into a station." << std::endl;
	return;
}

void Person::go_to_medic(Medic_Station* inputMedic)
{
	std::cout << "Sorry, I cont get healed." << std::endl;
	return;
}
















