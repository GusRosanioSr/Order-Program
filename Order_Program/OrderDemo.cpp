#include "stdafx.h"
#include "Order.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
using namespace group_project_order;

int main()
{
	bool status = true;
	bool exempt = false;
	char choice;
	char y = 'y';
	char n = 'n';
	int orderNumber;
	string name;
	string phoneNumber;
	string date;
	string time;
	string address;
	string item;
	string requests;

	cout << "Please input the order number: " << endl;
	cin >> orderNumber;
	Order order(orderNumber);

	bool done = false;
	while (done != true)
	{
		
		cout << "Now geting the order number." << endl;
		cout << "Order number is: " << order.get_order_number() << endl;

		cout << "Please enter the customer name now: " << endl;
		cin.ignore();
		getline(cin, name);
		order.change_name(name);
		cout << "Customer name is: " << order.get_name() << endl;

		cout << "Please enter the customers phone number: " << endl;
		getline(cin, phoneNumber);
		order.change_phone(phoneNumber);
		cout << "Phone number is: " << order.get_phone() << endl;

		cout << "Please enter the date for the order: " << endl;
		getline(cin, date);
		order.change_date(date);
		cout << "Date of the order is: " << order.get_date() << endl;

		cout << "Please enter the time for the order: " << endl;
		getline(cin, time);
		order.change_time(time);
		cout << "Time of the order is : " << order.get_time() << endl;

		cout << "Please enter the address the order will go to: " << endl;
		getline(cin, address);
		order.change_address(address);
		cout << "the address for the order is: " << order.get_address() << endl;

		cout << "Pleas enter in any special requests now: " << endl;
		getline(cin, requests);
		order.special_requests(requests);
		cout << "Special requests : " << order.get_requests() << " " << "recieved." << endl;
		
		cout << "Please enter an item into the order now: ";
		cin >> item;
		order.add_item(item);
		cout << "Item: " << item << " " << "was added to the order." << endl;
		cout << "All item in the order are: " << endl;
		order.get_order();

		
		cout << "Does the order need to canceled? enter y or n: " << endl;
		cin >> choice; // User's decision to cancel order
		choice = tolower(choice);
		if (choice == y)
		{
			status = true;
			cout << "The order will be canceled" << endl;
		}
		else if (choice == n)
		{
			status = false;
			cout << "The order will not be canceled" << endl;
		}
		order.cancel_order(status);

		
		char answer;
		cout << "Are you done with the demo? Enter y or n: ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y)')
		{
			done = true;
		}
		else if (answer == 'n' || answer == 'Y')
		{
			done = false;
		}
		
	}

	return 0;
}