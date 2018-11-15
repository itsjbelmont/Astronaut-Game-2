#include <iostream>
#include "Cart_Vector.h"

Cart_Vector::Cart_Vector()
{
	x = 0;
	y = 0;
	return;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
	return;
}


Cart_Vector operator* (const Cart_Vector &v1, const double &d)
{
	Cart_Vector retVector;
	retVector.x = v1.x * d;
	retVector.y = v1.y * d;
	return retVector;
}


Cart_Vector operator/ (const Cart_Vector &v1, const double &d)
{
	Cart_Vector retVector;
	retVector.x = v1.x / d;
	retVector.y = v1.y / d;
	return retVector;
}

std::ostream& operator<< (std::ostream& out, const Cart_Vector& v)
{
out << "<" << v.x << ", " << v.y << ">";
return out;
}




