#include <iostream>

#include "Game_Object.h"
#include "Cart_Point.h"
#include "Medic_Station.h"

Medic_Station::Medic_Station() : Game_Object('M')
{
	std::cout << "Medic_Station constructed." << std::endl;
	return;
}

Medic_Station::Medic_Station(Cart_Point inputLoc, int inputID) : Game_Object(inputLoc, inputID, 'M')
{
	std::cout << "Medic_Station constructed." << std::endl;
	return;
}

Medic_Station::~Medic_Station()
{
	std::cout << "Medic_Station destructed." << std::endl;
	return;
}

bool Medic_Station::update()
{
	return false;
}

void Medic_Station::show_status()
{
	std::cout << "Medic Station Status: ";
	Game_Object::show_status();
	std::cout << std::endl;

	return;
}















