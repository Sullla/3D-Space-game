#include "Motorbike.h"
#include <string>

Motorbike::Motorbike(string engineSize, string plateid, string vehiclebrand, string vehicletype, dateTime* date) :Vehicle(plateid, vehiclebrand, vehicletype, date, "", 0, 0, engineSize)
{
	
	this->engineSize = engineSize;
}

Motorbike::~Motorbike() {
	cout << " Motorbike was removed " << endl;
}

string Motorbike::getEngineSize()
{
	return engineSize;
}

string Motorbike::getDescription()
{
	return " Motorbike brand is: " + vehiclebrand + "\n PLate ID: " + plateID +
		"\n Engine size:" + engineSize;
}

