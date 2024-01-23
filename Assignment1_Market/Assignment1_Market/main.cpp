#include <iostream>
#include "BasketManager.hpp"
#include "Customer.hpp"
#include "AppUtilities.hpp"

int main()
{
	BasketManager basketManager = BasketManager();
	Customer customer = Customer();
	basketManager.CreateBasket(customer);

	Utilities utilities = Utilities(basketManager);
	utilities.EnterStartMenu();


	return 0;
}