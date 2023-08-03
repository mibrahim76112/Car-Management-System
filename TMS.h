#pragma once

#include<iostream>
#include <cstdlib>
#include <ctime>
#include"Driver.h"
#include"Vehicle.h"
#include"Customer.h"
#include"Service.h"
#include <fstream>
#include"Ride.h"
#include"Delivery.h"

int i = 1, j = 1, k = 1;

class TMS
{
	Customer* c;
	Vehicle* v;
	Driver* d;
public:
	TMS();
	void newcustomer();
	void newdriver();
	void removedriver();
	void addvehicle();
	void removevehicle();
	void customerdata();
	void driversdata();
	void vehicledata();
	void vehicleservices();
	void customerservices();
	void driverservices();
	void bestdrivers();
	void multiplelisdrivers();
	void updatedsalary();
	void addrequest();
	void cancelrequest();
	void completeservice();
	void samevehicle();
	void instantdelivery();
	void datependings();
	void driverpendings();
	void cancelledrequests();
	~TMS();
};

TMS::TMS()
{
	c = new Customer[15];
	v = new Vehicle[20];
	d = new Driver[10];
}

void TMS::newcustomer()
{
	char fname[10];
	char lname[10];
	int age;
	int day, month, year;
	int id;

	cout << endl;
	cout << "--------------NEW CUSTOMER--------------" << endl << endl;

	cout << "First Name: ";
	cin.getline(fname, 10);
	cout << endl;
	cout << "Last Name: ";
	cin.getline(lname, 10);
	cout << endl;
	cout << "Age: ";
	cin >> age;
	cout << endl;
	cout << "Date of Birth(dd/mm/yyyy): ";
	cout << endl << endl;
	cout << "Enter Day(dd): ";
	cin >> day;
	cout << endl;
	cout << "Enter Month(mm): ";
	cin >> month;
	cout << endl;
	cout << "Enter Year: ";
	cin >> year;

	c[i].set_age(age);
	c[i].set_fname(fname);
	c[i].set_lname(lname);
	c[i].set_date(day, month, year);
	srand((unsigned)time(NULL));
	id = rand();
	c[i].set_customerID(id);

	cout << endl << "Customer ID: " << c[i].get_customerID();

	ofstream out("Customer_List.txt", ios::app);
	out << i << endl;
	out << c[i].get_fname() << endl;
	out << c[i].get_lname() << endl;
	out << c[i].get_age() << endl;
	out << day << endl;
	out << month << endl;
	out << year << endl;
	out << endl;
	out << c[i].get_customerID() << endl;
	out.close();
	i++;
}

void TMS::newdriver()
{
	char fname[10];
	char lname[10];
	int age; int id;
	int day, month, year;
	int salary, experience, noofliscence;
	float ranking = 3;
	int* liscenses;

	srand((unsigned)time(NULL));
	id = rand();

	cout << endl;
	cout << "--------------NEW DRIVER--------------" << endl << endl;

	cout << "First Name: ";
	cin.getline(fname, 10);
	cout << endl;
	cout << "Last Name: ";
	cin.getline(lname, 10);
	cout << endl;
	cout << "Age: ";
	cin >> age;
	cout << endl;
	cout << "Date of Birth(dd/mm/yyyy): ";
	cout << endl << endl;
	cout << "Enter Day(dd): ";
	cin >> day;
	cout << endl;
	cout << "Enter Month(mm): ";
	cin >> month;
	cout << endl;
	cout << "Enter Year: ";
	cin >> year;
	cout << endl;
	cout << "Enter Salary: ";
	cin >> salary;
	cout << endl;
	cout << "Enter Experience: ";
	cin >> experience;
	cout << endl;
	cout << "Enter Number of Lisences: ";
	cin >> noofliscence;
	cout << endl;

	liscenses = new int[noofliscence];

	for (int i = 0; i < noofliscence; i++)
	{
		cout << "Enter Liscense Number " << i << " : ";
		cin >> liscenses[i];
		cout << endl;
	}

	d[j].set_age(age);
	d[j].set_fname(fname);
	d[j].set_lname(lname);
	d[j].set_date(day, month, year);
	d[j].set_driverId(id);
	d[j].set_experience(experience);
	d[j].set_noofliscences(noofliscence);
	d[j].set_salary(salary);
	d[j].set_overallranking(ranking);
	d[j].set_lisenceslist(liscenses);

	cout << endl << "Driver ID: " << d[j].get_driverId();

	ofstream out("Driver_List.txt", ios::app);

	out << j << endl;
	out << d[j].get_fname() << endl;
	out << d[j].get_lname() << endl;
	out << d[j].get_age() << endl;
	out << day << endl;
	out << month << endl;
	out << year << endl;
	out << d[j].get_driverId() << endl;
	out << d[j].get_experience() << endl;
	out << d[j].get_overallranking() << endl;
	out << d[j].get_salary() << endl;
	out << d[j].get_noofliscences() << endl;
	int* m;
	m = d[j].get_lisenceslist();
	for (int i = 0; i < noofliscence; i++)
	{
		out << m[i];
		out << endl;
	}
	out.close();
	j++;
}

void TMS::removedriver()
{
	char fname[10][15]; char lname[10][15]; int age[10]; int id1[10]; int day[10], month[10], year[10];
	int salary[10], experience[10], noofliscence[10]; int liscenses[10]; float ranking[10];
	int ID;

	ifstream in("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id1[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}
	in.close();

	cout << endl;
	cout << "--------------REMOVE DRIVER--------------" << endl << endl;

	cout << "Enter Driver ID: ";
	cin >> ID;

	ofstream out("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		if (id1[i] > 0 && id1[i] != ID)
		{
			out << j << endl;
			out << fname[i] << endl;
			out << lname[i] << endl;
			out << age[i] << endl;
			out << day[i] << endl;
			out << month[i] << endl;
			out << year[i] << endl;
			out << id1[i] << endl;
			out << experience[i] << endl;
			out << ranking[i] << endl;
			out << salary[i] << endl;
			out << noofliscence[i] << endl;
			for (int j = 0; j < noofliscence[i]; j++)
			{
				out << liscenses[i] << endl;
			}
		}
	}
	out.close();
}

void TMS::addvehicle()
{
	int num;
	int cost = 0;
	int day, month, year;
	int id;
	int regno;
	float milage;
	char lisctype[10];
	char fuel[10];
	float ranking = 3;
	Date manufacture;
	Feature* list;

	cout << endl;
	cout << "--------------NEW VEHICLE--------------" << endl << endl;

	cout << "Enter Vehicle Registration No.: ";
	cin >> regno;
	cout << endl;
	cout << "Enter Vehicle Average Milage: ";
	cin >> milage;
	cout << endl;
	cin.ignore();
	cout << "Enter Vehicle Liscence Type: ";
	cin.getline(lisctype, 10);
	cout << endl;
	cout << "Enter Vehicle Fuel Type: ";
	cin.getline(fuel, 10);
	cout << endl;
	cout << "Enter Vehicle Manufavturing Date(dd/mm/yyyy): ";
	cout << endl;
	cout << "Enter Day(dd): ";
	cin >> day;
	cout << endl;
	cout << "Enter Month(mm): ";
	cin >> month;
	cout << endl;
	cout << "Enter Year: ";
	cin >> year;
	cout << endl;
	cout << "How many Features of Vehicle you want to Enter ?";
	cin >> num;
	cout << endl;
	list = new Feature[num];

	for (int i = 0; i < num; i++)
	{
		char des[20][50];
		cin.ignore();
		cout << "Enter Feature " << (i + 1) << " Description: ";
		cin.getline(des[i], 50);
		cout << endl;
		cout << "Enter Feature " << (i + 1) << " Cost: ";
		cin >> cost;
		cout << endl;
		list[i].set_description(des[i]);
		list[i].set_cost(cost);
		srand((unsigned)time(NULL));
		id = rand();
		list[i].set_featureID(id);
	}

	manufacture.setdate(day, month, year);
	v[k].set_averagemilage(milage);
	v[k].set_featurelist(list);
	v[k].set_fueltype(fuel);
	v[k].set_liscencetype(lisctype);
	v[k].set_manufacturingdate(manufacture);
	v[k].set_overallranking(ranking);
	v[k].set_registrationo(regno);
	srand((unsigned)time(NULL));
	id = rand();
	v[k].set_vehicleID(id);

	cout << endl << "Vehicle ID: " << v[k].get_vehicleID();

	ofstream out("Vehicle_List.txt", ios::app);

	out << k << endl;
	out << v[k].get_averagemilage() << endl;
	out << num << endl;
	Feature* ch = v[k].get_featurelist();
	for (int i = 0; i < num; i++)
	{
		out << ch[i];
	}
	out << v[k].get_fueltype() << endl;
	out << v[k].get_liscencetype() << endl;
	out << day << endl;
	out << month << endl;
	out << year << endl;
	out << v[k].get_overallranking() << endl;
	out << v[k].get_registrationo() << endl;
	out << v[k].get_vehicleID() << endl;

	out.close();

	k++;
}

void TMS::removevehicle()
{
	int ID;
	int id[20];
	char list[20][10];
	int regno[20];
	int mileage[20];
	float ranking[20];
	char date[20][10];
	char liscence[20][10];
	char fuel[20][10];

	cout << endl;
	cout << "--------------REMOVE VEHICLE--------------" << endl << endl;

	cout << "Enter Vehicle ID: ";
	cin >> ID;

	ifstream in("Vehicle_list.txt");
	for (int i = 0; i < 20; i++)
	{
		in >> k;
		in >> mileage[i];
		in >> list[i];
		in >> fuel[i];
		in >> liscence[i];
		/*for (int j = 0; j < 8; j++)
		{
			in >> date[i][j];
		}*/
		in.getline(date[i], 10);
		in >> ranking[i];
		in >> regno[i];
		in >> id[i];
	}
	in.close();

	ofstream out("Vehicle_List.txt");
	for (int i = 0; i < k; i++)
	{
		if (id[i] != ID)
		{
			out << k << endl;
			out << mileage[i] << endl;
			out << list[i] << endl;
			out << fuel[i] << endl;
			out << liscence[i] << endl;
			out << date[i] << endl;
			out << ranking[i] << endl;
			out << regno[i] << endl;
			out << id[i];
		}
	}
	out.close();
}

void TMS::customerdata()
{
	char fname[15][10];
	char lname[15][10];
	int age[15];
	int day[15];
	int month[15];
	int year[15];
	int id[15];

	ifstream in("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		in >> i;
		in >> fname[k];
		in >> lname[k];
		in >> age[k];
		in >> day[k];
		in >> month[k];
		in >> year[k];
		in >> id[k];
	}
	in.close();

	cout << endl;
	cout << "--------------CUSTOMERS DETAILS-------------" << endl << endl;

	for (int k = 0; k < 15; k++)
	{
		if (id[k] > 0)
		{
			cout << "First Name: " << fname[k] << endl;
			cout << "Last Name: " << lname[k] << endl;
			cout << "Age: " << age[k] << endl;
			cout << "Date of Birth: " << day[k] << " " << month[k] << " " << year[k];
			cout << endl;
			cout << "Customer ID: " << id[k];
			cout << endl << endl;
		}
	}
}

void TMS::driversdata()
{
	char fname[10][15];
	char lname[10][15];
	int age[10];
	int id[10];
	int day[10], month[10], year[10];
	int salary[10], experience[10], noofliscence[10];
	int liscenses[10];
	float ranking[10];

	ifstream in("Driver_List.txt");

	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}

	in.close();

	cout << endl;
	cout << "--------------DRIVERS DETAILS-------------" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		if (age[i] > 0)
		{
			cout << "First Name: " << fname[i] << endl;
			cout << "Last Name: " << lname[i] << endl;
			cout << "Age: " << age[i] << endl;
			cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i] << endl;
			cout << "Driver ID: " << id[i] << endl;
			cout << "Experience: " << experience[i] << endl;
			cout << "Overall Ranking: " << ranking[i] << endl;
			cout << "Salary: " << salary[i] << endl;
			cout << "Number of Liscences: " << noofliscence[i] << endl;
			cout << "Liscences: ";
			for (int k = 0; k < noofliscence[i]; k++)
			{
				cout << liscenses[i] << "  ";
			}
			cout << endl << endl;
		}
	}
}

