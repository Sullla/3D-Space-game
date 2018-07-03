#pragma once
#define VAN_H
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Van : public Vehicle {

private:
	double cargoVolume;
public:
	Van(double cargoVolume, string plateid, string vehiclebrand, string vehicletype, dateTime* date);
	~Van();
	double getcargovolume();
	string getDescription();

};