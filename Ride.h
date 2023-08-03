#pragma once

#include <iostream>
#include "Service.h"
using namespace std;

class Ride : public Service
{
	int noofPassengers; // false for pending, true if complete
	char* rideType; // intercity, intracity
	float DriverRanking; // 0 to 5 scale (worst to best)
	float VehicleRanking; // 0 to 5 scale (worst to best)
	//you can add more members here if required
public:
	//add member functions
	Ride();
	Ride(int passen, char* ridetyp, float drivranking, float vehiranking);
	Ride(const Ride& r);
	void set_noofpassengers(int passe);
	void set_ridetype(char* ridetyp);
	void set_driverranking(float drivranking);
	void set_vehicleranking(float vehiranking);
	int get_noofpassengers();
	char* get_ridetype();
	float get_driverranking();
	float get_vehicleranking();
	friend ostream& operator<<(ostream& out, const Ride r);
	~Ride();
};

Ride::Ride()
{
	noofPassengers = 0;
	rideType = {};
	DriverRanking = 0;
	VehicleRanking = 0;
}

Ride::Ride(int passen, char* ridetyp, float drivranking, float vehiranking)
{
	noofPassengers = passen;
	rideType = new char[strlen(ridetyp) + 1];
	rideType = ridetyp;
	DriverRanking = drivranking;
	VehicleRanking = vehiranking;
}

Ride::Ride(const Ride& r)
{
	noofPassengers = r.noofPassengers;
	rideType = new char[strlen(r.rideType) + 1];
	rideType = r.rideType;
	DriverRanking = r.DriverRanking;
	VehicleRanking = r.VehicleRanking;
}

void Ride::set_noofpassengers(int passe)
{
	noofPassengers = passe;
}

void Ride::set_ridetype(char* ridetyp)
{
	rideType = new char[strlen(ridetyp) + 1];
	rideType = ridetyp;
}

void Ride::set_driverranking(float drivranking)
{
	DriverRanking = drivranking;
}

void Ride::set_vehicleranking(float vehiranking)
{
	VehicleRanking = vehiranking;
}

int Ride::get_noofpassengers()
{
	return noofPassengers;
}

char* Ride::get_ridetype()
{
	return rideType;
}

float Ride::get_driverranking()
{
	return DriverRanking;
}

float Ride::get_vehicleranking()
{
	return VehicleRanking;
}

ostream& operator<<(ostream& out, const Ride r)
{
	out << r.noofPassengers << endl;
	out << r.rideType << endl;
	out << r.DriverRanking << endl;
	out << r.VehicleRanking << endl;
	return out;
}

Ride::~Ride()
{
	delete[] rideType;
	rideType = nullptr;
}