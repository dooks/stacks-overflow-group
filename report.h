#pragma once

#include <vector>
#include "inventory.h"
#include "book.h"
using std::vector;

class Report {
private:
  Inventory* m_inv; // Reference to inventory
  void sort(vector<Book*>(&), Book::field, bool); // Sort list by field

public:
  Report(Inventory*);

  // Accessors
  vector<double> getWholeList();
  vector<double> getRetailList();
  double         vecAdd(vector<double>);

  // Inventory accessors
  vector<Book*> getAll();              // Does not sort
  vector<Book*> getSortQuantity(bool); // Sort by quantity, asc if true
  vector<Book*> getSortWhole(bool);    // Sort by wholesale, asc if true
  vector<Book*> getSortAge(bool);      // Sort by date added, asc if true
};
