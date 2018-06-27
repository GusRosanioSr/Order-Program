#include "stdafx.h"
#include "Order.h"
#include "Orders.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
using namespace rosanio_order;

int main()
{
	// create the orders linked list
	Orders orders;
	// open the txt file
	orders.open_file();
	// create variables
	int data, payment;
	string name, address, date, phone, time, requests;
	bool exempt, status;
	// prints the user instructions
	orders.print_instructions();
	// start the main loop of the user interface
	bool quit = false;
	while(quit != true)
	{
		cout << " " << endl;
		cout << "Please select an option" << endl;
		char choice;
		cout << "1: Add order" << endl;
		cout << "2: Print the orders" << endl;
		cout << "3: Exit the order managment system" << endl;
		cin >> choice;
		// check to see what the user decided to do
		if (choice == '1')
		{
			cout << "Please enter the order information now: " << endl;
			cout << "Order number: ";
			cin >> data;
			cout << "Name on the order: ";
			cin.ignore();
			getline(cin, name);
			cout << "Order date: ";
			getline(cin, date);
			cout << "Time to be delivered: ";
			getline(cin, time);
			cout << "Address: ";
			getline(cin, address);
			cout << "Phone number:";
			getline(cin, phone);
			cout << "Payment type (1 for cash, 2 for card, 3 for check): ";
			bool done = false;
			while (done != true)
			{
				cin >> payment;
				if ((payment == 1) || (payment == 2) || (payment == 3))
				{
					payment = payment;
					done = true;
				}
				else
				{
					cout << "ERROR. Please input a valid payment mehtod" << endl;
					cout << "Payment type (1 for cash, 2 for card, 3 for check): " << endl;
					done = false;
				}
			}
			cout << "Special requests: ";
			cin.ignore();
			getline(cin, requests);
			cout << "Enter Tax Status(1 for is exempt, 0 for not): ";
			cin >> exempt;
			orders.add(data, name, address, date, payment, phone, time, exempt, requests);

			// ensures the loop continues
			choice = false;
		}
		else if (choice == '2')
		{
			orders.print();
			// ensures the loop continues
			choice = false;
		}
		else if (choice == '3')
		{
			cout << "Thank you for using the GLR order managment system. Have a great day." << endl;
			// ensures the loop exits
			quit = true;
		}
		else
		{
			cout << "Error, please input a valid choice from the menu above." << endl;
		}

		
		
	}
	// calls the mehtod to close the txt file
	orders.close_file();

	// pause the system so that it doesnt exit on its own
	system("PAUSE");


	return EXIT_SUCCESS;
}