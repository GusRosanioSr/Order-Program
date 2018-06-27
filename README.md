# Order-Program
This is a program created to keep track of customer orders

This program has two header files, two implmentation files, and one demo file.
The way this program function is as follows:
  The Order.h file creates a class of a node, but for the value of the node there is a struct for multiple peices of
  data to be input. Inside of the struct is a queue for all of the items in the order. The class also has methods to 
  retrieve all of the information. 
  
  The Orders.h file creates a class for a linked list using a node of Order. By doing this, we are able to string
  together multiple orders and iterate through them. This class also has methods to open and close a text file of Orders.txt
  that is used to write to orders, so that even when the program is closed the orders are still readable. 
  
The Final file is LinkedListDemo.cpp. This file puts to use most of the functionality of Order and Orders,
but there is alwyas room for imporvement :).
