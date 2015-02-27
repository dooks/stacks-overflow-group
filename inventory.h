#pragma once
#include <vector>
#include "db.h"
#include "book.h"

class Inventory {
public:
  typedef std::vector<Book*> book_list;
  typedef std::vector<Book*>::iterator book_iter;

private:
  typedef std::vector<size_t> size_list;
  typedef std::vector<size_t> size_iter;

  book_list   m_bookList;
  book_list    m_addList; // List of new books to add at sync
  size_list  m_deltaList; // List of books that have changed
  size_list m_deleteList; // List of books to delete at sync
  DB::Database*     m_db;

  int clearBookList();    // Deletes list items, and clears

public:
  // Mutators
  int addBook(Book*);     // Append book to book list at sync
  int updBook(book_iter); // Flag book for changes at sync
  int delBook(book_iter); // Flag book for deletion at sync

  int sync();             // Save all buffered changes
  // Critical note: this will invalidate any iterators to book_list
  int reset();            // Reset book list to database
  // Critical note: this will invalidate any iterators to book_list

  // Accessors
  int getSize();          // Return number of books in inventory
  book_list getRange(int, int);
  book_list findBook(Book::field, void*);
};
