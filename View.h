#ifndef VIEW_H
#define VIEW_H

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"
#include "Model.h"
const int view_maxsize = 20;

class View 
{
public:
	int size;
	double scale;
	Cart_Point origin;
	char grid[view_maxsize][view_maxsize][2];

	bool get_subscripts(int &ix, int &iy, Cart_Point location);

public:
	View();
	void clear();
	void plot(Game_Object* ptr);
	void draw();





};








#endif
