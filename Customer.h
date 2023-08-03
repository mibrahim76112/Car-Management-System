#pragma once
#include <iostream>
#include"Person.h"
#include"Service.h"
using namespace std;

class Customer : public Person
{
private:
	int cId;
	// Unique and assigned first time when customer makes first service request
	Service** bookingHistory;
	//Maintain and Update history of customer for each service (ride or goods transportation order) by adding address of service in dynamic array.
	//you can add more members here if required
public:
	//add following functions in this class //Getter, Setters
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output operator (print complete information of customer including history if any)
	Customer();
	Customer(int id, Service** bookinghis);
	Customer(const Customer& c);
	void set_customerID(int id);
	void set_bookinghistory(Service** bookinghis);
	int get_customerID();
	Service** get_bookinghistory();
	friend ostream& operator<< (ostream& out, const Customer& c);
	~Customer();
};

Customer::Customer() :bookingHistory()
{
	cId = 0;
}

Customer::Customer(int id, Service** bookinghis)
{
	cId = id;
	bookingHistory = bookinghis;
}

Customer::Customer(const Customer& c)
{
	cId = c.cId;
	bookingHistory = c.bookingHistory;
}

void Customer::set_customerID(int id)
{
	cId = id;
}

void Customer::set_bookinghistory(Service** bookinghis)
{
	bookingHistory = bookinghis;
}

int Customer::get_customerID()
{
	return cId;
}

Service** Customer::get_bookinghistory()
{
	return bookingHistory;
}

ostream& operator<< (ostream& out, const Customer& c)
{
	out << c.cId << endl;
	out << c.bookingHistory << endl;
	return out;
}

Customer::~Customer()
{
	for (int i = 0; i < 20; i++)
	{
		delete[] bookingHistory[i];
	}
	bookingHistory = nullptr;
}
