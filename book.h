#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

#include "date.h"

#define POOL_INIT_SIZE  4 // Initial pool size is 1 << n
//#define POOL_COMP_PERC 30 // When pool usage reaches this n%, compress pools

class Book;
class BookPool;

class BookPoolSub {
  friend class BookPool;
  size_t m_size;          // Num of objects being allocated
  size_t m_size_class;    // Size of objects being allocated

  // Initialize with num of Book objects to allocate and size of class
  BookPoolSub(size_t, size_t);
  void* m_pool;           // Pre-allocated block of memory
  deque<void*> segment(); // Segment pool into void* based on sizes

public:
  ~BookPoolSub();         // Free memory pool
};

class BookPool {
  friend class Book;

  // Prevent instances of BookPool
  BookPool();
  BookPool(const BookPool&);
  void operator=(const BookPool&);
  ~BookPool();

  static deque<void*> m_free; // Free, usable void pointers
  static vector<BookPoolSub> m_poolList; // Each new pool is 1<<(n+1) in size
  static char m_maxsize;  // Current global total pool size, 1<<n

  static void Expand(size_t); // New pool list of 1<<(n+1) with size of class
  static void Compress(); // Free higher size pools when not used

protected:
  // "Public" to Book... this is just for reference
  static void* Allocate(size_t); // Returns void pointer to block of size Book
  static void  Free(void*);      // Marks void pointer as unused
};





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