void TMS::vehicledata()
{
	int num;
	int cost[20][20];
	char des[20][20][25];
	int day[20], month[20], year[20];
	int id[20];
	int fid[20][20];
	int regno[20];
	float mileage[20];
	char lisctype[20][10];
	char fuel[20][10];
	float ranking[20];

	ifstream in("Vehicle_List.txt");

	for (int i = 0; i < 20; i++)
	{
		in >> k;
		in >> mileage[i];
		in >> num;
		for (int k = 0; k < num; k++)
		{
			in >> fid[i][k];
			in.getline(des[i][k], 50);
			in.getline(des[i][k], 50);
			in >> cost[i][k];
		}
		in.getline(fuel[i], 10);
		in.getline(fuel[i], 10);
		in.getline(lisctype[i], 10);
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> ranking[i];
		in >> regno[i];
		in >> id[i];
	}

	in.close();

	cout << endl;
	cout << "--------------VEHICLES DETAILS--------------" << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		if (regno[i] > 0)
		{
			cout << "Registration No.: " << regno[i] << endl;
			cout << "ID: " << id[i] << endl;
			cout << "Category: " << lisctype[i] << endl;
			cout << "Date of Manufacture: " << day[i] << " " << month[i] << " " << year[i] << endl;
			cout << "Overall Ranking: " << ranking[i] << endl;
			cout << "Fuel Type: " << fuel[i] << endl;
			cout << "Features: " << endl;
			for (int k = 0; k < num; k++)
			{
				cout << "Feature No. " << k + 1 << " : " << endl;
				cout << "  Feature ID: " << fid[i][k] << endl;
				cout << "  Description: " << des[i][k];
				cout << endl << "  Feature Cost: " << cost[i][k];
				cout << endl;
			}
			cout << endl << endl;
		}
	}
}

void  TMS::vehicleservices()
{
	int num; int ID; int cost[20][20]; char des[20][20][25]; int day[20], month[20], year[20];
	int id[20]; int fid[20][20]; int regno[20]; float mileage[20], ranking[20]; char lisctype[20][10]; char fuel[20][10];
	char op; bool flag = false; int  stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], weight[20], id1[20];
	char source[20][20], destination[20][20], ridetype[20][20], goodstype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];

	ifstream in("Vehicle_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in >> k;
		in >> mileage[i];
		in >> num;
		for (int k = 0; k < num; k++)
		{
			in >> fid[i][k];
			in.getline(des[i][k], 25);
			in.getline(des[i][k], 25);
			in >> cost[i][k];
		}
		in.getline(fuel[i], 10);
		in.getline(fuel[i], 10);
		in.getline(lisctype[i], 10);
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> regno[i];
		in >> ranking[i];
		in >> id[i];
	}
	in.close();

	cout << endl;
	cout << "--------------VEHICLE DETAILS--------------" << endl << endl;

	cout << "Enter Vehicle ID: ";
	cin >> ID;

	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		if (id[i] == ID)
		{
			flag = true;
		}
	}

	if (flag == true)
	{
		cout << "Press 1 to Retrieve Rides Services History" << endl;
		cout << "Press 2 to Retrieve Delivery Services History" << endl;

		op = _getch();

		if (op == '1')
		{
			ifstream in1("Ride_Services_List.txt");
			for (int i = 0; i < 20; i++)
			{
				in1 >> serviceID[i];
				in1 >> id1[i];
				in1 >> passengers[i];
				in1.getline(ridetype[i], 20);
				in1.getline(ridetype[i], 20);
				in1 >> distance[i];
				in1.getline(source[i], 20);
				in1.getline(source[i], 20);
				in1.getline(destination[i], 20);
				in1 >> fuelcost[i];
				in1 >> driID[i];
				in1 >> drirank[i];
				in1 >> vehiID[i];
				in1 >> vehirank[i];
				in1 >> day1[i];
				in1 >> month1[i];
				in1 >> year1[i];
				in1 >> hours[i];
				in1 >> mins[i];
				in1 >> sec[i];
				in1 >> stat[i];
				in1 >> fare[i];
			}
			in1.close();

			for (int i = 0; i < 20; i++)
			{
				if (id[i] == ID)
				{
					cout << "Registration No.: " << regno[i] << endl;
					cout << "ID: " << id[i] << endl;
					cout << "Category: " << lisctype[i] << endl;
					cout << "Date of Manufacture: " << day[i] << " " << month[i] << " " << year[i] << endl;
					cout << "Fuel Type: " << fuel[i] << endl;
					cout << "Overall Ranking: " << ranking[i] << endl;
					cout << "Features: " << endl;
					for (int k = 0; k < num; k++)
					{
						cout << "Feature No. " << k + 1 << " : " << endl;
						cout << "  Feature ID: " << fid[i][k] << endl;
						cout << "  Description: " << des[i][k];
						cout << endl << "  Feature Cost: " << cost[i][k];
						cout << endl;
					}
					cout << endl << endl;
				}
				if (vehiID[i] == ID && stat[i] != -1)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Customer ID: " << id1[i] << endl;
					cout << "Driver ID: " << driID[i] << endl;
					cout << "Ride Type: " << ridetype[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Fuel Cost: " << fuelcost[i] << endl;
					cout << "Date of Booking: " << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: " << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Status of Service: " << stat[i] << endl;
					cout << "Vehicle Ranked: " << vehirank[i] << endl;
					cout << "Service Fare: " << fare[i] << endl;
					cout << endl;
				}
			}
		}
		else if (op == '2')
		{
			ifstream in2("Delivery_Services_List.txt");

			for (int i = 0; i < 20; i++)
			{
				in2 >> serviceID[i];
				in2 >> id1[i];
				in2 >> weight[i];
				in2.getline(goodstype[i], 20);
				in2.getline(goodstype[i], 20);
				in2 >> distance[i];
				in2.getline(source[i], 20);
				in2.getline(source[i], 20);
				in2.getline(destination[i], 20);
				in2 >> fuelcost[i];
				in2 >> driID[i];
				in2 >> vehiID[i];
				in2 >> day1[i];
				in2 >> month1[i];
				in2 >> year1[i];
				in2 >> hours[i];
				in2 >> mins[i];
				in2 >> sec[i];
				in2 >> stat[i];
				in2 >> fare[i];
			}

			in2.close();

			cout << endl << endl;

			for (int i = 0; i < 20; i++)
			{
				if (id[i] == ID)
				{
					cout << "Registration No.: " << regno[i] << endl;
					cout << "ID: " << id[i] << endl;
					cout << "Category: " << lisctype[i] << endl;
					cout << "Date of Manufacture: " << day[i] << " " << month[i] << " " << year[i] << endl;
					cout << "Fuel Type: " << fuel[i] << endl;
					cout << "Overall Ranking: " << ranking[i] << endl;
					cout << "Features: " << endl;
					for (int k = 0; k < num; k++)
					{
						cout << "Feature No. " << k + 1 << " : " << endl;
						cout << "  Feature ID: " << fid[i][k] << endl;
						cout << "  Description: " << des[i][k];
						cout << endl << "  Feature Cost: " << cost[i][k];
						cout << endl;
					}
					cout << endl << endl;
				}
				if (vehiID[i] == ID && stat[i] != -1)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Customer ID: " << id[i] << endl;
					cout << "Driver ID: " << driID[i] << endl;
					cout << "Goods Type: " << goodstype[i] << endl;
					cout << "Goods Weight: " << weight[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Vehicle Ranked: " << vehirank[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << endl << endl;
				}
			}
		}
	}
	else cout << "First Add a Vehicle by Choosing Option D";
}

