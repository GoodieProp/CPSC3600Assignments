/*
 * Xavier Gonzalez
 * Applied Programming Languages
 * February 20th, 2020
 *
 * Assignment 5
 * book.cpp
 */

#include <iostream>
#include <cstdlib>
#include "book.h"


// default constructor
book::book() {
	std::cout << "Default constructor" << std::endl;
	Title = "No Title";
	bookID = rand() % 1000 + 1;
	checkedOut = false;
}

// 3-parameter constructor
book::book(std::string title, int bID, bool bookCheckedOut) {
	Title = title;
	bookID = bID;
	checkedOut = bookCheckedOut;

}

// Copy constructor
book::book(const book &bookObj) {
	Title = bookObj.Title;
	bookID = bookObj.bookID;
	checkedOut = bookObj.checkedOut;
}

int book::getBookId() const {
	return bookID;
}

void book::setBookId(int bookId) {
	bookID = bookId;
}

bool book::isCheckedOut() const {
	return checkedOut;
}

void book::setCheckedOut(bool checkedOut) {
	this->checkedOut = checkedOut;
}

std::string book::getTitle() const {
	return Title;
}

void book::setTitle(std::string title) {
	Title = title;
}

// If book is true in checkedOut, it display
// a message to the user. If false, it will
// turn checkedOut to true
void book::borrowBook() {
	if (isCheckedOut() == true) {
		std::cout << "Book is not available to checkout." << std::endl;
	} else {
		checkedOut = true;
	}
}

// Sets checkedOut to false, if function is called.
void book::returnBook() {
	checkedOut = false;
}

std::string book::bStatus() {
	std::string bookA = "Book is available, and ready to be checked out!";
	std::string bookNA = "The book is currently checked out.";

	if (isCheckedOut() == true) {
		return bookNA;
	} else {
		return bookA;
	}
}


