/*
 *	Xavier Gonzalez
 *	Applied Programming Languages
 *	March 6th, 2020
 *
 *	Assignment 7 - Inheritance
 *	Account.cpp
 */

#include "Account.h"

// Default Constructor
Account::Account() {
	OwnerName = "N/A";
	AcctNum = 0;
	Balance = 0.0;
}

// 3-parameter Constructor
Account::Account(std::string oN, int aN, double bal) {
	OwnerName = oN;
	AcctNum = aN;
	Balance = bal;
}

int Account::getAcctNum() const {
	return AcctNum;
}

void Account::setAcctNum(int acctNum) {
	AcctNum = acctNum;
}

double Account::getBalance() const {
	return Balance;
}

void Account::setBalance(double balance) {
	Balance = balance;
}

const std::string& Account::getOwnerName() const {
	return OwnerName;
}

void Account::setOwnerName(const std::string &ownerName) {
	OwnerName = ownerName;
}
