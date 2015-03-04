#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "CashierMenu.h"
#include "InventoryMenu.h"
#include "BookInfoMenu.h"
#include "ReportMenu.h"
using namespace std;

int main()
{
	//object declaration
	CashierMenu CashierMenu;
	InventoryMenu InventoryMenu;
	ReportMenu ReportMenu;

	//menu choices
	const int CASHIER_MENU = 1,
			  INVENTORY_MENU = 2,
			  REPORT_MENU = 3,
			  QUIT_CHOICE = 4;
	int user_input, submenu;
	do
	{	
		cout << "\n\tSerendipity Bookstore\n"
			 << "\t      Main Menu\n\n"
			 << "1. Cashier Module\n"
			 << "2. Inventory Database Module\n"
			 << "3. Report Module\n"
			 << "4. Exit Program\n\n"
			 << "Enter Your Numerical Choice:\n\n";
		//testing user input with object functions
			cin >> user_input;

			InventoryMenu::field something;
			something = InventoryMenu::asdf;

		switch (user_input)
		{
			case CASHIER_MENU:
				CashierMenu.print(user_input);
				//something to get new data
				cin >> submenu;
				CashierMenu.pushback(submenu);
				cin.get();
				break;
			case INVENTORY_MENU:
				InventoryMenu.print(user_input);
				cin >> submenu;
				InventoryMenu.pushback(submenu);
				cin.get();
				break;
			case REPORT_MENU:
				ReportMenu.print(user_input);
				cin >> submenu;
				ReportMenu.pushback(submenu);
				cin.get();
				break;

			default: 
				cout << "you inputed something invalid." << endl;
				cin.get();
				return 0;

		}
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}while (user_input != QUIT_CHOICE);

	cin.get();
	return 0;
}

