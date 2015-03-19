#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

#include "tools/build-db.h"
#include "menu.h"
#include "Cashier.h"
#include "inventory.h"
#include "input.h"
#include "pager.h"

#define PAGER_SIZE 10

#ifdef __GNUC__
  #define PCLEAR "clear"
#else
  #define PCLEAR "cls"
#endif

// Program states
#define STATE_SPLASH    0
#define STATE_MAIN      1
#define STATE_CASHIER   2
#define STATE_INVENTORY 3
#define STATE_REPORT    4
#define STATE_SEARCH    5
#define STATE_DISPLAY   6
#define STATE_ADD       7
#define STATE_QUIT      8
#define STATE_DANCE     9

#define STATE_SUB_NONE        0
#define STATE_SUB_DELETE      1
#define STATE_SUB_CART_DELETE 2
#define STATE_SUB_EDIT        3
#define STATE_SUB_CART_ADD    4
#define STATE_SUB_CHECKOUT    5

int main() {
  // Modules
  Inventory inv;          // Inventory module
  inv.reset();            // Initialize inventory, default location is
                          // "tools/books.db"
  Input input;            // Input module
  Pager pager;          // Pager to assist displaying items
  Cashier cash(&inv);     // Handles transactions and cart
  Report report(&inv);    // Handles displaying data

  pager.setPageSize(PAGER_SIZE);  // Number of items to display per page

  // Menu modules
  Menu::Initialize(&inv, &cash, &report);
  Menu         menu_main;
  MenuCashier  menu_cash;
  MenuInventory menu_inv;
  MenuReport menu_report;
  MenuSearch menu_search;
  MenuBookList menu_list;
  MenuEdit     menu_edit;


  // Main globals
  int state = 0;    // 0 - splash page
                    // 1 - main menu
                    // 2 - cashier
                    // 3 - inventory
                    // 4 - report
                    // 5 - book search
                    // 6 - display booklist
                    // 7 - add book
                    // 8 - quit
                    // 9 - dance
                    // 10 - substate
  int prev_state = 0;

  int substate = 0; // 0 - none
                    // 1 - delete book
                    // 2 - delete from cart
                    // 3 - edit book
                    // 4 - add to cart
                    // 5 - checkout

  bool quit = false;

  //main.Menu1(userchoice);

  while(!quit) {
    // Prompt program splash
    switch(state) {
      case 0: // case state splash screen
        cout << "Serendipity Booksellers POS" << endl;
        cout << "Press enter to continue..." << endl;
        menu_main.displayFooter();

        input.getCh();  // wait for any key
        state = STATE_MAIN; // switch state to main menu
        break;

      case 1: // case state main menu
        menu_main.displayHeader(); // display main menu header
        menu_main.displayBody();   // display main menu body
        menu_main.displayFooter(); // display main menu footer

        prev_state = 1; // set last state to main menu
        switch(input.getCh()) { // switch input
          case 1: // case 1: cashier
            state = 2; // switch state to cashier
            break;

          case 2: // case 2: inventory
            state = 3; // switch state to inventory
            break;

          case 3: // case 3: report
            state = 4; // switch state to report
            break;

          case 4: // case 4: quit
            state = 8; // switch state to quit
        }
        break;

      case 2: // case state cashier module
        menu_cash.displayHeader(); // display cashier menu
        menu_cash.displayBody();
        menu_cash.displayFooter();

        prev_state = 2; // set last state to cashier
        switch(input.getCh()) { // switch input
          case 1: // case 1: add book
            state      = 5; // switch state to search
            substate   = 4; // switch substate to add cart
            break;
          case 2: // case 2: remove book
            Menu::m_activeList = cash.getCart(); // Change active list to cart
            pager.setLength(Menu::m_activeList.size());
            state      = 6; // switch state to substate (only removing from cart)
            substate   = 2; // switch substate to delete book(cart)
            break;
          case 3: // case 3: finalize transaction
            state      = 10; // switch state to display book list
            substate   = 5; // switch substate to checkout
            break;
          case 4: // case 4: return to main menu
            state      = 1; // switch state to main menu
            break;
          // TODO: default behavior
        }
        break;

      case 3: // case state inventory module
        menu_inv.displayHeader(); // display inventory header
        menu_inv.displayBody();   // display inventory body
        menu_inv.displayFooter(); // display inventory footer

        prev_state = 3; // set last state to inventory
        switch(input.getCh()) { // switch input
          case 1: // case 1: look up book
            state      = 5; // switch state to search
            break;
          case 2: // case 2: add a book
            state      = 7; // switch state to add book
            break;
          case 3: // case 3: edit a book's record
            state      = 5; // switch state to search
            substate   = 3; // switch substate to edit book
            break;
          case 4: // case 4: delete a book
            state      = 5; // switch state to search
            substate   = 1; // switch substate to delete book
            break;
          case 5: // case 5: sync changes
            //inv.sync();
            break;
          case 6: // case 5: return to previous menu
            state      = 1; // switch state to main menu
            break;
        }
        break;

      case 4: // case state report module
          menu_report.displayHeader(); // display report body
          menu_report.displayBody();   // display report body
          menu_report.displayFooter(); // display report body

          prev_state = 4; // set previous state to report
          switch(input.getCh()) { //switch input
            case 1: // case 1: list all books
              Menu::m_activeList = report.getAll();
              pager.setLength(Menu::m_activeList.size());
              state = 6; // switch state to display book list
              break;
            case 2: // case 2: list by wholesale price
              Menu::m_doubleList = report.getWholeList();
              pager.setLength(Menu::m_activeList.size());
              state = 6; // switch state to display book list(wholesale & total)
              break;
            case 3: // case 3: list by retail price
              Menu::m_doubleList = report.getWholeList();
              pager.setLength(Menu::m_activeList.size());
              state = 6; // switch state to display book list(retail & total)
              break;
            case 4: // case 4: list by quantity, desc
              Menu::m_activeList = report.getSortQuantity(false);
              pager.setLength(Menu::m_activeList.size());
              state = 6; // switch state to display book list
              break;
            case 5: // case 5: list by cost, desc
              Menu::m_activeList = report.getSortWhole(false);
              pager.setLength(Menu::m_activeList.size());
              state = 6; // switch state to display book list
              break;
            case 6:  // case 6: list by age, desc
              Menu::m_activeList = report.getSortAge(false);
              pager.setLength(Menu::m_activeList.size());
              state = 6; // switch state to display book list
              break;
            case 7:  // case 8: DANCE PARTY
              state = 9;
              break;
            case 8:   // case 7: return to previous menu
              state = 1; // switch state to main menu
              break;
          }
          break;

      case 5: { // case state book search
          menu_search.displayHeader();    // display search body
          menu_search.displayBody();    // display search body
          menu_search.displayFooter();    // display search body
          char temp_input = input.getCh();
          cout << "Enter search term: ";

          string temp;
          switch(temp_input) { // prompt user select field to change
            case 1: // case 1: isbn
              temp = input.getLine();
              Menu::m_activeList = inv.findBook(Book::ISBN, &temp);
              break;
            case 2: // case 2: author
              temp = input.getLine();
              Menu::m_activeList = inv.findBook(Book::AUTHOR, &temp);
              break;
            case 3:// case 3: title
              temp = input.getLine();
              Menu::m_activeList = inv.findBook(Book::TITLE, &temp);
              break;
            case 4: // case 4: publisher
              temp = input.getLine();
              Menu::m_activeList = inv.findBook(Book::PUBLISHER, &temp);
              break;
            case 5: // case 5: date added
              temp = input.getLine();
              Menu::m_activeList = inv.findBook(Book::DATEADDED, &temp);
              break;
            case 6: { // case 6: wholesale price
              temp = input.getLine();
              double dtemp = atof(temp.c_str());
              Menu::m_activeList = inv.findBook(Book::WHOLECOST, &dtemp);
              break;
              }
            case 7: { // case 7: retail price
              temp = input.getLine();
              double dtemp = atof(temp.c_str());
              Menu::m_activeList = inv.findBook(Book::RETAILPRICE, &dtemp);
              break;
              }
            case 8: { // case 8: quantity
              temp = input.getLine();
              int itemp = atoi(temp.c_str());
              Menu::m_activeList = inv.findBook(Book::QUANTITY, &itemp);
              break;
              }
            default:
              // TODO: If search fails, return all? or none
              //Menu::m_activeList = inv.getRange(0, inv.getSize());
              Menu::m_activeList.clear();
          }

          pager.setLength(Menu::m_activeList.size());
          state = 6;// set state to display book list

          break;
      }

      case 6: { // case display book list
        // display book list
        // Derive page from current temp list
        int first = pager.getPageFirst();
        int  last = pager.getPageLast() + 1;

        // Check array bounds to avoid subvector exception
        try { Menu::m_activeList.at(first); }
        catch(...) { first = 0; }
        try { Menu::m_activeList.at(last); }
        catch(...) { last = Menu::m_activeList.size(); }

        vector<Book*> current_page(
          Menu::m_activeList.begin() + first,
          Menu::m_activeList.begin() + last
        );

        menu_list.displayHeader();
        menu_list.displayBody(current_page);
        menu_list.displayFooter((substate != 0), pager); // If substate
        char temp_input = input.getCh();

        switch(temp_input) {// switch user input
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
          case 9: // case 1-10: user select given book
            // If substate is set, then we need to do more work
            if(substate != 0) {
              Menu::m_activeBook = current_page[(unsigned) temp_input];
              state = 10; // switch to substates
            }
            break;
          case 'n':// case N
          case 'N':// case N
            pager.movePage(Pager::DOWN);
            break;// go to next page
          case 'p':// case P
          case 'P':// case P
            pager.movePage(Pager::UP);
            break;// go to previous page
          case 'q':// case Q
          case 'Q':// case Q
            // Clear buffers
            Menu::m_activeList.clear();
            Menu::m_doubleList.clear();
            Menu::m_activeBook = NULL;
            state = prev_state;// go to previous state
        }

        break;
      }


      case 7: { // case state add book
         // create new menu temp book and prompt user for:
        menu_inv.displayHeader();
        menu_inv.displayBody();
        menu_inv.displayFooter();

        string temp;
        Menu::m_activeBook = new Book;
        cout << "ISBN: "; getline(cin, temp);
        Menu::m_activeBook->setISBN(temp);// prompt user for isbn
        cout << "Title: "; getline(cin, temp);
        Menu::m_activeBook->setTitle(temp);// prompt user for title
        cout << "Author: "; getline(cin, temp);
        Menu::m_activeBook->setAuthor(temp);// prompt user for author
        cout << "Publisher: "; getline(cin, temp);
        Menu::m_activeBook->setPublisher(temp);// prompt user for publisher
        //cout << "Month Added: "; getline(cin, temp);
        //Menu::m_activeBook->setMonth(stoi(temp));// prompt user for month added
        //cout << "Day Added: "; getline(cin, temp);
        //Menu::m_activeBook->setDay(stoi(temp));// prompt user for day added
        //cout << "Year Added: "; getline(cin, temp);
        //Menu::m_activeBook->setYear(stoi(temp));// prompt user for year added
        cout << "Wholesale Cost: "; getline(cin, temp);
        Menu::m_activeBook->setWholeCost(atof(temp.c_str()));// prompt user for wholesale price
        cout << "Retail Price: "; getline(cin, temp);
        Menu::m_activeBook->setRetailPrice(atoi(temp.c_str()));// prompt user for retail price

        inv.addBook(Menu::m_activeBook);

        // Clear buffers
        Menu::m_activeList.clear();
        Menu::m_doubleList.clear();
        Menu::m_activeBook = NULL;
        state=prev_state;// return to last state
        break;
      }

      case 8: // case quit
        quit = true; // set quit to true
        break;

      case 9: // case dance party
        system(PCLEAR);
        menu_main.displayHeader();
        cout << "ARE YOU READY? Y/N?" << endl;
        menu_main.displayFooter();

        switch(input.getCh()) {
          case 'y':
          case 'Y':
            ShellExecute(NULL, "open", "http://corgiorgy.com", NULL, NULL, SW_SHOWNORMAL);
          case 'n':
          case 'N':
            // Clear buffers
            Menu::m_activeList.clear();
            Menu::m_doubleList.clear();
            Menu::m_activeBook = NULL;
            state = prev_state;
        }

        break;

      case 10: { // substates
        if (substate == 1) {  // substate delete book
          inv.delBook(Menu::m_activeBook);

          // Clear buffers
          Menu::m_activeList.clear();
          Menu::m_doubleList.clear();
          Menu::m_activeBook = NULL;
          state = prev_state;
        }

        if (substate == 2) {  // substate remove from cart
          cash.delCart(Menu::m_activeBook);

          // Clear buffers
          Menu::m_activeList.clear();
          Menu::m_doubleList.clear();
          Menu::m_activeBook = NULL;
          state = prev_state;
        }

        if (substate == 3) { // substate edit book
          menu_edit.displayHeader();
          menu_edit.displayBody();
          menu_edit.displayFooter();

          char temp_input = input.getCh();

          string temp;
          cout << "Change to: ";
          switch(temp_input) { // prompt user select field to change
            case 0: // case 1: isbn
              temp = input.getLine(); // TODO: validate input
              Menu::m_activeBook->setISBN(temp);
              break;
            case 1:// case 1: title
              temp = input.getLine(); // TODO: validate input
              Menu::m_activeBook->setTitle(temp);
              break;
            case 2: // case 2: author
              temp = input.getLine();
              Menu::m_activeBook->setAuthor(temp);
              break;
            case 3: // case 3: publisher
              temp = input.getLine();
              Menu::m_activeBook->setPublisher(temp);
              break;
            case 4: { // case 5: date added
              date dtemp;

              cout << "Month: ";
              temp = input.getLine();
              dtemp.setMonth(atoi(temp.c_str()));

              cout << "Day: ";
              temp = input.getLine();
              dtemp.setDay(atoi(temp.c_str()));

              cout << "Year: ";
              temp = input.getLine();
              dtemp.setYear(atoi(temp.c_str()));
              Menu::m_activeBook->setDateAdded(dtemp);
              break;
              }
            case 5: // case 8: quantity
              temp = input.getLine();
              Menu::m_activeBook->setQuantity(atoi(temp.c_str()));
              break;
            case 6: // case 6: wholesale price
              temp = input.getLine();
              Menu::m_activeBook->setWholeCost(atof(temp.c_str()));
              break;
            case 7: // case 7: retail price
              temp = input.getLine();
              Menu::m_activeBook->setRetailPrice(atof(temp.c_str()));
              break;
            case 's':
            case 'S':
              inv.updBook(Menu::m_activeBook);
              // No break statement here, spills over to quit
            case 'q': // TODO
            case 'Q': // TODO
              // Clear buffers
              Menu::m_activeList.clear();
              Menu::m_doubleList.clear();
              Menu::m_activeBook = NULL;
              state = prev_state;
              break;
          }
        }

        if (substate == 4)  { // substate add to cart
            cash.addCart(Menu::m_activeBook); // add to cart

            // Clear buffers
            Menu::m_activeList.clear();
            Menu::m_doubleList.clear();
            Menu::m_activeBook = NULL;
            state = prev_state;
        }

        if (substate == 5) { // checkout
          //menu_cash.displaycheckout(); 
      menu_cash.displayHeader(); // display cashier menu
      menu_cash.displayCart();
      menu_cash.displayFooter();
      system("pause");
      cash.purchaseCart();
      substate = 0;
      state = 2;
        }
      break;
     }
    }
  }

  //system("pause");

}
