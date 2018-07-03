#include "CarParkManager.h"

void Carkparkmanager::menu()
{
	cout << " " << endl;
	cout << " " << endl;
	cout << "\t|||||||CAR PARKING MANAGER|||||||" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

	char command = ' ';

	
	do{
		cout << endl;
		cout << "\t---Type A to add a vehicle---"<< endl;
		cout << "\t---Type D to display parked vehicles---" << endl;
		cout << "\t---Type R to remove a vehicle---" << endl;
		cout << "\t---Type S to display statistics of vehicles---" << endl;
		cout << "\t---Type T to find a vehicle by a its date---" << endl;
		cout << "\t---Type C for a price calculation---" << endl;
		cout << "\t---Type P for probability calculation---" << endl;
		cout << "\t---Type E to end the program" << endl;
		cin >> command;

		switch (command) 
		{
		case 'a':
			cout << "Enter new vehicle details..." << endl;
			addvehicle();
			cout << " " << endl;
			break;

		case 'd':
			cout << " Displaying available vehicle details..." << endl;
			display();
			cout << " " << endl;
			break;

		case 'r':
			 cout << "Type detailsl in order to remove a vehicle..." << endl;
			removevehicle();
			cout << " " << endl;
			break;
		case 's' :
			cout << "Displaying a statistics for vehicles" << endl;
			displayStatistics();
			cout << " " << endl;
			break;
		case 't':
			cout << "Displaying the date of a vehicle..." << endl;
			displayVehicleDate();
			cout << " " << endl;
			break;
		case 'c':
			cout << "Calculating prices.." << endl;
			pricecalculation();
			break;
		case 'p':
			cout << "Probability" << endl;
			probability();
			cout << " " << endl;
			break;
		
		}

	} while (command != 'e');
}
Carkparkmanager::Carkparkmanager() {}
Carkparkmanager::~Carkparkmanager() {}

void Carkparkmanager::addvehicle() 
{
	string vehiclebrand;
	string plateid;
	double entryTime;
	double volume = 0.0;
	string sizeEngine;
	string vehicletype;
	int numOfdoors=0;
	string color;
	
	if(freeparkingslot > 0)
	{
		int vehicledetail = 0;
		do {
			
			cout << "\n\tPlease choose type of vehicle"<< endl;
			cout << "\t Type 1 for a Car" << endl;
			cout << "\t Type 2 for a Van/Truck" << endl;
			cout << "\t Type 3 for a Motorcycle" << endl;
			cout << "\t Type 0 to Exit" << endl;
			
			if (freeparkingslot <= 0) 
			{
				vehicledetail = 0;
			}
			else 
			{
				cin >> vehicledetail;

			}
			
			switch (vehicledetail) 
			{
			case 1:
				cout << "--Type details for the car--" << endl;
				cout << "" << endl;
				cout << "" << endl;
				vehicletype = "Car";
				carCounter++;
				
			
				numOfdoors = rand() % 5;
				vehiclebrand = generateRandom("B");
				plateid = generateRandom("I");
				color = generateRandom("C");
				dateCheck();

				date = new dateTime(day, month, year, hour, minute);
				carVehicle = new Car(numOfdoors, color, plateid, vehiclebrand, vehicletype, date);
				
				
				parkingSlot.push_back(carVehicle);
				freeparkingslot--;
				cout << " Free parking slots :" << freeparkingslot << endl;
				cout << " " << endl;
				break;
			case 2:
				cout << "--Type details for the Van/Truck--" << endl;
				cout << "" << endl;

				vehicletype = "Van/Truck";
				vanCounter++;

				volume = ((double)generateNumber() * 10);
				vehiclebrand = generateRandom("B");
				plateid = generateRandom("I");
				
				dateCheck();

				date = new dateTime(day, month, year, hour, minute);

				vanVehicle = new Van(volume, plateid, vehiclebrand, vehicletype, date);

				parkingSlot.push_back(vanVehicle);
				freeparkingslot -= 2;

				cout << "Currently available parking slots:" << freeparkingslot << endl;
				cout << "" <<endl;
				break;

			case 3:
				cout << "--Type details for Motorcycle--" << endl;
				cout << "" << endl;

				vehicletype = "Motorbike";
				motorCounter++;
				sizeEngine = generateRandom("E");
				vehiclebrand = generateRandom("B");
				plateid = generateRandom("I");
				dateCheck();

				date = new dateTime(day, month, year, hour, minute);
			    motorBikeVehicle = new Motorbike(sizeEngine, plateid, vehiclebrand, vehicletype, date);

				
				parkingSlot.push_back(motorBikeVehicle);
				freeparkingslot--;
				cout << " available free lots :" << freeparkingslot << endl;
				cout << " " << endl;
				break;


				
			}

		}while(vehicledetail != 0);
		sortVehicles();
	}
	else 
	{
		cout << "All parkking slots are taken" << endl;
	}
}

