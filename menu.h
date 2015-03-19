#pragma once

#include <string>
#include <iomanip>
using namespace std;

#include "inventory.h"
#include "book.h"
#include "report.h"
#include "Cashier.h"
#include "pager.h"


class Menu {
protected:
  static Inventory* m_inv;
  static Cashier* m_cash;
  static Report* m_report;

public:
  // Static buffers
  static vector<Book*>  m_activeList;
  static vector<double> m_doubleList;
  static Book*          m_activeBook;
  static void Initialize(Inventory*, Cashier*, Report*);

  virtual ~Menu();

  // Methods
  virtual void displayHeader();
  virtual void displayBody();
  virtual void displayFooter();
};





class MenuCashier : public Menu {
public:
  void displayHeader();
  void displayBody();  // Displays body based on state
  void displayCart();
  //void displayFooter();
};

class MenuInventory : public Menu {
public:
  void displayHeader();
  void displayBody();
  //void displayFooter();
  void displaySearchPrompt();
};

class MenuReport : public Menu {
public:
  void displayHeader();
  void displayBody();      // Displays body based on state
  //void displayFooter();
};

class MenuSearch : public Menu {
public:
  void displayHeader();
  void displayBody(); // Accepts a page to list
  //void displayFooter();
};

class MenuBookList : public Menu {
public:
  void displayHeader();
  void displayBody(vector<Book*>&); // Accepts a page to list
  void displayFooter(bool, Pager&);
};

class MenuEdit : public Menu {
public:
  void displayHeader();
  void displayBody(); // Accepts a page to list
  void displayFooter();
};
