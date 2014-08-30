#include "COMPLEX.h"


Complex COMPLEXinit(double r, double i)
{
    Complex c;
    c.Re = r;
    c.Im = i;
    return c;
}

double Re(Complex c)
{
    return c.Re;
}

double Im(Complex c)
{
    return c.Im;
}

Complex COMPLEXmult(Complex a, Complex b)
{
    Complex c;
    c.Re = a.Re * b.Re;
    c.Im =(-1) * a.Im * b.Im;
    return c;
}