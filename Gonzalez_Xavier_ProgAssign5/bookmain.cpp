/*
 * Xavier Gonzalez
 * Applied Programming Languages
 * February 20th, 2020
 *
 * Assignment 5
 * bookmain.cpp
 */

#include <iostream>
#include "book.h"

int main() {

	// book.h default constructor object
	book b1;

	// Initialized Variables
	std::string title;
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
	std::cout << b3.bStatus() << "\n" << std::endl;

	return 0;

}
