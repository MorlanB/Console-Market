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
		BasketManager basketManager;

		MenuOption startMenuOptions[3];
		MenuOption adminMenuOptions[3];
		MenuOption productMenuOptions[2];
		MenuOption checkoutMenuOptions[2];

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
		void SetMenu(menuType menu);

		void EnterAdminMenu();
		void EnterShopMenu();
		void EnterCheckoutMenu();

	public:
		Utilities(BasketManager basketManager);

		Utilities();

		//Menus
		void EnterStartMenu();

		//Display
		void DisplayMenuOptions(menuType activeMenu);
		void DisplayCatalogue(Basket basket);

		//Input Handling
		char WaitForCharInput();
		void SetActiveMenu(menuType menu);
};

#endif