void  TMS::customerservices()
{
	int ID; char op; bool flag = false; int  stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], weight[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20], goodstype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	char fname[15][10]; char lname[15][10]; int age[15]; int day[15]; int month[15];
	int year[15]; int id1[15];

	ifstream in("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		in >> i;
		in >> fname[k];
		in >> lname[k];
		in >> age[k];
		in >> day[k];
		in >> month[k];
		in >> year[k];
		in >> id1[k];
	}
	in.close();

	cout << endl;
	cout << "--------------CUSTOMER SERVICES HISTORY--------------" << endl << endl;

	cout << "Enter Customer ID: ";
	cin >> ID;

	for (int i = 0; i < 15; i++)
	{
		if (id1[i] == ID)
		{
			flag = true;
		}
	}

	cout << endl;

	if (flag == true)
	{
		cout << "Press 1 to Retrieve Rides Services History" << endl;
		cout << "Press 2 to Retrieve Delivery Services History" << endl;

		op = _getch();

		if (op == '1')
		{
			ifstream in("Ride_Services_List.txt");

			for (int i = 0; i < 20; i++)
			{
				in >> serviceID[i];
				in >> id[i];
				in >> passengers[i];
				in.getline(ridetype[i], 20);
				in.getline(ridetype[i], 20);
				in >> distance[i];
				in.getline(source[i], 20);
				in.getline(source[i], 20);
				in.getline(destination[i], 20);
				in >> fuelcost[i];
				in >> driID[i];
				in >> drirank[i];
				in >> vehiID[i];
				in >> vehirank[i];
				in >> day1[i];
				in >> month1[i];
				in >> year1[i];
				in >> hours[i];
				in >> mins[i];
				in >> sec[i];
				in >> stat[i];
				in >> fare[i];
			}

			in.close();

			cout << endl;

			for (int i = 0; i < 15; i++)
			{
				if (id1[i] == ID)
				{
					cout << "First Name: " << fname[i] << endl;
					cout << "Last Name: " << lname[i] << endl;
					cout << "Age: " << age[i] << endl;
					cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i];
					cout << endl;
					cout << "Customer ID: " << id1[i];
					cout << endl << endl;
				}
				if (id[i] == ID)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Customer ID: " << id[i] << endl;
					cout << "No of Passengers: " << passengers[i] << endl;
					cout << "Ride Type: " << ridetype[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Driver Ranked: " << drirank[i] << endl;
					cout << "Vehicle Ranked: " << vehirank[i] << endl;
					cout << endl << endl;
				}
			}
		}
		else if (op == '2')
		{
			ifstream in("Delivery_Services_List.txt");

			for (int i = 0; i < 20; i++)
			{
				in >> serviceID[i];
				in >> id[i];
				in >> weight[i];
				in.getline(goodstype[i], 20);
				in.getline(goodstype[i], 20);
				in >> distance[i];
				in.getline(source[i], 20);
				in.getline(source[i], 20);
				in.getline(destination[i], 20);
				in >> fuelcost[i];
				in >> driID[i];
				in >> vehiID[i];
				in >> day1[i];
				in >> month1[i];
				in >> year1[i];
				in >> hours[i];
				in >> mins[i];
				in >> sec[i];
				in >> stat[i];
				in >> fare[i];
			}

			in.close();

			cout << endl << endl;

			for (int i = 0; i < 15; i++)
			{
				if (id1[i] == ID)
				{
					cout << "First Name: " << fname[k] << endl;
					cout << "Last Name: " << lname[k] << endl;
					cout << "Age: " << age[k] << endl;
					cout << "Date of Birth: " << day[k] << " " << month[k] << " " << year[k];
					cout << endl;
					cout << "Customer ID: " << id1[k];
					cout << endl << endl;
				}
				if (id[i] == ID)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Customer ID: " << id[i] << endl;
					cout << "Goods Type: " << goodstype[i] << endl;
					cout << "Goods Weight: " << weight[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Driver Ranked: " << drirank[i] << endl;
					cout << "Vehicle Ranked: " << vehirank[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << endl << endl;
				}
			}
		}
	}
	else cout << "First Add Customer by choosing Option A";
}

void  TMS::driverservices()
{
	int ID; char op; bool flag = false; int  stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], weight[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20], goodstype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	char fname[10][15]; char lname[10][15];	int age[10]; int id1[10]; int day[10], month[10], year[10];
	int salary[10], experience[10], noofliscence[10];	int liscenses[10]; float ranking[10];

	ifstream in("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id1[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}
	in.close();

	cout << endl;
	cout << "--------------DRIVER SERVICES HISTORY--------------" << endl << endl;

	cout << "Enter Driver ID: ";
	cin >> ID;
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		if (id1[i] == ID)
		{
			flag = true;
		}
	}

	if (flag == true)
	{
		cout << "Press 1 to Retrieve Rides Services History" << endl;
		cout << "Press 2 to Retrieve Delivery Services History" << endl;

		op = _getch();

		if (op == '1')
		{
			ifstream in("Ride_Services_List.txt");
			for (int i = 0; i < 20; i++)
			{
				in >> serviceID[i];
				in >> id[i];
				in >> passengers[i];
				in.getline(ridetype[i], 20);
				in.getline(ridetype[i], 20);
				in >> distance[i];
				in.getline(source[i], 20);
				in.getline(source[i], 20);
				in.getline(destination[i], 20);
				in >> fuelcost[i];
				in >> driID[i];
				in >> drirank[i];
				in >> vehiID[i];
				in >> vehirank[i];
				in >> day1[i];
				in >> month1[i];
				in >> year1[i];
				in >> hours[i];
				in >> mins[i];
				in >> sec[i];
				in >> stat[i];
				in >> fare[i];
			}
			in.close();

			cout << endl;

			for (int i = 0; i < 20; i++)
			{
				if (id1[i] == ID)
				{
					cout << "First Name: " << fname[i] << endl;
					cout << "Last Name: " << lname[i] << endl;
					cout << "Age: " << age[i] << endl;
					cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i] << endl;
					cout << "Driver ID: " << id[i] << endl;
					cout << "Experience: " << experience[i] << endl;
					cout << "Overall Ranking: " << ranking[i] << endl;
					cout << "Salary: " << salary[i] << endl;
					cout << "Number of Liscences: " << noofliscence[i] << endl;
					cout << "Liscences: ";
					for (int k = 0; k < noofliscence[i]; k++)
					{
						cout << liscenses[i] << "  ";
					}
					cout << endl << endl;
				}
				if (driID[i] == ID && stat[i] != -1)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Driver ID: " << driID[i] << endl;
					cout << "Ride Type: " << ridetype[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Driver Ranked: " << drirank[i] << endl;
					cout << endl << endl;
				}
			}
		}
		else if (op == '2')
		{
			ifstream in("Delivery_Services_List.txt");
			for (int i = 0; i < 20; i++)
			{
				in >> serviceID[i];
				in >> id[i];
				in >> weight[i];
				in.getline(goodstype[i], 20);
				in.getline(goodstype[i], 20);
				in >> distance[i];
				in.getline(source[i], 20);
				in.getline(source[i], 20);
				in.getline(destination[i], 20);
				in >> fuelcost[i];
				in >> driID[i];
				in >> vehiID[i];
				in >> day1[i];
				in >> month1[i];
				in >> year1[i];
				in >> hours[i];
				in >> mins[i];
				in >> sec[i];
				in >> stat[i];
				in >> fare[i];
			}
			in.close();

			cout << endl << endl;

			for (int i = 0; i < 20; i++)
			{
				if (id1[i] == ID)
				{
					cout << "First Name: " << fname[i] << endl;
					cout << "Last Name: " << lname[i] << endl;
					cout << "Age: " << age[i] << endl;
					cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i] << endl;
					cout << "Driver ID: " << id[i] << endl;
					cout << "Experience: " << experience[i] << endl;
					cout << "Overall Ranking: " << ranking[i] << endl;
					cout << "Salary: " << salary[i] << endl;
					cout << "Number of Liscences: " << noofliscence[i] << endl;
					cout << "Liscences: ";
					for (int k = 0; k < noofliscence[i]; k++)
					{
						cout << liscenses[i] << "  ";
					}
					cout << endl << endl;
				}
				if (driID[i] == ID && stat[i] != -1)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Driver ID: " << driID[i] << endl;
					cout << "Goods Type: " << goodstype[i] << endl;
					cout << "Goods Weight: " << weight[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Driver Ranked: " << drirank[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << endl << endl;
				}
			}
		}
	}
	else cout << "First Add a Driver by Choosing Option B";
}

