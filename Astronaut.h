#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Medic_Station.h"

//Stuff edited for Personal addition (Medic_Station), Gravity change, and Computer controlled aliens.

class Astronaut: public Person
{
public:
	Astronaut();
	Astronaut(int in_id, Cart_Point in_loc);
	~Astronaut();

	bool update();
	void start_supplying(Oxygen_Depot* inputDepot);
	void start_depositing(Space_Station* inputStation);
	void go_to_station(Space_Station* inputStation);
	void show_status();

	//added for the medic station.
	bool heal();
	void go_to_medic(Medic_Station* inputMedic);



private:
	double amount_moonstones;
	double amount_oxygen;
	Oxygen_Depot* depot;
	Space_Station* home;
	Medic_Station* medic;


};





#endif
