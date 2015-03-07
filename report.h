#pragma once

#include <vector>
#include "inventory.h"
#include "book.h"
using std::vector;

class Report {
private:
  Inventory* inventory;
  void sort(vector<Book*>&, Book::field); // Sort list by field

public:
  Report();
  Report(Inventory*);

  // Mutators
  void setInventory(Inventory*);

  // Accessors
  vector<double> getWholeList();
  vector<double> getRetailList();
  double         vecAdd(vector<double>);

  // Inventory accessors
  vector<Book*> getAll();              // Do not sort
  vector<Book*> getSortQuantity(bool); // Sort by quantity, asc if true
  vector<Book*> getSortWhole(bool);    // Sort by, asc if true
  vector<Book*> getSortAge(bool);      // Sort by wholesale, asc if true
};
