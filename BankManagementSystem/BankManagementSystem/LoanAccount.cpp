#include<iostream>
using namespace std;
#include"LoanAccount.h"
#include<fstream>
#include<conio.h>
#include"Func.h"

void LoanAccount::CreateAccount() {
	Account::CreateAccount();
	cout << "Loan Principal Amount: "; cin >> this->PrincipalAmount; this->balance = this->PrincipalAmount;
	cout << "Number of installments: "; cin >> this->noOfInstallments; 
	this->monthlyInstallment = (long)(this->PrincipalAmount*(1 + (0.02) * this->noOfInstallments));
	this->monthlyInstallment /= this->noOfInstallments;
	cout << "Monthly Installment becomes(with 2% interest): " << this->monthlyInstallment << endl;

	ofstream oFile("LoanAccount.dat", ios::binary | ios::app); if (!oFile) cout << "Error in opening the file!\n" << endl;
	else {
		oFile.write((char*)this, sizeof(*this));
		cout << "Your account has been created successfully....!!\n\n";
		oFile.close();
	}
}
void LoanAccount::display()const {
	cout << "Name: " << this->Name << endl << "Father Name: " << this->FName << endl
		<< "Date of Birth: " << this->DOB << endl << "Gender: " << this->Gender << endl
		<< "CNIC: " << this->CNIC << endl << "Balance (Customer have to pay):" << PrincipalAmount
		<<endl<< "Account Number: " << this->accountNo << endl << "Balance: " << this->balance << endl
		<< "Contact: " << this->phone << endl << "Address: " << this->Address << endl
		<< "Date of Account Creation: " << this->DateOfAccountCreation << endl
		<< "Principal Amount: " << this->PrincipalAmount << endl << "Number of Installments: " << this->noOfInstallments << endl
		<< "Monthly Installment: " << this->monthlyInstallment << endl;
}
void LoanAccount::displayAccount() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ifstream iFile("LoanAccount.dat", ios::binary | ios::in); if (!iFile)cout << "File could not open!";
	else
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				this->display();
				flag = true;
			}
		}
	if (flag != true)cout << "Account Number you entered does not exist..!";
	iFile.close();
}
void LoanAccount::displayReport() {
	ifstream iFile("LoanAccount.dat", ios::binary | ios::in); if (!iFile)cout << "File could not open!";
	else {
		int i = 1;
		while (iFile.read((char*)this, sizeof(*this))) {
			cout << "\n\nRecord No." << i << endl; i++;
			this->display();
			cout << endl;
		}
	}
	iFile.close();
}
void LoanAccount::ReturnLoan() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("LoanAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "File could not open.!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				long deposit;
				cout << "Enter Amount you want to deposit: "; cin >> deposit;
				this->PrincipalAmount -= deposit;
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("LoanAccount.dat");
		rename("Temp.dat", "LoanAccount.dat");
		if (flag == false) cout << "Account Number you entered does not exist..!" << endl;
	}
}
void LoanAccount::balanceInquiry() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ifstream iFile("LoanAccount.dat", ios::binary | ios::in);
	if (!iFile)cout << "File could not open!";
	else
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				cout << "Name: " << this->Name << endl
					<< "Your Repayable Balance: " << this->balance << endl;
				flag = true;
			}
		}
	if (flag != true)cout << "Account Number you entered does not exist..!";
	iFile.close();
}
void LoanAccount::deleteAccount() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	char c;
	ofstream oFile("Temp.dat", ios::binary | ios::out);
	ifstream iFile("LoanAccount.dat", ios::binary);
	if (!iFile) cout << "Error in opening the file!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (!chrcmp(this->accountNo, tmp)) {
				oFile.write((char*)this, sizeof(*this));
				continue;
			}
			flag = true;
		}
		oFile.close(); iFile.close();
		remove("LoanAccount.dat");
		rename("Temp.dat", "LoanAccount.dat");
		if (flag == true) cout << "Account has been permanently deleted...!" << endl;
		else cout << "Account Number you entered does not exist..!";
	}
}
void LoanAccount::modify() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("LoanAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "File could not open.!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				char ch; cout << "\n\t1.Phone\n\t2.Address\n"; ch = _getch();
				if (ch == '1') { cout << "Enter New Phone Number: "; cin.ignore(); cin.getline(this->phone, 12); }
				if (ch == '2') { cout << "Enter New Address: "; cin.ignore(); cin.getline(this->Address, 50); }
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("LoanAccount.dat");
		rename("Temp.dat", "LoanAccount.dat");
		if (flag == true) cout << "Account has been modified...!";
		if (flag != true)cout << "Account Number you entered does not exist..!";
	}
}