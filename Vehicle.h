
#pragma once
#include <iostream>
#include"Date.h"
#include"Feature.h"
#include"Service.h"
using namespace std;

class Vehicle
{
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenceType; // License required for driving the vehicle
	bool status; // false for free, true if booked in a service already
	char* fueltype;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;
	//Add services address in the array for tracking complete information of service.
public:
	//you can add more members here if required
	//add member functions
	Vehicle();
	Vehicle(int vehiID, int regno, int milage, char* liscence, bool stat, char* fuel, float ranking, Date manudate, Feature* fealist, Service** servicehis);
	Vehicle(const Vehicle& v);
	void set_vehicleID(int vehiID);
	void set_registrationo(int regno);
	void set_averagemilage(int milage);
	void set_liscencetype(char* liscence);
	void set_status(bool stat);
	void set_fueltype(char* fuel);
	void set_overallranking(float ranking);
	void set_manufacturingdate(Date manudate);
	void set_featurelist(Feature* fealist);
	void set_servicehistory(Service** servicehis);
	int get_vehicleID();
	int get_registrationo();
	float get_averagemilage();
	char* get_liscencetype();
	bool get_status();
	char* get_fueltype();
	float get_overallranking();
	Date get_manufacturingdate();
	Feature* get_featurelist();
	Service** get_servicehistory();
	friend ostream& operator<<(ostream& out, const Vehicle& v);
	~Vehicle();
};

Vehicle::Vehicle()
{
	vId = 0;
	registrationNo = 0;
	avgMileage = 0;
	LicenceType = 0;
	status = 0;
	fueltype = 0;
	overallRanking = 0;
	list = 0;
	serviceHistory = 0;
}

Vehicle::Vehicle(int vehiID, int regno, int milage, char* liscence, bool stat, char* fuel, float ranking, Date manudate, Feature* fealist, Service** servicehis)
{
	vId = vehiID;
	registrationNo = regno;
	avgMileage = milage;
	LicenceType = liscence;
	status = stat;
	fueltype = fuel;
	overallRanking = ranking;
	manufacturingDate = manudate;
	list = fealist;
	serviceHistory = servicehis;
}

Vehicle::Vehicle(const Vehicle& v)
{
	vId = v.vId;
	registrationNo = v.registrationNo;
	avgMileage = v.avgMileage;
	LicenceType = v.LicenceType;
	status = v.status;
	fueltype = v.fueltype;
	overallRanking = v.overallRanking;
	list = v.list;
	serviceHistory = v.serviceHistory;
	manufacturingDate = v.manufacturingDate;
}

void Vehicle::set_vehicleID(int vehiID)
{
	vId = vehiID;
}

void Vehicle::set_registrationo(int regno)
{
	registrationNo = regno;
}

void Vehicle::set_averagemilage(int milage)
{
	avgMileage = milage;
}

void Vehicle::set_liscencetype(char* liscence)
{
	LicenceType = liscence;
}

void Vehicle::set_status(bool stat)
{
	status = stat;
}

void Vehicle::set_fueltype(char* fuel)
{
	fueltype = fuel;
}

void Vehicle::set_overallranking(float ranking)
{
	overallRanking = ranking;
}

void Vehicle::set_manufacturingdate(Date manudate)
{
	manufacturingDate = manudate;
}

void Vehicle::set_featurelist(Feature* fealist)
{
	list = fealist;
}

void Vehicle::set_servicehistory(Service** servicehis)
{
	serviceHistory = servicehis;
}

int Vehicle::get_vehicleID()
{
	return vId;
}

int Vehicle::get_registrationo()
{
	return registrationNo;
}

float Vehicle::get_averagemilage()
{
	return avgMileage;
}

char* Vehicle::get_liscencetype()
{
	return LicenceType;
}

bool Vehicle::get_status()
{
	return status;
}

char* Vehicle::get_fueltype()
{
	return fueltype;
}

float Vehicle::get_overallranking()
{
	return overallRanking;
}

Date Vehicle::get_manufacturingdate()
{
	return manufacturingDate;
}

Feature* Vehicle::get_featurelist()
{
	return list;
}

Service** Vehicle::get_servicehistory()
{
	return serviceHistory;
}

ostream& operator<<(ostream& out, const Vehicle& v)
{
	out << v.vId << endl;
	out << v.registrationNo << endl;
	out << v.avgMileage << endl;
	out << v.LicenceType << endl;
	out << v.overallRanking << endl;
	out << v.fueltype << endl;
	out << v.list << endl;
	out << v.manufacturingDate << endl;
	out << v.status << endl;
	out << v.serviceHistory << endl;
	return out;
}

Vehicle::~Vehicle()
{
	delete[] LicenceType;
	LicenceType = nullptr;
	delete[] fueltype;
	fueltype = nullptr;
	delete[] list;
	list = nullptr;
	for (int i = 0; i < 20; i++)
	{
		delete[] serviceHistory[i];
	}
	serviceHistory = nullptr;
}
