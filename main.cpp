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
						// switch state to add book
					// case 2: remove book
						// set last state to cashier
						// switch state to remove book
					// case 3: finalize transaction
						// set last state to main menu
						// switch state to ??
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
						// switch state to add book??
					// case 4: delete a book
						// set last state to inventory
						// switch 
					// case 6: return to previous menu
						// switch state to main menu
			
			// case state report module
					// display report body
					//switch input
						// case 1: list all books
						// case 2: list by wholesale price
						// case 3: list by retail price
						// case 4: list by quantity
						// case 5: list by cost
						// case 6: list by age
						// case 7: return to previous menu
							// switch state to main menu
						// case 8: DANCE PARTY

			// case display a book list
				// display book list
				// switch user input 
					// case (book index)
						// switch state to display a book
					// case N
						// go to next page
					// case P
						// go to previous page
					// case Q
						// go to previous state
			// case display a book
				// display book information
				// switch user input
					// case Q
						// switch state to previous state
			// case state prompt user to search
				// display search body
				// prompt user for search term
				// ???
				//i feel this is missing something
				//i guess the question marks are appropriate
				// profit
				// set state to most recent state
			// case state prompt user to add book
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
			// case quit
				// set quit to true
		}
	}

	//system("pause");

}
