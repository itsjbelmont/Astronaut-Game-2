#include <iostream>
#include <cmath>

#include "Cart_Point.h"
#include "Cart_Vector.h"


Cart_Point::Cart_Point()
{
	x = 0;
	y = 0;
	return;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
	return;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
	double deltaX = p2.x - p1.x;
	double deltaY = p2.y - p1.y;

	//Distance: aSquared + bSquared = cSquared
	double aSquared = pow(deltaX, 2);
	double bSquared = pow(deltaY, 2);
	double distance = sqrt(aSquared + bSquared);
	return distance;
}

Cart_Point operator+ (const Cart_Point &p1, const Cart_Point &p2)
{
	Cart_Point returnCP;
	returnCP.x = p1.x + p2.x;
	returnCP.y = p1.y + p2.y;
	return returnCP;
}

Cart_Vector operator- (const Cart_Point &p1, const Cart_Point &p2)
{
	Cart_Vector returnCV;
	returnCV.x = p1.x - p2.x;
	returnCV.y = p1.y - p2.y;
	return returnCV;
}

std::ostream& operator<< (std::ostream& out, const Cart_Point& p)
{
out << "(" << p.x << ", " << p.y << ")";
return out;
}









