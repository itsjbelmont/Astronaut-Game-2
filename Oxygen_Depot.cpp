#include <iostream>
#include "Oxygen_Depot.h"
#include "Game_Object.h"
#include "Cart_Point.h"

//Default constructor for Oxygen_Depot - is a child of Game_Object
Oxygen_Depot::Oxygen_Depot() : Game_Object('O')
{
	//display_code = 'O' done with the Game_Object('O') call above. also sets other Game_Object variables
	state = 'f';
	amount_oxygen = 50;
	//location = Cart_Point();

	std::cout << "Oxygen_Depot default constructed." << std::endl;
	return;
}


//Constructor with specified input
Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId) : Game_Object('O')
{
	//display_code = 'O';
	state = 'f';
	amount_oxygen = 50;

	id_num = inputId;

	location = inputLoc;

	std::cout << "Oxygen_Depot constructed." << std::endl;
	return;
}


Oxygen_Depot::~Oxygen_Depot()
{
	std::cout << "Oxygen_Depot destructed." << std::endl;

	return;
}


//checks if Oxygen_Depot is empty
bool Oxygen_Depot::is_empty()
{
	if (amount_oxygen == 0)
		return true;
	else
		return false;
}


//updates the Oxygen_Depot
bool Oxygen_Depot::update()
{
	if (amount_oxygen == 0 && state != 'e'){
		state = 'e';
		display_code = 'o';
		std::cout << "Oxygen_Depot (" << id_num << ") has been depleted." << std::endl;
		return true;
	}
	else {
		return false;
	}
	
}

//Extracts Oxygen from the Oxygen_Depot
double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
	if (amount_oxygen >= amount_to_extract){
		amount_oxygen = amount_oxygen - amount_to_extract;
		return amount_to_extract;
	}
	else {
		double current_ammount = amount_oxygen;
		amount_oxygen = 0;
		return current_ammount;
	}

}

//Shows the status of the Oxygen_Depot
void Oxygen_Depot::show_status()
{
	std::cout << "Oxygen Depot status: ";
	Game_Object::show_status();
	std::cout << " contains " << amount_oxygen << std::endl;
}









