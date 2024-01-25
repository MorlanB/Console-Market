#include "AppUtilities.hpp"

#include <iostream>
#include <stdlib.h>

Utilities::Utilities(BasketManager basketManager)
{
	this->basketManager = basketManager;

	startMenuOptions[0] = { 'A', "Admin Menu" };
	startMenuOptions[1] = { 'S', "Shop" };
	startMenuOptions[2] = { 'R', "Enter Reward Account" };

	adminMenuOptions[0] = { 'P', "Manage Product Catalogue" };
	adminMenuOptions[1] = { 'C', "Manage Registered Customers" };
	adminMenuOptions[2] = { 'B', "Back to Start screen" };

	productMenuOptions[0] = { 'C', "Proceed to Checkout" };
	productMenuOptions[1] = { 'B', "Go back to Start Menu" };
	productMenuOptions[2] = { 'A', "Add Product to Basket" };

	checkoutMenuOptions[0] = { 'P', "Pay" };
	checkoutMenuOptions[1] = { 'B', "Go Back to Shop" };
}

void Utilities::EnterStartMenu()
{
	SetActiveMenu(startMenu);
	std::cout << startAsciiString << std::endl << std::endl;
	DisplayMenuOptions(activeMenu);

	char input = WaitForCharInput();
	switch (input)
	{
		case 'A':
			EnterAdminMenu();
			break;
		case 'S':
			EnterShopMenu();
			break;
		case 'R':

			break;
		default:
			EnterStartMenu();
			break;
	}
}

void Utilities::EnterAdminMenu()
{
	SetActiveMenu(adminMenu);
	std::cout << "Admin Menu" << std::endl << std::endl;
	DisplayMenuOptions(activeMenu);

	char input = WaitForCharInput();
	switch (input)
	{
		case 'P':
			break;
		case 'C':
			break;
		case 'B':
			EnterStartMenu();
			break;
		default:
			EnterAdminMenu();
			break;
	}
}

void Utilities::EnterShopMenu()
{
	SetActiveMenu(productMenu);

	std::cout << std::endl << "\t\t---   Make your Selection   ---   " << std::endl << std::endl;
	Basket& basket = basketManager.GetBasket(0);
	basket.DisplayProducts();

	DisplayMenuOptions(activeMenu);

	char input = WaitForCharInput();
	switch (input)
	{
		case 'C':
			EnterCheckoutMenu();
			break;
		case 'B':
			EnterStartMenu();
			break;
		case 'A':
			int id;
			int quantity;
			std::cout << "Enter Product ID: ";
			std::cin >> id;
			std::cout << "Enter Quantity:";
			std::cin >> quantity;
			basket.AddProduct(id, quantity);
			EnterShopMenu();
			break;

		default:
			EnterShopMenu();
			break;
	}
}

void Utilities::EnterCheckoutMenu()
{
	SetActiveMenu(checkoutMenu);
	DisplayMenuOptions(activeMenu);

	char input = WaitForCharInput();
	switch (input)
	{
		case 'P':
			break;
		case 'B':
			EnterShopMenu();
			break;
		default:
			EnterCheckoutMenu();
			break;
	}
}

void Utilities::DisplayMenuOptions(menuType activeMenu)
{
	switch (activeMenu)
	{
		case startMenu:
			DisplayMenuOptions(startMenuOptions, 3);
			break;
		case adminMenu:
			DisplayMenuOptions(adminMenuOptions, 3);
			break;
		case productMenu:
			DisplayMenuOptions(productMenuOptions, 3);
			break;
		case checkoutMenu:
			DisplayMenuOptions(checkoutMenuOptions, 2);
			break;
	}
}

void Utilities::DisplayMenuOptions(MenuOption menuOptions[], int options)
{
	for (int i = 0; i < options; i++)
	{
		std::cout << menuOptions[i].key << " - " << menuOptions[i].description << std::endl;
	}
}

void Utilities::DisplayCatalogue(Basket basket)
{
	std::cout << "Product Catalogue" << std::endl << std::endl;
	std::cout << "ID" << "\t" << "Name" << "\t\t\t" << "Price" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < productCatalogue.GetProducts().size(); i++)
	{
		std::cout << productCatalogue.GetProducts()[i].id << "\t" << productCatalogue.GetProducts()[i].name << "\t\t" << productCatalogue.GetProducts()[i].price << std::endl;
	}

	std::cout << std::endl << std::endl;
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

void Utilities::SetActiveMenu(menuType menu)
{
	activeMenu = menu;
	system("CLS");
}
