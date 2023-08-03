#pragma once

#include <iostream>
#include"Service.h"
using namespace std;

class Delivery : public Service
{
	float goodsWeight; // Weight of goods in Kg
	char* goodsType; //type of goods food, furniture, petroleum, chemicals, etc.
	//you can add more members here if required
public:
	//add member functions
	Delivery();
	Delivery(float gweight, char* gtype);
	Delivery(const Delivery& d);
	void set_goodsweight(float gweight);
	void set_goodstype(char* gtype);
	float get_goodsweight();
	char* get_goodstype();
	friend ostream& operator<<(ostream& out, const Delivery d);
	~Delivery();
};

Delivery::Delivery()
{
	goodsWeight = 0;
	goodsType = {};
}

Delivery::Delivery(float gweight, char* gtype)
{
	goodsWeight = gweight;
	goodsType = new char[strlen(gtype) + 1];
	goodsType = gtype;
}

Delivery::Delivery(const Delivery& d)
{
	goodsWeight = d.goodsWeight;
	goodsType = new char[strlen(d.goodsType) + 1];
	goodsType = d.goodsType;
}

void Delivery::set_goodsweight(float gweight)
{
	goodsWeight = gweight;
}

void Delivery::set_goodstype(char* gtype)
{
	goodsType = new char[strlen(gtype) + 1];
	goodsType = gtype;
}

float Delivery::get_goodsweight()
{
	return goodsWeight;
}

char* Delivery::get_goodstype()
{
	return goodsType;
}

ostream& operator<<(ostream& out, const Delivery d)
{
	out << d.goodsWeight << endl;
	out << d.goodsType << endl;
	return out;
}

Delivery::~Delivery()
{
	delete[] goodsType;
	goodsType = nullptr;
}