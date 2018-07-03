#include "dateTime.h"

dateTime::dateTime(int day, int month, int year, int hour, int minute)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
	this->minute = minute;
}


int dateTime::getday()
{
	return day;
}
int dateTime::getmonth()
{
	return month;
}
int dateTime::getyear()
{
	return year;
}
int dateTime::gethour()
{
	return hour;
}
int dateTime::getminutes()
{
	return minute;
}

double dateTime::total()
{
	double total = (year * 365) + (month * 30) + day + (hour / 3600) + (minute / 60);

	return total;
}

