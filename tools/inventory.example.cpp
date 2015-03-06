#include <iostream>
#include "inventory.h"
#include "book.h"
using namespace std;

int main() {
  // Setting it up (there should only be one of these global objects
  // It might still work, but there is a possibility of having multiple
  // file handlers to the same file if more than one of these is
  // insantiated
  // I can probably add in more exception handling for that later
  Inventory inv;

  // Create a new database object, which the inventory object will use
  // It uses a file called "inv.db"
  inv.setDatabase(new DB::Local("inv.db"));

  // This discards all data in the inventory object and then pulls
  // in all the data from the database object you set earlier
  // The inventory object will then hold all of the records contained
  // in the database
  inv.reset();

  // You can access it through two different ways
  // 1. Get all
  //
  // The function inv.getRange(first, last) retrieves books in between
  //    the two specified ranges
  // The inv.getSize() function returns the number of books in the inventory
  //
  // The function returns a vector<Book*>
  vector<Book*> book_list = inv.getRange(0, inv.getSize());
  // or ...
  vector<Book*> book_page1 = inv.getRange(0, 10);
  // Please don't use book_page1 as a real variable
  // This is very useful for paging (find ranges from 0,9, then 10,19 etc.)

  // 2. Search with fields
  // inv.findBook(Book::field, void*)
  // This function takes a Book::field datatype (all the possible fields are
  // in the field enum inside of book.h)
  string sz_author = "J.K. Rowling";
  vector<Book*> jkRowling_list = inv.findBook(Book::AUTHOR, &sz_author);


  // Once you have a vector<Book*> list, you can iterate through them
  // to get their contents, and contain the size
  // Much better than simple arrays!
  int page1size = (int) book_list.size();
  // Vectors subscript [] are overloaded, so you can access them with
  // indices
  for(int i = 0; i < page1size; i++) {
    cout <<  "Title: " << book_list[i]->getTitle() << endl;
    cout << "Author: " << book_list[i]->getAuthor() << endl;
  }
  // Or much safer, vector iterators. Depends on your preference
  for(vector<Book*>::iterator it = book_list.begin(); it != book_list.end(); it++) {
    cout << " Title: " << (*it)->getTitle() << endl;
    cout << "Author: " << (*it)->getAuthor() << endl;
  }



  // Modifiying the inventory =====
  // Because of the way binary files are handled, we can't just insert and
  //    delete records in the middle of the file
  // So instead, we have to buffer changes, then write them all at once
  //    in order to reuse record slots, and efficiently write
  //
  // There are three ways to modify the inventory, and all of them must be
  //    followed by a sync() command in order for the changes to write
  //
  // Adding books
  // inv.addBook(Book*);
  Book* harry_potter_1 = new Book;
  harry_potter_1->setTitle("Harry Potter and the Sorcerer's Stone");
  harry_potter_1->setAuthor("J.K. Rowling");
  harry_potter_1->setQuantity(3);

  inv.addBook(harry_potter_1); // Does not write to file yet

  // Modifying books
  // inv.updBook(Book*);
  vector<Book*> hp2_list = inv.findBook(Book::TITLE, "Harry Potter and the Chamber of Secrets");
  // Note that findBook ---always--- has a possilibity of returning more
  // than one book
  for(int i = 0; i < (int) hp2_list.size(); i++) {
    hp2_list[i]->setQuantity(9);
    hp2_list[i]->setDateAdded(04, 28, 2003);

    inv.updBook(hp2_list[i]);
  }
  // inv.updBook(Book*) lets the inventory know that you made modifications to the
  // entry
  // Does not write to file yet


  // Deleting books
  // inv.delBook(Book*)
  vector<Book*> hp3_list = inv.findBook(Book::TITLE, "Harry Potter and Prisoner of Azkaban");
  inv.delBook(hp3_list[0]); // Flag first item in hp3_list for removal
  // Exactly like inv.updBook(Book*), just tells inventory that we want
  // to remove the book

  // Now that all our changes are done, we finally call
  inv.sync();

  // Doing it this way allows efficient insertion/removal/marking for any kind
  // of file or remote database (they will use the exact same commands)
}
