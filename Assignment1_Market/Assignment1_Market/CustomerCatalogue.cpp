#include "CustomerCatalogue.hpp"

Customer::Customer(int id, std::string name, int phoneNumber, std::string email)
{
	this->id = id;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->email = email;
}

Customer::Customer()
{
	this->id = 0;
	this->name = "Unknown";
	this->phoneNumber = 0;
	this->email = "unknown@mail.com";
}