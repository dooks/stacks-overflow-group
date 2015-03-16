#include <string>
#include <vector>
#include <deque>
#include "date.h"
using namespace std;

#include "book.h"

// BookPoolSub
BookPoolSub::BookPoolSub(unsigned size, deque<void*>& freeq) {
  // Assign memory block to m_pool
    // Memory block is size * (sizeof(Book) + 8byte padding)
  // for i to size
    // Create temp void*
    // Assign address of m_pool + i to temp void*
    // push back void* into freeq
}

BookPoolSub::~BookPoolSub() {
  // deallocate m_pool
}




// Book Pool
// static declarations
deque<void*> BookPool::m_free;
vector<BookPoolSub*> BookPool::m_poolList;
char BookPool::m_maxsize = POOL_INIT_SIZE;

BookPoolSub* BookPool::Expand(size_t size) {
  // Create new BookPoolSub with size
    // Segment pool
  // Return temp BookPoolSub
  return NULL;
}

void BookPool::Compress() {
  // Free higher size pools when not used
  // TODO: Low priority
  return;
}

void* BookPool::Allocate(size_t size) {
  // Create temp void pointer to NULL
  // if m_free is empty
    // Pools are completely filled
    // Expand pool, and push back into m_poolList
  // set temp void pointer to front of m_free
  // pop m_free
  // return temp void pointer
  return NULL;
}

void BookPool::Free(void* ptr)  {
  // Add ptr to front of m_free
  return;
}


Book::Book() {
  m_index = 0;
  m_quantity = 0;
  m_wholeCost = 0.0;
  m_retailPrice = 0.0;
  strcpy_s(m_isbn     , "");
  strcpy_s(m_title    , "");
  strcpy_s(m_author   , "");
  strcpy_s(m_publisher, "");
  m_dateAdded.setMonth(0);
    m_dateAdded.setDay(0);
   m_dateAdded.setYear(0);
}

Book::Book(const Book& o) {
  m_index       = o.m_index;
  strcpy_s(m_isbn     , o.m_isbn     );
  strcpy_s(m_title    , o.m_title    );
  strcpy_s(m_author   , o.m_author   );
  strcpy_s(m_publisher, o.m_publisher);
  m_dateAdded   = o.m_dateAdded;
  m_quantity    = o.m_quantity;
  m_wholeCost   = o.m_wholeCost;
  m_retailPrice = o.m_retailPrice;
}

void Book::operator=(const Book& o) {
  m_index       = o.m_index;
  strcpy_s(m_isbn     , o.m_isbn     );
  strcpy_s(m_title    , o.m_title    );
  strcpy_s(m_author   , o.m_author   );
  strcpy_s(m_publisher, o.m_publisher);
  m_dateAdded   = o.m_dateAdded;
  m_quantity    = o.m_quantity;
  m_wholeCost   = o.m_wholeCost;
  m_retailPrice = o.m_retailPrice;
}
Book::~Book() {}

void* Book::operator new(size_t size) {
  try {
    BookPool::Allocate(size);
  } catch(exception& e) {
    cerr << "Book::operator new: " << e.what() << endl;
    return NULL;
  }
}

void Book::operator delete(void* ptr) {
  try {
    BookPool::Free(ptr);
  } catch(exception& e)  {
    // Immediately throw exception
    throw e;
  }
}

void Book::setFileIndex(unsigned idx) { m_index = idx;        }
void Book::setISBN(string isbn)    {
  strcpy_s(m_isbn, isbn.c_str());
}
void Book::setTitle (string title)   { strcpy_s( m_title,  title.c_str()); }
void Book::setAuthor(string author)  { strcpy_s(m_author, author.c_str()); }
void Book::setPublisher(string publisher) {
  strcpy_s(m_publisher, publisher.c_str());
}
void Book::setQuantity(int quantity) { m_quantity = quantity; }
void Book::setDateAdded(int month, int day, int year) {
  m_dateAdded.setMonth(month);
      m_dateAdded.setDay(day);
    m_dateAdded.setYear(year);
}
void Book::setWholeCost(double cost)     { m_wholeCost = cost;    }
void Book::setRetailPrice(double price)  { m_retailPrice = price; }
void Book::setRandom()  {
  // Set random isbn string
  // Set random title
  // Set random author
  // Set random date
  // Set random quantity on hand
  // Set random wholesale cost
  // Set random retail price
}

unsigned Book::getFileIndex() { return m_index;       }
string Book::getISBN()        { string retval = m_isbn;      return retval;  }
string Book::getTitle()       { string retval = m_title;     return retval;  }
string Book::getAuthor()      { string retval = m_author;    return retval;  }
string Book::getPublisher()   { string retval = m_publisher; return retval;  }
date   Book::getDateAdded()   { return m_dateAdded;   }
int    Book::getQuantity()    { return m_quantity;    }
double Book::getWholeCost()   { return m_wholeCost;   }
double Book::getRetailPrice() { return m_retailPrice; }
