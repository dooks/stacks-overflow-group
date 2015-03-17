#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "menu.h"
#include "book.h"
#include "report.h"
#include "inventory.h"
#include "Cashier.h"

Inventory* Menu::m_inv = NULL;
Cashier* Menu::m_cash  = NULL;
Report* Menu::m_report = NULL;

vector<Book*> Menu::m_tempList;
Book*		  Menu::m_tempBook;


Menu::Menu(Inventory* inv, Cashier* cash) {
	m_inv = inv;
	m_cash = cash;
}

//void MainMenu::Menu1(int)
//{
//	userchoice = 0;
//	cout << "Welcome to Serendipity Booksellers!"<<endl<<endl;
//
//	cout << "1. Cashier Module" << endl;
//	cout << "2. Inventory Module" << endl;
//	cout << "3. Report Module" << endl;
//	cout << "4. Quit the program" << endl;
//	cout << "Please enter your choice found above:" << endl;
//	cin >> userchoice;
//	cout << endl;
//}
//
//void MainMenu::CashMenu1(int)
//{
//	Cashchoice = 0;
//	system("cls");
//	cout << "Welcome to the Serendipity Booksellers Cash Register!" <<endl<<endl;
//
//	cout << "1. Search for a book via ISBN" << endl;
//	cout << "2. Search for a book via Author" << endl;
//	cout << "3. Search for a book via Title" << endl;
//	cout << "4. Remove a book from this transaction" << endl;
//	cout << "5. Finalize your transaction" << endl;
//	cout << "6. Return to the Main Menu" << endl;
//	cout << "Please enter your choice found above:" << endl;
//	cin >> Cashchoice;
//}
//
//void MainMenu::InvMenu1(int)
//{
//	Invchoice = 0;
//	system("cls");
//	cout << "Welcome to the Serendipity Booksellers Inventory System!" << endl << endl;
//	cout << "1. Look up a book"<<endl;
//	cout << "2. Add a book"<<endl;
//	cout << "3. Edit a book's record"<<endl;
//	cout << "4. Delete a book" << endl;
//	cout << "5. Return to the Main Menu" << endl;
//	cout << "Please enter your choice found above:" << endl;
//	cin >> Invchoice;
//}
//
//void MainMenu::ReportMenu1(int)
//{
//	Repchoice = 0;
//	system("cls");
//	cout << "Welcome to the Serendipity Booksellers Report Module!" << endl << endl;
//	cout << "1. Inventory Listing" << endl;
//	cout << "2. Inventory Wholesale Listing" << endl;
//	cout << "3. Inventory Retail Listing" << endl;
//	cout << "4. List by quantity" << endl;
//	cout << "5. List by cost" << endl;
//	cout << "6. List by age" << endl;
//	cout << "Please enter your choice found above:" << endl;
//	cin >> Repchoice;
//}
//
//void MainMenu::CashMenuISBN()
//{
//	cout << "Please enter the ISBN: " << endl;
//	cin.clear();
//	fflush(stdin);
//	std::getline(std::cin, userisbn);
//
//	//function call to search for isbn
//	cout << "   ISBN            Title               Author            Price " << endl;
//	vector<Book*> isbnlist = m_cash.findISBN(userisbn);
//	for (unsigned i = 0; i < isbnlist.size(); i++)  {
//		cout << "";
//		cout <<i+1<<". "<< isbnlist[i]->getISBN() << "    "
//			<< isbnlist[i]->getTitle() << "     ";
//		cout << isbnlist[i]->getAuthor() << "     $"
//			<< isbnlist[i]->getRetailPrice() << endl;
//
//	}
//	cout << "Please type the number of the selection you'd like to add to your cart:" << endl;
//	cin >> cartchoice;
//	cartchoice = cartchoice - 1;
//	if (cartchoice>isbnlist.size())
//	{
//		cout << "There is no such selection. Please try again:" << endl;
//		cin >> cartchoice;
//	}
//	m_cash.addCart(isbnlist[cartchoice]);
//
//	/*vector<Book*> cart = m_cash.findISBN(userisbn);
//	Book* book = cart[0];
//	for (unsigned i = 0; i < cart.size(); i++) {
//		if (cartchoice == i)
//		{
//
//	m_cash.addCart(book);
//
//		}
//	}
//	cout << cartchoice << endl;
//	for (unsigned i = 0; i < cart.size(); i++)  {
//		cout << "";
//		cout << i + 1 << ". " << cart[i]->getISBN() << "    "
//			<< cart[i]->getTitle() << "     ";
//		cout << cart[i]->getAuthor() << "     $"
//			<< cart[i]->getRetailPrice() << endl;
//
//	}*/
//	cout << "Your selection has been added to your cart" << endl;
//	//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
//	//Please type the number of the selection you'd like to make.
//	system("pause");
//	MainMenu::CashMenu1(userchoice);
//
//}
//
//void MainMenu::CashMenuAuth(string)
//{
//	cout << "Please enter the author's name, last name first: " << endl;
//	cin.clear();
//	fflush(stdin);
//	std::getline(std::cin, userauth);
//
//	//function call to search for author
//	cout << "ISBN         Title        Author      Price " << endl;
//	vector<Book*> authlist = m_cash.findAuthor(userauth);
//	for (unsigned i = 0; i < authlist.size(); i++)  {
//		cout << "";
//		cout << i + 1 << ". " << authlist[i]->getISBN() << "    "
//			<< authlist[i]->getTitle() << "     ";
//		cout << authlist[i]->getAuthor() << "     $"
//			<< authlist[i]->getRetailPrice() << endl;
//		cout << i << endl;
//		cout << userisbn << endl;
//
//	}
//	cout << "Please type the number of the selection you'd like to add to your cart:" << endl;
//	cin >> cartchoice;
//	cartchoice = cartchoice - 1;
//
//
//	vector<Book*> cart = m_cash.findAuthor(userauth);
//	Book* book = cart[0];
//	for (unsigned i = 0; i < cart.size(); i++) {
//		if (cartchoice == i)
//		{
//
//			m_cash.addCart(book);
//
//		}
//	}
//	cout << cartchoice << endl;
//	/*for (unsigned i = 0; i < cart.size(); i++)  {
//	cout << "";
//	cout << i + 1 << ". " << cart[i]->getISBN() << "    "
//	<< cart[i]->getTitle() << "     ";
//	cout << cart[i]->getAuthor() << "     $"
//	<< cart[i]->getRetailPrice() << endl;
//
//	}*/
//	cout << "Your selection has been added to your cart" << endl;
//	//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
//	//Please type the number of the selection you'd like to make.
//	system("pause");
//
//
//}
//
//void MainMenu::CashMenuTitle(string)
//{
//	cout << "Please enter the title: " << endl;
//	cin.clear();
//	fflush(stdin);
//	std::getline(std::cin, usertitle);
//
//	//function call to search for author
//	cout << "ISBN         Title        Author      Price " << endl;
//	vector<Book*> titlelist = m_cash.findAuthor(usertitle);
//	for (unsigned i = 0; i < titlelist.size(); i++)  {
//		cout << "";
//		cout << i + 1 << ". " << titlelist[i]->getISBN() << "    "
//			<< titlelist[i]->getTitle() << "     ";
//		cout << titlelist[i]->getAuthor() << "     $"
//			<< titlelist[i]->getRetailPrice() << endl;
//
//
//	}
//	cout << "Please type the number of the selection you'd like to add to your cart:" << endl;
//	cin >> cartchoice;
//	cartchoice = cartchoice - 1;
//
//
//	vector<Book*> cart = m_cash.findTitle(usertitle);
//	Book* book = cart[0];
//	for (unsigned i = 0; i < cart.size(); i++) {
//		if (cartchoice == i)
//		{
//
//			m_cash.addCart(book);
//
//		}
//	}
//	cout << cartchoice << endl;
//	/*for (unsigned i = 0; i < cart.size(); i++)  {
//	cout << "";
//	cout << i + 1 << ". " << cart[i]->getISBN() << "    "
//	<< cart[i]->getTitle() << "     ";
//	cout << cart[i]->getAuthor() << "     $"
//	<< cart[i]->getRetailPrice() << endl;
//
//	}*/
//	cout << "Your selection has been added to your cart" << endl;
//	//cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
//	//Please type the number of the selection you'd like to make.
//
//
//}
//
//void MainMenu::CartRemove(string)
//{
//	cout << "Please enter the title of the book you'd like to remove from your cart:" << endl;
//	cin >> usertitle;
//	/*for (unsigned i = 0; i < cart.size(); i++) {
//		if (usertitle == cart.getTitle())
//		{
//
//			m_cash.delCart(book);
//
//		}
//	}
//	*/
//}
//
//void MainMenu::BuyBooks(double)
//{}




// Private methods
void Menu::displayHeader() {
	//cout << "Serendipity Bookstore POS" << endl;
}

void Menu::displayFooter() {
	// Program footer
}