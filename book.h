#pragma once
#include <iostream>
#include <string>
using std::string;
using std::size_t;

#include "date.h"

class Book {
  unsigned m_index;

  char m_isbn[11];
  char m_title[100];
  char m_author[25];
  char m_publisher[25];
  date   m_dateAdded;
  int    m_quantity;
  double m_wholeCost;
  double m_retailPrice;

public:
  enum field { ISBN, TITLE, AUTHOR, PUBLISHER,
    QUANTITY, WHOLECOST, RETAILPRICE, DATEADDED };

  // Constructors
  Book();                       // Default
  Book(const Book&);            // Copy
  ~Book();
  void  operator=(const Book&); // Assignment
  void* operator   new(size_t);
  void  operator delete(void*);

  // Mutators
  void setFileIndex(unsigned);
  void setISBN(string);
  void setTitle(string);
  void setAuthor(string);
  void setPublisher(string);
  void setDateAdded(int, int, int);
  void setQuantity(int);
  void setWholeCost(double);
  void setRetailPrice(double);
  void setRandom();

  // Accessors
  unsigned getFileIndex();
  string getISBN(void);
  string getTitle(void);
  string getAuthor(void);
  string getPublisher(void);
  date   getDateAdded(void);
  int    getQuantity(void);
  double getWholeCost(void);
  double getRetailPrice(void);
};