void Carkparkmanager::display() 
{

	if (parkingSlot.size() <= 0)
	{
		cout << " All parking slots are free " << endl;
	}
	else
	{
		for (int i = 0; i < parkingSlot.size(); i++)
		{
			if (parkingSlot.at(i)->getTypeOfVehicle() == "Car")
			{
				
				cout << to_string((i + 1)) + ". " + parkingSlot.at(i)->getplateID() + "---" + parkingSlot.at(i)->getcolor() + "---" + parkingSlot.at(i)->getTypeOfVehicle() + "---" + parkingSlot.at(i)->getvehiclebrand() + "---" + parkingSlot.at(i)->toString() + "---Number of Doors:" << parkingSlot.at(i)->numberofdoors << endl;
				

				
			}
			if (parkingSlot.at(i)->getTypeOfVehicle() == "Van/Truck")
			{
				cout << to_string((i + 1)) + ". "  + parkingSlot.at(i)->getplateID() + "---" + parkingSlot.at(i)->getTypeOfVehicle() + "---" + parkingSlot.at(i)->getvehiclebrand() + "---" + parkingSlot.at(i)->toString() + "---Cargo Volume:"  << parkingSlot.at(i)->cargovoluem() <<  endl;
				
			}
			if (parkingSlot.at(i)->getTypeOfVehicle() == "Motorbike")
			{
				cout << to_string((i + 1)) + ". " + parkingSlot.at(i)->getplateID() + "---" + parkingSlot.at(i)->getTypeOfVehicle() + "---" + parkingSlot.at(i)->getvehiclebrand() + "---" + parkingSlot.at(i)->toString() +  "---Engine Size:" << parkingSlot.at(i)->getenginesize() << endl;
				
			}
		}
		cout << "Free parking slots:" << freeparkingslot << endl;
	}

}
void Carkparkmanager::removevehicle() 
{
	int command = 0;;
	int pickID;

	if (parkingSlot.size() > 0) 
	{
		
		do{

			

			cout << "---Type 1 to remove a vehicle--- " << endl;
			cout << "---Type 0 to go back to main menu---" << endl;

			if (parkingSlot.size() <= 0) 
			{
				command = 0;
			}
			else
			{
				cin >> command;
			}

			if (command == 1)
			{
				cout << "---Choose id plate form the list to remove a vehicle please---" << endl;
				for (int r = 0; r<parkingSlot.size(); r++)
				{
					cout << "---" + to_string((r + 1)) + "--" + parkingSlot.at(r)->getplateID() << "---" + parkingSlot.at(r)->getTypeOfVehicle() + "---" << parkingSlot.at(r)->getvehiclebrand() << endl;
				}
				cin >> pickID;

				
				if (parkingSlot.at(pickID - 1)->getTypeOfVehicle() == "Car")
				{
					carCounter--;
					freeparkingslot++;
				}

				else if (parkingSlot.at(pickID - 1)->getTypeOfVehicle() == "Van/Truck")
				{
					vanCounter--;
					freeparkingslot += 2;
				}
				else if (parkingSlot.at(pickID - 1)->getTypeOfVehicle() == "Motorbike")
				{
					motorBikeVehicle--;
					freeparkingslot++;
				}
				else 
				{
					cout << "Sorry, but wrong command was written." << endl;
				}

				string vehicle = parkingSlot.at(pickID - 1)->getTypeOfVehicle() + " " + parkingSlot.at(pickID - 1)->getplateID();
				parkingSlot.erase(parkingSlot.begin() + (pickID - 1));
				cout << " ---Available parking slot: " << freeparkingslot << endl;
				cout << " " << endl;
				cout << " ---Removed vehicle: " << vehicle << endl;
				cout << " " << endl;
			}
			else
			{
				cout << "---Available parking places: " << freeparkingslot << endl;
			}
		}while (command != 0);
	}
	else 
	{
		cout << "----Pakring slots are all empty----" << endl;
	}
	
}



