#include "inventory.h"
#include "db.h"
#include "book.h"

#define INV_FILE "tools/books.db"

Inventory::Inventory() {
  //m_db = new DB::Local(INV_FILE);
}

Inventory::Inventory(DB::Database* db) {
  m_db = db;
}

Inventory::~Inventory() {
  delete m_db;
}

// Mutators
int Inventory::addBook(Book* book) {
  // push book to add list
  return 0;
}

int Inventory::updBook(Book* book) {
  // Get index from iterator
  // if index exists in delta list
  //    erase element from delta list
  //    return error
  // Push index to delta list
  return 0;
}

int Inventory::delBook(Book* book) {
  // Get index from iterator
  // if index exists in delta list
  //    return error
  // Push index to delete list
  return 0;
}

int Inventory::sync() {
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
  // clear delta list, add list, and delete list
  return 0;
}

int Inventory::reset() {
  // Clear delta list, add list, and delete list
  // Clear book list
  // Open database
  // While not database eof
  //    Create temporary book (on stack)
  //    Read record into book
  //    If read succeeds
  //      Create new book (on heap)
  //      Copy temp book to new
  //      Push to book list
  //    else
  //      Skip record
  // Close database
  return 0;
}

int Inventory::getSize()               {
  // Return number of books in inventory
  return 0;
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