void  TMS::bestdrivers()
{
	int stat[20], count[10] = { 0 }; float sum[10] = { 0 };
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	char fname[10][15]; char lname[10][15]; int age[10]; int id1[10]; int day[10], month[10], year[10];
	int salary[10], experience[10], noofliscence[10]; int liscenses[10]; float ranking[10];

	cout << endl;
	cout << "--------------BEST DRIVERS--------------" << endl << endl;

	ifstream in("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id1[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}
	in.close();

	ifstream in1("Ride_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in1 >> serviceID[i];
		in1 >> id[i];
		in1 >> passengers[i];
		in1.getline(ridetype[i], 20);
		in1.getline(ridetype[i], 20);
		in1 >> distance[i];
		in1.getline(source[i], 20);
		in1.getline(source[i], 20);
		in1.getline(destination[i], 20);
		in1 >> fuelcost[i];
		in1 >> driID[i];
		in1 >> drirank[i];
		in1 >> vehiID[i];
		in1 >> vehirank[i];
		in1 >> day1[i];
		in1 >> month1[i];
		in1 >> year1[i];
		in1 >> hours[i];
		in1 >> mins[i];
		in1 >> sec[i];
		in1 >> stat[i];
		in1 >> fare[i];
	}
	in1.close();

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (id1[i] > 0 && id1[i] == driID[j])
			{
				count[i]++;
				sum[i] += drirank[j];
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		ranking[i] = sum[i] / count[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (ranking[i] > 4.5)
		{
			cout << "First Name: " << fname[i] << endl;
			cout << "Last Name: " << lname[i] << endl;
			cout << "Age: " << age[i] << endl;
			cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i] << endl;
			cout << "Driver ID: " << id1[i] << endl;
			cout << "Experience: " << experience[i] << endl;
			cout << "Overall Ranking: " << ranking[i] << endl;
			cout << "Salary: " << salary[i] << endl;
			cout << "Number of Liscences: " << noofliscence[i] << endl;
			cout << "Liscences: ";
			for (int k = 0; k < noofliscence[i]; k++)
			{
				cout << liscenses[i] << "  ";
			}
			cout << endl << endl;
		}
	}

	ofstream out("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		out << j << endl;
		out << fname[i] << endl;
		out << lname[i] << endl;
		out << age[i] << endl;
		out << day[i] << endl;
		out << month[i] << endl;
		out << year[i] << endl;
		out << id1[i] << endl;
		out << experience[i] << endl;
		out << ranking[i] << endl;
		out << salary[i] << endl;
		out << noofliscence[i] << endl;
		for (int j = 0; j < noofliscence[i]; j++)
		{
			out << liscenses[i] << endl;
		}
	}
	out.close();
}

void  TMS::multiplelisdrivers()
{
	char fname[10][15]; char lname[10][15]; int age[10]; int id[10]; int day[10], month[10], year[10];
	int salary[10], experience[10], noofliscence[10]; int liscenses[10]; float ranking[10];

	ifstream in("Driver_List.txt");

	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}

	in.close();

	cout << endl;
	cout << "--------------MULTIPLE LICENSED DRIVERS DETAILS-------------" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		if (noofliscence[i] >= 2)
		{
			cout << "First Name: " << fname[i] << endl;
			cout << "Last Name: " << lname[i] << endl;
			cout << "Driver ID: " << id[i] << endl;
			cout << "Experience: " << experience[i] << endl;
			cout << "Overall Ranking: " << ranking[i] << endl;
			cout << "Number of Liscences: " << noofliscence[i] << endl;
			cout << "Liscences: ";
			for (int k = 0; k < noofliscence[i]; k++)
			{
				cout << liscenses[i] << "  ";
			}
			cout << endl << endl;
		}
	}
}

void  TMS::updatedsalary()
{
	char fname[10][15]; char lname[10][15]; int age[10]; int id1[10]; int day[10], month[10], year[10];
	int salary[10], experience[10], noofliscence[10]; int liscenses[10]; float ranking[10];

	ifstream in("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id1[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}
	in.close();

	cout << endl;
	cout << "--------------UPDATED SALERY OF DRIVERS--------------" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		if (ranking[i] >= 4.5)
		{
			salary[i] = salary[i] + (salary[i] * (15.0 / 100));
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (ranking[i] > 4.5)
		{
			cout << "First Name: " << fname[i] << endl;
			cout << "Last Name: " << lname[i] << endl;
			cout << "Age: " << age[i] << endl;
			cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i] << endl;
			cout << "Driver ID: " << id1[i] << endl;
			cout << "Experience: " << experience[i] << endl;
			cout << "Overall Ranking: " << ranking[i] << endl;
			cout << "Salary: " << salary[i] << endl;
			cout << "Number of Liscences: " << noofliscence[i] << endl;
			cout << "Liscences: ";
			for (int k = 0; k < noofliscence[i]; k++)
			{
				cout << liscenses[i] << "  ";
			}
			cout << endl << endl;
		}
	}


	ofstream out("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		if (id1[i] > 0)
		{
			out << j << endl;
			out << fname[i] << endl;
			out << lname[i] << endl;
			out << age[i] << endl;
			out << day[i] << endl;
			out << month[i] << endl;
			out << year[i] << endl;
			out << id1[i] << endl;
			out << experience[i] << endl;
			out << ranking[i] << endl;
			out << salary[i] << endl;
			out << noofliscence[i] << endl;
			for (int j = 0; j < noofliscence[i]; j++)
			{
				out << liscenses[i] << endl;
			}
		}
	}
	out.close();
}

