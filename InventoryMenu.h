#ifndef INVENTORYMENU_H
#define INVENTORYMENU_H


#include <string>
#include <iomanip>
#include "BookInfoMenu.h"
using namespace std;


class InventoryMenu
{
	private:
		int test;
		int userInvMenu;
	public:

		//Constructors
		InventoryMenu();
		~InventoryMenu();

		void print(int test);
		
		void pushback(int userInvMenu);

		void bookMenu();

};

#endif
