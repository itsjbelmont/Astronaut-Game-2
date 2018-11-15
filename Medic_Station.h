#ifndef MEDIC_STATION_H
#define MEDIC_STATION_H


#include "Game_Object.h"
#include "Cart_Point.h"


//There will be one medic station on the map that an astronaut can go to 
//and trade 10 moonstones to get their health back up to 5(max health)
class Medic_Station: public Game_Object
{
public:
	Medic_Station();
	Medic_Station(Cart_Point inputLoc, int inputID);
	~Medic_Station();

	void show_status();

	bool update(); //always returns false. nothing changes in this class





};









#endif
