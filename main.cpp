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
	Cashier cash(&inv);		// Handles transactions and cart
	Report report(&inv);	// Handles displaying data

	// Menu modules
	Menu menu_main(&inv, &cash);
	MenuCashier menu_cash;
	MenuInventory menu_inv;
	//MenuBookList menu_list;


	// Main globals
	int state = 0;		// 0 - splash page
								  	// 1 - main menu
								  	// 2 - cashier
								  	// 3 - inventory
								  	// 4 - report
								  	// 5 - quit
								  	// 6 - book search
								  	// 7 - display booklist
								  	// 8 - add book
	int prev_state = 0;

	int substate = 0; // 0 - none
										// 1 - delete book
										// 2 - edit book
										// 3 - add to cart

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
				menu_cash.displayHeader(); // display cashier body
				switch(input.getCh()) { // switch input
					case 1: // case 1: add book
						prev_state=2; // set last state to cashier
						state=6;// switch state to search
						substate=4;// switch substate to add cart
						state = prev_state; // return to last state
						break;
					case 2: // case 2: remove book
						prev_state=2;// set last state to cashier
						state=6;// switch state to search
						substate=1;// switch substate to delete book(cart)
						state = prev_state;// return to last state
						break;
					case 3: // case 3: finalize transaction
						prev_state=2;// set last state to cashier
						state=7;// switch state to display book list(cart)
						substate=// switch substate to checkout
						// return to last state
						break;
					case 4: // case 4: return to previous menu
						// switch state to main menu
						break;
					default:
						// TODO: ? Later, what should we do for this
						break;
				}

			case 3: // case state inventory module
				menu_inv.displayHeader(); // display inventory header
				menu_inv.displayBody(); // display inventory body
				menu_inv.displayFooter(); // display inventory footer

				prev_state = 3; // set last state to inventory

				switch(input.getCh()) { // switch input
					case 1: // case 1: look up book
						state 	 = 6; // switch state to search
					case 2: // case 2: add a book
						state 	 = 8; // switch state to add book
					case 3: // case 3: edit a book's record
						state 	 = 6; // switch state to search
						substate = 2; // switch substate to edit book
					case 4: // case 4: delete a book
						state 	 = 6; // switch state to search
						substate = 1; // switch substate to delete book
					case 5: // case 5: return to previous menu
						state		 = 1; // switch state to main menu
				}

			// case state report module
					// display report body
					//switch input
						// case 1: list all books
							// set last state to report
							// switch state to display book list
						// case 2: list by wholesale price
							// set last state to report
							// switch state to display book list(wholesale & total)
						// case 3: list by retail price
							// set last state to report
							// switch state to display book list(retail & total)
						// case 4: list by quantity
							// set last state to report
							// switch state to display book list
						// case 5: list by cost
							// set last state to report
							// switch state to display book list
						// case 6: list by age
							// set last state to report
							// switch state to display book list
						// case 7: return to previous menu
							// switch state to main menu
						// case 8: DANCE PARTY

			// case state book search
				// display search body
				// prompt user for search term
				// assign to menu temp list
				// set state to display book list
			// case display book list
				// display book list
				// switch user input
					// case (book index)
						// switch state to display a book
					// case 1-10: user select given book
						// switch to last state
					// case N
						// go to next page
					// case P
						// go to previous page
					// case Q
						// go to previous state
				// substate delete book
					//switch state to delete book
				// substate add to cart
					//switch state to add to cart
				// substate edit book
					//switch state to edit book
				// clear substate


			// case state add book
				// create new menu temp book and prompt user for:
				// prompt user for isbn
				// prompt user for title
				// prompt user for author
				// prompt user for publisher
				// prompt user for year added
				// prompt user for month added
				// prompt user for day added
				// prompt user for wholesale price
				// prompt user for retail price
				// ??? add book logic, come back to this
				// return to last state

			// case substate edit book
				// prompt user select field to change
					// case 1: isbn
					// case 2: author
					// case 3: title
					// case 4: publisher
					// case 5: date added
					// case 6: wholesale price
					// case 7: retail price
					// case 8: quantity
				// user input change
				// return to last state

			// case substate add to cart
				//user selection added to cart list

			// case substate delete book
				// user selection deleted

			// case substate checkout
				// append sales information to booklist
				// delete book(s)

			// case quit
				// set quit to true

		}
	}

	//system("pause");

}
