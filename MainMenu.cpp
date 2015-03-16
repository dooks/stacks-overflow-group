#include "MainMenu.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
int userchoice;

MainMenu::MainMenu()
{
}
void MainMenu::Menu1(int)
{
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
	userchoice = 0;
	system("cls");
	cout << "Welcome to the Serendipity Booksellers Cash Register!" <<endl<<endl;

	cout << "1. Search for a book via ISBN" << endl;
	cout << "2. Search for a book via Author" << endl;
	cout << "3. Search for a book via Title" << endl;
	cout << "4. Remove a book from this transaction" << endl;
	cout << "5. Finalize your transaction" << endl;
	cout << "6. Return to the Main Menu" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> userchoice;
}
void MainMenu::InvMenu1(int)
{
	userchoice = 0;
	system("cls");
	cout << "Welcome to the Serendipity Booksellers Inventory System!" << endl << endl;
	cout << "1.Look up a book"<<endl;
	cout << "2.Add a book"<<endl;
	cout << "3.Edit a book's record"<<endl;
	cout << "4.Delete a book" << endl;
	cout << "5.Return to the Main Menu" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> userchoice;
}
void MainMenu::ReportMenu1(int)
{
	userchoice = 0;
	system("cls");
	cout << "Welcome to the Serendipity Booksellers Report Module!" << endl << endl;
	cout << "1. Inventory Listing" << endl;
	cout << "2. Inventory Wholesale Listing" << endl;
	cout << "3. Inventory Retail Listing" << endl;
	cout << "4. List by quantity" << endl;
	cout << "5. List by cost" << endl;
	cout << "6. List by age" << endl;
	cout << "Please enter your choice found above:" << endl;
	cin >> userchoice;
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

	}
	if (userchoice == 2)
	{
		main.InvMenu1(userchoice);
	}
	if (userchoice == 3)
	{
		main.ReportMenu1(userchoice);
	}
	
	cout << endl<< userchoice << endl;
	system("pause");

}
