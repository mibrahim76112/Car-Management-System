#pragma once
#pragma once
#include <iostream>
using namespace std;

class Name
{
private:
	char* fName{};
	char* lName{};
public:
	//add following functions
	//Getter, Setters
	//Destructor, Default Constructor, Copy Constructor,
	Name();
	Name(char* fN, char* lN);
	Name(const Name& n);
	void setname(char* fN, char* lN);
	void setfname(char* fN);
	void setlname(char* fN);
	void getname();
	char* getfname();
	char* getlname();
	friend ostream& operator<<(ostream& out, const Name& n);
	~Name();
};

Name::Name()
{
	fName = NULL;
	lName = NULL;
}

Name::Name(char* fN, char* lN)
{
	fName = new char[strlen(fN) + 1];
	fName = fN;
	lName = new char[strlen(lN) + 1];
	lName = lN;
}

Name::Name(const Name& n)
{
	if (n.fName != nullptr && n.lName != nullptr)
	{
		fName = new char[strlen(n.fName) + 1];
		fName = n.fName;
		lName = new char[strlen(n.lName) + 1];
		lName = n.lName;
	}
}

void Name::setname(char* fN, char* lN)
{
	fName = new char[strlen(fN) + 1];
	fName = fN;
	lName = new char[strlen(lN) + 1];
	lName = lN;
}

void Name::setfname(char* fN)
{
	fName = new char[strlen(fN) + 1];
	fName = fN;
}

void Name::setlname(char* lN)
{
	lName = new char[strlen(lN) + 1];
	lName = lN;
}

void Name::getname()
{
	cout << fName << " " << lName;
}

char* Name::getfname()
{
	return fName;
}

char* Name::getlname()
{
	return lName;
}

ostream& operator<<(ostream& out, const Name& n)
{
	out << n.fName << " " << n.lName << endl;
	return out;
}

Name::~Name()
{
	delete fName;
	delete lName;
	fName = nullptr;
	lName = nullptr;
}