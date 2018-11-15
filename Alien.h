#ifndef ALIEN_H
#define ALIEN_H

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"

//added willAttack for use when computer is controling the aliens.
//added get_target() and give_new_target for use when computer is controling the aliens.

class Alien : public Game_Object
{
private:
	int attack_strength;
	double range;
	Person* target;
	double speed;
	Cart_Point destination;
	Cart_Vector delta;

public:
	Alien();
	Alien(int in_id, Cart_Point in_loc);
	virtual ~Alien();

	//Returns the target for use in computer controlled aliens
	Person* get_target();
	//Gives a new target but doesnt do anything with it. for use in computer controlled aliens.
	void give_new_target(Person* person);

	void start_attack(Person* in_target);
	void show_status();
	bool update();

	void start_moving(Cart_Point dest);
	void stop();

	bool willAttack;

protected:
	bool update_location();
	void setup_destination(Cart_Point dest);










};











#endif
