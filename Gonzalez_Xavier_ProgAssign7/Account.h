/*
 *	Xavier Gonzalez
 *	Applied Programming Languages
 *	March 6th, 2020
 *
 *	Assignment 7 - Inheritance
 *	Account.h
 *
 */

#include <string>
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

// Base Class
class Account {
protected:
	/*
	 *  Variables are in protected mode instead of private
	 *  because if it were on private, you wouldn't be able to access it.
	 */
	// Initialized Variables
	std::string OwnerName;
	int AcctNum;
	double Balance;

public:
	// SETTERS
	void setAcctNum(int acctNum);
	void setBalance(double balance);
	void setOwnerName(const std::string &ownerName);

	// GETTERS
	int getAcctNum() const;
	double getBalance() const;
	const std::string& getOwnerName() const;

	// DEFAULT CONSTRUCTOR
	Account();

	// 3-parameter constructor
	Account(std::string oN, int aC, double bal);


};

// Derived Class
class CheckingAcct : public Account{

public:
	// FUNCTIONS
	void Deposit(double balance);
	void Withdraw(double balance);

	// 3-parameter constructor
	CheckingAcct(std::string ownerNum, int n, double balance);
};

// Derived Class
class LoanAcct : public Account {
private:
	double IntRate;

public:
	// SETTER
	void setInterestRate(double interest);
	// GETTER
	double getInterestRate();

	// FUNCTIONS
	void PayBalance(double num);
	void CalcInterest();

	// 3-parameter constructor
	LoanAcct(std::string ownerName, int num, double balance, double interest);

};


#endif /* ACCOUNT_H_ */
