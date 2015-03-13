#include <algorithm>
#include "report.h"

#include "inventory.h"
#include "book.h"
using std::vector;
using std::sort;

// Global comparison operators for sort
bool _report_lessq(Book* left, Book* right) {
  return (left->getQuantity() < right->getQuantity());
}

bool _report_lessw(Book* left, Book* right) {
  return (left->getWholeCost() < right->getWholeCost());
}

bool _report_lessd(Book* left, Book* right) {
  return (left->getDateAdded() < right->getDateAdded());
}

Report::Report(Inventory* inv) : m_inv(inv) { /* Initialize members */ }

// Accessors
vector<double> Report::getWholeList() {
  vector<double> retval;    // Create temporary double vector
  vector<Book*>  book_temp; // Create temporary book list
  book_temp = m_inv->getRange(0, (int) m_inv->getSize());// Get entire inventory

  // for all items in book list
  for(unsigned i = 0; i < book_temp.size(); i++) {
    // Push items wholesale cost into retval
    retval.push_back(book_temp[i]->getWholeCost());
  }
  return retval; // return temp double vec
}

vector<double> Report::getRetailList() {
  vector<double> retval;    // Create temporary double vector
  vector<Book*>  book_temp; // Create temporary book list
  book_temp = m_inv->getRange(0, (int) m_inv->getSize());// Get entire inventory

  // for all items in book list
  for(unsigned i = 0; i < book_temp.size(); i++) {
    // Push items retail price into retval
    retval.push_back(book_temp[i]->getRetailPrice());
  }
  return retval; // return temp double vec
}

double Report::vecAdd(const vector<double>& vec) {
  double retval = 0; // Create temp double
  for(unsigned i = 0; i < vec.size(); i++) { // for all items in vec list
    retval += vec[i]; // Add to double
  }
  return retval; // return double
}




// Inventory accessors
vector<Book*> Report::getAll() {
  vector<Book*> retval; // Create temp book list

  // Return range from inventory from zero to end
  retval = m_inv->getRange(0, m_inv->getSize());

  // return book list
  return retval;
}

vector<Book*> Report::getSortQuantity(bool asc) {
  vector<Book*> retval; // Create temp book list

  // Return range from inventory from zero to end
  retval = m_inv->getRange(0, m_inv->getSize());

  if(asc) {
    //    Sort book list by quantity by asc
    sort(retval, Book::QUANTITY, true);
  } else {
    //    Sort book list by quantity by desc
    sort(retval, Book::QUANTITY, false);
  }
  return retval; // return book list
}

vector<Book*> Report::getSortWhole(bool asc) {
  vector<Book*> retval; // Create temp book list

  // Return range from inventory from zero to end
  retval = m_inv->getRange(0, m_inv->getSize());

  if(asc) {
    //    Sort book list by whole cost by asc
    sort(retval, Book::WHOLECOST, true);
  } else {
    //    Sort book list by whole cost by desc
    sort(retval, Book::WHOLECOST, false);
  }
  return retval; // return book list
}

vector<Book*> Report::getSortAge(bool asc) {
  vector<Book*> retval; // Create temp book list

  // Return range from inventory from zero to end
  retval = m_inv->getRange(0, m_inv->getSize());

  if(asc) {
    //    Sort book list by date by asc
    sort(retval, Book::DATEADDED, true);
  } else {
    //    Sort book list by date by desc
    sort(retval, Book::DATEADDED, false);
  }
  return retval; // return book list
}


// Private methods
void Report::sort(vector<Book*>(&list), Book::field field, bool) {
  switch(field) {
    case Book::QUANTITY:
      // Sort list by quantity
      std::sort( list.begin(), list.end(), _report_lessq);
      break;
    case Book::WHOLECOST:
      // Sort list by wholesale cost
      std::sort( list.begin(), list.end(), _report_lessw);
      break;
    case Book::DATEADDED:
      // Sort list by date added
      std::sort( list.begin(), list.end(), _report_lessd);
      break;
  }
}