void  TMS::addrequest()
{
	char fname[15][10]; char lname[15][10]; int age[15]; int day[15]; int month[15]; int year[15]; int id[15];
	int num2; int cost2[20][20]; char des2[20][20][25]; int day2[20], month2[20], year2[20]; int id2[20];
	int fid2[20][20]; int regno2[20]; float mileage2[20]; char lisctype2[20][10]; char fuel2[20][10]; float ranking2[20];
	char fname3[10][15]; char lname3[10][15]; int age3[10]; int id3[10]; int day3[10], month3[10], year3[10];
	int salary3[10], experience3[10], noofliscence3[10]; int liscenses3[10];	float ranking3[10];
	int ID; char op = 0; bool flag = false, stat; int day1, month1, year1, hours, mins, sec;
	float fuelcost; int distance, passengers, weight; char source[20], destination[20], ridetype[20], goodstype[20];
	int ID2, ID3, serviceID; float fare; int drivrankings[10], vehirankings[20];
	Ride* s = new Ride;
	Delivery* e = new Delivery;

	ifstream in("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		in >> i;
		in >> fname[k];
		in >> lname[k];
		in >> age[k];
		in >> day[k];
		in >> month[k];
		in >> year[k];
		in >> id[k];
	}
	in.close();

	ifstream in1("Vehicle_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in1 >> k;
		in1 >> mileage2[i];
		in1 >> num2;
		for (int k = 0; k < num2; k++)
		{
			in1 >> fid2[i][k];
			in1.getline(des2[i][k], 50);
			in1.getline(des2[i][k], 50);
			in1 >> cost2[i][k];
		}
		in1.getline(fuel2[i], 10);
		in1.getline(fuel2[i], 10);
		in1.getline(lisctype2[i], 10);
		in1 >> day2[i];
		in1 >> month2[i];
		in1 >> year2[i];
		in1 >> ranking2[i];
		in1 >> regno2[i];
		in1 >> id2[i];
	}
	in1.close();

	ifstream in2("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		in2 >> j;
		in2 >> fname3[i];
		in2 >> lname3[i];
		in2 >> age3[i];
		in2 >> day3[i];
		in2 >> month3[i];
		in2 >> year3[i];
		in2 >> id3[i];
		in2 >> experience3[i];
		in2 >> ranking3[i];
		in2 >> salary3[i];
		in2 >> noofliscence3[i];
		for (int j = 0; j < noofliscence3[i]; j++)
		{
			in2 >> liscenses3[i];
		}
	}
	in2.close();

	cout << endl << "--------------ADD A REQUEST--------------" << endl << endl;

	cout << "Enter Customer ID: ";
	cin >> ID;

	int i = 0;
	for (i = 0; i < 15; i++)
	{
		if (id[i] == ID)
		{
			flag = true;
			break;
		}
	}

	if (flag == true)
	{
		cout << endl;
		cout << "Press 1 to Book a Ride" << endl;
		cout << "Press 2 to Book a Delivery" << endl;

		op = _getch();

		if (op == '1')
		{
			cout << endl;
			cout << "Enter No. of Passengers: ";
			cin >> passengers;
			cout << endl;
			cin.ignore();
			cout << "Enter Type of Ride: ";
			cin.getline(ridetype, 20);
			cout << endl;
			cout << "Enter Source: ";
			cin.getline(source, 20);
			cout << endl;
			cout << "Enter Destination: ";
			cin.getline(destination, 20);
			cout << endl;
			cout << "Enter Distance: ";
			cin >> distance;
			cout << endl;
			cout << "Enter Booking Date: ";
			cout << endl << endl;
			cout << "  Enter Day(dd): ";
			cin >> day1;
			cout << endl;
			cout << "  Enter Month(mm): ";
			cin >> month1;
			cout << endl;
			cout << "  Enter Year: ";
			cin >> year1;
			cout << endl;
			cout << "Enter Booking Time: ";
			cout << endl << endl;
			cout << "  Enter Hours(hh): ";
			cin >> hours;
			cout << endl;
			cout << "  Enter Minutes(mm): ";
			cin >> mins;
			cout << endl;
			cout << "  Enter Seconds(ss): ";
			cin >> sec;
			cout << endl;
			cout << "Enter Fuel Cost: ";
			cin >> fuelcost;
			cout << endl;

			fare = distance * fuelcost;

			for (int i = 0; i < 10; i++)
			{
				drivrankings[i] = ranking3[i];
			}
			for (int i = 0; i < 20; i++)
			{
				vehirankings[i] = ranking2[i];
			}

			for (int i = 0; i < 10 - 1; i++)
			{
				for (int j = 0; j < 10 - i - 1; j++)
				{
					if (drivrankings[j] < drivrankings[j + 1])
					{
						float temp = drivrankings[j];
						drivrankings[j] = drivrankings[j + 1];
						drivrankings[j + 1] = temp;
					}
				}
			}

			for (int i = 0; i < 20 - 1; i++)
			{
				for (int j = 0; j < 20 - i - 1; j++)
				{
					if (vehirankings[j] < vehirankings[j + 1])
					{
						float temp = vehirankings[j];
						vehirankings[j] = vehirankings[j + 1];
						vehirankings[j + 1] = temp;
					}
				}
			}

			cout << "Driver ID    " << "Driver Name    " << "Driver Ranking" << endl << endl;
			for (int i = 0; i < 10; i++)
			{

				if (drivrankings[i] > 0)
				{
					cout << id3[i] << "  " << fname3[i] << " " << lname3[i] << "  " << ranking3[i] << endl;
				}

			}

			cout << endl << "Enter Driver ID to Select: ";
			cin >> ID3;
			cout << endl;

			for (int i = 0; i < 10; i++)
			{
				if (ID3 == id3[i])
				{
					drivrankings[0] = ranking3[i];
				}
			}

			fare = fare * drivrankings[0];

			cout << "Vehicle ID    " << "Vehicle Category  " << "Vehicle Ranking" << endl << endl;
			for (int i = 0; i < 20; i++)
			{

				if (vehirankings[i] > 0)
				{
					cout << id2[i] << "  " << lisctype2[i] << "  " << ranking2[i] << endl;
				}

			}

			cout << endl << "Enter Vehicle ID to Select: ";
			cin >> ID2;
			cout << endl;

			for (int i = 0; i < 20; i++)
			{
				if (ID2 == id2[i])
				{
					vehirankings[0] = ranking2[i];
				}
			}

			fare = fare * vehirankings[0];

			stat = false;

			Date d;
			d.setdate(day1, month1, year1);
			mTime t;
			t.set_time(hours, mins, sec);

			s->set_customerID(id[i]);
			s->set_noofpassengers(passengers);
			s->set_ridetype(ridetype);
			s->set_distance(distance);
			s->set_source(source);
			s->set_destination(destination);
			s->set_fuelrate(fuelcost);
			s->set_driverID(ID3);
			s->set_driverranking(drivrankings[0]);
			s->set_vehicleID(ID2);
			s->set_vehicleranking(vehirankings[0]);
			s->set_bookingDate(d);
			s->set_bookingTime(t);
			s->set_status(stat);

			srand((unsigned)time(NULL));
			serviceID = rand();

			cout << endl << "Service ID: " << serviceID;
			ofstream out("Ride_Services_List.txt", ios::app);

			out << serviceID << endl;
			out << s->get_customerID() << endl;
			out << s->get_noofpassengers() << endl;
			out << s->get_ridetype() << endl;
			out << s->get_distance() << endl;
			out << s->get_source() << endl;
			out << s->get_destination() << endl;
			out << s->get_fuelrate() << endl;
			out << s->get_driverID() << endl;
			out << s->get_driverranking() << endl;
			out << s->get_vehicleID() << endl;
			out << s->get_vehicleranking() << endl;
			out << day1 << endl << month1 << endl << year1 << endl;
			out << hours << endl << mins << endl << sec << endl;
			out << s->get_status() << endl;
			out << fare << endl;

			out.close();
		}
		else if (op == '2')
		{
			cout << endl;
			cout << "Enter Weight of Goods: ";
			cin >> weight;
			cout << endl;
			cin.ignore();
			cout << "Enter Type of Goods: ";
			cin.getline(goodstype, 20);
			cout << endl;
			cout << "Enter Source: ";
			cin.getline(source, 20);
			cout << endl;
			cout << "Enter Destination: ";
			cin.getline(destination, 20);
			cout << endl;
			cout << "Enter Distance: ";
			cin >> distance;
			cout << endl;
			cout << "Enter Booking Date: ";
			cout << endl << endl;
			cout << "  Enter Day(dd): ";
			cin >> day1;
			cout << endl;
			cout << "  Enter Month(mm): ";
			cin >> month1;
			cout << endl;
			cout << "  Enter Year: ";
			cin >> year1;
			cout << endl;
			cout << "Enter Booking Time: ";
			cout << endl << endl;
			cout << "  Enter Hours(hh): ";
			cin >> hours;
			cout << endl;
			cout << "  Enter Minutes(mm): ";
			cin >> mins;
			cout << endl;
			cout << "  Enter Seconds(ss): ";
			cin >> sec;
			cout << endl;
			cout << "Enter Fuel Cost: ";
			cin >> fuelcost;
			cout << endl;


			fare = distance * fuelcost;

			for (int i = 0; i < 10; i++)
			{
				drivrankings[i] = ranking3[i];
			}
			for (int i = 0; i < 20; i++)
			{
				vehirankings[i] = ranking2[i];
			}

			for (int i = 0; i < 10 - 1; i++)
			{
				for (int j = 0; j < 10 - i - 1; j++)
				{
					if (drivrankings[j] < drivrankings[j + 1])
					{
						float temp = drivrankings[j];
						drivrankings[j] = drivrankings[j + 1];
						drivrankings[j + 1] = temp;
					}
				}
			}

			for (int i = 0; i < 20 - 1; i++)
			{
				for (int j = 0; j < 20 - i - 1; j++)
				{
					if (vehirankings[j] < vehirankings[j + 1])
					{
						float temp = vehirankings[j];
						vehirankings[j] = vehirankings[j + 1];
						vehirankings[j + 1] = temp;
					}
				}
			}

			cout << "Driver ID    " << "Driver Name    " << "Driver Ranking" << endl << endl;
			for (int i = 0; i < 10; i++)
			{

				if (drivrankings[i] > 0)
				{
					cout << id3[i] << "  " << fname3[i] << " " << lname3[i] << "  " << ranking3[i] << endl;
				}

			}

			cout << endl << "Enter Driver ID to Select: ";
			cin >> ID3;
			cout << endl;

			for (int i = 0; i < 10; i++)
			{
				if (ID3 == id3[i])
				{
					drivrankings[0] = ranking3[i];
				}
			}

			fare = fare * drivrankings[0];

			cout << "Vehicle ID    " << "Vehicle Category  " << "Vehicle Ranking" << endl << endl;
			for (int i = 0; i < 20; i++)
			{

				if (vehirankings[i] > 0)
				{
					cout << id2[i] << "  " << lisctype2[i] << "  " << ranking2[i] << endl;
				}

			}

			cout << endl << "Enter Vehicle ID to Select: ";
			cin >> ID2;
			cout << endl;

			for (int i = 0; i < 20; i++)
			{
				if (ID2 == id2[i])
				{
					vehirankings[0] = ranking2[i];
				}
			}

			fare = fare * vehirankings[0];

			stat = false;

			Date d;
			d.setdate(day1, month1, year1);
			mTime t;
			t.set_time(hours, mins, sec);

			e->set_customerID(id[i]);
			e->set_goodsweight(weight);
			e->set_goodstype(goodstype);
			e->set_distance(distance);
			e->set_source(source);
			e->set_destination(destination);
			e->set_fuelrate(fuelcost);
			e->set_driverID(ID3);
			e->set_vehicleID(ID2);
			e->set_bookingDate(d);
			e->set_bookingTime(t);
			e->set_status(stat);

			srand((unsigned)time(NULL));
			serviceID = rand();

			cout << endl << "Serivce ID: " << serviceID;


			ofstream out("Delivery_Services_List.txt", ios::app);

			out << serviceID << endl;
			out << e->get_customerID() << endl;
			out << e->get_goodsweight() << endl;
			out << e->get_goodstype() << endl;
			out << e->get_distance() << endl;
			out << e->get_source() << endl;
			out << e->get_destination() << endl;
			out << e->get_fuelrate() << endl;
			out << e->get_driverID() << endl;
			out << e->get_vehicleID() << endl;
			out << day1 << endl << month1 << endl << year1 << endl;
			out << hours << endl << mins << endl << sec << endl;
			out << e->get_status() << endl;
			out << fare << endl;
			out.close();
		}
	}
	else cout << endl << "First Add a New Customer by Choosing Option A" << endl;
}

