#include "AppUtilities.hpp"

#include <iostream>
#include <stdlib.h> 

Utilities::Utilities()
{
	startMenuOptions[0] = { 'A', "Admin Menu" };
	startMenuOptions[1] = { 'S', "Shop" };
	startMenuOptions[2] = { 'R', "Enter Reward Account" };

	adminMenuOptions[0] = { 'P', "Manage Product Catalogue" };
	adminMenuOptions[1] = { 'C', "Manage Registered Customers" };

	productMenuOptions[0] = { 'E', "Proceed to Checkout" };

	checkoutMenuOptions[0] = { 'P', "Pay" };
}

void Utilities::EnterStartMenu()
{
	std::cout << startAsciiString << std::endl << std::endl;
	DisplayMenuOptions(startMenuOptions, 3);

	char input = WaitForCharInput();
	switch (input)
	{
		case 'A':
			EnterAdminMenu();
			break;
		case 'S':
			system("CLS");
			DisplayMenuOptions(productMenuOptions, 1);
			break;
		case 'R':

			break;
	}
}

void Utilities::EnterAdminMenu()
{
	system("CLS");
	DisplayMenuOptions(adminMenuOptions, 2);
	char input = WaitForCharInput();
	switch (input)
	{
		case 'P':
			break;
		case 'C':
			break;
	}
}

void Utilities::DisplayMenuOptions(MenuOption menuOptions[], int options = 1)
{
	for (int i = 0; i < options; i++)
	{
		std::cout << menuOptions[i].key << " - " << menuOptions[i].description << std::endl;
	}
}

char Utilities::WaitForCharInput()
{
	char input;
	std::cout << std::endl <<  "Select an option: ";
	std::cin >> input;

	if (input >= 'a' && input <= 'z')
		input -= 32;

	return input;
}