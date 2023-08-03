#include <iostream>
#include<conio.h>
#include"TMS.h"

using namespace std;


int main()
{
	char op = 0;
	TMS t;

	while (1)
	{

		cout << "-------------------------------------------------------" << endl;
		cout << "             TRANSPORT MANAGEMENT SYSTEM               " << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Press A to Add a New Customer" << endl;
		cout << "Press B to Add a New Driver" << endl;
		cout << "Press C to Remove a Driver" << endl;
		cout << "Press D to Add a New Vehicle" << endl;
		cout << "Press E to Remove a Vehicle" << endl;
		cout << "Press F to Retrieve Customers Data" << endl;
		cout << "Press G to Retrieve Drivers Data" << endl;
		cout << "Press H to Retrieve Vehicles Data" << endl;
		cout << "Press I to Retrieve Vehicle Service History" << endl;
		cout << "Press J to Retrieve Customer Service History" << endl;
		cout << "Press K to Retrieve Driver Service History" << endl;
		cout << "Press L to Retrieve Best Drivers" << endl;
		cout << "Press M to Retrieve Drivers with Multiple Liscenes" << endl;
		cout << "Press N to Retrieve Updated Salary of Drivers" << endl;
		cout << "Press O to Add a Service Request" << endl;
		cout << "Press P to Cancel a Booking" << endl;
		cout << "Press Q to Complete a Service" << endl;
		cout << "Press R to Retrieve Customers with Same Vehicle Usage" << endl;
		cout << "Press S to Retrieve Drivers with Instant Delivery" << endl;
		cout << "Press T to Retrieve Pending Services On Particlur Date" << endl;
		cout << "Press U to Retrieve Pending Services of a Particular Driver" << endl;
		cout << "Press V to Retrieve Cancelled Services of a Particular Customer" << endl;

		op = _getch();

		if (op == 'a' || op == 'A')
		{
			system("cls");
			t.newcustomer();
		}
		else if (op == 'b' || op == 'B')
		{
			system("cls");
			t.newdriver();
		}
		else if (op == 'c' || op == 'C')
		{
			system("cls");
			t.removedriver();
		}
		else if (op == 'd' || op == 'D')
		{
			system("cls");
			t.addvehicle();
		}
		else if (op == 'e' || op == 'E')
		{
			system("cls");
			t.removevehicle();
		}
		else if (op == 'f' || op == 'F')
		{
			system("cls");
			t.customerdata();
		}
		else if (op == 'g' || op == 'G')
		{
			system("cls");
			t.driversdata();
		}
		else if (op == 'h' || op == 'H')
		{
			system("cls");
			t.vehicledata();
		}
		else if (op == 'i' || op == 'I')
		{
			system("cls");
			t.vehicleservices();
		}
		else if (op == 'j' || op == 'J')
		{
			system("cls");
			t.customerservices();
		}
		else if (op == 'k' || op == 'K')
		{
			system("cls");
			t.driverservices();
		}
		else if (op == 'l' || op == 'L')
		{
			system("cls");
			t.bestdrivers();
		}
		else if (op == 'm' || op == 'M')
		{
			system("cls");
			t.multiplelisdrivers();
		}
		else if (op == 'n' || op == 'N')
		{
			system("cls");
			t.updatedsalary();
		}
		else if (op == 'o' || op == 'O')
		{
			system("cls");
			t.addrequest();
		}
		else if (op == 'p' || op == 'P')
		{
			system("cls");
			t.cancelrequest();
		}
		else if (op == 'q' || op == 'Q')
		{
			system("cls");
			t.completeservice();
		}
		else if (op == 'r' || op == 'R')
		{
			system("cls");
			t.samevehicle();
		}
		else if (op == 's' || op == 'S')
		{
			system("cls");
			t.instantdelivery();
		}
		else if (op == 't' || op == 'T')
		{
			system("cls");
			t.datependings();
		}
		else if (op == 'u' || op == 'U')
		{
			system("cls");
			t.driverpendings();
		}
		else if (op == 'v' || op == 'V')
		{
			system("cls");
			t.cancelledrequests();
		}

		cout << endl << endl;
	}
	return 0;
}