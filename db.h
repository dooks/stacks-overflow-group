#pragma once
#include <string>
#include <fstream>
#include <queue>
using std::string;
using std::fstream;
using std::queue;

#include "book.h"

namespace DB {
  typedef unsigned char flag8;

  extern flag8 OPEN;
  extern flag8 FAIL;
  extern flag8 FEOF;

  class Database {
    // Interface
    protected:
      short m_status;
      virtual bool clean() = 0; // Reindex database

    public:
      // Methods
      virtual bool open(string) = 0; // Open database for reading/writing
      virtual bool isOpen()      = 0; // Check if db is open
      virtual  int add(Book*)    = 0; // Add book to database
      virtual bool read(Book*)   = 0; // Read current record and move up one
      virtual bool change(Book*) = 0; // Change book* (it must exist as record)
      virtual bool remove(Book*) = 0; // Remove this record
      virtual bool close()       = 0; // Close database
      virtual void start()       = 0; // Start reading at start of database
      virtual bool eof()         = 0; // Check if at end of database
      virtual ~Database() {}
  };

  class Local : public Database {
    unsigned m_cursor;
    size_t    m_align;
    size_t   m_header;
    unsigned m_dbSize;

    fstream*  m_file;
    queue<unsigned> m_unusedIndex;

    // Internal Methods
    queue<unsigned> findUnused(); // Read entire db file for unused records
                                  // Resets and populates m_unusedIndex
    void write(Book*, bool); // Write book into record used/unused
    void seekb(unsigned);    // Set cursor to record from beginning
    void seekr(int);         // Set cursor to record relative
    bool clean();            // Squash unused records and reindex

  public:
    Local();

    // Public methods
    bool open(string);
    bool isOpen();
    int  add(Book*);    // Used unused record if exists, otherwise append
    bool read(Book*);
    bool change(Book*);
    bool remove(Book*); // Mark record as unused
    bool close();

    void start(); // Move cursor to first record
    bool   eof(); // Check if last record reached
  };

  class Remote : public Database {
    /*
     * Remote database implementation
     * Low priority
     */
  };
}
