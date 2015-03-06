#pragma once
#include <string>
using std::string;

#include "date.h"

class Book {
  unsigned m_index;

  string m_isbn;
  string m_title;
  string m_author;
  string m_publisher;
  date   m_dateAdded;
  int    m_quantity;
  double m_wholeCost;
  double m_retailPrice;

public:
  enum field { ISBN, TITLE, AUTHOR, PUBLISHER,
    QUANTITY, WHOLECOST, RETAILPRICE, DATEADDED };

  // Constructors
  Book();
  ~Book();

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
