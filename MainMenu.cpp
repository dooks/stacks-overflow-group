#include "MainMenu.h"
#include "inventory.h"
#include "Cashier.h"
#include "Cashier.cpp"
#include "inventory.cpp"
#include "book.h"
#include "book.cpp"
#include "report.cpp"
#include "report.h"


#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
int userchoice, Cashchoice,Invchoice,Repchoice;
string userisbn, userauth, usertitle,deletion;
double total;
Inventory inv;
Cashier cash;
Report rep;

MainMenu::MainMenu()
{

}
void MainMenu::Menu1(int)
{
	userchoice = 0;
	cout << "Welcome to Serendipity Booksellers!"<<endl<<endl;
	
	cout << "1. Cashier Module" << endl;
	cout << "2. Inventory Module" << endl;
	cout << "3. Report Module" << endl;
	cout << "4. Quit the program" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> userchoice;
	cout << endl;
}
void MainMenu::CashMenu1(int)
{
	Cashchoice = 0;
	system("cls");
	cout << "Welcome to the Serendipity Booksellers Cash Register!" <<endl<<endl;

	cout << "1. Search for a book via ISBN" << endl;
	cout << "2. Search for a book via Author" << endl;
	cout << "3. Search for a book via Title" << endl;
	cout << "4. Remove a book from this transaction" << endl;
	cout << "5. Finalize your transaction" << endl;
	cout << "6. Return to the Main Menu" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> Cashchoice;
}
void MainMenu::InvMenu1(int)
{
	Invchoice = 0;
	system("cls");
	cout << "Welcome to the Serendipity Booksellers Inventory System!" << endl << endl;
	cout << "1.Look up a book"<<endl;
	cout << "2.Add a book"<<endl;
	cout << "3.Edit a book's record"<<endl;
	cout << "4.Delete a book" << endl;
	cout << "5.Return to the Main Menu" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> Invchoice;
}
void MainMenu::ReportMenu1(int)
{
	Repchoice = 0;
	system("cls");
	cout << "Welcome to the Serendipity Booksellers Report Module!" << endl << endl;
	cout << "1. Inventory Listing" << endl;
	cout << "2. Inventory Wholesale Listing" << endl;
	cout << "3. Inventory Retail Listing" << endl;
	cout << "4. List by quantity" << endl;
	cout << "5. List by cost" << endl;
	cout << "6. List by age" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> Repchoice;
}
void MainMenu::CashMenuISBN(string)
{
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
}

MainMenu::~MainMenu()
{
}
int main()
{
	MainMenu main;
	main.Menu1(userchoice);
	if (userchoice == 1)
	{
		main.CashMenu1(userchoice);
		cout << Cashchoice;
		switch (Cashchoice)
		{
		case 1:
			main.CashMenuISBN(userisbn);
			break;

		case 2:
			main.CashMenuAuth(userauth);
			break;
		case 3:
			main.CashMenuTitle(usertitle);
			break;
		case 4:
			main.CartRemove(deletion);
			break;

		case 5:
			main.BuyBooks(total);
			break;
		case 6:
			main.Menu1(userchoice);
			break;
		}

	}
	if (userchoice == 2)
	{
		main.InvMenu1(userchoice);
		cout << Invchoice;
	}
	if (userchoice == 3)
	{
		main.ReportMenu1(userchoice);
		cout << Repchoice;
	}
	if (userchoice == 4)
	{
		return 0;
	}
	cout << endl<< userchoice << endl;
	system("pause");

}
