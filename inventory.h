#pragma once
#include <vector>
#include "db.h"
#include "book.h"
using std::vector;

class Inventory {
private:
  typedef std::vector<size_t> size_list;
  typedef std::vector<size_t> size_iter;

  vector<Book*>  m_bookList;
  vector<Book*>  m_addList; // List of new books to add at sync
  vector<size_t> m_deltaList; // List of books that have changed
  vector<size_t> m_deleteList; // List of books to delete at sync
  DB::Database*  m_db;

  int clearBookList();    // Deletes list items, and clears

public:
  Inventory();
  Inventory(DB::Database*);
  ~Inventory();

  // Mutators
  void setDatabase(DB::Database*);
  int  addBook(Book*); // Append book to book list at sync
  int  updBook(Book*); // Flag book for changes at sync
  int  delBook(Book*); // Flag book for deletion at sync

  int sync();             // Save all buffered changes
  // Critical note: this will invalidate any iterators to vector<Book*>
  int reset();            // Reset book list to database
  // Critical note: this will invalidate any iterators to vector<Book*>

  // Accessors
  int getSize();          // Return number of books in inventory
  vector<Book*> getRange(int, int);
  vector<Book*> findBook(Book::field, void*);
};
