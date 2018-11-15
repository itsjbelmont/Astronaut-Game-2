#include <iostream>
#include "Game_Object.h"

Game_Object::Game_Object(char in_code)
{
	display_code = in_code;
	id_num = 1;
	state = 's';

	std::cout << "Game_Object constructed." << std::endl;
	return;
}

Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	state = 's';

	std::cout << "Game_Object constructed." << std::endl;
	return;
}

Game_Object::~Game_Object()
{
	std::cout << "Game_Object destructed." << std::endl;

	return;
}

Cart_Point Game_Object::get_location()
{
	return location;
}

int Game_Object::get_id()
{
	return id_num;
}

char Game_Object::get_state()
{
	return state;
}

char Game_Object::get_display_code()
{
	return display_code;
}

void Game_Object::show_status()
{
	std::cout << display_code << id_num << " at " << location;
	return;
}

bool Game_Object::is_alive()
{
	return true;
}

void Game_Object::display_code_case_lower()
{
	display_code = tolower(display_code);
	return;
}

void Game_Object::display_code_case_raise()
{
	display_code = toupper(display_code);
	return;
}

void Game_Object::drawself(char* ptr)
{
	*ptr = display_code;

	char id_char = '0' + id_num;

	*(ptr + 1) = id_char;


	return;
}














