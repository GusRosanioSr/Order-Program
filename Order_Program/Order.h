/*
FILE: Order.h
Gustave Rosanio
Header file for Order (Node class)

CONSTRUCTOR for the order class
	Order(int orderNumber)
	pre condition: orderNumber must be a positive number)
	post conditon: creates an instance of the Order class

DECONSTRUCTOR for the order class
	~Order()

 MODIFICATION MEMBER FUNCTIONS

string change_name(string name)
	pre conditions: name must be a string of charachters
	post condition: changes the name of the customer on the order

string change_phone(string phone)
	pre condition: phone must be a string of charachters
	post condition: changes the phone number on the order

string change_date(string date)
	pre condition: date must be a string of charachters
	post condition: changes the date of the order

string change_time(string time)
	pre condition: time must be a string of charachters
	post condition: changes the time of the order

string change_address(string address)
	pre condition: address must be a sting of charachters
	post condition: changes the address of the order

bool cancel_order(const bool status)
	pre condition: status must be a boolean value
	post condition: changes the status from the order to either true or false

string special_requests(string requests)
	pre condition: requests must be a string of charachters
	post condition: adds special requests to the order

bool change_tax_status(const bool exempt)
	pre condition: exempt must be a boolean value
	post conditon: changes the tac ezxempt status to true or false

int change_payment(const int new_payment)
	pre condition: new_payment must be a value of 1, 2, or 3
	post condition: changes the type of payment

void add_item(string item)
	pre condition: item must be a string of charachers
	post condition: item is added to the queue

void *link(Order *next) { link_field = next; }
	pre condition: next must be of class Order
	post condition: links the two nodes together

void create_order(std::string name, std::string address, std::string date, int payment, std::string phone,
				  std::string time, bool exempt, bool status, std::string requests)
	pre conditions: name, address, date, phone, time, and requests must all be strings. payment must be an integer,
					exempt and status must be boolean values
	post condition: creates an order with all of the above parameters

CONSTANT MEMBER FUNCTIONS

int get_order_number() const
	post condition: returns the order number

string get_name() const
	post condition: returns the name on the order

string get_phone() const
	post condition: returns the phone number on the order

string get_date() const
	post condition: returns the date on the order

string get_time() const
	post condition: returns the time for the order

string get_address() const
	post condition: returns the address for the order

bool get_order_status() const
	post condition: returns the status of the order

int get_size() const
	post condition: returns the size of the queue

string get_requests() const
	post condition: returns the special requests for the order

bool get_tax_status() const
	post condition: returns the tax status

string get_payment_method() const
	post condition: returns the payment method

void get_order()
	post condition: pritns out all itmes in the order_struct queue
*/

#include <string>
#include <queue>
#pragma once
#ifndef ROSANIO_ORDER
#define ROSANIO_ORDER

namespace rosanio_order
{
	class Order
	{
	public:
		// typedef string so it can be used easier in the header file
		typedef std::string string;

		// Constructor
		Order(int orderNumber);
		// Deconstructor 
		~Order();

		// Modification Member Functions
		string change_name(string name);
		string change_phone(string phone);
		string change_date(string date);
		string change_time(string time);
		string change_address(string address);
		bool cancel_order(const bool status);
		string special_requests(string requests);
		bool change_tax_status(const bool exempt);
		string change_payment(const int new_payment);
		void add_item(string item);

		// Constant Member Functions
		int get_order_number() const;
		string get_name() const;
		string get_phone() const;
		string get_date() const;
		string get_time() const;
		string get_address() const;
		bool get_order_status() const;
		int get_size() const;
		string get_requests() const;
		bool get_tax_status() const;
		string get_payment_method() const;
		void get_order();
		void create_order(std::string name, std::string address, std::string date, int payment, std::string phone,
			              std::string time, bool exempt, std::string requests);

		// Method to return the next node in the list
		const Order *get_link() { return link_field; }

		// Varibales
		// struct used to increase the amount of itmes the node can have in its data field
		struct order_struct
		{
			// the number of the order
			int order_number;
			// name of the customer
			string customer_name;
			// customer phone number
			string customer_phone;
			// date for the order
			string order_date;
			// time for the order
			string order_time;
			// address the order will be delivered to
			string order_address;
			// special requests for the order
			string request;
			// true = not canceled, false = canceled
			bool order_status;
			// size of the queue
			int size = 1;
			// the next spot in th queue
			int next = 1;
			// queue of strings used to store all of the itms in the order
			std::queue <std::string> order;
			// true = tax exempt, false = not tax exempt
			bool tax_status;
			// payment, 1 for cash, 2 for credit, 3 for check
			string payment;
		};
		// the next Order in the list
		Order *link_field;
		// creates the order struct
		order_struct my_order;
	};
}
#endif // !ROSANIO_ORDER