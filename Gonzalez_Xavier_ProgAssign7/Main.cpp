/*
 *	Xavier Gonzalez
 *	Applied Programming Languages
 *	March 6th, 2020
 *
 *	Assignment 7 - Inheritance
 *	Main.cpp
 *
 */

#include <string>
#include <iostream>
#include "Account.h"

int main() {

	std::cout << "****************************************************" << std::endl;

	// Account
	Account a1("Xavier's General Account", 12345, 3736.30);
	std::cout << "Owner:\t\t\t\t" << a1.getOwnerName() << std::endl;
	std::cout << "Account Number:\t\t\t" << a1.getAcctNum() << std::endl;
	std::cout << "Balance:\t\t\t$" << a1.getBalance() << "\n" <<std::endl;

	std::cout << "****************************************************" << std::endl;

	// Checking Account
	CheckingAcct cA("Xavier's Checking Account", 123456, 2830.20);
	std::cout << "Owner:\t\t\t\t" << cA.getOwnerName() << std::endl;
	std::cout << "Account Number:\t\t\t" << cA.getAcctNum() << std::endl;
	std::cout << "Current Balance:\t\t$" << cA.getBalance() << std::endl;

	// DEPOSIT
	std::cout << "\nDepositing $100." << std::endl;
	cA.Deposit(100);
	std::cout << "Current Balance:\t\t$" << cA.getBalance() << std::endl;

	// WITHDRAW
	std::cout << "\nWithdrawing $50." << std::endl;
	cA.Withdraw(50);
	std::cout << "Current Balance:\t\t$" << cA.getBalance() << "\n" <<std::endl;

	std::cout << "****************************************************" << std::endl;

	// Loan Account
	LoanAcct lA("Xavier's Loan Account", 123, 3629.29, .78);
	std::cout << "Owner:\t\t\t\t" << lA.getOwnerName() << std::endl;
	std::cout << "Account Number:\t\t\t" << lA.getAcctNum() << std::endl;
	std::cout << "Current Loan Balance:\t\t$" << lA.getBalance() << std::endl;

	// INTEREST RATE FUNCTION
	int interest = lA.getInterestRate();
	std::cout << "Interest Rate: " << interest << "%" << std::endl;

	// PAY BALANCE FUNCTION
	std::cout << "$\n300 payment to Loan Balance." << std::endl;
	lA.PayBalance(300);
	std::cout << "Current Loan Balance:\t\t$" << lA.getBalance() << std::endl;

	// CALCULATE INTEREST FUNCTION
	std::cout << "\nAdding Monthly Interest on Current Loan Balance." << std::endl;
	lA.CalcInterest();
	std::cout << "Current Loan Balance:\t\t$" << lA.getBalance() << std::endl;





}




