#include "report.h"

#include "inventory.h"
#include "book.h"
using std::vector;

Report::Report(Inventory* inv) { /* Initialize members */ }

// Mutators
void Report::setInventory(Inventory* inv) {
  // Set local inventory to inv
}



// Accessors
vector<double> Report::getWholeList() {
  vector<double> temp;
  // Create temporary double vector
  // Create temporary book list
  // Get entire inventory, and save into temp book list
  //
  // for all items in book list
  //    Push items wholesale cost into temp double vec
  // return temp double vec
  return temp;
}

vector<double> Report::getRetailList() {
  vector<double> temp;
  // Create temporary double vector
  // Create temporary book list
  // Get entire inventory, and save into temp book list
  //
  // for all items in book list
  //    Push items retail cost into temp double vec
  // return temp double vec
  return temp;
}

double Report::vecAdd(vector<double> vec) {
  // Create temp double
  // for all items in vec list
  //    Add to double
  // return double
  return 0;
}




// Inventory accessors
vector<Book*> Report::getAll() {
  vector<Book*> temp;
  // Create temp book list
  // Get size of inventory
  // Return range from inventory from zero to size
  // return book list
  return temp;
}

vector<Book*> Report::getSortQuantity(bool asc) {
  vector<Book*> temp;
  // Create temp book list
  // Get size of inventory
  // Return range from inventory from zero to size
  // if asc is true
  //    Sort book list by quantity by asc
  // else
  //    Sort book list by quantity by desc
  // return book list
  return temp;
}

vector<Book*> Report::getSortWhole(bool asc) {
  vector<Book*> temp;
  // Create temp book list
  // Get size of inventory
  // Return range from inventory from zero to size
  // if asc is true
  //    Sort book list by whole cost by asc
  // else
  //    Sort book list by whole cost by desc
  // return book list
  return temp;
}

vector<Book*> Report::getSortAge(bool asc) {
  vector<Book*> temp;
  // Create temp book list
  // Get size of inventory
  // Return range from inventory from zero to size
  // if asc is true
  //    Sort book list by date field by asc
  // else
  //    Sort book list by date field by desc
  // return book list
  return temp;
}


// Private methods
void Report::sort(Inventory::book_list& list, Book::field field) {
  // switch field:
  //    Sort....
}