void Carkparkmanager::sortVehicles()
{
	bool change;
	vector<Vehicle*> temp(1);

	int lastIndex;
	int checkforNum;
	checkforNum = parkingSlot.size() - 1;

	do
	{
		change= false;
		lastIndex = checkforNum - 1;

		for (int i = 0; i <= lastIndex; i++)
		{

			if (parkingSlot.at(i)->getDate()->total()   <= parkingSlot.at(i + 1)->getDate()->total())
			{
				temp[0] = parkingSlot.at(i);
				parkingSlot.at(i) = parkingSlot.at(i + 1);
				parkingSlot.at(i + 1) = temp[0];
				change = true;
			}

		}
		checkforNum--;
	} while (change && (checkforNum > 0));
	cout << " " << endl;
}
void Carkparkmanager::displayStatistics() 
{
	double prcntVanTruck;
	double prcntMotor;
	double prcntCar;

	prcntVanTruck = (vanCounter * 100.0) / parkingSlot.size();

	prcntCar = (carCounter * 100.0) / parkingSlot.size();
	
	prcntMotor = (motorCounter * 100.0) / parkingSlot.size();



	if (parkingSlot.size() > 0)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << "The percentage of motorbikes  is: " << prcntMotor << "%" << endl;

		cout << "The percentage of cars is: " << prcntCar << "%" << endl;
		cout << " " << endl;
		cout << "The percentage of vans/trucks is: " << prcntVanTruck << "%" << endl;
		cout << " " << endl;
		
		cout << " " << endl;

		cout << "Vehicle that accessed the carpark recently: " << endl;
		cout << parkingSlot.at(0)->getplateID() << " " << parkingSlot.at(0)->getTypeOfVehicle() << " " << parkingSlot.at(0)->toString() << endl;
		cout << " " << endl;


		cout << "The longest time parked vehicle is: " << endl;
		cout << parkingSlot.at((parkingSlot.size() - 1))->getplateID() << " " << parkingSlot.at(parkingSlot.size() - 1)->getTypeOfVehicle() << " " << parkingSlot.at(parkingSlot.size() - 1)->toString() << endl;
		cout << " " << endl;
		
	}
	else
	{
		cout << " No cars currently in the parking slot" << endl;
	}

}

void Carkparkmanager::displayVehicleDate() 
{
	int day;
	int year;
	int months;
	bool vehicledate = false;

	cout << "Type the date in order find vehicle by a date:" << endl;
	cout << "Day:" << endl;
	cin >> day;
	cout << "Month:" << endl;
	cin >> months;
	cout << "Year:" << endl;
	cin >> year;

	cout << " " << endl;


	for (int i = 0; i < parkingSlot.size(); i++)
	{
		if (parkingSlot.at(i)->getDate()->getday()== day
			&& parkingSlot.at(i)->getDate()->getmonth()== month
			&& parkingSlot.at(i)->getDate()->getyear()== year)
		{
			cout << " Here is the typed results: " << endl;
			cout << " " << endl;
			cout << parkingSlot.at(i)->getTypeOfVehicle() << " " << parkingSlot.at(i)->getplateID() << endl;
			vehicledate = true;
		}

	}

	if (!vehicledate)
	{
		cout << " no vehicle were found by this date " << endl;
	}


}

