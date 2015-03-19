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

#ifdef __GNUC__
  #define PCLEAR "clear"
#else
  #define PCLEAR "cls"
#endif


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
  system(PCLEAR);
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
  cout << " :: ";
}








// Cashier Menu Functions
void MenuCashier::displayHeader() {
  system(PCLEAR);
  cout << "Serendipity Booksellers :: Cashier" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuCashier::displayBody() {
  vector<Book*> cart = m_cash->getCart();
  
  // If there is an item in the cart, display the cart
  if(cart.size() > 0) {
    // Display table header
    cout  <<  setw(4) << right << " Qty"
          << setw(7) << right << "Price"
          << setw(2) << ""
          << setw(100) << left << "Title" << endl;

    // Display table
    for (unsigned i = 0; i < cart.size(); i++) {
      cout <<  setw(4) << right << cart[i]->getQuantity()    // Qty
           << setw(7) << right << cart[i]->getRetailPrice() // Price
           << setw(2) << ""
           << setw(50) << left << cart[i]->getTitle();       // Title
      cout << endl;
    }

    cout << setprecision(2) << fixed;
    cout << setfill('=') << setw(30) << "" << "\n\n";
    cout << setfill(' ');
    cout << setw(20) << right << "Subtotal: " << m_cash->getSubTotal() << endl;
    cout << setw(20) << right << "Sales Tax:" << m_cash->getSalesTax() << endl;
    cout << setw(20) << right << "Total:"
         << m_cash->getSubTotal() + m_cash->getSalesTax() << endl;
  }

  // Instructions
  cout << "\n" << "1: Add a book" << endl;
  cout << "2: Remove a book" << endl;
  cout << "3: Finalize Transaction" << endl;
  cout << "4: Return to Main Menu" << endl;
}







//Inventory Menu Functions
void MenuInventory::displayHeader() {
  system(PCLEAR);
  cout << "Serendipity Booksellers :: Inventory Menu" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuInventory::displayBody() {
  cout << "1. Look up a book" << endl;
  cout << "2. Add a book" << endl;
  cout << "3. Edit a book's record" << endl;
  cout << "4. Delete a book" << endl;
  cout << "5. Write changes to inventory" << endl;
  cout << "6. Return to Main Menu" << endl;
}
void MenuInventory::displaySearchPrompt(){
  cout << "Please enter your search term here: "<< endl;
}








//Report Menu Functions
void MenuReport::displayHeader(){
  system(PCLEAR);
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


// Search Menu
void MenuSearch::displayHeader(){
  system(PCLEAR);
  cout << "Serendipity Booksellers :: Search" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuSearch::displayBody() {
  cout << "Select a field to search for:" << endl;
  cout << "1. ISBN"             << endl;
  cout << "2. Author"           << endl;
  cout << "3. Title"            << endl;
  cout << "4. Publisher"        << endl;
  cout << "5. Date Added"       << endl;
  cout << "6. Wholesale Cost"   << endl;
  cout << "7. Retail Price"     << endl;
  cout << "8. Quantity on Hand" << endl;
}





//Book List Menu Functions
void MenuBookList::displayHeader(){
  system(PCLEAR);
  cout << "Serendipity Booksellers :: " << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuBookList::displayBody(vector<Book*>& current_page) {
  if(current_page.size() <= 0) {
    cout << "\n\n\n" << setw(17) << right << "[No books to display]" << "\n\n\n";
  }

  // Display current book list
  for(unsigned i = 0; i < current_page.size(); i++) {
    cout << setprecision(2) << fixed;

    cout << setw(3) << right << "[" << i << "]";
    cout << setw(5) << right << "Title: "
         << setw(50) << left << current_page[i]->getTitle();
    cout << endl;

    cout << setw(10) << right << "ISBN: "
         << setw(15) << left << current_page[i]->getISBN();
    cout << endl;

    cout << setw(10) << right << "Author: "
         << setw(15) << left << current_page[i]->getAuthor();
    cout << setw(15) << right << "Publisher: "
         << setw(25) << left << current_page[i]->getPublisher();
    cout << endl;

    cout << setw(10) << right << "Age: "
         << setw(15) << left << current_page[i]->getDateAdded().str();
    cout << setw(15) << right << "Quantity: "
         << setw(5) << left << current_page[i]->getQuantity();
    cout << endl;

    cout << setw(20) << right << "Wholesale Value: " << current_page[i]->getWholeCost()   << endl;
    cout << setw(20) << right << "Retail Price: "    << current_page[i]->getRetailPrice() << endl;
    cout << endl;
  }
}

void MenuBookList::displayFooter(bool sub, Pager& page ) { // If substate, show options to select book
  cout << "\n" << setfill('=') << setw(W_SPACER) << "" << endl;
  cout << setfill(' ');
  if(sub) {
    cout << "'0-9': Select book" << endl;
  }

  cout << "Page : " << page.getPageCurrent() << "/" << page.getPageTotal()-1 << endl;
  cout << "'N': Next page" << endl;
  cout << "'P': Prev page" << endl;
  cout << "'Q': Quit page" << endl;
  cout << " :: ";
}


void MenuEdit::displayHeader(){
  system(PCLEAR);
  cout << "Serendipity Booksellers :: Edit book" << endl;
  cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
  cout << setfill(' ');
}

void MenuEdit::displayBody() {
  // Display current book with field numbers

  cout << setw(20) << right << "[0] ISBN: "
       << setw(50) << left << Menu::m_tempBook->getISBN() << endl;
  cout << setw(20) << right << "[1] Title: "
       << setw(50) << left << Menu::m_tempBook->getTitle() << endl;
  cout << setw(20) << right << "[2] Author: "
       << setw(50) << left << Menu::m_tempBook->getAuthor() << endl;
  cout << setw(20) << right << "[3] Publisher: "
       << setw(50) << left << Menu::m_tempBook->getPublisher() << endl;
  cout << setw(20) << right << "[4] Age: "
       << setw(50) << left << Menu::m_tempBook->getDateAdded().str() << endl;
  cout << setw(20) << right << "[5] Quantity: "
       << setw(50) << left << Menu::m_tempBook->getQuantity() << endl;
  cout << setw(20) << right << "[6] Wholesale Cost: "
       << setw(50) << left << Menu::m_tempBook->getWholeCost() << endl;
  cout << setw(20) << right << "[7] Retail Price: "
       << setw(50) << left << Menu::m_tempBook->getRetailPrice() << endl;

  //cout << " Title: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " ISBN: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " Author: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " Publisher: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " Age: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " Quantity: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " Wholesale Cost: " << setw(50) << Menu::m_tempBook->getTitle();
  //cout << " Retail Price: " << setw(50) << Menu::m_tempBook->getTitle();
}

void MenuEdit::displayFooter() { // If substate, show options to select book
  cout << "\n" << setfill('=') << setw(W_SPACER) << "" << endl;
  cout << setfill(' ');

  cout << "[0-7]: Edit field" << endl;
  cout << "'S': save and quit" << endl;
  cout << "'Q': discard changes" << endl;
  cout << " :: ";
}
