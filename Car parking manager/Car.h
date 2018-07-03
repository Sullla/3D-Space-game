#pragma once

#define CAR_H

#include <iostream>
#include "Vehicle.h"
#include <string>

using namespace std;

class Car :public Vehicle {

private:
	int numofdoors;
	string color;
public:
	Car(int numofdoors, string color, string plateID, string vehiclebrand, string vehicletype, dateTime* date);
	~Car();
	int getnumofdoors();
	string getcolor();
	string getdescription();  
};


