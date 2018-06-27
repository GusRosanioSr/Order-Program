/*
FILE: Orders.h
Gustave Rosanio
Header file for Orders (Linked List class)

CONSTRUCTOR for the Orders class
	Orders()

DECONSTRUCTOR for the Orders class
	~Orders()

FUNCTIONS
void add(int data, std::string name, std::string address, std::string date, int payment, std::string phone,
		 std::string time, bool exempt, bool status, std::string requests);
	pre conditions: name, address, date, phone, time, and requests must all be strings. payment must be an integer,
					exempt and status must be boolean values
	post condition: creates an order with all of the above parameters

void print()
	post condition: prints out all of the Order nodes in the linked list

void print_instructions()
	post condition: prints user instructions

void open_file()
	pre condition: have a txt file named Orders that can be opened
	post condition: opens the file

void close_file()
	pre condition: have a txt file that matches the file you open so you can close it
	post condition: close the file
*/
#include "Order.h"
#include <string>
#include <fstream>
#pragma once
#ifndef ROSANIO_ORDERS
#define ROSANIO_ORDERS
namespace rosanio_order
{
#pragma once
	class Orders
	{
	public:
		// typedef string so it can be used easier in the header file
		typedef std::string string; 

		// Constructor
		Orders();
		// Destructor
		~Orders();

		// Modification member functions
		void add(int data, std::string name, std::string address, std::string date, int payment, std::string phone,
			     std::string time, bool exempt, std::string requests);

		// Constant member functions
		void print();
		void print_instructions();
		void open_file();
		void close_file();
		
		// Variables
		// length of the list
		int length;
		// head of the list
		Order* head;
		// creates the variable for the file
		std::ofstream myfile;
	};
}
#endif // !PROJECT_ORDERS