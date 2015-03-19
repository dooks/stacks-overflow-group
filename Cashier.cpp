#include <iostream>
#include <vector>
#include <string>

#include "Cashier.h"
#include "inventory.h"
#include "book.h"

#define SALES_TAX 0.0875

Cashier::Cashier(Inventory* minv) {
  inv = minv;
}

vector<Book*> Cashier::findISBN(string isbn) {
  /*
  Create temp string for isbn
  Create temporary book list
  Call inventory find book function with temp string and assign to temp book list
  return temporary book list
  */
  string userisbn = isbn;
  vector<Book*> isbnsearch = inv->findBook(Book::ISBN, &userisbn);
  return isbnsearch;
}
vector<Book*> Cashier::findAuthor(string author) {
  /*
  Create temp string for author
  Create temporary book list
  Call inventory find book function with temp string and assign to temp book list
  return temporary book list
  */
  string userauth = author;
  vector<Book*> authsearch = inv->findBook(Book::AUTHOR, &userauth);
  return authsearch;
}
vector<Book*> Cashier::findTitle(string title) {
  /*
  Create temp string for title
  Create temporary book list
  Call inventory find book function with temp string and assign to temp book list
  return temporary book list
  */
  string usertitle = title;
  vector<Book*> titlesearch = inv->findBook(Book::TITLE, &usertitle);
  return titlesearch;
}

bool Cashier::addCart(Book* book) {
  /*
  Add book to cart list
  */

  // Check if book is in cart
  for(unsigned i = 0; i < m_cartlist.size(); i++) {
    // Compare file index instead of pointer because they will be different!
    if(m_cartlist[i]->getFileIndex() == book->getFileIndex()) {
      // If book exists in cart
      // Change increment quantity instead
      int quantity = m_cartlist[i]->getQuantity();
      m_cartlist[i]->setQuantity(quantity + 1);
      // return function
      return true;
    }
  }

  // Book does not exist in cart
  // Create new copy of book and set quantity to 1
  Book* cart_book = new Book;
  *cart_book = *book; // Copy
  cart_book->setQuantity(1);
  m_cartlist.push_back(cart_book);
  return true;
}

bool Cashier::delCart(Book* book) {
  /*
  If book is in cart list
  decrement from cart list... if it goes to zero

  */
  for (unsigned i = 0; i < m_cartlist.size(); i++)
  {
    if(m_cartlist[i]->getFileIndex() == book->getFileIndex()) {
      int quantity = m_cartlist[i]->getQuantity();
      if(quantity > 1) {
        m_cartlist[i]->setQuantity(quantity - 1);
        return true;
      } else {
        // Delete element
        delete m_cartlist[i];
        // Erases element from m_cartlist
        m_cartlist.erase((m_cartlist.begin() + i));
        return true;
      }
    }
  }
  // No book found
  return false;
}

bool Cashier::clearCart() {
  for(unsigned i = 0; i < m_cartlist.size(); i++) {
    // delete all elements
    delete m_cartlist[i];
  }

  // Clear vector
  m_cartlist.clear();

  return true;
}

vector<Book*> Cashier::getCart() {
  return m_cartlist;
}

bool Cashier::purchaseCart() {
  /*
  For each item in cart list
  delete book from inventory
  Clear cart list
  */

  for (unsigned i = 0; i < m_cartlist.size(); i++)
  {
    // If quantity of this book is greater than one
    // delete book for # quantity

    if (m_cartlist[i]->getQuantity() > 1) {
      for (int j = 0; j < m_cartlist[i]->getQuantity() - 1; j++) {
        inv->delBook(m_cartlist[i]);
      }
    }

    inv->delBook(m_cartlist[i]);
  }
  m_cartlist.clear();
  return true;
}

double Cashier::getSalesTax(){
  /*
  Returns sales tax
  */
  double retval = getSubTotal() * SALES_TAX;
  return retval;
}

double Cashier::getSubTotal(){
  /*
     Get subtotal of all items in cart
  */

  double subtotal = 0;
  for (unsigned i = 0; i < m_cartlist.size(); i++) {
    // If book matches item in list, this item's subtotal is added
    subtotal += m_cartlist[i]->getRetailPrice() * m_cartlist[i]->getQuantity();
  }
  return subtotal;
}
