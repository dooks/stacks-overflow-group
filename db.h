#pragma once
#include <string>
#include <fstream>
#include <vector>
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
      virtual  int read(Book*)   = 0; // Read record at cursor into Book*
      virtual  int remove(Book*) = 0; // Remove this record
      virtual bool close()       = 0;
      virtual ~Database() {}
  };

  class Local : public Database {
    int m_cursor;
    int m_align;

    std::string m_filename;
    std::ifstream*  m_file;
    std::vector<int> m_unusedIndex;

    // Internal Methods
    int write(Book*, bool); // Write book into record used/unused
    void checkUnused(); // Read entire db file for unused records
    void seekb(int);  // Set cursor to record from beginning
    void seekr(int);  // Set cursor to record relative
    void seeke(void); // Set cursor to last record
    bool clean();

    // Status methods
    bool eof();
    bool fail();
    bool clear();

  public:
    Local(std::string);

    // Public methods
    bool open(std::string);
    int    add(Book*);
    int   read(Book*);
    int remove(Book*); // Mark record as unused
    bool      close();
  };

  class Remote : public Database {
    /*
     * Remote database implementation
     * Low priority
     */
  };
}
