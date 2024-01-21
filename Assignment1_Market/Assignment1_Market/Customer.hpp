#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>

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
#endif