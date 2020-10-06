#include "osztaly.h"
#include <iostream>

/// \file this is sparta

osztaly::osztaly(int data)
{
    szam = data;
}

void osztaly::kiir()
{
    std::cout << szam;
}