void  TMS::cancelrequest()
{
	int ID, ID1; char op; bool flag = false; int stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], weight[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20], goodstype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	double fine[20];

	cout << endl;
	cout << "--------------COMPLETE SERVICE--------------" << endl << endl;

	cout << "Press 1 to Cancel  Service of Ride" << endl;
	cout << "Press 2 to Cancel Service of Goods Transportation" << endl;

	op = _getch();

	cout << endl << endl;

	if (op == '1')
	{
		cout << "Enter Service ID: ";
		cin >> ID;
		cout << endl;
		cout << "Enter Customer ID: ";
		cin >> ID1;
		cout << endl;

		ifstream in("Ride_Services_List.txt");
		for (int i = 0; i < 20; i++)
		{
			in >> serviceID[i];
			in >> id[i];
			in >> passengers[i];
			in.getline(ridetype[i], 20);
			in.getline(ridetype[i], 20);
			in >> distance[i];
			in.getline(source[i], 20);
			in.getline(source[i], 20);
			in.getline(destination[i], 20);
			in >> fuelcost[i];
			in >> driID[i];
			in >> drirank[i];
			in >> vehiID[i];
			in >> vehirank[i];
			in >> day1[i];
			in >> month1[i];
			in >> year1[i];
			in >> hours[i];
			in >> mins[i];
			in >> sec[i];
			in >> stat[i];
			in >> fare[i];
		}
		in.close();

		ofstream out("Ride_Services_List.txt");

		int i = 0;
		for (i = 0; i < 20; i++)
		{
			if (serviceID[i] == ID)
			{
				stat[i] = 2;
				fine[i] = fare[i] * (5.0 / 100);
				out << serviceID[i] << endl;
				out << id[i] << endl;
				out << passengers[i] << endl;
				out << ridetype[i] << endl;
				out << distance[i] << endl;
				out << source[i] << endl;
				out << destination[i] << endl;
				out << fuelcost[i] << endl;
				out << driID[i] << endl;
				out << drirank[i] << endl;
				out << vehiID[i] << endl;
				out << vehirank[i] << endl;
				out << day1[i] << endl;
				out << month1[i] << endl;
				out << year1[i] << endl;
				out << hours[i] << endl;
				out << mins[i] << endl;
				out << sec[i] << endl;
				out << stat[i] << endl;
				out << fare[i] << endl;
			}
			else if (serviceID[i] > 0)
			{
				out << serviceID[i] << endl;
				out << id[i] << endl;
				out << passengers[i] << endl;
				out << ridetype[i] << endl;
				out << distance[i] << endl;
				out << source[i] << endl;
				out << destination[i] << endl;
				out << fuelcost[i] << endl;
				out << driID[i] << endl;
				out << drirank[i] << endl;
				out << vehiID[i] << endl;
				out << vehirank[i] << endl;
				out << day1[i] << endl;
				out << month1[i] << endl;
				out << year1[i] << endl;
				out << hours[i] << endl;
				out << mins[i] << endl;
				out << sec[i] << endl;
				out << stat[i] << endl;
				out << fare[i] << endl;
			}
		}
		out.close();

		cout << "Service Cancellation DONE" << endl;
		cout << "Fine Imposed: ";
		for (int i = 0; i < 20; i++)
		{
			if (fine[i] > 0)
			{
				cout << fine[i];
			}
		}
	}
	else if (op == '2')
	{
		cout << "Enter Service ID: ";
		cin >> ID;
		cout << endl;
		cout << "Enter Customer ID: ";
		cin >> ID1;
		cout << endl;

		ifstream in("Delivery_Services_List.txt");
		for (int i = 0; i < 20; i++)
		{
			in >> serviceID[i];
			in >> id[i];
			in >> weight[i];
			in.getline(goodstype[i], 20);
			in.getline(goodstype[i], 20);
			in >> distance[i];
			in.getline(source[i], 20);
			in.getline(source[i], 20);
			in.getline(destination[i], 20);
			in >> fuelcost[i];
			in >> driID[i];
			in >> vehiID[i];
			in >> day1[i];
			in >> month1[i];
			in >> year1[i];
			in >> hours[i];
			in >> mins[i];
			in >> sec[i];
			in >> stat[i];
			in >> fare[i];
		}
		in.close();

		ofstream out("Delivery_Services_List.txt");
		for (int i = 0; i < 20; i++)
		{
			if (serviceID[i] == ID)
			{
				stat[i] = 2;
				fine[i] = fare[i] * (5.0 / 100);
				out << serviceID[i] << endl;
				out << id[i] << endl;
				out << weight[i] << endl;
				out << goodstype[i] << endl;
				out << distance[i] << endl;
				out << source[i] << endl;
				out << destination[i] << endl;
				out << fuelcost[i] << endl;
				out << driID[i] << endl;
				out << vehiID[i] << endl;
				out << day1[i] << endl;
				out << month1[i] << endl;
				out << year1[i] << endl;
				out << hours[i] << endl;
				out << mins[i] << endl;
				out << sec[i] << endl;
				out << stat[i] << endl;
				out << fare[i] << endl;
			}
			else if (serviceID[i] > 0)
			{
				out << serviceID[i] << endl;
				out << id[i] << endl;
				out << weight[i] << endl;
				out << goodstype[i] << endl;
				out << distance[i] << endl;
				out << source[i] << endl;
				out << destination[i] << endl;
				out << fuelcost[i] << endl;
				out << driID[i] << endl;
				out << vehiID[i] << endl;
				out << day1[i] << endl;
				out << month1[i] << endl;
				out << year1[i] << endl;
				out << hours[i] << endl;
				out << mins[i] << endl;
				out << sec[i] << endl;
				out << stat[i] << endl;
				out << fare[i] << endl;
			}
		}
		out.close();

		cout << "Service Cancellation DONE" << endl;
		cout << "Fine Imposed: ";
		for (int i = 0; i < 20; i++)
		{
			if (fine[i] > 0)
			{
				cout << fine[i];
			}
		}
	}
}

void  TMS::completeservice()
{
	int day, month, year;
	int ID; char op; bool flag = false; int stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], weight[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20], goodstype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];

	cout << endl;
	cout << "--------------COMPLETE SERVICE--------------" << endl << endl;

	cout << "Press 1 to Complete Service of Ride" << endl;
	cout << "Press 2 to Complete Service of Goods Transportation" << endl;

	op = _getch();

	cout << endl << endl;

	if (op == '1')
	{
		cout << "Enter Service ID: ";
		cin >> ID;
		cout << endl;

		ifstream in("Ride_Services_List.txt");
		for (int i = 0; i < 20; i++)
		{
			in >> serviceID[i];
			in >> id[i];
			in >> passengers[i];
			in.getline(ridetype[i], 20);
			in.getline(ridetype[i], 20);
			in >> distance[i];
			in.getline(source[i], 20);
			in.getline(source[i], 20);
			in.getline(destination[i], 20);
			in >> fuelcost[i];
			in >> driID[i];
			in >> drirank[i];
			in >> vehiID[i];
			in >> vehirank[i];
			in >> day1[i];
			in >> month1[i];
			in >> year1[i];
			in >> hours[i];
			in >> mins[i];
			in >> sec[i];
			in >> stat[i];
			in >> fare[i];
		}
		in.close();

		for (int i = 0; i < 20; i++)
		{
			if (serviceID[i] == ID)
			{
				stat[i] = 1;

				cout << "Rank the Driver(0-5): ";
				cin >> drirank[i];
				cout << endl;
				cout << "Rank the Vehicle(0-5): ";
				cin >> vehirank[i];
				cout << endl;

				ofstream out("Ride_Services_List.txt");
				for (int i = 0; i < 20; i++)
				{
					if (serviceID[i] > 0)
					{
						out << serviceID[i] << endl;
						out << id[i] << endl;
						out << passengers[i] << endl;
						out << ridetype[i] << endl;
						out << distance[i] << endl;
						out << source[i] << endl;
						out << destination[i] << endl;
						out << fuelcost[i] << endl;
						out << driID[i] << endl;
						out << drirank[i] << endl;
						out << vehiID[i] << endl;
						out << vehirank[i] << endl;
						out << day1[i] << endl;
						out << month1[i] << endl;
						out << year1[i] << endl;
						out << hours[i] << endl;
						out << mins[i] << endl;
						out << sec[i] << endl;
						out << stat[i] << endl;
						out << fare[i] << endl;
					}
				}
				out.close();
			}
		}
	}
	else if (op == '2')
	{
		cout << "Enter Service ID: ";
		cin >> ID;
		cout << endl;

		ifstream in("Delivery_Services_List.txt");
		for (int i = 0; i < 20; i++)
		{
			in >> serviceID[i];
			in >> id[i];
			in >> weight[i];
			in.getline(goodstype[i], 20);
			in.getline(goodstype[i], 20);
			in >> distance[i];
			in.getline(source[i], 20);
			in.getline(source[i], 20);
			in.getline(destination[i], 20);
			in >> fuelcost[i];
			in >> driID[i];
			in >> vehiID[i];
			in >> day1[i];
			in >> month1[i];
			in >> year1[i];
			in >> hours[i];
			in >> mins[i];
			in >> sec[i];
			in >> stat[i];
			in >> fare[i];
		}
		in.close();

		for (int i = 0; i < 20; i++)
		{
			if (serviceID[i] == ID)
			{
				stat[i] = 1;

				cout << "Rank the Driver(0-5): ";
				cin >> drirank[i];
				cout << endl;
				cout << "Rank the Vehicle(0-5): ";
				cin >> vehirank[i];
				cout << endl;

				cout << "Enter Date of Delivery: ";
				cout << endl;
				cout << "Enter Day(dd): ";
				cin >> day;
				cout << endl;
				cout << "Enter Month(mm): ";
				cin >> month;
				cout << endl;
				cout << "Enter Year: ";
				cin >> year;
				cout << endl;

				ofstream out1("completed.txt", ios::app);
				out1 << day << endl;
				out1 << month << endl;
				out1 << year << endl;
				out1.close();

				ofstream out("Delivery_Services_List.txt");
				for (int i = 0; i < 20; i++)
				{
					if (serviceID[i] > 0)
					{
						out << serviceID[i] << endl;
						out << id[i] << endl;
						out << weight[i] << endl;
						out << goodstype[i] << endl;
						out << distance[i] << endl;
						out << source[i] << endl;
						out << destination[i] << endl;
						out << fuelcost[i] << endl;
						out << driID[i] << endl;
						out << vehiID[i] << endl;
						out << day1[i] << endl;
						out << month1[i] << endl;
						out << year1[i] << endl;
						out << hours[i] << endl;
						out << mins[i] << endl;
						out << sec[i] << endl;
						out << stat[i] << endl;
						out << fare[i] << endl;
					}
				}
				out.close();
			}
		}
	}
}

