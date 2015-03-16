#ifndef MAINMENU_h
#define MAINMENU_h
#include <string>
#include <iomanip>

using namespace std;
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void Menu1(int);
	void CashMenu1(int);
	void CashMenuISBN(string);
	void CashMenuAuth(string);
	void CashMenuTitle(string);
	void CartRemove(string);
	void BuyBooks(double);
	void InvMenu1(int);
	void ReportMenu1(int);
};
#endif MAINMENU_h
