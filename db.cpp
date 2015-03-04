#include <iostream>
#include "db.h"
#include "book.h"
using namespace std;

namespace DB {
  flag8 OPEN = 0x01;
  flag8 FAIL = 0x02;
  flag8 FEOF = 0x04;


  Local::Local() :
    m_cursor(0), m_dbSize(0) {
      m_header = sizeof(unsigned);
      m_align  = sizeof(Book) + sizeof(bool);
      /* Initialize members*/
    }

  bool Local::open(string filename) {
    // if m_open is false
    if(m_file == NULL) {
      // Open file if it doesn't exist
      ifstream temp_file(filename);
      temp_file.close();

      // Open db file for reading at beginning
      // Save pointer to istream to m_file
      m_file = new fstream(filename, ios::in | ios::out | ios::binary);

      if(!m_file->fail()) {
        m_status |= DB::OPEN; // set status flag open

        // If File is not empty
        if(m_file->peek() != fstream::traits_type::eof()) {
          // Read header
          m_file->read(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned)); // Get size of database
          checkUnused(); // Check for unused records
          return true;
        } else {
          m_file->clear();

          // File is empty
          m_dbSize = 0; // Set size of db to zero
          // Write header
          m_file->write(reinterpret_cast<char*>(&m_dbSize), sizeof(unsigned));

          queue<unsigned>().swap(m_unusedIndex); // Clear unused index queue
          return true; // return true
        }
      } else {
        // TODO: throw exception
        // File failed to read
        return false;
      }
    } else {
      // File already opened
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
    //    Seek to beginning
    //    While not end of file
    //       Read next bool into temp var
    //       If true, continue
    //       else push into m_unusedIndex
    } else {
    //    Throw exception and ignore
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

  bool Local::seekb(int index) {
    // Move cursor to index * align
    m_cursor = m_header + (index * m_align);
    if(m_cursor <= m_dbSize)
      return true;
    else
      return false;
  }

  bool Local::seekr(int index) {
    // Move cursor to alignment of current record
    //m_cursor = (m_cursor - (m_cursor % m_align));
    // Move cursor relative by index * align
    m_cursor += (index * m_align);
    if(m_cursor <= m_dbSize)
      return true;
    else
      return false;
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
    // Reindex database... low priority
    return true;
  }
}