void  TMS::samevehicle()
{
	bool flag = false; int  stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	char fname[15][10]; char lname[15][10]; int age[15]; int day[15]; int month[15];
	int year[15]; int id1[15];

	cout << endl;
	cout << "--------------SAME VEHICLES USED--------------" << endl << endl;

	ifstream in1("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		in1 >> i;
		in1 >> fname[k];
		in1 >> lname[k];
		in1 >> age[k];
		in1 >> day[k];
		in1 >> month[k];
		in1 >> year[k];
		in1 >> id1[k];
	}
	in1.close();

	ifstream in("Ride_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in >> serviceID[i];
		in >> id[i];
		in >> passengers[i];
		in.getline(ridetype[i], 20);
		in.getline(ridetype[i], 20);
		in >> distance[i];
		in.getline(source[i], 20);
		in.getline(source[i], 20);
		in.getline(destination[i], 20);
		in >> fuelcost[i];
		in >> driID[i];
		in >> drirank[i];
		in >> vehiID[i];
		in >> vehirank[i];
		in >> day1[i];
		in >> month1[i];
		in >> year1[i];
		in >> hours[i];
		in >> mins[i];
		in >> sec[i];
		in >> stat[i];
		in >> fare[i];
	}
	in.close();

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (id1[i] == id[j] && vehiID[i] == vehiID[j] && (day1[i] != day1[j] || month1[i] != month1[j] || year1[i] != year1[j]))
			{
				cout << "First Name: " << fname[i] << endl;
				cout << "Last Name: " << lname[i] << endl;
				cout << "Age: " << age[i] << endl;
				cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i];
				cout << endl;
				cout << "Customer ID: " << id1[i];
				cout << endl << endl;

				cout << "Service ID: " << serviceID[i] << endl;
				cout << "Customer ID: " << id[i] << endl;
				cout << "No of Passengers: " << passengers[i] << endl;
				cout << "Ride Type: " << ridetype[i] << endl;
				cout << "Source: " << source[i] << endl;
				cout << "Destination: " << destination[i] << endl;
				cout << "Distance: " << distance[i] << endl;
				cout << "Date of Booking: ";
				cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
				cout << "Time of Booking: ";
				cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
				cout << "Fare: " << fare[i] << endl;
				cout << "Status of Booking: " << stat[i] << endl;
				cout << "Driver Ranked: " << drirank[i] << endl;
				cout << "Vehicle Ranked: " << vehirank[i] << endl;
				cout << endl << endl;
				cout << "Service ID: " << serviceID[j] << endl;
				cout << "Customer ID: " << id[j] << endl;
				cout << "No of Passengers: " << passengers[j] << endl;
				cout << "Ride Type: " << ridetype[j] << endl;
				cout << "Source: " << source[j] << endl;
				cout << "Destination: " << destination[j] << endl;
				cout << "Distance: " << distance[j] << endl;
				cout << "Date of Booking: ";
				cout << day1[j] << " " << month1[j] << " " << year1[j] << endl;
				cout << "Time of Booking: ";
				cout << hours[j] << " : " << mins[j] << " : " << sec[j] << endl;
				cout << "Fare: " << fare[j] << endl;
				cout << "Status of Booking: " << stat[j] << endl;
				cout << "Driver Ranked: " << drirank[j] << endl;
				cout << "Vehicle Ranked: " << vehirank[i] << endl;
				cout << endl << endl;
			}
		}
	}
}

void  TMS::instantdelivery()
{
	bool flag = false; int stat2[20];
	int day[20], month[20], year[20];
	int day2[20], month2[20], year2[20], hours2[20], mins2[20], sec2[20];
	int fuelcost2[20], distance2[20], weight2[20], id2[20];
	char source2[20][20], destination2[20][20], goodstype2[20][20];
	int driID2[20], vehiID2[20], serviceID2[20]; float fare2[20];
	char fname[10][15]; char lname[10][15]; int age[10]; int id[10];
	int salary[10], experience[10], noofliscence[10]; int liscenses[10]; float ranking[10];

	ifstream in("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		in >> j;
		in >> fname[i];
		in >> lname[i];
		in >> age[i];
		in >> day[i];
		in >> month[i];
		in >> year[i];
		in >> id[i];
		in >> experience[i];
		in >> ranking[i];
		in >> salary[i];
		in >> noofliscence[i];
		for (int j = 0; j < noofliscence[i]; j++)
		{
			in >> liscenses[i];
		}
	}
	in.close();

	ifstream in2("completed.txt");
	for (int i = 0; i < 20; i++)
	{
		in2 >> day[i];
		in2 >> month[i];
		in2 >> year[i];
	}
	in2.close();

	cout << endl;
	cout << "--------------INSTANT DELIVERIES--------------" << endl << endl;

	ifstream in1("Delivery_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in1 >> serviceID2[i];
		in1 >> id2[i];
		in1 >> weight2[i];
		in1.getline(goodstype2[i], 20);
		in1.getline(goodstype2[i], 20);
		in1 >> distance2[i];
		in1.getline(source2[i], 20);
		in1.getline(source2[i], 20);
		in1.getline(destination2[i], 20);
		in1 >> fuelcost2[i];
		in1 >> driID2[i];
		in1 >> vehiID2[i];
		in1 >> day2[i];
		in1 >> month2[i];
		in1 >> year2[i];
		in1 >> hours2[i];
		in1 >> mins2[i];
		in1 >> sec2[i];
		in1 >> stat2[i];
		in1 >> fare2[i];
	}
	in1.close();

	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		if (day[i] == day2[i] && month[i] == month2[i] && year[i] == year2[i] && day[i] > 0)
		{
			for (int j = 0; j < 10; j++)
			{
				if (driID2[i] == id[j])
				{
					cout << "First Name: " << fname[j] << endl;
					cout << "Last Name: " << lname[j] << endl;
					cout << "Age: " << age[j] << endl;
					cout << "Date of Birth: " << day[j] << " " << month[j] << " " << year[j] << endl;
					cout << "Driver ID: " << id[j] << endl;
					cout << "Experience: " << experience[j] << endl;
					cout << "Overall Ranking: " << ranking[j] << endl;
					cout << "Salary: " << salary[j] << endl;
					cout << "Number of Liscences: " << noofliscence[j] << endl;
					cout << "Liscences: ";
					for (int k = 0; k < noofliscence[j]; k++)
					{
						cout << liscenses[j] << "  ";
					}
					cout << endl << endl;
				}
			}
			cout << "Service ID: " << serviceID2[i] << endl;
			cout << "Customer ID: " << id2[i] << endl;
			cout << "Driver ID: " << driID2[i] << endl;
			cout << "Goods Type: " << goodstype2[i] << endl;
			cout << "Goods Weight: " << weight2[i] << endl;
			cout << "Source: " << source2[i] << endl;
			cout << "Destination: " << destination2[i] << endl;
			cout << "Distance: " << distance2[i] << endl;
			cout << "Date of Booking: ";
			cout << day2[i] << " " << month2[i] << " " << year2[i] << endl;
			cout << "Time of Booking: ";
			cout << hours2[i] << " : " << mins2[i] << " : " << sec2[i] << endl;
			cout << "Status of Booking: " << stat2[i] << endl;
			cout << "Date of Delivery: ";
			cout << day[i] << " " << month[i] << " " << year[i] << endl;
			cout << "Fare: " << fare2[i] << endl;
			cout << endl << endl;
		}
	}
}

void  TMS::datependings()
{
	int day, month, year;
	bool flag = false; int  stat[20], stat2[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	int day2[20], month2[20], year2[20], hours2[20], mins2[20], sec2[20];
	int fuelcost2[20], distance2[20], weight2[20], id2[20];
	char source2[20][20], destination2[20][20], goodstype2[20][20];
	int driID2[20], vehiID2[20], serviceID2[20]; float fare2[20];

	cout << endl;
	cout << "--------------PENDING SERVICES ON PARTICULAR DATE--------------" << endl << endl;

	cout << "Enter Date(dd/mm/yyyy): ";
	cout << endl << endl;
	cout << "Enter Day(dd): ";
	cin >> day;
	cout << endl;
	cout << "Enter Month(mm): ";
	cin >> month;
	cout << endl;
	cout << "Enter Year: ";
	cin >> year;
	cout << endl;

	ifstream in("Ride_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in >> serviceID[i];
		in >> id[i];
		in >> passengers[i];
		in.getline(ridetype[i], 20);
		in.getline(ridetype[i], 20);
		in >> distance[i];
		in.getline(source[i], 20);
		in.getline(source[i], 20);
		in.getline(destination[i], 20);
		in >> fuelcost[i];
		in >> driID[i];
		in >> drirank[i];
		in >> vehiID[i];
		in >> vehirank[i];
		in >> day1[i];
		in >> month1[i];
		in >> year1[i];
		in >> hours[i];
		in >> mins[i];
		in >> sec[i];
		in >> stat[i];
		in >> fare[i];
	}
	in.close();

	cout << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		if (day1[i] == day && month1[i] == month && year1[i] == year && stat[i] == 0)
		{
			cout << "Service ID: " << serviceID[i] << endl;
			cout << "Driver ID: " << driID[i] << endl;
			cout << "Ride Type: " << ridetype[i] << endl;
			cout << "Source: " << source[i] << endl;
			cout << "Destination: " << destination[i] << endl;
			cout << "Distance: " << distance[i] << endl;
			cout << "Date of Booking: ";
			cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
			cout << "Time of Booking: ";
			cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
			cout << "Fare: " << fare[i] << endl;
			cout << "Status of Booking: " << stat[i] << endl;
			cout << "Driver Ranked: " << drirank[i] << endl;
			cout << endl << endl;
		}
	}

	ifstream in1("Delivery_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in1 >> serviceID2[i];
		in1 >> id2[i];
		in1 >> weight2[i];
		in1.getline(goodstype2[i], 20);
		in1.getline(goodstype2[i], 20);
		in1 >> distance2[i];
		in1.getline(source2[i], 20);
		in1.getline(source2[i], 20);
		in1.getline(destination2[i], 20);
		in1 >> fuelcost2[i];
		in1 >> driID2[i];
		in1 >> vehiID2[i];
		in1 >> day2[i];
		in1 >> month2[i];
		in1 >> year2[i];
		in1 >> hours2[i];
		in1 >> mins2[i];
		in1 >> sec2[i];
		in1 >> stat2[i];
		in1 >> fare2[i];
	}
	in1.close();

	cout << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		if (day2[i] == day && month2[i] == month && year2[i] == year && stat2[i] == 0)
		{
			cout << "Service ID: " << serviceID2[i] << endl;
			cout << "Customer ID: " << id2[i] << endl;
			cout << "Driver ID: " << driID2[i] << endl;
			cout << "Goods Type: " << goodstype2[i] << endl;
			cout << "Goods Weight: " << weight2[i] << endl;
			cout << "Source: " << source2[i] << endl;
			cout << "Destination: " << destination2[i] << endl;
			cout << "Distance: " << distance2[i] << endl;
			cout << "Date of Booking: ";
			cout << day2[i] << " " << month2[i] << " " << year2[i] << endl;
			cout << "Time of Booking: ";
			cout << hours2[i] << " : " << mins2[i] << " : " << sec2[i] << endl;
			cout << "Status of Booking: " << stat2[i] << endl;
			cout << "Fare: " << fare2[i] << endl;
			cout << endl << endl;
		}
	}
}

