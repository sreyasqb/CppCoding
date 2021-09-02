#include "mycomplex.h"
#include <iostream>
int main()
{
    MyComplex complex1;
    complex1.setValue(3,4);
    std::cout<<complex1.toString();
    
}