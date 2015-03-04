#include "InventoryMenu.h"
#include <iostream>
using namespace std;

InventoryMenu::InventoryMenu()
{};
InventoryMenu::~InventoryMenu()
{};



void InventoryMenu::print(int test)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\tSerendipity Booksellers\n"
		<< "\t\tInventory Database\n\n"
		<< "\t1.\tLook Up A Book\n"
		<< "\t2.\tAdd a Book\n"
		<< "\t3.\tEdit a BOok's Record\n"
		<< "\t4.\tDelete a Book\n"
		<< "\t5.\tReturn to the Main Menu\n" << endl;

}
void InventoryMenu::pushback(int userInvMenu)
{
	cout << "You have chosen option " << userInvMenu << endl;
	BookInfoMenu bookmenu;
	bookmenu.print();
}
void InventoryMenu::bookMenu()
{};

//for book.h
/*
Report report;
vector<Book*> temp_list = report.getAll();

for (vector<Book*>::iterator it = temp_list.begin(); it != temp_list.end(); it++) {
	Book* temp = (**it);

	cout << temp.getISBN();
	cout << temp.getTitle();
}

}
*/


