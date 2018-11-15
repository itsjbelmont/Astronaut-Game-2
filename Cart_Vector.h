#ifndef CART_VECTOR_H
#define CART_VECTOR_H

class Cart_Vector
{
public:
	double x;
	double y;

	Cart_Vector();
	Cart_Vector(double inputx, double inputy);

};

Cart_Vector operator* (const Cart_Vector &v1, const double &d);

Cart_Vector operator/ (const Cart_Vector &v1, const double &d);

std::ostream& operator<< (std::ostream& out, const Cart_Vector& v);


#endif
