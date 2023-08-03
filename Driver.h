#pragma once
#include <iostream>
#include"Person.h"
#include"Service.h"
using namespace std;

class Driver : public Person
{
private:
	int dId;
	int* LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled
	Service** serviceHistory;
	//Add services address in the array for tracking complete information of service.
public:
	//add following functions in this class
	//Getter, Setters
	//Destructor, Default and Parameterized Constructor, Copy Constructor, Output operator (prints complete information of Driver)
	Driver();
	Driver(int drivID, int* lisenlist, int liscenses, float drivranking, float sal, int exp, int stat, Service** servhistory);
	Driver(const Driver& d);
	void set_driverId(int drivID);
	void set_lisenceslist(int* lisenlist);
	void set_noofliscences(int liscenses);
	void set_overallranking(float drivranking);
	void set_salary(float sal);
	void set_experience(int exp);
	void set_status(int stat);
	void set_servicehistory(Service** servhistory);
	int get_driverId();
	int* get_lisenceslist();
	int get_noofliscences();
	float get_overallranking();
	float get_salary();
	int get_experience();
	int get_status();
	Service** get_servicehistory();
	friend ostream& operator<<(ostream& out, const Driver& d);
	~Driver();
};

Driver::Driver() :serviceHistory()
{
	dId = 0;
	LicencesList = 0;
	noofLicences = 0;
	overallRanking = 0;
	salary = 0;
	experience = 0;
	status = 0;
}

Driver::Driver(int drivID, int* lisenlist, int liscenses, float drivranking, float sal, int exp, int stat, Service** servhistory)
{
	dId = drivID;
	LicencesList = new int[liscenses];
	LicencesList = lisenlist;
	noofLicences = liscenses;
	overallRanking = drivranking;
	salary = sal;
	experience = exp;
	status = stat;
	serviceHistory = servhistory;
}

Driver::Driver(const Driver& d)
{
	dId = d.dId;
	LicencesList = d.LicencesList;
	noofLicences = d.noofLicences;
	overallRanking = d.overallRanking;
	salary = d.salary;
	experience = d.experience;
	status = d.status;
	serviceHistory = d.serviceHistory;
}

void Driver::set_driverId(int drivID)
{
	dId = drivID;
}

void Driver::set_lisenceslist(int* lisenlist)
{
	LicencesList = lisenlist;
}

void Driver::set_noofliscences(int liscenses)
{
	noofLicences = liscenses;
}

void Driver::set_overallranking(float drivranking)
{
	overallRanking = drivranking;
}

void Driver::set_salary(float sal)
{
	salary = sal;
}

void Driver::set_experience(int exp)
{
	experience = exp;
}

void Driver::set_status(int stat)
{
	status = stat;
}

void Driver::set_servicehistory(Service** servhistory)
{
	serviceHistory = servhistory;
}

int Driver::get_driverId()
{
	return dId;
}

int* Driver::get_lisenceslist()
{
	return LicencesList;
}

int Driver::get_noofliscences()
{
	return noofLicences;
}

float Driver::get_overallranking()
{
	return overallRanking;
}

float Driver::get_salary()
{
	return salary;
}

int Driver::get_experience()
{
	return experience;
}

int Driver::get_status()
{
	return status;
}

Service** Driver::get_servicehistory()
{
	return serviceHistory;
}

ostream& operator<<(ostream& out, const Driver& d)
{
	out << d.dId << endl;
	out << d.LicencesList << endl;
	out << d.noofLicences << endl;
	out << d.overallRanking << endl;
	out << d.salary << endl;
	out << d.serviceHistory << endl;
	out << d.status << endl;
	return out;
}

Driver::~Driver()
{
	delete[] LicencesList;
	LicencesList = nullptr;
	for (int i = 0; i < 20; i++)
	{
		delete[] serviceHistory[i];
	}
	serviceHistory = nullptr;
}

