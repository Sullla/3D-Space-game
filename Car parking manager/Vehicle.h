#pragma once
#define  VEHICLE_H
#include <iostream>
#include "dateTime.h"

using namespace std;

class Vehicle {
public:
	string plateID;
	string vehiclebrand;
	string vehicletype;
	dateTime* date;

	string color;
	int numberofdoors;
	int cargovolume;
	string enginesize;


public:
	Vehicle(string plateid, string vehiclebrand, string vehicletype, dateTime* date, string color, int numberofdoor,int  cargovolume, string enginesize);
	string getTypeOfVehicle();
	string getplateID();
	string getvehiclebrand();
	dateTime* getDate();
	string toString();

	string getcolor();
	int getnumofdoors();
	int cargovoluem();
	string getenginesize();

};


