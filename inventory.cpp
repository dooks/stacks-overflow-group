#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "inventory.h"
#include "db.h"
#include "book.h"
using namespace std;

Inventory::Inventory()  {
  m_db = new DB::Local;
  m_dbFileName = DEFAULT_INV_FILE;
}
Inventory::Inventory(string filename) {
  m_db = new DB::Local;
  m_dbFileName = filename;
}

Inventory::~Inventory() { if(m_db != NULL) delete m_db; }

// Mutators
bool Inventory::addBook(Book* book) {
  try {
    if(book == NULL) throw domain_error("Domain Error: Argument is NULL");

    // ISBN numbers are unique (or should be...): search if exists
    // Only add to FIRST book found
    vector<Book*> search = findBook(Book::ISBN, &(book->getISBN()));
    if(search.empty()) {
      // Add book to list, for writing to file later
      m_addList.push_back(book);
    } else {
      // Change quantity of found book
      search[0]->setQuantity( search[0]->getQuantity() + 1);
      // Mark book for update
      updBook(search[0]);
    }
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
  try {
    // Open database
    m_db->open(m_dbFileName);

    // for elements in delta list
    for(unsigned i = 0; i < m_deltaList.size(); i++) {
      // Find book by index
      Book* temp = getBook(m_deltaList[i]);
      // Write book to record
      //if(!m_db->change(temp)) throw runtime_error("Could not modify database");
    }


    // Sort delete list in reverse... order matters when deleting from arrays!
    sort(m_deleteList.begin(), m_deleteList.end());
    reverse(m_deleteList.begin(), m_deleteList.end()); // TODO: Inefficient...?
    //for(unsigned i = m_deleteList.size(); i >= 0; i--) {
      //Book* temp = getBook(m_deleteList[i]);
      ////if(!m_db->remove(temp)) throw runtime_error("Could not remove from database");
      //delete temp;        // Deallocate
      //m_deleteList.erase(m_deleteList.begin() + i); // Erase from vector
    //}


    // for elements in add list
    for(unsigned i = 0; i < m_addList.size(); i++) {
      // Push element to book list
      m_bookList.push_back(m_addList[i]);
      // Write book to database
      //if(!m_db->add(m_addList[i])) throw runtime_error("Could not add to database");
    }

    m_db->close();
    reset();
    return true;
  } catch(exception& e) {
    cerr << "Inventory::sync: " << e.what() << endl;
    return false;
  }
}

bool Inventory::reset() {
  try {
    if(m_db == NULL) throw domain_error("Database not initialized (use Inventory::setDatabase");

    // Clear delta list, add list, and delete list
    m_deltaList.clear(); m_addList.clear(); m_deleteList.clear();
    clearBookList(); // Clear book list

    // Open database
    m_db->open(m_dbFileName);
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

  try {
    if(first >= last) throw domain_error("Domain Error: first >= last");

    // check if first/last are within book list bounds
    // Auto throws out of range exception
    m_bookList.at(first);
    m_bookList.at(last);

    // Assign empty vector with bounds from book list
    vector<Book*> sub(m_bookList.begin() + first, m_bookList.begin() + last);
    retval = sub;

  } catch(exception &e) {
    cerr << "Inventory::getRange: "  << e.what() << endl;
  }
  return retval;
}

vector<Book*> Inventory::findBook(Book::field field, void* search) {
  // Create temp book list
  vector<Book*> retval;

  // for all books in book list
  for(unsigned i = 0; i < m_bookList.size(); i++) {
    Book* book = m_bookList[i];
    switch(field) {
      case Book::ISBN:
        if(book->getISBN() == *((string*) search))
          retval.push_back(book);
        break;
      case Book::TITLE:
        if(book->getTitle() == *((string*) search))
          retval.push_back(book);
        break;
      case Book::AUTHOR:
        if(book->getAuthor() == *((string*) search))
          retval.push_back(book);
        break;
      case Book::QUANTITY:
        if(book->getQuantity() == *((int*) search))
          retval.push_back(book);
        break;
      case Book::WHOLECOST:
        if(book->getWholeCost() == *((double*) search))
          retval.push_back(book);
        break;
      case Book::RETAILPRICE:
        if(book->getRetailPrice() == *((double*) search))
          retval.push_back(book);
        break;
      case Book::DATEADDED:
        if(book->getDateAdded() == *((date*) search))
          retval.push_back(book);
        break;
      default:
        break;
    }
  }
  return retval;
}





// Private methods
Book* Inventory::getBook(unsigned index) {
  try {
    if(index >= m_bookList.size()) throw out_of_range("Out of Range");

    // For all items in book list
    // TODO: critical: book file indices must start at 0, not 1
    for(unsigned i = 0; i < m_bookList.size(); i++) {
      if(m_bookList[i]->getFileIndex() == index)
        return m_bookList[i];
    }

    return NULL;
  } catch(exception& e) {
    cerr << "Inventory::getBook: " << e.what() << endl;
    return NULL;
  }
}

void Inventory::clearBookList() {
  for(unsigned i = 0; i < m_bookList.size(); i++) {
    delete m_bookList[i];
  }
}
