#pragma once
#include <vector>
#include <string>
#include "db.h"
#include "book.h"
using std::string;
using std::vector;

#define DEFAULT_INV_FILE "books.db"

class Inventory {
  vector<Book*>  m_bookList;
  vector<Book*>  m_addList; // List of new books to add at sync
  vector<unsigned> m_deltaList; // List of books that have changed
  vector<unsigned> m_deleteList; // List of books to delete at sync
  DB::Database*  m_db;
  string m_dbFileName;

  Book* getBook(unsigned); // Retrieve Book* from index
  void clearBookList();    // Deletes list items, and clears

public:
  Inventory();          // Use default db file, DEFAULT_INV_FILE
  Inventory(string);    // Initialize with a filename
  ~Inventory();

  // Mutators
  bool setFile(string); // Set location of db file
  bool addBook(Book*);  // Append book to book list at sync
  bool updBook(Book*);  // Flag book for changes at sync
  bool delBook(Book*);  // Flag book for deletion at sync

  bool sync();             // Save all buffered changes
  // Critical note: this will invalidate any iterators to vector<Book*>
  bool reset();            // Reset book list to database
  // Critical note: this will invalidate any iterators to vector<Book*>

  // Accessors
  unsigned getSize();          // Return number of books in inventory
  vector<Book*> getRange(int, int);
  vector<Book*> findBook(Book::field, void*);
};
