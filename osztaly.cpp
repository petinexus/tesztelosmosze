#include "osztaly.h"
#include <iostream>

osztaly::osztaly(int data)
{
    szam = data;
}

void osztaly::kiir()
{
    std::cout << szam;
}