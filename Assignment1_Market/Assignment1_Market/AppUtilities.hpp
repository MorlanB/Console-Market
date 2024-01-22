#include <string>
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

struct MenuOption
{
	char key;
	std::string description;
};

class Utilities
{
	private:
		MenuOption startMenuOptions[3];
		MenuOption adminMenuOptions[2];
		MenuOption productMenuOptions[1];
		MenuOption checkoutMenuOptions[1];

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



	public:
		Utilities();
		void EnterStartMenu();
		void EnterAdminMenu();
		void DisplayMenuOptions(MenuOption menuOptions[], int options);
		char WaitForCharInput();
};

#endif