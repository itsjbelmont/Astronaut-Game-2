#include <iostream>
#include <cmath>

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"
#include "Alien.h"

Alien::Alien() : Game_Object('X')
{
	attack_strength = 2;
	range = 2.0;
	speed = 5;

	willAttack = false;

	target = NULL;

	std::cout << "Alien constructed." <<std::endl;

	return;
}


Alien::Alien(int in_id, Cart_Point in_loc) : Game_Object(in_loc, in_id, 'X')
{
	attack_strength = 2;
	range = 2.0;
	speed = 5;

	willAttack = false;

	target = NULL;

	std::cout << "Alien constructed." <<std::endl;

	return;
}


Alien::~Alien()
{
	std::cout << "Alien Destructed." << std::endl;

	return;
}


void Alien::start_moving(Cart_Point dest)
{

		//determines delta value and sets the destination
		Alien::setup_destination(dest);

		//person is moving
		state = 'm';

		//output information.
		std::cout << "Moving " << display_code << id_num << " to " << destination << "." << std::endl;
		//std::cout << display_code << id_num << ": On my way." << std::endl;


	return;
}


void Alien::setup_destination(Cart_Point dest)
{
		destination = dest;
		delta = (destination - location) * (speed / cart_distance(destination, location));

	return;
}


bool Alien::update_location()
{
	double deltaX = fabs(destination.x - location.x);
	double deltaY = fabs(destination.y - location.y);

	if(deltaX <= fabs(delta.x) && deltaY <= fabs(delta.y))
	{
		location = destination;

		if (state == 'l'){
			//Just dont do anything
		} 
		else {
			std::cout << display_code << id_num << ": I'm there!" << std::endl;
		}

		return true;
	}
	else {
		location = location + Cart_Point(delta.x, delta.y);
		std::cout << display_code << id_num << ": step..." << std::endl;
		return false;
	}

}


void Alien::stop()
{
	state = 's';
	std::cout << "Stopping " << id_num << "." << std::endl;
	std::cout << display_code << id_num << ": All Right." << std::endl;
	if (willAttack) {
		willAttack = false;
	}

	return;
}


void Alien::start_attack(Person* in_target)
{
	Cart_Point target_loc = in_target -> get_location();
	double a_squared = pow( fabs(target_loc.x - location.x), 2 );
	double b_squared = pow( fabs(target_loc.y - location.y), 2 );

	double dist_between = sqrt(a_squared + b_squared);

	if ( dist_between <= 2 ) {
		std::cout << "Smash!" << std::endl;
		target = in_target;
		state = 'a';
	}
	else {
		std::cout << "Target is out of range." << std::endl;
		if (willAttack) {
			willAttack = false;
		}
	}



	return;
}


bool Alien::update()
{
	switch ( state ) {
		case 's' :
			{
				return false;
				break;
			}
		case 'm' :
			{
				if ( update_location() ) {
					state = 's';
					return true;
				}
				else {
					return false;
				}
				break;
			}
		case 'a' :
			{
				Cart_Point target_loc = target -> get_location();
				double a_squared = pow( fabs(target_loc.x - location.x), 2 );
				double b_squared = pow( fabs(target_loc.y - location.y), 2 );

				double dist_between = sqrt(a_squared + b_squared);

				if ( target -> get_state() == 'l' ) {
					std::cout << "Target locked at a station." << std::endl;
					state = 's';

					if (willAttack) {
						willAttack = false;
					}

					return true;
				}
				else if ( dist_between > 2 ) {
					std::cout << display_code << id_num << ": Target Astronaut is out of range." << std::endl;
					if (willAttack) {
						willAttack = false;
					}
					state = 's';
					return true;
				}
				else if ( dist_between <= 2 && !target->is_alive() ) {
					std::cout << display_code << id_num << ": I triumph!" << std::endl;
					if (willAttack) {
						willAttack = false;
					}
					state = 's';
					return true;
				}
				else if ( dist_between <= 2 && target->get_state() != 'x' ) {
					std::cout << display_code << id_num << ": Take that!" << std::endl;
					target->take_hit( attack_strength ); 
					return true;
				}
				else {
					return false;
				}



				return false; ////////////////

				break;
			}
		default :
			{
				return false;
				break;
			}

	}

}

void Alien::show_status()
{
	std::cout << "Alien Status: ";
	Game_Object::show_status();

	switch ( state ) {
		case 's' :
			{
				std::cout << " is stopped." <<std::endl;
				break;
			}
		case 'm' :
			{
				std::cout << " is moving at speed " << speed << " towards " 
							<< destination << std::endl;

				break;
			}
		case 'a' :
			{
				std::cout << " attacking astronaut A" << target->get_id() << std::endl;

				break;
			}
		default :
			{
				std::cout <<": Apears to be doing something strange." << std::endl;
				return;
				break;
			}

	}

	return;
}


Person* Alien::get_target() 
{
	return target;
}

void Alien::give_new_target(Person* person)
{
	target = person;
	return;
}




















