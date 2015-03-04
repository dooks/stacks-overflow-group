#include <string>
using std::string;

#include "book.h"

Book::Book() {}
Book::~Book() {}

void Book::setFileIndex(unsigned idx) { m_index = idx;     }
void Book::setISBN  (string isbn)    { m_isbn = isbn; }
void Book::setTitle (string title)   { m_title = title; }
void Book::setAuthor(string author)  { m_author = author; }
void Book::setQuantity(int quantity)  { m_quantity = quantity; }
void Book::setDateAdded(int month, int day, int year) {
  m_dateAdded.setMonth(month);
      m_dateAdded.setDay(day);
    m_dateAdded.setYear(year);
}
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
string Book::getISBN()        { return m_isbn;        }
string Book::getTitle()       { return m_title;       }
string Book::getAuthor()      { return m_author;      }
date   Book::getDate()        { return m_dateAdded;   }
int    Book::getQuantity()    { return m_quantity;    }
double Book::getWholeCost()   { return m_wholeCost;   }
double Book::getRetailPrice() { return m_retailPrice; }
