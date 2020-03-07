/*
 *	Xavier Gonzalez
 *	Applied Programming Languages
 *	March 6th, 2020
 *
 *	Assignment 7 - Inheritance
 *	LoanAcct.cpp
 *
 */

#include <iostream>
#include "Account.h"

LoanAcct::LoanAcct(std::string oN, int aN, double bal, double interest) {
	OwnerName = oN;
	AcctNum = aN;
	Balance = bal;
	IntRate = interest;
}

void LoanAcct::setInterestRate(double interest) {
	IntRate = interest;
}

double LoanAcct::getInterestRate() {
	return IntRate;
}

void LoanAcct::PayBalance(double num) {
	Balance -= num;
}

void LoanAcct::CalcInterest() {
	float cI = IntRate * Balance;
	Balance += cI;
}



