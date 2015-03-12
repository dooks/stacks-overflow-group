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
	int userSubMenu;
public:
	//Constructors
	CashierMenu();
	~CasierMenu();
	void print(int test);
	void pushback(int userCashMenu);
	void pushback(int userSubMenu);
};
#endif
