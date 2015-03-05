#include <iostream>
#include <stdexcept>
#include "db.h"
#include "book.h"
using namespace std;

namespace DB {
  flag8 OPEN = 0x01;
  flag8 FAIL = 0x02;
  flag8 FEOF = 0x04;


  Local::Local() :
    m_cursor(0), m_dbSize(0),
    m_header(sizeof(unsigned)),
    m_align(sizeof(Book) + sizeof(bool)) { /* Initialize members*/ }

  bool Local::open(string filename) {
    try {
      {
        // Open file if it doesn't exist - should always work
        ofstream o(filename, ios::out | ios::app);
        o.close();
      }

    if(m_file != NULL) throw logic_error("Database already opened");

    // Open db file
    // Save pointer to fstream to m_file
    m_file = new fstream;
    m_file->open(filename, ios::in | ios::out | ios::binary | ios::ate);
    if(m_file->fail()) throw logic_error(filename + " failed to open");

    m_status |= DB::OPEN; // set status flag open

    m_file->seekg(0, ios::beg);
    m_file->seekp(0, ios::beg);

    if(m_file->peek() != fstream::traits_type::eof()) {
      // File is not empty
      // Read header
      // Get size of database from file
      m_file->read(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));
      if(m_file->fail()) throw runtime_error("Failed to read " + filename);

      checkUnused(); // Check for unused records
      return true;

    } else {
      // File is empty
      m_file->clear();
      m_dbSize = 0;
      // Write header
      m_file->write(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));
      if(m_file->fail()) throw runtime_error("Failed to write to " + filename);

      queue<unsigned>().swap(m_unusedIndex); // Clear unused index queue
      return true; // return true
    }

    } catch(exception& e) {
      cerr << "Local::open() -- Exception: " << e.what() << endl;
      if(m_file != NULL) {
        m_file->close();
        delete m_file;
        m_file = NULL;
      }
      return false;
    }
  }

  bool Local::isOpen() {
    if(m_status & DB::OPEN) return true;
    else return false;
  }

  int Local::add(Book* book) {
    // If book is invalid
    if(book == NULL) {
      // TODO: exception handling
      return -1;
    }

    unsigned index = 0;
    // If an element of unused indices exist
    if(!m_unusedIndex.empty()) {
      index = m_unusedIndex.front(); // Assign first index to temp var
      m_unusedIndex.pop(); // Pop first element of unused indices list
      book->setFileIndex(index); // Assign index to book
      seekb(index); // Set cursor to record at index
      write(book, true); // Write book with used flag
    } else {
      // Increase size of db by one
      index = m_dbSize += 1;
      m_file->seekp(0); // Set cursor to beginning of file
      m_file->write(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));

      // Append book
      m_file->seekp(0, ios::end); // Set cursor to end of file
      write(book, true); // Write book with used flag
      //m_file->clear(); // Clear EOF flag? necessary?
    }
    return index;
  }

  bool Local::read(Book* book) {
    // Check if used record
    bool used = true;
    m_file->read(reinterpret_cast<char*>(used), sizeof(bool));
    if(!used) return false; // Skip record

    // TODO: deep copy...
    m_file->read(reinterpret_cast<char*>(book), sizeof(book)); // Save record at cursor into book
    // TODO: exception... file corrupt
    return true;
  }

  bool Local::remove(Book* book) {
    // Check if book's index is within db size
    if(book->getFileIndex() < m_dbSize) {
      // Reduce size of database by one
      m_file->seekp(0);
      m_file->write(reinterpret_cast<char*>(&(--m_dbSize)), sizeof(unsigned));

      seekb(book->getFileIndex()); // Seek record at book's index
      bool temp = false;
      m_file->write(reinterpret_cast<char*>(&temp), sizeof(bool)); // Write unused
      return true;
    } else {
      // TODO: throw exception
      return false;
    }
  }

  bool Local::close() {
    // if m_open is false
    if(m_file == NULL) {
      // Throw exception? or ignore
      return false;
    } else {
      m_file->close(); // Close db file
      delete m_file;
      m_file = NULL;
      return true;
    }
  }





  // Internal methods
  void Local::checkUnused() {
    if(isOpen()) {
      try { seekb(0); /* Seek to first record */ }
      catch(const out_of_range& oor) {
        cerr << "Local::checkUnused(): " << oor.what() << endl;
      }

      bool used = true; // If record is used
      unsigned i = 0;   // index counter
      while(!eof()) {
        // Check if record is marked used
        m_file->read(reinterpret_cast<char*>(used), sizeof(bool));
        if(used) continue;
        else m_unusedIndex.push(i); // Add index to unused list
      }
    } else {
      cerr << "Local::checkUnused(): Database is not open" << endl;
    }
  }

  int Local::write(Book* book, bool used) {
    //if(isOpen()) {
    if(true) {
      // If file is open:
      bool temp = true; // Write bool used
      m_file->write(reinterpret_cast<char*>(&temp), sizeof(bool));
      // Write book structure
      m_file->write(reinterpret_cast<char*>(book), sizeof(Book));
      return book->getFileIndex();
    } else {
      // File not open
      // Throw exception
      return -1;
    }
  }

  void Local::seekb(unsigned index) {
    // Throw exception if index is out of range
    if(index > m_dbSize) throw out_of_range("Exception: Bad index");
    // Move cursor to index * align
    m_cursor = m_header + (index * m_align);
  }

  void Local::seekr(unsigned index) {
    // Move cursor to alignment of current record
    // m_cursor = (m_cursor - (m_cursor % m_align));
    // Move cursor relative by index * align
    m_cursor += (index * m_align);
  }

  bool Local::eof() {
    if(m_file->eof()) {
      m_file->clear();
      return true;
    } else {
      return false;
    }
  }

  bool Local::clean() {
    // TODO
    // Reindex database... low priority
    return true;
  }
}
