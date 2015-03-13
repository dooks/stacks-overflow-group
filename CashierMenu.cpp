#include "InventoryMenu.h"
#include "MainMenu.h"
#include "inventory.h"
#include "Cashier.h"
#include "Cashier.cpp""
#include <iostream>
using namespace std;
string userisbn, userauth, usertitle;
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
		std::getline(std::cin, userisbn);

		//function call to search for isbn
		cout << "ISBN         Title        Author      Price " << endl;
		vector<Book*> isbnlist = cash.findISBN(userisbn);
		for (unsigned i = 0; i < isbnlist.size(); i++)  {
			cout << "";
			cout << isbnlist[i]->getISBN() << "    " << isbnlist[i]->getTitle() << "     ";
			cout << isbnlist[i]->getAuthor() << "     $" << isbnlist[i]->getRetailPrice() << endl;

		}
		//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
		//Please type the number of the selection you'd like to make.
		void userSubmenu();


		break;
	case 2:
		cout << "Please enter the title: " << endl;
		std::getline(std::cin, usertitle);

		//function call to search for title
		cout << "ISBN         Title        Author      Price " << endl;
		vector<Book*> titlelist = cash.findTitle(usertitle);
		for (unsigned i = 0; i < titlelist.size(); i++)  {
			cout << "";
			cout << titlelist[i]->getISBN() << "    " << titlelist[i]->getTitle() << "     ";
			cout << titlelist[i]->getAuthor() << "     $" << titlelist[i]->getRetailPrice() << endl;

		}
		//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
		//Please type the number of the selection you'd like to make.
		void userSubmenu();


		break;
	case 3:
		cout << "Please enter the author, last name first: " << endl;
		std::getline(std::cin, userisbn);

		//function call to search for author
		cout << "ISBN         Title        Author      Price " << endl;
		vector<Book*> authlist = cash.findAuthor(userauth);
		for (unsigned i = 0; i < authlist.size(); i++)  {
			cout << "";
			cout << authlist[i]->getISBN() << "    " << authlist[i]->getTitle() << "     ";
			cout << authlist[i]->getAuthor() << "     $" << authlist[i]->getRetailPrice() << endl;

		}
		//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
		//Please type the number of the selection you'd like to make.
		void userSubmenu();


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
