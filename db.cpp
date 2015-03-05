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
    m_file->exceptions( fstream::failbit | fstream::badbit );
    m_file->open(filename, ios::in | ios::out | ios::binary | ios::ate);

    m_status |= DB::OPEN; // set status flag open

    m_file->seekg(0, ios::beg);
    m_file->seekp(0, ios::beg);

    if(m_file->peek() != fstream::traits_type::eof()) {
      // File is not empty
      // Read header
      // Get size of database from file
      m_file->read(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));

      checkUnused(); // Check for unused records
      return true;

    } else {
      // File is empty
      m_file->clear(); // EOF was reached, make sure to clear error bits

      // Write header
      m_dbSize = 0;
      m_file->write(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));

      queue<unsigned>().swap(m_unusedIndex); // Clear unused index queue
      return true; // return true
    }

    } catch(exception& e) {
      cerr << "Local::open(): " << e.what() << endl;
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
    // Reset file bits
    m_file->clear();

    try {
      // If book is invalid
      if(book   == NULL) throw domain_error("Domain Error: Argument is NULL");
      if(m_file == NULL) throw logic_error("Database not open");

      unsigned index = 0;
      if(!m_unusedIndex.empty()) {
        // If an element of unused indices exist
        index = m_unusedIndex.front(); // Assign first index to temp var
        m_unusedIndex.pop(); // Pop first element of unused indices list
        book->setFileIndex(index); // Assign index to book
        seekb(index); // Set cursor to record at index
        write(book, true); // Write book with used flag

      } else {
        // No unused indices... append to file instead
        // Increase size of db by one
        index = m_dbSize += 1;
        m_file->seekp(0, ios::beg); // Set cursor to beginning of file
        m_file->write(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));

        // Append book
        m_file->seekp(0, ios::end); // Set cursor to end of file
        book->setFileIndex(index);
        write(book, true); // Write book with used flag
        //m_file->clear(); // Clear EOF flag? necessary?
      }
      return index;
    } catch(exception& e) {
      cerr << "Local::add(): " << e.what() << endl;
      return -1;
    }
  }

  bool Local::read(Book* book) {
    // Reset fail bits
    m_file->clear();

    // Check if used record
    bool used = true;
    m_file->read(reinterpret_cast<char*>(used), sizeof(bool));
    if(m_file->fail()) throw runtime_error("Could not read file.");
    if(!used) return false; // Skip record

    // TODO: deep copy...
    m_file->read(reinterpret_cast<char*>(book), sizeof(book)); // Save record at cursor into book
    if(m_file->fail()) throw runtime_error("Could not read file.");
    // TODO: exception... file corrupt
    return true;
  }

  bool Local::remove(Book* book) {
    // Reset fail bits
    m_file->clear();

    try {
      if(book   == NULL)
        throw domain_error("Domain Error: Argument is NULL");
      if(book->getFileIndex() == -1)
        throw domain_error("Domain Error: Book's index is not valid.");
      if(m_file == NULL)
        throw logic_error("Database not open");

      // Check if book's index is within db size
      if(book->getFileIndex() <= m_dbSize) {
        // Write record as unused
        bool temp = false;
        seekb(book->getFileIndex()); // Seek record at book's index
        m_file->write(reinterpret_cast<char*>(&temp), sizeof(bool));
        m_unusedIndex.push(book->getFileIndex()); // Add index to unused index
        return true;
      } else {
        throw out_of_range("Index out of range of database size");
      }
    } catch(exception &e) {
      cerr << "Local::remove(): " << e.what() << endl;
      return false;
    }
  }

  bool Local::close() {
    try {
      if(m_file == NULL) {
        throw runtime_error("Runtime Error: No database open");
      } else {
        m_file->close(); // Close db file
        delete m_file;
        m_file = NULL;
        return true;
      }
    } catch(exception &e) {
      cerr << "Local::close(): " << e.what() << endl;
      throw e;
      return false;
    }
  }





  // Internal methods
  void Local::checkUnused() {
    try {
      if(isOpen()) {
        seekb(0); /* Seek to first record */

        bool used = true; // If record is used
        unsigned i = 0;   // index counter
        while(m_file->peek() != fstream::traits_type::eof()) {
          // Check if record is marked used
          m_file->clear();
          m_file->read(reinterpret_cast<char*>(&used), sizeof(bool));
          //if(m_file->fail()) throw runtime_error("Failed to read record");
          seekr(1);

          if(!used)
            m_unusedIndex.push(i); // Add index to unused list
          i++;
        }
      } else {
        throw logic_error("Database not open");
      }

    } catch(exception& e) {
      cerr << "Local::checkUnused(): " << e.what() << endl;
      throw e;
    }
  }

  int Local::write(Book* book, bool used) {
    // Reset fail bits...
    m_file->clear();

    if(isOpen()) {
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
    // TODO: Throw exception if index is out of range
    if(index > m_dbSize) {
      m_file->seekg(0, ios::end);
      m_file->seekp(0, ios::end);
    } else {
      // Move cursor to index * align
      m_cursor = m_header + (index * m_align);

      m_file->seekg(m_cursor, ios::beg);
      m_file->seekp(m_cursor, ios::beg);
    }
  }

  void Local::seekr(int index) {
    // TODO: Throw exception if index is out of range
    // Check if index will move cursor out of range
    if(m_cursor < m_header) {
      // Assume user wants first record
      seekb(0);
      return;
    } else if(m_cursor >= (m_align*m_dbSize + m_header)) {
      // Assume end of file
      seekb(m_dbSize + 1);
      return;
    }

    // Align cursor to beginning of current record
    m_cursor = m_cursor - ((m_cursor - m_header) % m_align);

    // Calculate where cursor will shift to
    int shifted = (int) m_cursor + index * (int) m_align;
    // Check if cursor will go out of bounds
    if(shifted <= (int) m_header) {
      seekb(0);
    } else if(shifted > (int) m_dbSize * (int) m_align + (int) m_header) {
      seekb(m_dbSize + 1);
    } else {
      // Move cursor relative by index * align
      m_cursor += (index * m_align);

      m_file->seekg(m_cursor, ios::beg);
      m_file->seekp(m_cursor, ios::beg);
    }
  }

  bool Local::clean() {
    // TODO
    // Reindex database... low priority
    return true;
  }
}
