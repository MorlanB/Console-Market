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

	int GetId();
	void SetId(int id);

	std::string GetName();
	int GetPhoneNumber();
	std::string GetEmail();
};

class CustomerCatalogue
{
	private:
	std::vector<Customer> customers;

	public:
		CustomerCatalogue()
			: customers({
				Customer(1, "Link", 123456789, "link@hyrule.com"),
				Customer(2, "Zelda", 987654321, "zelda@hyrule.com"),
				Customer(3, "Ganon", 123123123, "ganon@hyrule.com")
			})
		{}

		void AddCustomer(Customer customer);
		bool RemoveCustomer(int customerId);
		Customer GetCustomer(int customerId);

		void DisplayCustomers();
		std::vector<Customer> GetCustomers();
		int GenerateCustomerId();
};
#endif
