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

int Customer::GetId()
{
	return id;
}

void Customer::SetId(int id)
{
	this->id = id;
}

std::string Customer::GetName()
{
	return name;
}

int Customer::GetPhoneNumber()
{
	return phoneNumber;
}

std::string Customer::GetEmail()
{
	return email;
}

void CustomerCatalogue::AddCustomer(Customer customer)
{
	customers.push_back(customer);
}

bool CustomerCatalogue::RemoveCustomer(int customerId)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].GetId() == customerId)
		{
			customers.erase(customers.begin() + i);
			return true;
		}
	}
}

Customer CustomerCatalogue::GetCustomer(int customerId)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].GetId() == customerId)
		{
			return customers[i];
		}
	}
	return Customer(-1, "", -1, "");
}

void CustomerCatalogue::DisplayCustomers()
{
	std::cout << "Customer Catalogue" << std::endl << std::endl;
	std::cout << " ID" << "\t" << "Name" << "\t\t" << "Phone Number" << "\t" << "Email" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < customers.size(); i++)
	{
		std::cout << " " << customers[i].GetId() << "\t" << customers[i].GetName() << "\t\t" << customers[i].GetPhoneNumber() << "\t\t" << customers[i].GetEmail() << std::endl;
	}
	std::cout << std::endl << std::endl;
}

std::vector<Customer> CustomerCatalogue::GetCustomers()
{
	return customers;
}

int CustomerCatalogue::GenerateCustomerId()
{
	int newId = customers.size() + 1;
	while (GetCustomer(newId).GetId() > -1)
		newId++;

	return newId;
}
