/*
 * Xavier Gonzalez
 * Applied Programming Languages
 * February 20th, 2020
 *
 * Assignment 5
 * book.h
 */
#include <string>
#ifndef BOOK_H
#define BOOK_H

class book {
private:
	std::string Title;
	int bookID;
	bool checkedOut;
	
public:
	// SETTERS
	void setBookId(int bookId);
	void setCheckedOut(bool checkedOut);
	void setTitle(std::string title);

	// GETTERS
	int getBookId() const;
	bool isCheckedOut() const;
	std::string getTitle() const;

	// CONSTRUCTORS
	book(); // default constructor book b;
	book(std::string t, int bID, bool bCheckedOut); // Initialize the Title and the bookID

	// COPY CONSTRUCTOR
	book(const book &bookObj);

	/*	If checkedOut returns true, a message will be displayed
	* 	to the user saying it is unavailable, if returned
	*	false, it will turn checkedOut to true
	*/
	void borrowBook();

	// sets checkedOut to false when book is returned
	void returnBook();

	// Added this in because it was bland without this.
	std::string bStatus();

	/*
	 * Xavier Gonzalez
	 * Applied Programming Languages
	 * February 27th, 2020
	 *
	 * Assignment 6
	 * Updated book.cpp
	 */

	book operator+(const book &right); //prototype for overloading +
	book operator-(book &right); // prototype for overloading -
	book operator=(const book &right); // prototype for overloading =
};
#endif
