#pragma once
#include <iostream>
#include"Date.h"
#include"name.h"
using namespace std;

class Person
{
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	//add following functions in this class 
	//Getter, Setters
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output operator (print information of person)
	Person();
	Person(char* fname, char* lname, int day, int month, int year, int age, int id);
	Person(const Person& p);
	void set_name(char* fname, char* lname);
	void set_fname(char* fname);
	void set_lname(char* lname);
	void set_date(int day, int month, int year);
	void set_age(int ag);
	void set_id(int id);
	void get_name();
	char* get_fname();
	char* get_lname();
	int* get_date();
	int get_age();
	int get_id();
	friend ostream& operator <<(ostream& out, const Person& p);
};


Person::Person() :pName(), DOB()
{
	Age = 0;
	Nid = 0;
}

Person::Person(char* fname, char* lname, int day, int month, int year, int ag, int id) :pName(fname, lname), DOB(day, month, year)
{
	Age = ag;
	Nid = id;
}

Person::Person(const Person& p)
{
	DOB = p.DOB;
	Age = p.Age;
	pName = p.pName;
	Nid = p.Nid;
}

void Person::set_name(char* fname, char* lname)
{
	pName.setname(fname, lname);
}

void Person::set_fname(char* fname)
{
	pName.setfname(fname);
}

void Person::set_lname(char* lname)
{
	pName.setlname(lname);
}

void Person::set_date(int day, int month, int year)
{
	DOB.setdate(day, month, year);
}

void Person::set_age(int ag)
{
	Age = ag;
}

void Person::set_id(int id)
{
	Nid = id;
}

void Person::get_name()
{
	pName.getname();
}

char* Person::get_fname()
{
	return pName.getfname();
}

char* Person::get_lname()
{
	return pName.getlname();
}

int* Person::get_date()
{
	return DOB.getdate();
}

int Person::get_age()
{
	return Age;
}

int Person::get_id()
{
	return Nid;
}

ostream& operator <<(ostream& out, const Person& p)
{
	out << p.pName << endl;
	out << p.DOB << endl;
	out << p.Age << endl;
	out << p.Nid;
	return out;
}
