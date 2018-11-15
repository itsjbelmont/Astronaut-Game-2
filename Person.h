#ifndef PERSON_H
#define PERSON_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Medic_Station.h"

//added get_destination to be used in the Model::computer_attack function for when the computer is controling the aliens.

class Person: public Game_Object
{
	//accessed anywhere
public:
	Person();
	Person(char in_code);
	Person(Cart_Point in_loc, int in_id, char in_code);
	virtual ~Person();

	void start_moving(Cart_Point dest);
	void stop();
	void show_status();
	int get_health();

	void take_hit( int attack_strength );
	bool is_alive();

	//added for computer determined attacks.
	Cart_Point get_destination();

	//added for the gravity changing
	void change_speed(double gravity);



//Added from page 17
	virtual void start_supplying(Oxygen_Depot* inputDepot);
	virtual void start_depositing(Space_Station* inputStation);
	virtual void go_to_station(Space_Station* inputStation);
	virtual void go_to_medic(Medic_Station* inputMedic);

	//accessed by class or by children class
protected:
	int health;
	bool update_location();
	void setup_destination(Cart_Point dest);


	//accessed by class only
private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;

};







#endif
