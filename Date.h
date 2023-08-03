#pragma once
#include <iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
	int* dob;
public:
	Date();
	Date(int d, int m, int y);
	void setdate(int d, int m, int y);
	void setday(int d);
	void setmonth(int m);
	void setyear(int y);
	int getday();
	int getmonth();
	int getyear();
	int* getdate();
	void print();
	friend ostream& operator<<(ostream& out, const Date& d);
	//add constructurs getter setters and stream output function, which output date in given format day / Mon / Year
};

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	dob = new int[3];
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	//dob = NULL;
}

void Date::setdate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	dob[0] = d;
	dob[1] = m;
	dob[2] = y;
}

void Date::setday(int d)
{
	day = d;
}

void Date::setmonth(int m)
{
	month = m;
}

void Date::setyear(int y)
{
	year = y;
}

int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}

int* Date::getdate()
{
	return dob;
}

void Date::print()
{
	cout << day << "/" << month << "/" << year;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d.day << d.month << d.year;
	return out;
}
