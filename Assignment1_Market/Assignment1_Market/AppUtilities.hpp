#include <string>
#include "ProductCatalogue.hpp"
#include "BasketManager.hpp"

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

struct MenuOption
{
	char key;
	std::string description;
};

enum menuType
{
	startMenu,
	adminMenu,
	productMenu,
	checkoutMenu,
	catalogueMenuAdmin,
	customerMenuAdmin
};

class Utilities
{
	private:
		menuType activeMenu;
		ProductCatalogue productCatalogue;
		CustomerCatalogue customerCatalogue;
		BasketManager basketManager;

		MenuOption startMenuOptions[3];
		MenuOption adminMenuOptions[3];
		MenuOption productMenuOptions[3];
		MenuOption checkoutMenuOptions[2];
		MenuOption procuctCatalogueMenuAdminOptions[4];
		MenuOption customerCatalogueMenuAdminOptions[4];

		std::string startAsciiString =
			"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
			"|||||-----------------------------------------------------------|||||\n"
			"|||||	  WELCOME TO ...                    _                   |||||\n"
			"|||||            -----    -     -   ----   | |   ---            |||||\n"
			"|||||           | |  \\ \\ |  \\  | | |  |\\  \\|_| /   __\\          |||||\n"
			"|||||           | |  / / | |  \\| | |  |/  /     \\  \\            |||||\n"
			"|||||           | |---   | | \\ | | |  |\\  \\     _\\  \\           |||||\n"
			"|||||           | |      | |   \\ | |  |/  /    \\    /           |||||\n"
			"|||||            -        -     -   ------      ----            |||||\n"
			"|||||                                            ... MARKET     |||||\n"
			"|||||___________________________________________________________|||||\n"
			"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
			;

		void DisplayMenuOptions(MenuOption menuOptions[], int options);

		//Menus
		void EnterAdminMenu();
		void EnterShopMenu();
		void EnterCheckoutMenu();
		void EnterCatalogueMenuAdmin();

	public:
		Utilities(BasketManager basketManager);

		//Menus
		void EnterStartMenu();
		void SetActiveMenu(menuType menu);

		void EnterCustomerMenuAdmin();

		//Display
		void DisplayMenuOptions();
		void DisplayCatalogue(Basket basket);

		//Input Handling
		int WaitForIntInput();
		float WaitForFloatInput();
		char WaitForCharInput();
		std::string WaitForStringInput();

		void TryMakePayment();
};

#endif