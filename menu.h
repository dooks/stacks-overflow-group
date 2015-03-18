#pragma once

#include <string>
#include <iomanip>
using namespace std;

#include "inventory.h"
#include "book.h"
#include "report.h"
#include "Cashier.h"


class Menu {
	static Inventory* m_inv;
	static Cashier* m_cash;
	static Report* m_report;

	static vector<Book*> m_tempList;
	static Book* 			   m_tempBook;

	int state;

public:
	Menu(Inventory* inv, Cashier* cash);
	virtual ~Menu();

  // Methods
	virtual void displayHeader();
	virtual void displayBody();
	virtual void displayFooter();

	// Mutators
	void setState();

	// Accessors
	void getState();
};





class MenuCashier : public Menu {
public:
	MenuCashier();
	~MenuCashier();

	void displayHeader();
	void displayBody(int);			// Displays body based on state
	void displayFooter();
};

class MenuInventory : public Menu {
public:
	MenuInventory();
	~MenuInventory();

	void displayHeader();
	void displayBody(int);			// Displays body based on state
	void displayFooter();
};

class MenuReport : public Menu {
	MenuReport();
	~MenuReport();

	void displayHeader();
	void displayBody(int);			// Displays body based on state
	void displayFooter();
};

class MenuBookList : public Menu {
	MenuBookList();
	~MenuBookList();

	void displayHeader();
	void displayBody(int first, int last); // Displays based on range
	void displayFooter();
}
