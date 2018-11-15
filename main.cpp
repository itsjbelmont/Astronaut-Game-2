#include <iostream>
#include <stdlib.h>

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include "Alien.h"
#include "Input_Handling.h"

/*
I did extra credit for this PA as follows: 

Change gravity: 
	Gravity has a chance of changing on every step. When gravity changes the amount 
	by which the astronaut speed changes is desplayed in model.show_status();
	Speed can go up or down by 2.

	Model::gravity;
	void Model::change_gravity();
	void Person::change_speed(double gravity);

Computer Controlled Aliens:
	Person* Alien::get_target();
	void Alien::give_new_target(Person* person);
	bool willAttack; in Alien class
	bool Model::computer_attack();
	Cart_Point Astronaut::get_destination();

Personal Addition (Medic Stations):
	Added 1 medic station at (15,15). No extra medic stations can be added.
	An astronaut can trade 5 moonstones for full health at a medic station.
	Healing at a medic station works similarly to depositing at a spacestation
		or working at a depot
	Command for working a medic station is as follows:

			h id1 id2 
						where the id1 is the astronaut id
						where the id2 is the medic station id

	Medic_Station.cpp
	Medic_Station.h

	bool Astronaut::heal();
	void Astronaut::go_to_medic(Medic_Station* inputMedic);

	void do_heal_command(Model& model, int id1, int id2); - in Game_Command
	



***** Please note:  Other member functions in many classes were modified slightly to account
					for the aditions from the extra credit. This includes adding the parameters
					that certain functions must take to run propperly. 

					Other member variables and functions not listed above may also have been added
					in certain places to achieve tasks.


*/

int main()
{
	std::cout << std::endl;
	std::cout << "EC327: Intro to Engineering." << std::endl;
	std::cout << "Jack Belmont" << std::endl;
	std::cout << "Programming Assignement 4" <<std::endl;
	std::cout << "Fall 2017" << std::endl <<std::endl;

//////////////// Check If user wants to contole aliens ////////////////////////////////////
	char mode = ' ';
	while (mode != 'n' && mode != 'c') {
		try
		{
			std::cout << "Would you like to control aliens in mode(n) or" << std::endl;
			std::cout << "would you like the computer to control aliens in mode(c): ";
			std::cin >> mode;
			if ( std::cin.fail() ) {
				std::cin.clear();
				throw Invalid_Input("Could not read the mode.");
			}

			mode = tolower(mode);
			if (mode != 'n' && mode != 'c') {
				throw Invalid_Input("Not a valid mode.");
			}

		}
		catch(Invalid_Input& except){
			std::cin.ignore(1000,'\n');
			std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

		}

	}

	if (mode == 'n') {
		std::cout << "You have entered normal mode." << std::endl << std::endl;
	}
	else if(mode == 'c') {
		std::cout << "You have entered computer mode." << std::endl << std::endl;
	}
	else {
		std::cout << "Something went wrong with the mode selection." << std::endl << std::endl;
		exit(EXIT_SUCCESS);
	}

///////////////////////////////////////////////////////////////////////////////////////////

	
	Model model = Model();
	std::cout << std::endl;
	View view = View();
	model.show_status();
	std::cout << std::endl;
	model.display(view);

	while (true) {
		char command;
		char type;
		int id1;
		int id2;
		double x;
		double y;


		try {
			std::cout << "Enter Command: ";
			std::cin >> command;
			command = tolower(command);
			

			switch ( command ) {

				case 'n':
					{
						std::cin >> type >> id1 >> x >> y;
						if(std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'new' command with invalid formating.");
						}
						model.handle_new_command( type, id1, Cart_Point(x,y) );

						break;
					}
				case 'm':
					{
						std::cin >> id1 >> x >> y;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'move' command with invalid formating.");
						}

						do_move_command(model, mode, id1, x, y);


						break;
					}
				case 'w':
					{
						std::cin >> id1 >> id2;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'work' command with invalid formating.");
						}

						do_work_a_depot_command(model, id1, id2);

						break;
					}
				case 'd':
					{
						std::cin >> id1 >> id2;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'deposit' command with invalid formating.");
						}

						do_deposit_moon_stones_command(model, id1, id2);

						break;
					}
				case 's':
					{
						std::cin >> id1;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'stop' command with invalid formating.");
						}

						do_stop_command(model, mode, id1);

						break;
					}
				case 'l':
					{
						std::cin >> id1 >> id2;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'lock' command with invalid formating.");
						}

						do_lock_in_at_station_command(model, id1, id2);

						break;
					}
				case 'a':
					{
						std::cin >> id1 >> id2;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'attack' command with invalid formating.");
						}

						do_attack_command(model, id1, id2);

						break;
					}
				case 'h':
					{
						std::cin >> id1 >> id2;

						//Error check
						if (std::cin.fail()) {
							std::cin.clear();
							throw Invalid_Input("You entered the 'heal' command with invalid formating.");
						}

						do_heal_command(model, id1, id2);

						break;
					}
				case 'g':
					{
						do_go_command(model, mode);

						model.show_status();

						std::cout << std::endl;
						model.display(view);

						break;
					}
				case 'r':
					{
						do_run_command(model, mode);

						model.show_status();

						std::cout << std::endl;
						model.display(view);

						break;
					}
				case 'q':
					{
						do_quit_command(model);
						break;
					}
				default:
					{
						// std::cin.clear();
						// std::cin.ignore();
						std::cin.ignore(1000,'\n');

						throw Invalid_Input("You have entered an invalid command!");
						break;
					}
			}
		}
		catch(Invalid_Input& except){
			std::cin.ignore(1000,'\n');
			std::cout << "Invalid Input - " << except.msg_ptr << std::endl;

		}

	}



	return 0;
}
