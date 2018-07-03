#pragma once
//#include "Vehicle.h"
#include "Car.h"
#include "Motorbike.h"
#include "Van.h"
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Carkparkmanager 
{
private:

	int carCounter;
	int vanCounter;
	int motorCounter;
	int freeparkingslot = 20;
	vector<Vehicle*> parkingSlot;

	Car* carVehicle;
	vector<Car*> vectorCar;
	int carvectorCounter;

	Van* vanVehicle;
	vector<Van*> vectorVan;
	int vanvectorcounter;

	dateTime* date;

	Motorbike* motorBikeVehicle;
	vector <Motorbike*> vectorMotor;
	int motorvectorcounter;
	int day;
	int month;
	int year;
	int hour;
	int minute;

	bool checkfordate;
public:
	Carkparkmanager();
	~Carkparkmanager();

	void displayStatistics();
	void displayVehicleDate();
	void pricecalculation();
	void dateCheck();
	void addvehicle();
	void removevehicle();
	void display();
	void sortVehicles();
	void menu();
	string generateRandom(string num);
	int generateNumber();
	void probability();
};
