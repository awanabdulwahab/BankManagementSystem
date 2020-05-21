#include"Account.h"
#include"Func.h"
class CheckingAccount : public Account {
	int creditLimit, overdraftFee;
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