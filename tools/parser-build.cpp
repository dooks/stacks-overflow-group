#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include "../db.h"
#include "../book.h"
using namespace std;

int main() {
  srand((unsigned) time(NULL)); // Seed RNG

  vector<Book*> temp_list;
  ifstream test_file("tools/library.txt");
  DB::Local db_local;

  int counter = 0;
  string line;   // Create line buffer
  string buffer; // Create string buffer

  while(getline(test_file, line)) {
    // Create new book
    Book* book = new Book;

    // Create ss for line buffer
    stringstream linestream(line);

    // For each value seperated by delimiter # on line
    getline(linestream, buffer, '#');
    book->setISBN(buffer); // getline ISBN into string buffer
    getline(linestream, buffer, '#');
    book->setTitle(buffer); // getline Title into string buffer
    getline(linestream, buffer, '#');
    book->setAuthor(buffer); // getline Author into string buffer
    getline(linestream, buffer, '#');
    book->setPublisher(buffer); // getline Publisher into string buffer

    // getline Date Added
    getline(linestream, buffer, '#'); int month = atoi(buffer.c_str());
    getline(linestream, buffer, '#'); int   day = atoi(buffer.c_str());
    getline(linestream, buffer, '#'); int  year = atoi(buffer.c_str());
    book->setDateAdded(month, day, year); // getline Year into string buffer

    getline(linestream, buffer, '#'); // Read quantity
    book->setQuantity(atoi(buffer.c_str()));

    getline(linestream, buffer, '#');
    book->setWholeCost(atof(buffer.c_str())); // getline Wholesale Price into string buffer
    getline(linestream, buffer, '#');
    book->setRetailPrice(atof(buffer.c_str())); // getline Retail price into string buffer

    temp_list.push_back(book); // Push book into temp_list
  }

  // Print out all books to make sure we have everything...
  //for(int i = 0; i < (int) temp_list.size(); i++) {
    //cout << temp_list[i]->getISBN()        << " : ";
    //cout << temp_list[i]->getTitle()       << " : ";
    //cout << temp_list[i]->getAuthor()      << " : ";
    //cout << temp_list[i]->getPublisher()   << " : ";
    //cout << (temp_list[i]->getDateAdded()).str() << " : ";
    //cout << temp_list[i]->getQuantity()    << " : ";
    //cout << temp_list[i]->getWholeCost()   << " : ";
    //cout << temp_list[i]->getRetailPrice() << endl;
  //}

  // Open database for reading/writing
  db_local.open("books.db");
  for(int i = 0; i < (int) temp_list.size(); i++) {
    db_local.add(temp_list[i]);
  }
  db_local.close(); // Close database

  for(int i = 0; i < (int) temp_list.size(); i++) {
    delete temp_list[i];
  }

  system("pause");
  return 0;
}
