#include "Van.h"
#include <string>

Van::Van(double cargoVolume, string plateID, string vehiclebrand, string vehicletype, dateTime* date) :Vehicle(plateID, vehiclebrand, vehicletype, date,"",0, cargoVolume, "")
{
	this->cargoVolume = cargoVolume;
	this->plateID = plateID;
}
Van::~Van() {
	cout << " Van was removed " << endl;
}
double Van::getcargovolume()
{
	return cargoVolume;
}
string Van::getDescription() {
	return " Van brand is " + vehiclebrand + "\n idPlate: " + plateID +
		"\n Cargo Volume : " + to_string(cargoVolume);
}