void  TMS::driverpendings()
{
	int ID; bool flag = false; int  stat[20], stat2[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	int day2[20], month2[20], year2[20], hours2[20], mins2[20], sec2[20];
	int fuelcost2[20], distance2[20], weight2[20], id2[20];
	char source2[20][20], destination2[20][20], goodstype2[20][20];
	int driID2[20], vehiID2[20], serviceID2[20]; float fare2[20];

	cout << endl;
	cout << "--------------PENDING SERVICES OF PARTICULAR DRIVER--------------" << endl << endl;

	cout << "Enter Driver ID: ";
	cin >> ID;

	ifstream in("Ride_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in >> serviceID[i];
		in >> id[i];
		in >> passengers[i];
		in.getline(ridetype[i], 20);
		in.getline(ridetype[i], 20);
		in >> distance[i];
		in.getline(source[i], 20);
		in.getline(source[i], 20);
		in.getline(destination[i], 20);
		in >> fuelcost[i];
		in >> driID[i];
		in >> drirank[i];
		in >> vehiID[i];
		in >> vehirank[i];
		in >> day1[i];
		in >> month1[i];
		in >> year1[i];
		in >> hours[i];
		in >> mins[i];
		in >> sec[i];
		in >> stat[i];
		in >> fare[i];
	}
	in.close();

	cout << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		if (driID[i] == ID && stat[i] == 0)
		{
			cout << "Service ID: " << serviceID[i] << endl;
			cout << "Driver ID: " << driID[i] << endl;
			cout << "Ride Type: " << ridetype[i] << endl;
			cout << "Source: " << source[i] << endl;
			cout << "Destination: " << destination[i] << endl;
			cout << "Distance: " << distance[i] << endl;
			cout << "Date of Booking: ";
			cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
			cout << "Time of Booking: ";
			cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
			cout << "Fare: " << fare[i] << endl;
			cout << "Status of Booking: " << stat[i] << endl;
			cout << "Driver Ranked: " << drirank[i] << endl;
			cout << endl << endl;
		}
	}

	ifstream in1("Delivery_Services_List.txt");
	for (int i = 0; i < 20; i++)
	{
		in1 >> serviceID2[i];
		in1 >> id2[i];
		in1 >> weight2[i];
		in1.getline(goodstype2[i], 20);
		in1.getline(goodstype2[i], 20);
		in1 >> distance2[i];
		in1.getline(source2[i], 20);
		in1.getline(source2[i], 20);
		in1.getline(destination2[i], 20);
		in1 >> fuelcost2[i];
		in1 >> driID2[i];
		in1 >> vehiID2[i];
		in1 >> day2[i];
		in1 >> month2[i];
		in1 >> year2[i];
		in1 >> hours2[i];
		in1 >> mins2[i];
		in1 >> sec2[i];
		in1 >> stat2[i];
		in1 >> fare2[i];
	}
	in1.close();

	cout << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		if (driID2[i] == ID && stat2[i] == 0)
		{
			cout << "Service ID: " << serviceID2[i] << endl;
			cout << "Customer ID: " << id2[i] << endl;
			cout << "Driver ID: " << driID2[i] << endl;
			cout << "Goods Type: " << goodstype2[i] << endl;
			cout << "Goods Weight: " << weight2[i] << endl;
			cout << "Source: " << source2[i] << endl;
			cout << "Destination: " << destination2[i] << endl;
			cout << "Distance: " << distance2[i] << endl;
			cout << "Date of Booking: ";
			cout << day2[i] << " " << month2[i] << " " << year2[i] << endl;
			cout << "Time of Booking: ";
			cout << hours2[i] << " : " << mins2[i] << " : " << sec2[i] << endl;
			cout << "Status of Booking: " << stat2[i] << endl;
			cout << "Fare: " << fare2[i] << endl;
			cout << endl << endl;
		}
	}
}

void  TMS::cancelledrequests()
{
	int ID; char op; bool flag = false; int  stat[20];
	int day1[20], month1[20], year1[20], hours[20], mins[20], sec[20];
	int fuelcost[20], distance[20], passengers[20], weight[20], id[20];
	char source[20][20], destination[20][20], ridetype[20][20], goodstype[20][20];
	int driID[20], vehiID[20], serviceID[20]; float drirank[20], vehirank[20], fare[20];
	char fname[15][10]; char lname[15][10]; int age[15]; int day[15]; int month[15];
	int year[15]; int id1[15];

	ifstream in("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		in >> i;
		in >> fname[k];
		in >> lname[k];
		in >> age[k];
		in >> day[k];
		in >> month[k];
		in >> year[k];
		in >> id1[k];
	}
	in.close();

	cout << endl;
	cout << "--------------CUSTOMER CANCELLED SERVICES--------------" << endl << endl;

	cout << "Enter Customer ID: ";
	cin >> ID;

	for (int i = 0; i < 15; i++)
	{
		if (id1[i] == ID)
		{
			flag = true;
		}
	}

	cout << endl;

	if (flag == true)
	{
		cout << "Press 1 to Retrieve Rides Services History" << endl;
		cout << "Press 2 to Retrieve Delivery Services History" << endl;

		op = _getch();

		if (op == '1')
		{
			ifstream in("Ride_Services_List.txt");

			for (int i = 0; i < 20; i++)
			{
				in >> serviceID[i];
				in >> id[i];
				in >> passengers[i];
				in.getline(ridetype[i], 20);
				in.getline(ridetype[i], 20);
				in >> distance[i];
				in.getline(source[i], 20);
				in.getline(source[i], 20);
				in.getline(destination[i], 20);
				in >> fuelcost[i];
				in >> driID[i];
				in >> drirank[i];
				in >> vehiID[i];
				in >> vehirank[i];
				in >> day1[i];
				in >> month1[i];
				in >> year1[i];
				in >> hours[i];
				in >> mins[i];
				in >> sec[i];
				in >> stat[i];
				in >> fare[i];
			}

			in.close();

			cout << endl;

			for (int i = 0; i < 15; i++)
			{
				if (id1[i] == ID)
				{
					cout << "First Name: " << fname[i] << endl;
					cout << "Last Name: " << lname[i] << endl;
					cout << "Age: " << age[i] << endl;
					cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i];
					cout << endl;
					cout << "Customer ID: " << id1[i];
					cout << endl << endl;
				}
				if (id1[i] == ID && stat[i] == 2)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Customer ID: " << id[i] << endl;
					cout << "No of Passengers: " << passengers[i] << endl;
					cout << "Ride Type: " << ridetype[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Driver Ranked: " << drirank[i] << endl;
					cout << "Vehicle Ranked: " << vehirank[i] << endl;
					cout << endl << endl;
				}
			}
		}
		else if (op == '2')
		{
			ifstream in("Delivery_Services_List.txt");

			for (int i = 0; i < 20; i++)
			{
				in >> serviceID[i];
				in >> id[i];
				in >> weight[i];
				in.getline(goodstype[i], 20);
				in.getline(goodstype[i], 20);
				in >> distance[i];
				in.getline(source[i], 20);
				in.getline(source[i], 20);
				in.getline(destination[i], 20);
				in >> fuelcost[i];
				in >> driID[i];
				in >> vehiID[i];
				in >> day1[i];
				in >> month1[i];
				in >> year1[i];
				in >> hours[i];
				in >> mins[i];
				in >> sec[i];
				in >> stat[i];
				in >> fare[i];
			}

			in.close();

			cout << endl << endl;

			for (int i = 0; i < 15; i++)
			{
				if (id1[i] == ID)
				{
					cout << "First Name: " << fname[i] << endl;
					cout << "Last Name: " << lname[i] << endl;
					cout << "Age: " << age[i] << endl;
					cout << "Date of Birth: " << day[i] << " " << month[i] << " " << year[i];
					cout << endl;
					cout << "Customer ID: " << id1[i];
					cout << endl << endl;
				}
				if (id[i] == ID && stat[i] == 2)
				{
					cout << "Service ID: " << serviceID[i] << endl;
					cout << "Customer ID: " << id[i] << endl;
					cout << "Goods Type: " << goodstype[i] << endl;
					cout << "Goods Weight: " << weight[i] << endl;
					cout << "Source: " << source[i] << endl;
					cout << "Destination: " << destination[i] << endl;
					cout << "Distance: " << distance[i] << endl;
					cout << "Date of Booking: ";
					cout << day1[i] << " " << month1[i] << " " << year1[i] << endl;
					cout << "Time of Booking: ";
					cout << hours[i] << " : " << mins[i] << " : " << sec[i] << endl;
					cout << "Status of Booking: " << stat[i] << endl;
					cout << "Driver Ranked: " << drirank[i] << endl;
					cout << "Vehicle Ranked: " << vehirank[i] << endl;
					cout << "Fare: " << fare[i] << endl;
					cout << endl << endl;
				}
			}
		}
	}
	else cout << "First Add Customer by choosing Option A";
}

TMS::~TMS()
{
	delete[] c;
	c = nullptr;
	delete[] v;
	v = nullptr;
	delete[] d;
	d = nullptr;
}