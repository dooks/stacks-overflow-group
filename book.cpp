#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "date.h"
using std::string;

#include "book.h"

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
