#ifndef _COMPLEX_H
#define _COMPLEX_H
typedef struct{
    double Re;
    double Im;
} Complex;

Complex COMPLEXinit(double, double);

double Re(Complex);

double Im(Complex);

Complex COMPLEXmult(Complex, Complex);
#endif