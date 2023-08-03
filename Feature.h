#pragma once
#include <iostream>
using namespace std;

class Feature
{
	int fId{};
	char* description{};
	float cost{};
	//you can add more members here if required
public:
	//add member functions
	Feature();
	Feature(int featID, char* desc, float money);
	Feature(const Feature& f);
	void set_featureID(int featID);
	void set_description(char* desc);
	void set_cost(float money);
	int get_featureID();
	char* get_description();
	float get_cost();
	friend ostream& operator<<(ostream& out, const Feature& f);
	~Feature();
};

Feature::Feature()
{
	fId = 0;
	description = {};
	cost = 0;
}

Feature::Feature(int featID, char* desc, float money)
{
	fId = featID;
	description = new char[strlen(desc) + 1];
	description = desc;
	cost = money;
}

Feature::Feature(const Feature& f)
{
	fId = f.fId;
	description = new char[strlen(f.description) + 1];
	description = f.description;
	cost = f.cost;
}

void Feature::set_featureID(int featID)
{
	fId = featID;
}

void Feature::set_description(char* desc)
{
	description = new char[strlen(desc) + 1];
	description = desc;
}

void Feature::set_cost(float money)
{
	cost = money;
}

int Feature::get_featureID()
{
	return fId;
}

char* Feature::get_description()
{
	return description;
}

float Feature::get_cost()
{
	return cost;
}

ostream& operator<<(ostream& out, const Feature& f)
{
	out << f.fId << endl;
	for (int i = 0; i < f.description[i] != '\0'; i++)
	{
		out << f.description[i];
	}
	out << endl;
	out << f.cost << endl;
	return out;
}

Feature::~Feature()
{
	delete[] description;
	description = nullptr;
}
