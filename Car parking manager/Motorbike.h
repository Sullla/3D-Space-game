#pragma once
#define MOTORBIKE_H
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Motorbike : public Vehicle {

private:
	string engineSize;
public:
	Motorbike(string engineSize, string plateid, string vehiclebrand, string vehicletype, dateTime* date);
	~Motorbike();

	string getEngineSize();

	string getDescription();

};