#ifndef Account_HEADER
#define Account_HEADER
#include"CDate.h"

class Account {
protected:
	char Name[20], FName[20], CNIC[15], Address[50], phone[12], accountNo[17], Gender;
	CDate DOB, DateOfAccountCreation;
	long balance;
public:
	void CreateAccount();
};
#endif