#pragma once
#include"Account.h"
class SavingAccount : public Account {
	int interestRate;
	CDate upDate;
	void display();
public:
	void CreateAccount();
	void depositAmount();
	void withdraw();
	void deleteAccount();
	void modify();
	void displayAccount();
	void displayReport();
	void balanceInquiry();
};