#include "AppUtilities.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>

Utilities::Utilities(BasketManager basketManager)
{
	this->basketManager = basketManager;

	startMenuOptions[0] = { 'A', "Admin Menu" };
	startMenuOptions[1] = { 'S', "Shop" };
	startMenuOptions[2] = { 'R', "Scan Reward Card" };

	adminMenuOptions[0] = { 'P', "Manage Product Catalogue" };
	adminMenuOptions[1] = { 'C', "Manage Registered Customers" };
	adminMenuOptions[2] = { 'B', "Back to Start screen" };

	productMenuOptions[0] = { 'C', "Proceed to Checkout" };
	productMenuOptions[1] = { 'B', "Go back to Start Menu" };
	productMenuOptions[2] = { 'A', "Add Product to Basket" };

	checkoutMenuOptions[0] = { 'P', "Pay" };
	checkoutMenuOptions[1] = { 'B', "Go Back to Shop" };

	procuctCatalogueMenuAdminOptions[0] = { 'A', "Add Product" };
	procuctCatalogueMenuAdminOptions[1] = { 'D', "Delete Product" };
	procuctCatalogueMenuAdminOptions[2] = { 'E', "Edit Product" };
	procuctCatalogueMenuAdminOptions[3] = { 'B', "Back to Admin Menu" };

	customerCatalogueMenuAdminOptions[0] = { 'A', "Add Customer" };
	customerCatalogueMenuAdminOptions[1] = { 'D', "Delete Customer" };
	customerCatalogueMenuAdminOptions[2] = { 'E', "Edit Customer" };
	customerCatalogueMenuAdminOptions[3] = { 'B', "Back to Admin Menu" };

	bool isCardScanned = false;
}

#pragma region MenuStates

