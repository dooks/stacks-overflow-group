#pragma once

#include <string>
#include <iomanip>
using namespace std;

#include "inventory.h"
#include "book.h"
#include "report.h"
#include "Cashier.h"


class Menu {
protected:
  static Inventory* m_inv;
  static Cashier* m_cash;
  static Report* m_report;

public:
  // Static buffers
  static vector<Book*>  m_tempList;
  static vector<double> m_doubleList;
  static Book*          m_tempBook;
  static void Initialize(Inventory*, Cashier*, Report*);

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
  void displayHeader();
  void displayBody();      // Displays body based on state
  //void displayFooter();
};

class MenuInventory : public Menu {
public:
  void displayHeader();
  void displayBody();
  //void displayFooter();
};

class MenuReport : public Menu {
public:
  void displayHeader();
  void displayBody();      // Displays body based on state
  //void displayFooter();
};

class MenuBookList : public Menu {
public:
  void displayHeader();
  void displayBody();
  //void displayFooter();
};
