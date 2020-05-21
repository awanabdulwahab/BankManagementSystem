#include<iostream>
using namespace std;
#include<fstream>
#include"Account.h"
void Account::CreateAccount() {
	cout << "Applicant Name: "; cin.getline(Name, 20);
	cout << "Applicant's Father Name: "; cin.getline(FName, 20);
	cout << "CNIC: "; cin.getline(CNIC, 15);
	cout << "Date of Birth: "; cin >> DOB; cin.ignore();
	cout << "Account Number: "; cin.getline(this->accountNo, 17);
	cout << "Phone: "; cin.getline(phone, 12);
	cout << "Address: "; cin.getline(Address, 50);
	cout << "Gender (M/F): "; cin >> Gender;
	cout << "Date of Account Creation: "; cin >> DateOfAccountCreation; cin.ignore();
	
	}
