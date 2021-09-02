#include <iostream>
#include "mycomplex.h"
using namespace std;
MyComplex::MyComplex()
{
    real=0;
    imag=0;
}
void MyComplex::setReal(double real)
{
    this->real=real;
}
void MyComplex::setImag(double imag)
{
    this->imag=imag;
}
MyComplex::MyComplex(double real,double imag)
{
    this->imag=imag;
    this->real=real;
}
double MyComplex::getReal(double real)
{
    return real;
}
double MyComplex::getImag(double imag)
{
    return imag;
}
void MyComplex::setValue(double real,double imag)
{
    this->real=real;
    this->imag=imag;
}
std::string MyComplex::toString()
{
    return "("+std::to_string(real)+"+"+std::to_string(imag)+"i)";
}
bool MyComplex::isReal()
{
    if (imag==0)
        return true;
    else
        return false;
}
bool MyComplex::isImaginary()
{
    if (real==0)
        return true;
    else
        return false;
}
bool MyComplex::equals(double real,double imag)
{
    if (real==this->real && imag==this->imag)
        return true;
    else
        return false;
}
