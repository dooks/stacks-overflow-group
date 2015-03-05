#pragma once
#include <string>
#include <fstream>
#include <queue>
using std::string;

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
      virtual bool open(std::string) = 0; // Open database for reading/writing
      virtual bool isOpen()      = 0; // Check if db is open
      virtual  int add(Book*)    = 0; // Add book to database
      virtual bool read(Book*)   = 0; // Read record at cursor into Book*
      virtual bool remove(Book*) = 0; // Remove this record
      virtual bool close()       = 0;
      virtual ~Database() {}
  };

  class Local : public Database {
    unsigned m_cursor;
    size_t    m_align;
    size_t   m_header;
    unsigned m_dbSize;

    std::fstream*  m_file;
    std::queue<unsigned> m_unusedIndex;

    // Internal Methods
    int write(Book*, bool); // Write book into record used/unused
    void checkUnused();     // Read entire db file for unused records
    void seekb(unsigned);   // Set cursor to record from beginning
    void seekr(int);        // Set cursor to record relative
    bool clean();

  public:
    Local();

    // Public methods
    bool open(std::string);
    bool isOpen();
    int  add(Book*);
    bool read(Book*);
    bool remove(Book*); // Mark record as unused
    bool close();
    bool eof();
  };

  class Remote : public Database {
    /*
     * Remote database implementation
     * Low priority
     */
  };
}