void Utilities::EnterStartMenu()
{
	SetActiveMenu(startMenu);
	std::cout << startAsciiString << std::endl << std::endl;
	DisplayMenuOptions();

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
			ScanRewardCard();
			PressAnyKeyToContinue();
			EnterStartMenu();
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
	DisplayMenuOptions();

	char input = WaitForCharInput();
	switch (input)
	{
		case 'P':
			EnterCatalogueMenuAdmin();
			break;
		case 'C':
			EnterCustomerMenuAdmin();
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

	DisplayMenuOptions();

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
			id = WaitForIntInput();
			std::cout << "Enter Quantity:";
			quantity = WaitForIntInput();
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
	float cash = 0;
	float total = basketManager.GetBasket(0).GetTotal();
	float discount = 0;
	SetActiveMenu(checkoutMenu);
	std::cout << "Checkout" << std::endl << std::endl;
	if (isCardScanned)
	{
		std::cout << "Subtotal: " << total << std::endl;

		discount = total * 0.1;
		total -= discount;

		std::cout << "Discount: " << discount << std::endl;
		std::cout << "Total: " << total << std::endl << std::endl;
	}
	else
	{
		std::cout << "Total: " << basketManager.GetBasket(0).GetTotal() << std::endl << std::endl;
	}

	DisplayMenuOptions();

	char input = WaitForCharInput();
	switch (input)
		{
		case 'P':
			TryMakePayment();
			break;
		case 'B':
			EnterShopMenu();
			break;
		default:
			EnterCheckoutMenu();
			break;
	}
}

void Utilities::TryMakePayment()
{
	float cash = 0;
	char input;

	std::cout << "Please enter amount in cash: ";
	cash = WaitForFloatInput();
	if (cash < basketManager.GetBasket(0).GetTotal())
	{
		std::cout << "Not enough cash, please try again" << std::endl;
		TryMakePayment();
	}
	else
	{
		std::cout << std::endl << "Change: " << cash - basketManager.GetBasket(0).GetTotal() << std::endl;
		std::cout << "Thank you for shopping at ... MARKET" << std::endl;
		std::cout << "Please come again" << std::endl;
		std::cout << "Press any key to continue" << std::endl;
		PressAnyKeyToContinue();
		EnterStartMenu();
	}
}


void Utilities::EnterCatalogueMenuAdmin()
{
	std::string productName;
	int id = 0;
	float price = 0;

	SetActiveMenu(catalogueMenuAdmin);
	productCatalogue.DisplayProducts();
	DisplayMenuOptions();

	char input = WaitForCharInput();
	switch (input)
	{
		case 'A':
			std::cout << "Enter Product Name: ";
			productName = WaitForStringInput();
			std::cout << "Enter Product Price: ";
			price = WaitForFloatInput();
			id = productCatalogue.GetProducts().size() + 1;
			productCatalogue.AddProduct(Product(productCatalogue.GenerateProductId(), productName, price));
			EnterCatalogueMenuAdmin();
			break;
		case 'D':
			std::cout << "Enter Product ID: ";
			id = WaitForIntInput();
			productCatalogue.RemoveProduct(id);
			EnterCatalogueMenuAdmin();
			break;
		case 'E':
			std::cout << "Enter Product ID: ";
			id = WaitForIntInput();
			std::cout << "Enter Product Name: ";
			productName = WaitForStringInput();
			std::cout << "Enter Product Price: ";
			price = WaitForFloatInput();
			productCatalogue.RemoveProduct(id);
			productCatalogue.AddProduct(Product(id, productName, price));
			EnterCatalogueMenuAdmin();
			break;
		case 'B':
			EnterAdminMenu();
			break;
		default:
			EnterCatalogueMenuAdmin();
			break;
	}
}

void Utilities::EnterCustomerMenuAdmin()
{
	std::string customerName;
	int phoneNumber = 0;
	std::string email;
	int id = 0;

	SetActiveMenu(customerMenuAdmin);
	customerCatalogue.DisplayCustomers();
	DisplayMenuOptions();

	char input = WaitForCharInput();
	switch (input)
	{
		case 'A':
			std::cout << "Enter Customer Name: ";
			customerName = WaitForStringInput();
			std::cout << "Enter Customer Phone Number: ";
			phoneNumber = WaitForIntInput();
			std::cout << "Enter Customer Email: ";
			email = WaitForStringInput();
			customerCatalogue.AddCustomer(Customer(customerCatalogue.GenerateCustomerId(), customerName, phoneNumber, email));
			EnterCustomerMenuAdmin();
			break;
		case 'D':
			std::cout << "Enter Customer ID: ";
			id = WaitForIntInput();
			customerCatalogue.RemoveCustomer(id);
			EnterCustomerMenuAdmin();
			break;
		case 'E':
			std::cout << "Enter Customer ID: ";
			id = WaitForIntInput();
			std::cout << "Enter Customer Name: ";
			customerName = WaitForStringInput();
			std::cout << "Enter Customer Phone Number: ";
			phoneNumber = WaitForIntInput();
			std::cout << "Enter Customer Email: ";
			email = WaitForStringInput();
			customerCatalogue.RemoveCustomer(id);
			customerCatalogue.AddCustomer(Customer(id, customerName, phoneNumber, email));
			EnterCustomerMenuAdmin();
			break;
		case 'B':
			EnterAdminMenu();
			break;
		default:
			EnterCustomerMenuAdmin();
			break;
	}
}

#pragma endregion

#pragma region Output

void Utilities::DisplayMenuOptions()
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
		case catalogueMenuAdmin:
			DisplayMenuOptions(procuctCatalogueMenuAdminOptions, 4);
			break;
		case customerMenuAdmin:
			DisplayMenuOptions(customerCatalogueMenuAdminOptions, 4);
			break;
		default:
			break;
	}
}

void Utilities::DisplayMenuOptions(MenuOption menuOptions[], int options)
{
	for (int i = 0; i < options; i++)
	{
		std::cout << "  " << menuOptions[i].key << " - " << menuOptions[i].description << std::endl;
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

#pragma endregion

#pragma region Input Handling

char Utilities::WaitForCharInput()
{
	char input;
	std::cout << std::endl <<  "Select an option: ";
	std::cin >> input;

	if (input >= 'a' && input <= 'z')
		input -= 32;

	return input;
}

int Utilities::WaitForIntInput()
{
	int input;
	if (std::cin >> input)
		return input;
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input, please try again" << std::endl;
		WaitForIntInput();
	}
	return input;
}

std::string Utilities::WaitForStringInput()
{
	std::string input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	return input;
}

float Utilities::WaitForFloatInput()
{
	float input;
	if (std::cin >> input)
		return input;
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input, please try again" << std::endl;
		WaitForFloatInput();
	}
	return input;
}

void Utilities::SetActiveMenu(menuType menu)
{
	activeMenu = menu;
	system("CLS");
}

#pragma endregion

void Utilities::ScanRewardCard()
{
	isCardScanned = true;
	std::cout << std::endl << "Card Scanned" << std::endl << std::endl;
}

void Utilities::PressAnyKeyToContinue()
{
	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}
