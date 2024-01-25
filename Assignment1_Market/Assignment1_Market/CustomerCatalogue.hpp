#ifndef CUSTOMERS_HPP
#define CUSTOMERS_HPP

#include <iostream>
#include <vector>

class Customer
{
private:
	int id;
	std::string name;
	int phoneNumber;
	std::string email;

public:
	Customer(int id, std::string name, int phoneNumber, std::string email);
	Customer();
};

class CustomerCatalogue
{
	private:
	std::vector<Customer> customers;

};
#endif
