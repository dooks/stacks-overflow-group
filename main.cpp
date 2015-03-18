#include <iostream>
#include "menu.h"
#include "Cashier.h"
#include "inventory.h"
#include "input.h"
#include "pager.h"

int main() {
	// Modules
	Inventory inv;				// Inventory module
	inv.reset();					// Initialize inventory, default location is
												// "tools/books.db"
	Input input;					// Input module
	Pager pager();				// Pager to assist displaying items
	Cashier cash(&inv);		// Handles transactions and cart
	Report report(&inv);	// Handles displaying data

	// Menu modules
	Menu menu_main(&inv, &cash);
	MenuCashier menu_cash;
	MenuInventory menu_inv;
	//MenuBookList menu_list;
	MenuReport menu_report;


	// Main globals
	int state = 0;		// 0 - splash page
								  	// 1 - main menu
								  	// 2 - cashier
								  	// 3 - inventory
								  	// 4 - report
								  	// 5 - book search
								  	// 6 - display booklist
								  	// 7 - add book
								  	// 8 - quit
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
				input.getCh();	// wait for any key
				state = 1; // switch state to main menu
				break;
			case 1: // case state main menu
				menu_main.displayHeader(); // display main menu header
				menu_main.displayBody();   // display main menu body
				menu_main.displayFooter(); // display main menu footer
				switch(input.getCh()) { // switch input
					case 1: // case 1: cashier
						state = 2;// switch state to cashier
						break;

					case 2: // case 2: inventory
						state = 3; // switch state to inventory
						break;

					case 3: // case 3: report
						state = 4; // switch state to report
						break;

					case 4: // case 4: quit
						bool quit = true;	// switch state to quit
				}

			case 2: // case state cashier module
				Menu::m_tempList = cash.getCart(); // Set temp list to cart
				menu_cash.displayHeader(); // display cashier body
				menu_cash.displayBody();
				menu_cash.displayFooter();

				switch(input.getCh()) { // switch input
					case 1: // case 1: add book
						prev_state=2; // set last state to cashier
						state=6;// switch state to search
						substate=4;// switch substate to add cart
						break;
					case 2: // case 2: remove book
						prev_state=2;// set last state to cashier
						state=6;// switch state to search
						substate=2;// switch substate to delete book(cart)
						break;
					case 3: // case 3: finalize transaction
						prev_state=2;// set last state to cashier
						state=7;// switch state to display book list
						substate=5;// switch substate to checkout
						break;
					case 4: // case 4: return to previous menu
						state=1;// switch state to main menu
						break;
					// TODO: default behavior
				}

			case 3: // case state inventory module
				menu_inv.displayHeader(); // display inventory header
				menu_inv.displayBody(); 	// display inventory body
				menu_inv.displayFooter(); // display inventory footer
				prev_state = 3; // set last state to inventory

				switch(input.getCh()) { // switch input
					case 1: // case 1: look up book
						state 	 = 6; // switch state to search
						break;
					case 2: // case 2: add a book
						state 	 = 8; // switch state to add book
						break;
					case 3: // case 3: edit a book's record
						state 	 = 6; // switch state to search
						substate = 3; // switch substate to edit book
						break;
					case 4: // case 4: delete a book
						state 	 = 6; // switch state to search
						substate = 1; // switch substate to delete book
						break;
					case 5: // case 5: return to previous menu
						state		 = 1; // switch state to main menu
						break;
				}

			case 4: // case state report module
					menu_report.displayHeader(); // display report body
					menu_report.displayBody();	 // display report body
					menu_report.displayFooter(); // display report body

					prev_state = 4;

					switch(input.getCh()) { //switch input
						case 1: // case 1: list all books
							prev_state=4;
							state = 7; // switch state to display book list
							state=prev_state;
							break;
						case 2: // case 2: list by wholesale price
							prev_state=4;
							state =7;// switch state to display book list(wholesale & total)
							state=prev_state;
							break;
						case 3: // case 3: list by retail price
							prev_state=4;
							state = 7;// switch state to display book list(retail & total)
							state=prev_state;
							break;
						case 4: // case 4: list by quantity
							prev_state=4;
							state = 7;// switch state to display book list
							state=prev_state;
							break;
						case 5: // case 5: list by cost
							prev_state=4;
							state = 7;// switch state to display book list
							state=prev_state;
							break;

						case 6:  // case 6: list by age
							prev_state=4;
							state=7;// switch state to display book list
							state=prev_state;
							break;
						case 7:  	// case 7: return to previous menu
							prevstate=4;
							state=7;// switch state to main menu
							state=prev_state;
							break;
						case 8:  // case 8: DANCE PARTY
							prevstate=4;
							state=9;
							state=prev_state;
							break;
					}
					break;

			case 5:	// case state book search
					menu_search.displayBody();// display search body
					menu_search.displayPrompt();// prompt user for search term
					insert voodoo black magic here;	// assign to menu temp list
					state=7;// set state to display book list
					break;
			case 6: // case display book list
				// display book list
				// book list is Menu::m_tempList
				char temp_input = input.getCh();
				switch(temp_input) {// switch user input
					case 1: 						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[0];
						state = prev_state;// switch to last state
						break;// case 1-10: user select given book
					case 2:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[1];
						state = prev_state;// switch to last state
						break;
					case 3:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[2];
						state = prev_state;// switch to last state
						break;
					case 4:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[3];
						state = prev_state;// switch to last state
						break;
					case 5:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[4];
						state = prev_state;// switch to last state
						break;
					case 6:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[5];
						state = prev_state;// switch to last state
						break;
					case 7:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[6];
						state = prev_state;// switch to last state
						break;
					case 8:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[7];
						state = prev_state;// switch to last state
						break;
					case 9:						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[8];
						state = prev_state;// switch to last state
						break;
					case 10:
						// Select book from list and save into temp book
						Menu::m_tempBook = Menu::m_tempList[9];
						state = prev_state;// switch to last state
						break;
					case 'n';// case N
					case 'N';// case N
						pager.movePage(down);
						break;// go to next page
					case 'p';// case P
					case 'P';// case P
						pager.movePage(up);
						break;// go to previous page
					case 'q';// case Q
					case 'Q';// case Q
						state = prev_state;// go to previous state
				}

				if (substate == 1) {	// substate delete book
						inv.delBook(Menu::m_tempBook);  	//switch state to delete book
						state = prev_state;
					}
				if (substate == 2) {	// substate remove from cart
					cash.delCart(Menu::m_tempBook);
					state = prev_state;
				}

				if (substate == 3) { // substate edit book
					switch(input.getCh()) { // prompt user select field to change
						case 1: // case 1: isbn
							string temp = input.getLine(); // TODO: validate input
							Menu::m_tempBook->setISBN(temp);
							break;
						case 2: // case 2: author
							string temp = input.getLine(); // TODO: validate input
							Menu::m_tempBook->setAuthor(temp);
						case 3:// case 3: title
							string temp = input.getLine();
							Menu::m_tempBook->setTitle(temp);
							break;
						case 4: // case 4: publisher
							string temp = input.getLine();
							Menu::m_tempBook->setTitle(temp);
							break;
						case 5: // case 5: date added
							string temp;
							date dtemp;

							cout << "Month: ";
							temp = input.getLine();
							dtemp.setMonth(dtemp);

							cout << "Day: ";
							temp = input.getLine();
							dtemp.setDay(dtemp);

							cout << "Year: ";
							temp = input.getLine();
							dtemp.setYear(dtemp);
							Menu::m_tempBook->setDateAdded(dtemp);
							break;
						case 6: // case 6: wholesale price
							string temp = input.getLine();
							Menu::m_tempBook->setWholeCost(temp);
							break;
						case 7: // case 7: retail price
							string temp = input.getLine();
							Menu::m_tempBook->setRetailPrice(temp);
							break;
						case 8: // case 8: quantity
							string temp = input.getLine();
							Menu::m_tempBook->setQuantity(temp);
							break;
					}
					// return to last state
					state = prev_state;
				}

				if (substate == 4)	{ // substate add to cart
						cash.addCart(Menu::m_tempBook);	// add to cart
						Menu::m_tempBook = NULL; // Clear temp buffer
				}

				if (substate == 5) // checkout
				{
					menu_cash.displaycheckout(); // TODO <--- ?
				}

				substate=0; // Clear substate
				break;


			case 7:  // case state add book
				menu_inv.displayHeader();// create new menu temp book and prompt user for:
				menu_inv.displayBody();// create new menu temp book and prompt user for:
				menu_inv.displayFooter();// create new menu temp book and prompt user for:
				
				string temp;
				Menu::m_tempBook = new Book;
				cout << "ISBN: "; getLine(cin, temp);
				Menu::m_tempBook->setISBN(temp);// prompt user for isbn
				cout << "Title: "; getLine(cin, temp);
				Menu::m_tempBook->setTitle(temp);// prompt user for title
				cout << "Author: "; getLine(cin, temp);
				Menu::m_tempBook->setAuthor(temp);// prompt user for author
				cout << "Publisher: "; getLine(cin, temp);
				Menu::m_tempBook->setPublisher(temp);// prompt user for publisher
				cout << "Month Added: "; getLine(cin, temp);
				Menu::m_tempBook->setMonth(stoi(temp));// prompt user for month added
				cout << "Day Added: "; getLine(cin, temp);
				Menu::m_tempBook->setDay(stoi(temp));// prompt user for day added
				cout << "Year Added: "; getLine(cin, temp);
				Menu::m_tempBook->setYear(stoi(temp));// prompt user for year added
				cout << "Wholesale Cost: "; getLine(cin, temp);
				Menu::m_tempBook->setWholesale(stod(temp));// prompt user for wholesale price
				cout << "Retail Price: "; getLine(cin, temp);
				Menu::m_tempBook->setRetailPrice(stoid(temp));// prompt user for retail price
				
				inv.addBook(Menu::m_tempBook);
				Menu::m_tempBook = NULL;
				
				state=prev_state;// return to last state
				break;

			case 8: // case quit
				quit = true; // set quit to true
		}
	}

	//system("pause");

}
