#include "Vehicle.h"
#include <string>

Vehicle::Vehicle(string plateID, string vehiclebrand, string vehicletype, dateTime* date, string color, int numberofdoors, int cargovolume,string enginesize) {
	this->plateID = plateID;
	this->vehiclebrand = vehiclebrand;
	this->date = date;
	this->vehicletype = vehicletype;
	this->color = color;
	this->numberofdoors = numberofdoors;
	this->cargovolume = cargovolume;
	this->enginesize = enginesize;

}

string Vehicle::getplateID() {
	return plateID;
}
string Vehicle::getvehiclebrand()
{
	return vehiclebrand;
}

dateTime* Vehicle::getDate()
{
	return date;
}

string Vehicle::toString()
{

	string stringDay = to_string(date->getday())
	 , stringMonth = to_string(date->getmonth())
	 , stringYear = to_string(date->getyear())
	 , stringHour = to_string(date->gethour())
	 , stringMinute = to_string(date->getminutes());

	if (date->getday() < 10)
	{
		stringDay = "0" + stringDay;
	}
	if (date->getmonth() < 10)
	{
		stringMonth = "0" + stringMonth;
	}
	if (date->getyear() < 10)
	{
		stringYear = "0" + stringYear;
	}
	if (date->gethour() < 10)
	{
		stringHour = "0" + stringHour;
	}
	if (date->getminutes() < 10)
	{
		stringMinute = "0" + stringMinute;
	}

	return stringDay + "/ " + stringMonth + "/ " + stringYear + "  " + stringHour + ":" + stringMinute;
}

string Vehicle::getTypeOfVehicle()
{
	return vehicletype;
}


string Vehicle::getcolor() 
{
	return color;

}
int Vehicle::getnumofdoors() 
{
	return numberofdoors;;
}
int Vehicle::cargovoluem() 
{
	return cargovolume;
}
string Vehicle::getenginesize() 
{
	return enginesize;
}

