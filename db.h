#include <string>
#include <vector>
using std::string;

#include "book.h"

typedef char flag8;
typedef char flag16;

namespace DB {
  flag8 FAIL   = 0x00; // 0000 0000
  flag8 FEOF   = 0x01; // 0000 0010

  flag8 READ   = 0x00; // 0000 0000
  flag8 WRITE  = 0x01; // 0000 0001
  flag8 APPEND = 0x02; // 0000 0010
  flag8 BEGIN  = 0x04; // 0000 0100
  flag8 END    = 0x08; // 0000 1000

  class Database {
    // Interface
    protected:
      short m_status;
      bool    m_open;

    public:
      // Methods
      virtual bool  open(string); // Open database for reading/writing
      virtual bool   read(Book*);  // Add book to database
      virtual bool    add(Book*);   // Read record at cursor into Book*
      virtual bool remove(Book*); // Remove this record
      virtual bool close();
      virtual ~Database();
  };

  class Local : public Database {
    string m_filename;
    ifstream*  m_file;
    int      m_cursor;
    std::vector<int> m_unusedIndex;

    // Internal Methods
    write(Book*, bool); // Write book into record used/unused

    // Status methods
    bool eof();
    bool fail();
    bool clear();
    int seekb( int); // Set cursor to record from beginning
    int seekr( int); // Set cursor to record relative
    int seeke(void); // Set cursor to last record

  public:
    Local(string);

    // Public methods
    bool        open();
    int     add(Book*);
    bool   read(Book*);
    bool remove(Book*); // Mark record as unused
    bool       close();

  };

  class Remote : public Database { };
}

