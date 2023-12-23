#include "Koichi_Nakata_Die.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Comment 5: when a Die object is created, it takes the number of the sides, and initially rolls a die, which will be stored in attribute "value". 
Die::Die(int num) { setSides(num); }

void Die::setSides(int num) {
  numSides = num;
  roll();
}

void Die::roll() { value = rand() % numSides + 1; }

// Comment 6: these are just an accessor, so we should put const keyword just in case.
unsigned int Die::getSides() const { return numSides; }

unsigned int Die::getValue() const { return value; }
