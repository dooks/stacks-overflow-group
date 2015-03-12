#include "InventoryMenu.h"
#include "MainMenu.h"
#include "inventory.h"
#include "Cashier.h"
#include "Cashier.cpp""
#include <iostream>
using namespace std;
string isbn, auth, title;
Inventory inv;
Cashier cash;
MainMenu main1;
CashierMenu::CashierMenu()
{};
CashierMenu::~CashierMenu()
{};
int CashierMenu::CashierinitMenu(int test)
{
	system("cls");
	cout << "\t\tSerendipity Booksellers\n"
		<< "\t\tCash Register\n\n"
		<< "\t1.\tAdd a book to this transaction via ISBN\n"
		<< "\t2.\tAdd a book to this transation via book title\n"
		<< "\t3.\tAdd a book to this transaction via author\n"
		<< "\t4.\tRemove a book from this transaction\n"
		<< "\t5.\tComplete this transaction\n"
		<< "\t6.\tReturn to the Main Menu\n" << endl;
}

void CashierMenu::submenu(int userCashMenu)
{
	switch (userCashMenu)
	{
	case 1:
		cout << "Please enter the ISBN: " << endl;
		cin >> isbn;
		Cashier::findISBN(isbn);
		//function call to search for isbn
		cout << "ISBN         Title        Author      Price " << endl;
		//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
		//Please type the number of the selection you'd like to make.
		void userSubmenu();


		break;
	case 2:
		cout << "Please enter the title: " << endl;
		cin << searchTitle();
		//function call to search for Title
		cout << "ISBN         Title        Author      Price " << endl;
		//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
		//Please type the number of the selection you'd like to make.
		userSubmenu();
		cout << "If the book you're searching for is not found here please refine your search and try again.";
		break;
	case 3:
		cout << "Please enter the author's last name: " << endl;
		cin << searchTitle();
		//function call to search for Title
		cout << "ISBN         Title        Author      Price " << endl;
		//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
		//Please type the number of the selection you'd like to make.
		userSubmenu();
		cout << "If the book you're searching for is not found here please refine your search and try again.";
		break;
	case 4:
		cout << "You have chosen to remove a book from your cart" << endl;
		cout << "ISBN         Title        Author      Price " << endl;
		cout << //AddtoCart()
			//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
			//Please type the number of the selection you'd like to make.
			userSubmenu2();

		break;
	case 5:
		cout << "Today you've purchased these books: ";
		cout << "ISBN      Title      Author     Price " << endl;
		cout <<//AddtoCart()
			cout << "Your subtotal is " << getSubtotal();
		cout << "With tax, this becomes a total of :" << getTotal();
		cout << "Thank you for shopping with Serendipity Booksellers!";

	case 6:
		cout << "Returning to Main Menu." << endl;
		system("pause");
		main1.MainMenuFunc();
		break;
	}
}

void userSubMenu(int addsubmenu)
{
	switch (addsubmenu)
	{
	case 1: 
		addCart(Book* book)
		//add corresponding choice from previous menu to transaction
		cout << "\"Title\" has been added to your transaction";
		break;
	case 2: Addbook();
		cout << "\"Title\" has been added to your transaction";
		break;
	case 3: Addbook();
		cout << "\"Title\" has been added to your transaction";
		break;
	case 4: Addbook();
		cout << "\"Title\" has been added to your transaction";
		break;
	case 5: //return to CashierMenu
		break;
	}
}

void userSubMenu2(int removemenu)
{
	switch (removemenu)
	{
	case 1: Removebook();
		//remove corresponding choice from previous menu to transaction
		cout << "\"Title\" has been removed from your transaction";
		break;
	case 2: Removebook();
		cout << "\"Title\" has been rmoved from your transaction";
		break;
	case 3: Removebook();
		cout << "\"Title\" has been removed from your transaction";
		break;
	case 4: Removebook();
		cout << "\"Title\" has been removed from your transaction";
		break;
	case 5: //return to CashierMenu
		break;
	}
}