void Carkparkmanager::pricecalculation() 
{
	int totalyear, totalmonth, totalday,
		totalhour, totalminute, addeddays;

	int addedhour, addedminutes, priceintotal;
	int daysinTotal = 0;
	int check;
	int totalprice= 0;
	int hourDiff;

	if (parkingSlot.size() > 0)
	{
		display();
		cout << "Type exit date for vehicle " << endl;
		cout << " " << endl;
		dateCheck();

		for (int i = 0; i < parkingSlot.size(); i++)
		{
			totalyear = (year - parkingSlot.at(i)->getDate()->getyear()) * 365;
			totalmonth = (month - parkingSlot.at(i)->getDate()->getmonth());
			totalday = (day - parkingSlot.at(i)->getDate()->getday());
			totalhour = hour - parkingSlot.at(i)->getDate()->gethour();
			totalminute = minute - parkingSlot.at(i)->getDate()->getminutes();

			for (int a = parkingSlot.at(i)->getDate()->getmonth(); a < month; a++)
			{
				if (a <= 2 && a % 2 == 0)
				{
					daysinTotal += 28;
				}
				else
				{
					if (a <= 7)
					{
						if (a % 2 != 0)
						{
							daysinTotal += 31;
						}
						else
						{
							daysinTotal += 30;
						}

					}
					else
					{
						if (a % 2 == 0)
						{
							daysinTotal += 31;
						}
						else
						{
							daysinTotal += 30;
						}
					}
				}
			}  

			addeddays = totalyear + daysinTotal + totalday;

			addedhour = 0;
			if (parkingSlot.at(i)->getDate()->gethour() > hour)
			{
				addeddays--;
				addedhour = 24 + totalhour;
				totalhour = addedhour;
			}
			if (parkingSlot.at(i)->getDate()->getminutes() > minute)
			{
				totalhour--;
				addedminutes = 60 + totalminute;
				totalminute = addedminutes;
			}
			if (totalminute > 0 && totalminute < 59)
			{
				totalhour++;
			}
			if (totalhour > 24)
			{
				addeddays++;
				totalhour -= 24;
			}
			if (totalhour <= 3)
			{
				totalprice = totalhour * 3;

			}
			else if (totalhour > 3 && totalhour < 24)
			{
				totalprice = 3 * 3;
				hourDiff = totalhour - 3;
				totalprice += hourDiff * 4;
			}
			cout << "---Total price" << totalprice << endl;
			cout << " " << endl;
			if (addeddays > 0)
			{
				totalprice += (addeddays * 30);
			}
			cout << parkingSlot.at(i)->getplateID() << " "<< parkingSlot.at(i)->getTypeOfVehicle() << " Receipt: Total prpice for parking is " << totalprice << ".0 Pounds!!" << endl;
			cout << " " << endl;
		}
	}
	else
	{
		cout << "---NO VEHICLES PARKED HERE---" << endl;
	}
}


void Carkparkmanager::dateCheck()
{
	
	do{


		
		do{
			
			do{
				cout << " Entry Day " << endl;
				cin >> day;
			} while (day > 31 || day <= 0);
			do{
				cout << " Entry Month " << endl;
				cin >> month;
			} while (month > 12 || month <= 0);

			if (day > 28 && month == 2)
			{
				checkfordate = false;
				cout << " February has only 28 days " << endl;
			}
			else
			{
				checkfordate = true;
			}
		}while (checkfordate == false);

		if (month <= 7)
		{
			if (month % 2 != 0 && day <= 31)
			{
				checkfordate = true;
			}

			else if (month ==4 && day > 30 || month ==6 && day > 30)
			{
				checkfordate = false;
				cout << "---Months like April and June only have 30 days---" << endl;
				
			}
			else
			{
				checkfordate = true;
			}
		}
		else
		{
			if (month ==9 && day > 30 || month == 11 && day > 30)
			{
				
				checkfordate = false;
				cout << " Months like September and November only have 30 days  " << endl;
			}
			else
			{
				checkfordate = true;
			}
		}

	} while (checkfordate == false);

	 do{

		cout << " Enter year " << endl;
		cin >> year;
	}while (year <= 2000);

	do{
		cout << " Type hours please: " << endl;
		cin >> hour;
	} while (hour > 24 || hour < 0);

	do{
		cout << " Type  minutes please:" << endl;
		cin >> minute;
	} while (minute >= 60 || minute < 0);
}


