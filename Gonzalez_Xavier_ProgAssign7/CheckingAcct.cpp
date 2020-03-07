/*
 *	Xavier Gonzalez
 *	Applied Programming Languages
 *	March 6th, 2020
 *
 *	Assignment 7 - Inheritance
 *	CheckingAcct.cpp
 *
 */
#include <iostream>
#include "Account.h"

CheckingAcct::CheckingAcct(std::string oN, int n, double bal) {
	OwnerName = oN;
	AcctNum = n;
	Balance = bal;
}

void CheckingAcct::Deposit(double num) {
	Balance += num;
}

void CheckingAcct::Withdraw(double num) {
	Balance -= num;
}




