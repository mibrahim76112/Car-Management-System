#pragma once
#pragma once
#include <iostream>
#include"Date.h"
#include"mTime.h"
using namespace std;

class Service
{
	char* source;
	char* destination;
	float distance; //in km
	Date bookingDate;
	mTime bookingTime;
	bool status; // false for pending, true if complete
	float fuelrate;
	int cId; // Customer Id who booked the ride
	int dId; // Driver Id
	int vId; // vehicle Id
	//you can add more members here if required
public:
	//add member functions
	Service();
	Service(char* sou, char* des, float dist, Date bookingD, mTime bookingT, bool stat, float frate, int cusId, int driId, int vehiId);
	Service(const Service& s);
	void set_source(char* sou);
	void set_destination(char* des);
	void set_distance(float dist);
	void set_bookingDate(Date bookingD);
	void set_bookingTime(mTime bookingT);
	void set_status(bool stat);
	void set_fuelrate(float frate);
	void set_customerID(int cusId);
	void set_driverID(int driId);
	void set_vehicleID(int vehiId);
	char* get_source();
	char* get_destination();
	float get_distance();
	Date get_bookingDate();
	mTime get_bookingTime();
	bool get_status();
	float get_fuelrate();
	int get_customerID();
	int get_driverID();
	int get_vehicleID();
	friend ostream& operator<<(ostream& out, const Service& s);
	~Service();
};

Service::Service() :bookingDate(), bookingTime()
{
	source = {};
	destination = {};
	distance = 0;
	status = 0;
	fuelrate = 0;
	cId = 0;
	dId = 0;
	vId = 0;
}

Service::Service(char* sou, char* des, float dist, Date bookingD, mTime bookingT, bool stat, float frate, int cusId, int driId, int vehiId) :bookingDate(bookingD), bookingTime(bookingT)
{
	source = new char[strlen(sou) + 1];
	source = sou;
	destination = new char[strlen(des) + 1];
	destination = des;
	distance = dist;
	status = stat;
	fuelrate = frate;
	cId = cusId;
	dId = driId;
	vId = vehiId;
}

Service::Service(const Service& s)
{
	source = new char[strlen(s.source) + 1];
	source = s.source;
	destination = new char[strlen(s.destination) + 1];
	destination = s.destination;
	distance = s.distance;
	bookingDate = s.bookingDate;
	bookingTime = s.bookingTime;
	status = s.status;
	fuelrate = s.fuelrate;
	cId = s.cId;
	dId = s.dId;
	vId = s.vId;
}

void Service::set_source(char* sou)
{
	source = new char[strlen(sou) + 1];
	source = sou;
}

void Service::set_destination(char* des)
{
	destination = new char[strlen(des) + 1];
	destination = des;
}

void Service::set_distance(float dist)
{
	distance = dist;
}

void Service::set_bookingDate(Date bookingD)
{
	bookingDate = bookingD;
}

void Service::set_bookingTime(mTime bookingT)
{
	bookingTime = bookingT;
}

void Service::set_status(bool stat)
{
	status = stat;
}

void Service::set_fuelrate(float frate)
{
	fuelrate = frate;
}

void Service::set_customerID(int cusId)
{
	cId = cusId;
}

void Service::set_driverID(int driId)
{
	dId = driId;
}

void Service::set_vehicleID(int vehiId)
{
	vId = vehiId;
}

char* Service::get_source()
{
	return source;
}

char* Service::get_destination()
{
	return destination;
}

float Service::get_distance()
{
	return distance;
}

Date  Service::get_bookingDate()
{
	return bookingDate;
}

mTime  Service::get_bookingTime()
{
	return bookingTime;
}

bool  Service::get_status()
{
	return status;
}

float  Service::get_fuelrate()
{
	return fuelrate;
}

int  Service::get_customerID()
{
	return cId;
}

int  Service::get_driverID()
{
	return dId;
}

int  Service::get_vehicleID()
{
	return vId;
}

ostream& operator<<(ostream& out, const Service& s)
{
	out << s.source << endl;
	out << s.destination << endl;
	out << s.distance << endl;
	out << s.bookingDate << endl;
	out << s.bookingTime << endl;
	out << s.status << endl;
	out << s.fuelrate << endl;
	out << s.cId << endl;
	out << s.dId << endl;
	out << s.vId << endl;
	return out;
}

Service::~Service()
{
	delete[] source;
	source = nullptr;
	delete[] destination;
	destination = nullptr;
}