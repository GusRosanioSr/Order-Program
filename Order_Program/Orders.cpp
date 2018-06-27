#include "stdafx.h"
#include "Orders.h"
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

namespace rosanio_order
{

	Orders::Orders()
	{
		this->length = 0;
		this->head = NULL;
		// creates the variable for the file
		std::ofstream myfile;
	}

	Orders::~Orders()
	{

	}

	void Orders::add(int data, std::string name, std::string address, std::string date, int payment, std::string phone,
		std::string time, bool exempt, std::string requests)
	{
		assert(data >= 0);
		Order *order = new Order(data);
		order->link_field = this->head;
		this->head = order;
		this->length++;
		order->create_order(name, address, date, payment, phone, time, exempt, requests);
		// write all of the information to the txt file
		myfile << "Order number: " << head->get_order_number() << std::endl;
	    myfile << "Name on the order: " << head->get_name() << std::endl;
		myfile << "Date of the order: " << head->get_date() << std::endl;
		myfile << "Time of the order: " << head->get_time() << std::endl;
		myfile << "Address the order will be delvered to: " << head->get_address() << std::endl;
		myfile << "Customer phone number: " << head->get_phone() << std::endl;
		myfile << "Payment method: " << head->get_payment_method() << std::endl;
		myfile << "Special requests for the order: " << head->get_requests() << std::endl;
		myfile << "Customer tax exempt: " << head->get_tax_status() << std::endl;
		myfile << "Size of the order: " << head->get_size() << std::endl;
		// loop to input items into the order
		std::cout << "Time to add some items to the order." << std::endl;
		int done = 0;
		while (done != -1)
		{
			// creates an string for the item
			std::string item;
			std::cout << "Item: ";
			std::cin.ignore();
			std::getline(std::cin, item);
			myfile << "Item " << done + 1 << ": " << item << std::endl;
			// add the item to the string
			order->add_item(item);
			char decision;
			std::cout << "Any more items to add? (enter y for yes and n for no) : ";
			std::cin >> decision;
			// check to see what decision the user made
			if ((decision == 'y' || decision == 'y'))
			{
				done++;
			}
			else if ((decision == 'n' || decision == 'N'))
			{
				done = -1;
			}
		}
		myfile << " " << std::endl;
	}

	void Orders::print()
	{
		Order* head = this->head;
		int i = 1;
		while (head) {
			std::cout << "Order number: " << head->get_order_number() << std::endl;
			std::cout << "Name on the order: " << head->get_name() << std::endl;
			std::cout << "Date of the order: " << head->get_date() << std::endl;
			std::cout << "Time of the order: " << head->get_time() << std::endl;
			std::cout << "Address the order will be delvered to: " << head->get_address() << std::endl;
			std::cout << "Customer phone number: " << head->get_phone() << std::endl;
			std::cout << "Payment method: " << head->get_payment_method() << std::endl;
			std::cout << "Special requests for the order: " << head->get_requests() << std::endl;
			std::cout << "Customer tax exempt: " << head->get_tax_status() << std::endl;
			std::cout << "Size of the order: " << head->get_size() << std::endl;
			head->get_order();
			std::cout << " " << std::endl;
			if (head->get_order_status() == 1)
			{
				std::cout << "Order is not canceled" << std::endl;
				std::cout << " " << std::endl;
			}
			else if (head->get_order_status() == 0)
			{
				std::cout << "Order is canceled" << std::endl;
				std::cout << " " << std::endl;
			}

			head = head->link_field;
			i++;
		}
	}

	void Orders::print_instructions()
	{
		std::cout << "Hello and welcome to the GLR order managment system " << std::endl;
		std::cout << "Operations you can perform on the orders are listed below " << std::endl;

	}
	void Orders::open_file()
	{
		// use std::ios::out to make it the out fiel
		// use std::ios::app to append the file
		myfile.open("Orders.txt", std::ios::out | std::ios::app);
	}
	void Orders::close_file()
	{
		myfile.close();
	}
}