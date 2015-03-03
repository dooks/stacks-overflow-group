#include "db.h"
#include "book.h"
using std::string;

namespace DB {
  flag8 OPEN = 0x01;
  flag8 FAIL = 0x02;
  flag8 FEOF = 0x04;

  Local::Local(string filename) { /* Initialize members*/ }

  bool Local::open(string filename) {
    // if m_open is false
    //    Open db file for reading at beginning
    //    Save pointer to istream to m_file
    //    set status flag open
    //    Check for unused records
    // else
    //    Throw exception? or just ignore
    //    Set status flag fail
    // return false
    return false;
  }

  int Local::add(Book* book) {
    // If an element of unused indices exist
    //    Assign first index to temp var
    //    Pop first element of unused indices list
    //    Assign index to book
    //    Write book with used flag
    //    return index
    // else
    //    Set cursor to last record and save index + 1
    //    Set cursor to end record
    //    Write book with used flag
    //    return index
    return 0;
  }

  int Local::read(Book* book) {
    // Move cursor up by one bool sizeof
    // Save record at cursor into book
    // Set cursor up to next record
    // return true
    return 0;
  }

  int Local::remove(Book* book) {
    // Seek record at book's index
    // Write unused
    return 0;
  }

  bool Local::close() {
    // if m_open is false
    //    Throw exception? or ignore
    // else
    //    Close db file
    //    Set m_open to false
    return false;
  }





  // Internal methods
  void Local::checkUnused() {
    // If m_open is true:
    //    Seek to beginning
    //    While not end of file
    //       Read next bool into temp var
    //       If true, continue
    //       else push into m_unusedIndex
    // else
    //    Throw exception and ignore
  }

  int Local::write(Book* book, bool used) {
    // If m_open is true:
    //    Write bool used
    //    Write book structure
    //    return book index
    // else:
    //    Throw exception
    return 0;
  }

  void Local::seekb(int index) {
    // Move cursor to index * align
  }

  void Local::seekr(int index) {
    // Move cursor to alignment of current record
    // Move cursor relative by index * align
  }

  void Local::seeke() {
    // Move cursor to eof
    // Move cursor to previous record
  }

  bool Local::clean() {
    // Reindex database... low priority
    return true;
  }

  // Status methods - low priority
  bool Local::eof()   {
    // if db file is at eof
    //    clear file eof
    //    return true
    // else
    //    return false
    return false;
  }
  bool Local::fail()  { return false; }
  bool Local::clear() { return false; }
}
