#pragma once
#include <vector>
#include "inventory.h"
#include "book.h"
using namespace std;

class Cashier
{
  vector<Book*> m_cartlist;
  Inventory* inv;
  double addAll();

public:
  Cashier(Inventory* inv);
  vector<Book*> findISBN(string);
  vector<Book*> findAuthor(string);
  vector<Book*> findTitle(string);
  bool addCart(Book* book);
  bool delCart(Book* book);
  vector<Book*> getCart();
  bool clearCart();
  bool purchaseCart();
  double getSalesTax();
  double getSubTotal();
};
