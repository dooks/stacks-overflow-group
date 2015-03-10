#ifndef CASHIERMENU_H
#define CASHIERMENU_H


#include <string>
#include <iomanip>
using namespace std;


class CashierMenu 
{
	private:
		int test;
		int userCashMenu;
	public:
		//Constructors
//		CashierMenu();
//		~CashierMenu();

		void print(int test)
		{
			cout << "Serendipity Booksellers Cashier Mode" << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "Date:\n"
			 	 << "Qty" << "\tISBN" << "\t\tTitle" << "\t\t\tPrice"
			  	 << "\t\tTotal" << endl;
			cout << "________________________________________________________________\n\n" << endl;
			cout << "\t\tSubtotal\n\n"
				 << "\t\tTax\n\n"
				 << "\t\tTotal" << endl;
			cout << "Enter your Numerical Choice: " << endl;

		}

		void pushback(int userCashMenu)
		{
			// cout << "You have chosen option " << userCashMenu << endl;
		
		}
};
//nothingwaschangeddontfreakout
#endif
