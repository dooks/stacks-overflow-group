#include <iostream>
#include "menu.h"
#include "Cashier.h"
#include "inventory.h"
#include "input.h"
#include "pager.h"

int main() {
	// Initialize all modules
	Inventory inv;
	Input input;
	Cashier cash(&inv);
	Report report(&inv);
	Menu main(&inv, &cash);
	inv.reset();

	int state = 0;
	bool quit = false;

	//main.Menu1(userchoice);

	while(!quit) {
		// Prompt program splash
		switch(state) {
			// case state splash screen
				// wait for any key
				// switch state to main menu

			// case state main menu
				// display main menu body
				// switch input
					// case 1: cashier
						// switch state to cashier
					// case 2: inventory
						// switch state to inventory
					// case 3: report
						// switch state to report
					// case 4: quit
						// switch state to return 0

			// case state cashier module
				// display cashier body
				// switch input
					// case 1: add book
						// set last state to cashier
						// switch state to search
						// switch substate to add cart
						// return to last state
					// case 2: remove book
						// set last state to cashier
						// switch state to search
						// switch substate to delete book(cart)
						// return to last state
					// case 3: finalize transaction
						// set last state to main menu
						// switch state to display book list(cart)
						// switch substate to checkout
						// return to last state
					// case 4: return to previous menu
						// switch state to main menu

			// case state inventory module
				// display inventory body
				// switch input
					// case 1: look up book
						//set last state to inventory
						// switch state to search
					// case 2: add a book
						// set last state to inventory
						// switch state to add book
					// case 3: edit a book's record
						// set last state to inventory
						// switch state to search
						// switch substate to edit book
					// case 4: delete a book
						// set last state to inventory
						// switch state to search
						// switch substate to delete book
					// case 6: return to previous menu
						// switch state to main menu

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
				// create temporary book
				// prompt user for isbn
				// prompt user for title
				// prompt user for author
				// prompt user for publisher
				// prompt user for year added
				// prompt user for month added
				// prompt user for day added
				// prompt user for wholesale price
				// prompt user for retail price

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
