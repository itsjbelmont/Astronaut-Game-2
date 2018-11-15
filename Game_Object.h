#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Cart_Point.h"

class Game_Object
{
protected:
	Cart_Point location;
	int id_num;
	char display_code;
	char state;


public:
	Game_Object(char in_code);
	Game_Object(Cart_Point in_loc, int in_id, char in_code);
	virtual ~Game_Object();

	virtual bool update() = 0;
	virtual void show_status();
	bool is_alive();

	Cart_Point get_location();
	int get_id();
	char get_state();
	char get_display_code();
	void drawself(char* ptr);

	void display_code_case_lower();
	void display_code_case_raise();

};






#endif
