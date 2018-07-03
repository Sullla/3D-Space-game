#include "Car.h"


Car::Car(int numofdoors, string color, string plateid, string vehiclebrand, string vehicletype, dateTime* date) :Vehicle(plateid, vehiclebrand, vehicletype, date, color, numofdoors, 0, "")
{
	this->numofdoors = numofdoors;
	this->color = color;
}
Car::~Car() {
	cout << " Car was removed" << endl;
}

int Car::getnumofdoors()
{
	return numofdoors;
}
string Car::getcolor()
{
	return color;
}

string Car::getdescription() {
	return " Car brand is " + vehiclebrand + "\n ID Plate: " + plateID + "\n Number of Doors "
		+ to_string(numofdoors) + "\n Color: " + color;
}



