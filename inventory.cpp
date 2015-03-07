#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "inventory.h"
#include "db.h"
#include "book.h"
using namespace std;

#define INV_FILE "tools/books.db"

Inventory::Inventory()                 { m_db = NULL; }
Inventory::Inventory(DB::Database* db) { m_db = db;   }

Inventory::~Inventory() {
  if(m_db != NULL) delete m_db;
}

// Mutators
bool Inventory::addBook(Book* book) {
  try {
    if(book == NULL) throw domain_error("Domain Error: Argument is NULL");

    // TODO: Issue #26: Should change quantity if book exists
    // Add book to list, for writing to file later
    m_addList.push_back(book);
  } catch(exception& e) {
    cerr << "Inventory::addBook: " << e.what() << endl;
  }
  return 0;
}

bool Inventory::updBook(Book* book) {
  try {
    vector<unsigned>::iterator first = m_deltaList.begin();
    vector<unsigned>::iterator last = m_deltaList.end();

    // if file index does not exist in delta list
    if(find(first, last, book->getFileIndex()) == last) {
      // Push index to delta list
      m_deltaList.push_back(book->getFileIndex());
    }
  } catch(exception& e) {
    cerr << "Inventory::updBook(): "  << e.what() << endl;
  }
  return 0;
}

bool Inventory::delBook(Book* book) {
  try {
    vector<unsigned>::iterator first = m_deleteList.begin();
    vector<unsigned>::iterator last = m_deleteList.end();

    // if file index does not exist in delete list
    if(find(first, last, book->getFileIndex()) == last) {
      // Push index to delta list
      m_deleteList.push_back(book->getFileIndex());
      return true;
    } else {
      return false;
    }
  } catch(exception& e) {
    cerr << "Inventory::delBook(): "  << e.what() << endl;
  }
  return 0;
}

bool Inventory::sync() {
  // Open database
  // for elements in delta list
  //    Set cursor to record based on index
  //    Write book to record
  // for elements in delete list
  //    Set cursor to record based on index
  //    Remove record from database
  //    Erase book from book list
  // for elements in add list
  //    TODO: check if element exists in book list
  //    Push element to book list
  //    Write book to database
  // close database
  //
  // call reset
  return 0;
}

bool Inventory::reset() {
  try {
    // Clear delta list, add list, and delete list
    m_deltaList.clear(); m_addList.clear(); m_deleteList.clear();
    clearBookList(); // Clear book list

    // Open database
    m_db->open(INV_FILE);
    m_db->start(); // Start reading from beginning

    while(!m_db->eof()) {
      Book buffer; // Create temporary book (on stack)
      if(m_db->read(&buffer)) {
        // Read record into book, and if succeeds...?
        Book* book = new Book; // Create new book (on heap)
        *book = buffer;        // Copy buffer book to new
        m_bookList.push_back(book); // Push to book list
      } else {
        throw runtime_error("Unable to read record");
      }
    }

    m_db->close(); // Close database
    return true;
  } catch(exception& e) {
    cerr << "Inventory::reset(): " << e.what() << endl;
    return false;
  }
}

unsigned Inventory::getSize()               {
  // Return number of books in inventory
  return m_bookList.size();
}

vector<Book*> Inventory::getRange(int first, int last) {
  // Create empty book list
  vector<Book*> retval;

  // if first < last
  //    if first/last are within book list bounds
  //      Assign empty vector with bounds from book list
  // return book list (empty or not)
  return retval;
}

vector<Book*> Inventory::findBook(Book::field field, void* search) {
  // Create temp book list
  vector<Book*> retval;

  // for all books in book list
  //    switch field
  //      case ISBN
  //        if book isbn is equal to search
  //          push book to temp book list
  //      case TITLE
  //        if book title is equal to search
  //          push book to temp book list
  //      case AUTHOR
  //        if book author is equal to search
  //          push book to temp book list
  //      case QUANTITY
  //        if book quantity is equal to search
  //          push book to temp book list
  //      case WHOLECOST
  //        if book wholecost is equal to search
  //          push book to temp book list
  //      case DATEADDED
  //        if book dateadded is equal to search
  //          push book to temp book list
  return retval;
}










// Private methods
void Inventory::clearBookList() {
  for(unsigned i = 0; i < m_bookList.size(); i++) {
    delete m_bookList[i];
  }
}
