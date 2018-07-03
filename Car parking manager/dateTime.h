#pragma once
#define DATETIME_H

#include <iostream>

using namespace std;

class dateTime {

private:
	int day;
	int month;
	int year;
	int hour;
	int minute;
public:
	dateTime(int day, int month, int year, int hour, int minute);
	int getday();
	int getmonth();
	int getyear();
	int gethour();
	int getminutes();
	double total();

};

