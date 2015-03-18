#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "menu.h"
#include "book.h"
#include "date.h"
#include "report.h"
#include "inventory.h"
#include "Cashier.h"

#define W_SPACER 30


// Static globals
Inventory* Menu::m_inv = NULL;
Cashier* Menu::m_cash  = NULL;
Report* Menu::m_report = NULL;

// Static buffers
vector<Book*> Menu::m_tempList;
vector<double> Menu::m_doubleList;
Book*     Menu::m_tempBook;

Menu::~Menu() { /* No garbage collection necessary */ }

void Menu::Initialize(Inventory* inv, Cashier* cash, Report* report) {
  m_inv = inv;
  m_cash = cash;
  m_report = report;
}

void Menu::displayHeader() {
  system("cls");
  cout << "Serendipity Booksellers :: Main Menu" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void Menu::displayBody() {
  cout << "1. Cashier Module"   << endl;
  cout << "2. Inventory Module" << endl;
  cout << "3. Report Module"    << endl;
  cout << "4. Quit the program" << endl;
}

void Menu::displayFooter() {
  cout << "\n" << setfill('=') << setw(W_SPACER) << "" << endl;
  cout << setfill(' ');
  cout << "De Anza CIS22B Winter 2015" << endl;
  cout << "Alfred Ly | James Chantler | Dylan Lotivio" << endl;
}








// Cashier Menu Functions
void MenuCashier::displayHeader() {
  system("cls");
  cout << "Serendipity Booksellers :: Cashier" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuCashier::displayBody() {
  // Display table header
  cout  <<  setw(9) << right << "Qty"
        << setw(15) << right << "ISBN"
        << setw(25) << right << "Title"
        << setw(15) << right << "Price"
        << "Total" << endl;
  //cout << "________________________________________________________________";

  // Display table
  for (unsigned i = 0; i < Menu::m_tempList.size(); i++) {
    cout <<  setw(9) << right << Menu::m_tempList[i]->getQuantity()    // Qty
         << setw(15) << right << Menu::m_tempList[i]->getISBN()        // ISBN
         << setw(25) << right << Menu::m_tempList[i]->getTitle()       // Title
         << setw(15) << right << Menu::m_tempList[i]->getRetailPrice() // Price
         << setw(15) << right << Menu::m_tempList[i]->getQuantity()    // Total
                                 * Menu::m_tempList[i]->getRetailPrice();
    cout << setprecision(2) << fixed;
  }

    cout << "Subtotal:"   << setw(30) << right << m_cash->getSubTotal() << endl;
    cout << "Sales Tax:"  << setw(30) << right << m_cash->getSalesTax() << endl;
    cout << "Total:"      << setw(30) << right <<
      m_cash->getSubTotal() + m_cash->getSalesTax() << endl;

    // Instructions
    cout << "\n" << "1: Add a book" << endl;
    cout << "2: Remove a book" << endl;
    cout << "3: Finalize Transaction" << endl;
    cout << "4: Return to Main Menu" << endl;
}







//Inventory Menu Functions
void MenuInventory::displayHeader() {
  system("cls");
  cout << "Serendipity Booksellers :: Inventory Menu" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuInventory::displayBody() {
  cout << "1. Look up a book" << endl;
  cout << "2. Add a book" << endl;
  cout << "3. Edit a book's record" << endl;
  cout << "4. Delete a book" << endl;
  cout << "5. Return to Main Menu" << endl;
}






//Report Menu Functions
void MenuReport::displayHeader(){
  system("cls");
  cout << "Serendipity Booksellers :: Report Menu" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuReport::displayBody() {
  cout << "1. Inventory Listing" << endl;
  cout << "2. Inventory Wholesale Value" << endl;
  cout << "3. Inventory Retail Value" << endl;
  cout << "4. Listing by Quantity" << endl;
  cout << "5. Listing by Cost" << endl;
  cout << "6. Listing by Age" << endl;
  cout << "7. Return to Main Menu" << endl;
}






//Book List Menu Functions
void MenuBookList::displayHeader(){
  system("cls");
  cout << "Serendipity Booksellers :: Book Info Menu" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuBookList::displayBody() {
  if(m_tempList.size() <= 0) {
    cout << "\n\n\n" << setw(17) << right << "[No books to display]" << "\n\n\n";
  }
  // Display current book list
  for(unsigned i = 0; i < m_tempList.size(); i++) {
    cout << setprecision(2) << fixed;
    cout << setw(17) << right << "ISBN"            << m_tempList[i]->getISBN()        << endl;
    cout << setw(17) << right << "Title"           << m_tempList[i]->getTitle()       << endl;
    cout << setw(17) << right << "Author"          << m_tempList[i]->getAuthor()      << endl;
    cout << setw(17) << right << "Publisher"       << m_tempList[i]->getPublisher()   << endl;
    cout << setw(17) << right << "Age"             << m_tempList[i]->getDateAdded().str() << endl;
    cout << setw(17) << right << "Quantity"        << m_tempList[i]->getQuantity()    << endl;
    cout << setw(17) << right << "Wholesale Value" << m_tempList[i]->getWholeCost()   << endl;
    cout << setw(17) << right << "Retail Price"    << m_tempList[i]->getRetailPrice() << endl;
  }
}

/*
//void MainMenu::Menu1(int)
//{
//  userchoice = 0;
//  cout << "Welcome to Serendipity Booksellers!"<<endl<<endl;
//
//  cout << "1. Cashier Module" << endl;
//  cout << "2. Inventory Module" << endl;
//  cout << "3. Report Module" << endl;
//  cout << "4. Quit the program" << endl;
//  cout << "Please enter your choice found above:" << endl;
//  cin >> userchoice;
//  cout << endl;
//}
//
//void MainMenu::CashMenu1(int)
//{
//  Cashchoice = 0;
//  system("cls");
//  cout << "Welcome to the Serendipity Booksellers Cash Register!" <<endl<<endl;
//
//  cout << "1. Search for a book via ISBN" << endl;
//  cout << "2. Search for a book via Author" << endl;
//  cout << "3. Search for a book via Title" << endl;
//  cout << "4. Remove a book from this transaction" << endl;
//  cout << "5. Finalize your transaction" << endl;
//  cout << "6. Return to the Main Menu" << endl;
//  cout << "Please enter your choice found above:" << endl;
//  cin >> Cashchoice;
//}
//
//void MainMenu::InvMenu1(int)
//{
//  Invchoice = 0;
//  system("cls");
//  cout << "Welcome to the Serendipity Booksellers Inventory System!" << endl << endl;
//  cout << "1. Look up a book"<<endl;
//  cout << "2. Add a book"<<endl;
//  cout << "3. Edit a book's record"<<endl;
//  cout << "4. Delete a book" << endl;
//  cout << "5. Return to the Main Menu" << endl;
//  cout << "Please enter your choice found above:" << endl;
//  cin >> Invchoice;
//}
//
//void MainMenu::ReportMenu1(int)
//{
//  Repchoice = 0;
//  system("cls");
//  cout << "Welcome to the Serendipity Booksellers Report Module!" << endl << endl;
//  cout << "1. Inventory Listing" << endl;
//  cout << "2. Inventory Wholesale Listing" << endl;
//  cout << "3. Inventory Retail Listing" << endl;
//  cout << "4. List by quantity" << 
//}
//
//void MainMenu::CashMenuISBN()
//{
//  cout << "Please enter the ISBN: " << endl;
//  cin.clear();
//  fflush(stdin);
//  std::getline(std::cin, userisbn);
//
//  //function call to search for isbn
//  cout << "   ISBN            Title               Author            Price " << endl;
//  vector<Book*> isbnlist = m_cash.findISBN(userisbn);
//  for (unsigned i = 0; i < isbnlist.size(); i++)  {
//    cout << "";
//    cout <<i+1<<". "<< isbnlist[i]->getISBN() << "    "
//      << isbnlist[i]->getTitle() << "     ";
//    cout << isbnlist[i]->getAuthor() << "     $"
//      << isbnlist[i]->getRetailPrice() << endl;
//
//  }
//  cout << "Please type the number of the selection you'd like to add to your cart:" << endl;
//  cin >> cartchoice;
//  cartchoice = cartchoice - 1;
//  if (cartchoice>isbnlist.size())
//  {
//    cout << "There is no such selection. Please try again:" << endl;
//    cin >> cartchoice;
//  }
//  m_cash.addCart(isbnlist[cartchoice]);
//
//  /*vector<Book*> cart = m_cash.findISBN(userisbn);
//  Book* book = cart[0];
//  for (unsigned i = 0; i < cart.size(); i++) {
//    if (cartchoice == i)
//    {
//
//  m_cash.addCart(book);
//
//    }
//  }
//  cout << cartchoice << endl;
//  for (unsigned i = 0; i < cart.size(); i++)  {
//    cout << "";
//    cout << i + 1 << ". " << cart[i]->getISBN() << "    "
//      << cart[i]->getTitle() << "     ";
//    cout << cart[i]->getAuthor() << "     $"
//      << cart[i]->getRetailPrice() << endl;
//
//  }*/
//  cout << "Your selection has been added to your cart" << endl;
//  //cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
//  //Please type the number of the selection you'd like to make.
//  system("pause");
//  MainMenu::CashMenu1(userchoice);
//
//}
//
//void MainMenu::CashMenuAuth(string)
//{
//  cout << "Please enter the author's name, last name first: " << endl;
//  cin.clear();
//  fflush(stdin);
//  std::getline(std::cin, userauth);
//
//  //function call to search for author
//  cout << "ISBN         Title        Author      Price " << endl;
//  vector<Book*> authlist = m_cash.findAuthor(userauth);
//  for (unsigned i = 0; i < authlist.size(); i++)  {
//    cout << "";
//    cout << i + 1 << ". " << authlist[i]->getISBN() << "    "
//      << authlist[i]->getTitle() << "     ";
//    cout << authlist[i]->getAuthor() << "     $"
//      << authlist[i]->getRetailPrice() << endl;
//    cout << i << endl;
//    cout << userisbn << endl;
//
//  }
//  cout << "Please type the number of the selection you'd like to add to your cart:" << endl;
//  cin >> cartchoice;
//  cartchoice = cartchoice - 1;
//
//
//  vector<Book*> cart = m_cash.findAuthor(userauth);
//  Book* book = cart[0];
//  for (unsigned i = 0; i < cart.size(); i++) {
//    if (cartchoice == i)
//    {
//
//      m_cash.addCart(book);
//
//    }
//  }
//  cout << cartchoice << endl;
//  /*for (unsigned i = 0; i < cart.size(); i++)  {
//  cout << "";
//  cout << i + 1 << ". " << cart[i]->getISBN() << "    "
//  << cart[i]->getTitle() << "     ";
//  cout << cart[i]->getAuthor() << "     $"
//  << cart[i]->getRetailPrice() << endl;
//
//  }*/
//  cout << "Your selection has been added to your cart" << endl;
//  //cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
//  //Please type the number of the selection you'd like to make.
//  system("pause");
//
//
//}
//
//void MainMenu::CashMenuTitle(string)
//{
//  cout << "Please enter the title: " << endl;
//  cin.clear();
//  fflush(stdin);
//  std::getline(std::cin, usertitle);
//
//  //function call to search for author
//  cout << "ISBN         Title        Author      Price " << endl;
//  vector<Book*> titlelist = m_cash.findAuthor(usertitle);
//  for (unsigned i = 0; i < titlelist.size(); i++)  {
//    cout << "";
//    cout << i + 1 << ". " << titlelist[i]->getISBN() << "    "
//      << titlelist[i]->getTitle() << "     ";
//    cout << titlelist[i]->getAuthor() << "     $"
//      << titlelist[i]->getRetailPrice() << endl;
//
//
//  }
//  cout << "Please type the number of the selection you'd like to add to your cart:" << endl;
//  cin >> cartchoice;
//  cartchoice = cartchoice - 1;
//
//
//  vector<Book*> cart = m_cash.findTitle(usertitle);
//  Book* book = cart[0];
//  for (unsigned i = 0; i < cart.size(); i++) {
//    if (cartchoice == i)
//    {
//
//      m_cash.addCart(book);
//
//    }
//  }
//  cout << cartchoice << endl;
//  /*for (unsigned i = 0; i < cart.size(); i++)  {
//  cout << "";
//  cout << i + 1 << ". " << cart[i]->getISBN() << "    "
//  << cart[i]->getTitle() << "     ";
//  cout << cart[i]->getAuthor() << "     $"
//  << cart[i]->getRetailPrice() << endl;
//
//  }*/
//  cout << "Your selection has been added to your cart" << endl;
//  //cout << 1. \n 2. \n  3. \n 4. \n 5. vector search results=true
//  //Please type the number of the selection you'd like to make.
//
//
//}
//
//void MainMenu::CartRemove(string)
//{
//  cout << "Please enter the title of the book you'd like to remove from your cart:" << endl;
//  cin >> usertitle;
//  /*for (unsigned i = 0; i < cart.size(); i++) {
//    if (usertitle == cart.getTitle())
//    {
//
//      m_cash.delCart(book);
//
//    }
//  }
//  */
//}
//
//void MainMenu::BuyBooks(double)
//{}
