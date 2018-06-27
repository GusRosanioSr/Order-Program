#include "stdafx.h"
#include "Order.h"
#include <iostream>
#include <string>
#include <cassert>

namespace rosanio_order
{
	Order::Order(int orderNumber)
	{
		// initializes some of the varables
		my_order.order_number = orderNumber;
		my_order.order_status = true;
		my_order.tax_status = false;
	}

	Order::~Order()
	{

	}

	std::string Order::change_name(std::string name)
	{
		my_order.customer_name = name;
		return my_order.customer_name;
	}

	std::string Order::change_phone(std::string phone)
	{
		my_order.customer_phone = phone;
		return my_order.customer_phone;
	}

	std::string Order::change_date(std::string date)
	{
		my_order.order_date = date;
		return my_order.order_date;
	}

	std::string Order::change_time(std::string time)
	{
		my_order.order_time = time;
		return my_order.order_time;
	}

	std::string Order::change_address(std::string address)
	{
		my_order.order_address = address;
		return my_order.order_address;
	}

	bool Order::cancel_order(const bool status)
	{
		my_order.order_status = status;
		return my_order.order_status;
	}

	std::string Order::special_requests(std::string requests)
	{
		my_order.request = requests;
		return my_order.request;
	}

	bool Order::change_tax_status(const bool exempt)
	{
		my_order.tax_status = exempt;
		return my_order.tax_status;
	}

	std::string Order::change_payment(const int new_payment)
	{
		if (new_payment == 1)
		{
			my_order.payment = "Cash";
		}
		else if (new_payment == 2)
		{
			my_order.payment = "Credit Card";
		}
		else if (new_payment == 3)
		{
			my_order.payment = "Check";
		}
		else
		{
			std::cout << "ERROR: PLEASE ENTER 1 FOR CASH, 2 FOR CARD, OR 3 FOR CHECK" << std::endl;
		}
		return my_order.payment;
	}

	void Order::add_item(string item)
	{
		// adds an item to the order by using the push() method of queue
		my_order.order.push(item);
	}

	int Order::get_order_number() const
	{
		return my_order.order_number;;
	}

	std::string Order::get_name() const
	{
		return my_order.customer_name;
	}

	std::string Order::get_phone() const
	{
		return my_order.customer_phone;
	}

	std::string Order::get_date() const
	{
		return my_order.order_date;
	}

	std::string Order::get_time() const
	{
		return my_order.order_time;
	}

	std::string Order::get_address() const
	{
		return my_order.order_address;
	}

	bool Order::get_order_status() const
	{
		return my_order.order_status;
	}

	int Order::get_size() const
	{
		return my_order.size;
	}

	std::string Order::get_requests() const
	{
		return my_order.request;
	}

	bool Order::get_tax_status() const
	{
		return my_order.tax_status;
	}

	std::string Order::get_payment_method() const
	{
		return my_order.payment;
	}

	void Order::get_order()
	{
		// creates a temperary queue to hold data in
		std::queue <std::string> temp_order;
		// set it equal to the order
		temp_order = my_order.order;
		// start loop
		for (unsigned int i = 0; i < my_order.order.size(); i++)
		{
			// create a string called item
			string item;
			// set itme equal to the front of the temp_order
			item = temp_order.front();
			// print out the item
			std::cout << item << std::endl;
			// pop the item out of the queue
			temp_order.pop();
		}
		// delete all of the elements of the queue
		temp_order.empty();
	}
	void Order::create_order(std::string name, std::string address, std::string date, int payment, std::string phone,
							 std::string time, bool exempt, std::string requests)
	{
		change_name(name);
		change_address(address);
		change_date(date);
		change_payment(payment);
		change_phone(phone);
		change_tax_status(exempt);
		change_time(time);
		special_requests(requests);
	}
}