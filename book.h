#pragma once
#include <string>
using std::string;

#include "date.h"

class Book {
  unsigned m_index;

  string m_isbn;
  string m_title;
  string m_author;
  date   m_dateAdded;
  int    m_quantity;
  double m_wholeCost;
  double m_retailPrice;

public:
  enum field { ISBN, TITLE, AUTHOR, QUANTITY, WHOLECOST, DATEADDED };

  // Constructors
  Book();
  ~Book();

  // Mutators
  void setFileIndex(unsigned);
  void setISBN(string);
  void setTitle(string);
  void setAuthor(string);
  void setDateAdded(int, int, int);
  void setQuantity(int);
  void setRandom();

  // Accessors
  unsigned getFileIndex();
  string getISBN(void);
  string getTitle(void);
  string getAuthor(void);
  date   getDate(void);
  int    getQuantity(void);
  double getWholeCost(void);
  double getRetailPrice(void);
};
