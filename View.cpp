#include <iostream>

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"
#include "Model.h"
#include "View.h"


View::View()
{
	size = 11;

	scale = 2;

	origin = Cart_Point(0,0);

	return;
}

void View::draw()
{
	int yscale = 20;
	for ( int i = size; i > 0; i-- ) {

		if ( i%2 != 0 ) {
			if (yscale < 10){
				std::cout << yscale << " ";
				yscale = yscale - 4;
			}
			else {
				std::cout << yscale;
				yscale = yscale - 4;
			}
		}
		else{
			std::cout << "  ";
		}


		for ( int j = 0; j < size; j++ ) {
			std::cout << grid[i][j][0];
			std::cout << grid[i][j][1];
		}

		std::cout << std::endl;
	}

	std::cout << "  " << 0 << "   " << 4 << "   " << 8 << "   " << 12 << "  "
				<< 16 << "  " << 20 << std::endl;

	return;
}

void View::clear()
{

	for ( int i = 0; i < size + 1; i++ ) {

		for ( int j = 0; j < size; j++ ) {
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';

		}

	}



	return;
}


bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	Cart_Vector cv = location - origin;

	int x = cv.x / scale;
	int y = cv.y / scale;


	ix = x;
	iy = y;

	if ( x >= origin.x && y >= origin.y  &&  x <= ( origin.x + (size -1) ) && y <= ( origin.y + (size -1) ) ) {
		return true;
	}
	else {
		std::cout << "An object is outside the display." << std::endl;
		return false;
	}
}


void View::plot(Game_Object* ptr)
{
	int ix, iy;

	bool valid = get_subscripts(ix, iy, ptr->get_location());

	if ( valid && grid[iy + 1][ix][0] == '.' && ptr->get_state() != 'x' ) {
		ptr -> drawself(grid[iy + 1][ix]);
	}
	else if ( valid && ptr->get_state() != 'x' ) {
		grid[iy + 1][ix][0] = '*';
		grid[iy + 1][ix][1] = ' ';
	}





	return;
}
















/* TO DO
	












*/
