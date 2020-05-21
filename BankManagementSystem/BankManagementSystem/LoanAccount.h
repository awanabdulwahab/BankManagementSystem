#include"Account.h"
#include"CDate.h"
#include"SavingAccount.h"
class LoanAccount : public Account {
	long PrincipalAmount, monthlyInstallment;
	int noOfInstallments;
	void display()const;
public:
	void CreateAccount();
	void ReturnLoan();
	void balanceInquiry();
	void deleteAccount();
	void modify();
	void displayAccount();
	void displayReport();
};