string Carkparkmanager::generateRandom(string rnd)
{
	string rtrn = " ";
	int randomnum;
	if (rnd =="C") 
	{
		randomnum = generateNumber();

	
			if (randomnum == 0)
			{
				
				rtrn = " Blue";
			}
			 else if (randomnum == 1)
			{
				rtrn = "Red";
			}
			 else if (randomnum == 2)
			{
				rtrn = "Yellow";
			}
			 else  if (randomnum == 3)
			{
				
				rtrn = "White";
			}
			 else  if (randomnum == 4)
			{
				rtrn = "Green";
			}
			 else  if (randomnum == 5)
			
			{
				rtrn = "Black";
			}
		
	}
	else if (rnd == "B") 
	{
		randomnum = generateNumber();
		if (randomnum == 0)
		 {
			rtrn = "Mercedes";
		 }
		else if (randomnum == 1)
		 {
			rtrn = "Audi";
		 }
		else if (randomnum == 2)
		 {
			rtrn = "Wolkswagen";
		 }
		else if (randomnum == 3)
		 {
			rtrn = "Lexus";
		 }
		else if (randomnum == 4)
		 {
			rtrn = "Fiat";
		 }
		else if (randomnum == 5)
		{
			rtrn = "Ferrari";
		}
		else if (randomnum == 6)
		{
			rtrn = "Lamborghini";
		}
		else if (randomnum == 7)
		{
			rtrn = "Hyundai";
		}
		else if (randomnum == 8)
		{
			rtrn = "Honda";
		}
		else if (randomnum == 9)
		{
			rtrn = "Porche";
		}
		else if (randomnum == 10)
		{
			rtrn = "Tesla";
		}
		else if (randomnum == 11)
		{
			rtrn = "Suzuki";
		}
		else if (randomnum == 12)
		{
			rtrn = "Subaru";
		}
		else if (randomnum == 13)
		 {
			rtrn = "Toyota";
		 }
	}
	else if (rnd == "I")
	{
		randomnum = generateNumber();
		if (randomnum == 0)
		 {
			rtrn = "Ae2345";
		 }
		else if (randomnum == 1)
		 {
			rtrn = "WE3434";
		 }
		else if (randomnum == 2)
		 {
			rtrn = "DD3323";
		 }
		else if (randomnum == 3)
		 {
			rtrn = "TR5555";
		 }
		else if (randomnum == 4)
		 {
			rtrn = "SY1818";
		 }
		else if (randomnum == 5)
		{
			rtrn = "SU3418";
		}
		else if (randomnum == 6)
		{
			rtrn = "SU3420";
		}
		else if (randomnum == 7)
		{
			rtrn = "KL4452";
		}
		else if (randomnum == 8)
		{
			rtrn = "NI2323";
		}
		else if (randomnum == 9)
		{
			rtrn = "NI2323";
		}
		else if (randomnum == 10)
		{
			rtrn = "HO5644";
		}
		else if (randomnum == 11)
		{
			rtrn = "LA3224";
		}
		else if (randomnum == 12)
		{
			rtrn = "LQ2324";
		}
		else if (randomnum == 13)
		 {
			rtrn = "N2342N";
		 }

	}
	else if (rnd=="E")
	{
		randomnum = generateNumber();
		if (randomnum == 0)
		 {
			rtrn = "50";
		 }
		if (randomnum == 1)
		 {
			rtrn = "100";
		 }
		if (randomnum == 2)
		 {
			rtrn = "125";
		 }
		if (randomnum == 3)
		 {
			rtrn = "250";
		 }
		if (randomnum == 4)
		 {
			rtrn = "500";
		 }
		if(randomnum == 5)
		 {
			rtrn = "625";
		 }
	}

	return rtrn;

}

int Carkparkmanager::generateNumber() 
{
	int ranNum = rand() % 13;

	return ranNum;
} 

void Carkparkmanager::probability() 
{
	
	double probone;
	double probtwo;
	int freeparkingslots= 20;
	double rate;

	// equation that were used  15x + 12y = 10;

	double speed = 15.0;
	double speed2 = 12.0;

	rate = freeparkingslots / (speed + speed2);

	probone = rate * speed;
	probtwo = rate * speed2;

	cout << "Probability that cars will enter from entrance 1 based on the speed of 15 to fill in 10 parks available are: " << round(probone) << endl;
	cout << "Probability that cars will nter from entrance 2 based on the speed of 12 to fill in 10 parks available are: " << round(probtwo) << endl;

}



