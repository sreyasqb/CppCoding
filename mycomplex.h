#include <stdio.h>
#include <string>
class MyComplex
{
    private:
        double real;
        double imag;
    public:
        MyComplex();
        MyComplex(double real,double imag);
        double getReal(double real);
        double getImag(double imag);
        void setReal(double real);
        void setImag(double imag);
        void setValue(double real,double imag);
        std::string toString();
        bool isReal();
        bool isImaginary();
        bool equals(double real,double imag);
};

//a