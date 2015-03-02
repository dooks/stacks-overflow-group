#include "db.h"
#include "book.h"

namespace DB {
  Local::Local(string filename) {
    // Set m_filename to filename
  }

  bool Local::open(string filename) {
    // Open db file for reading at beginning
    // Save pointer to istream to m_file
    // Set m_open to true
  }

  bool     Local::add(Book* book) {
    // If an element of unused indices exist
    //    Assign first index to temp var
    //    Pop first element of unused indices list
    //    Assign index to book
    //    return true
    // else
    //    Set cursor to last record and save index + 1
    //    Set cursor to end record
    //    Write book with used flag
    //    return true
  }

  bool   Local::write(Book* book, bool used) {
    // Write used
    // Write book
    // exception... return false
    // return true
  }

  bool    Local::read(Book* book) {
    // Move cursor up by one bool sizeof
    // Save record at cursor into book
    // return true
  }

  bool  Local::remove(Book* book) {
    // 
  }

  bool             Local::close() {
    // Close db file
    // Set m_open to false
  }

  // Status methods
  bool Local::eof()   { return false; }
  bool Local::fail()  { return false; }
  bool Local::clear() { return false; }
}
