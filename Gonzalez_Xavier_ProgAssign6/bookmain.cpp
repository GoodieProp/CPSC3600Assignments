/*
 * Xavier Gonzalez
 * Applied Programming Languages
 * February 20th, 2020
 *
 * Assignment 5
 * bookmain.cpp
 */

#include <iostream>
#include <string>
#include "book.h"

void previousAssignment() {
	// book.h default constructor object
		book b1;

		// Initialized Variables
		std::string title;
		std::string bookLTitle;
		int bID;

		// User enters title
		std::cout << "Enter a title: " << std::endl;
		std::getline(std::cin, title);
		b1.setTitle(title);

		// User enters Book ID
		std::cout << "Enter the Book ID: " << std::endl;
		std::cin >> bID;
		b1.setBookId(bID);

		// Use getters from constructor class to get values
		std::cout << "Title: " << b1.getTitle() << std::endl;
		std::cout << "Book ID: " << b1.getBookId() << std::endl;
		std::cout << b1.bStatus() << "\n" << std::endl;
		b1.borrowBook();

		// 2nd go-around
		std::cout << "Title: " << b1.getTitle() << std::endl;
		std::cout << "Book ID: " << b1.getBookId() << std::endl;
		std::cout << b1.bStatus() << "\n" << std::endl;

		// Hardcode values for the 3-parameter constructor
		book b2("Strange Case of Dr. Jekyll and Mr. Hyde", 23, true);
		std::cout << "Title: " << b2.getTitle() << std::endl;
		std::cout << "Book ID: " << b2.getBookId() << std::endl;
		std::cout << b2.bStatus() << "\n" << std::endl;
		b2.returnBook();

		// 2nd go-around again
		std::cout << "Title: " << b2.getTitle() << std::endl;
		std::cout << "Book ID: " << b2.getBookId() << std::endl;
		std::cout << b2.bStatus() << "\n" << std::endl;

		// Using the copy constructor
		book b3(b1);
		std::cout << "Title: " << b3.getTitle() << std::endl;
		std::cout << "Book ID: " << b3.getBookId() << std::endl;
		std::cout << b3.bStatus()  << std::endl;
}

int main() {

	/*
	 * 	The previousAssignment function is commented out because
	 * 	it causes a bug with the new assignment. When both assignments run,
	 * 	in the for loop of the new assignment, which is the array of book objects,
	 * 	it goes through the for loop twice before stopping, and shows "Enter a title" twice.
	 *
	 * 	Therefore previousAssignment function is commented out to prevent this.
	 * 	Both Assignments work fine, but the bug loses the touch in terms of display.
	 */
	 //previousAssignment();


	/*	-----------Array of Objects Assignment Starts Here--------------
	 *	Xavier Gonzalez
	 *	Applied Programming Languages
	 *	February 27th, 2020
	 *
	 *	Assignment 6
	 *	Updated bookmain.cpp
	 */

	book bookLibrary[5];
	std::string bookLTitle;

	// For loop to go 5 times.
	for (int i = 0; i < 5; i++) {
		// User inputs title, BookId is a random int between 1 - 1000
		// and checkedOut is set to false

		std::cout << "Enter a title: " << std::endl;
		std::getline(std::cin, bookLTitle);
		int bLID = rand() % 1000 + 1;
		bool cOut = false;

		// Title, bookID, and checkedOut are passed to the
		// 2nd constructor and added to the bookLibrary array
		bookLibrary[i] = book(bookLTitle, bLID, cOut);
	}

	// Tests the operator functions
	bookLibrary[0] = bookLibrary[1];
	bookLibrary[2] = bookLibrary[3] + bookLibrary[4];
	bookLibrary[3] = bookLibrary[1] - bookLibrary[4];

	std::cout << "" << std::endl;

	// For loops that iterates through the bookLibrary Array and prints them.
	for (int i = 0; i < 5; i++) {
		std::cout << "Title: " << bookLibrary[i].getTitle() << std::endl;
		std::cout << "Book ID: " << bookLibrary[i].getBookId() << std::endl;
		std::cout << "" << std::endl;
	}

	return 0;

}
