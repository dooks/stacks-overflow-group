#ifndef REPORTMENU_H
#define REPORTMENU_H


#include <string>
#include <iomanip>
using namespace std;


class ReportMenu 
{
	private:
		int test;
		int userReportMenu;

	public:
		//Constructor
//		ReportMenu();
//		~ReportMenu();

		void print(int test)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\t\tSerendipity Booksellers\n"
				 << "\t\t Reports\n\n"
				 << "\t1.\t Inventory Listing\n"
				 << "\t2.\t Inventory Retail Value\n"
				 << "\t3.\t Inventory Retail Value\n"
				 << "\t4.\t Listing by Quantity\n"
				 << "\t5.\t Listing by Cost\n"
				 << "\t6.\t listing by Age\n"
			 	 << "\t7.\t Return to Main Menu\n" << endl;

		}
		void pushback(int userReportMenu)
		{
			cout << "You have chosen option " << userReportMenu << endl;
		}
};

#endif
