#include<iostream>
using namespace std;
#include<fstream>
#include<conio.h>
#include"SavingAccount.h"
#include"Func.h"
CDate currDate;
void SavingAccount::CreateAccount(){
	Account::CreateAccount();
	cout << "Initial Balance (must be Rs.10000/- or more): "; 
	do {
		cin >> this->balance; if (this->balance < 10000) { cerr << "Re-Enter Balance: "; };
	} while (this->balance < 10000);
	this->interestRate = (this->balance * 10) / 100;
	cout << "Annual Interest Rate is 10%: " << this->interestRate << endl;
	this->upDate = this->DateOfAccountCreation;
	//writing to file.
	ofstream oFile("SavingAccount.dat", ios::binary | ios::app);
	if (!oFile) cerr << "Error in opening the file!";
	else{
		oFile.write((char*)this, sizeof(*this));
		cout << "Account has been created successfully..!";
	}
	oFile.close();
}
void SavingAccount::displayReport() {
	cout << "\nEnter Current Date: "; cin >> currDate;
	ifstream iFile("SavingAccount.dat", ios::binary | ios::in);
	if (!iFile)cerr << "Error in opening the file!";
	else {
		int i = 1;
		while (iFile.read((char*)this, sizeof(*this))) {
			int d = currDate - this->upDate;
			if (d >= 30) {
				this->balance += (d / 30)*(this->interestRate); //to calculate monthly interest
				this->upDate = currDate;
			}
			cout << "\n\nRecord No." << i << endl; i++;
			this->display();
			cout << endl;
		}
	}
	iFile.close();
}
void SavingAccount::display() {
	cout << "Name: " << this->Name << endl << "Father Name: " << this->FName << endl
		<< "Date of Birth: " << this->DOB << endl << "Gender: " << this->Gender << endl
		<< "CNIC: " << this->CNIC << endl
		<< "Account Number: " << this->accountNo << endl << "Balance: " << this->balance << endl
		<< "Contact: " << this->phone << endl << "Address: " << this->Address << endl
		<< "Date of Account Creation: " << this->DateOfAccountCreation << endl
		<< "Interest Rate (per month): " << this->interestRate << endl;
		cout << "Interest Updated on: " << this->upDate;
}
void SavingAccount::depositAmount(){
	char tmp[17]; bool flag = false; cin.ignore();
	cout << "\nEnter Account No.: "; cin.getline(tmp, 17);
	cout << "Enter Current Date: "; cin >> currDate;
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("SavingAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "Error in opening the file!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				int d = currDate - this->upDate;
				if (d >= 30) {
					this->balance += (d / 30)*(this->interestRate); //to calculate monthly interest
					this->upDate = currDate;
				}
				long deposit;
				cout << "Enter Amount you want to deposit: "; cin >> deposit;
				this->balance += deposit;
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("SavingAccount.dat");
		rename("Temp.dat", "SavingAccount.dat");
		if (flag == true) cout << "\tYour amount has been deposited...!";
		else { cout << "Account Number you entered does not exist..!" << endl; }
	}
}
void SavingAccount::withdraw(){
	char tmp[17]; bool flag = false; cin.ignore();
	cout << "\nEnter Account No.: "; cin.getline(tmp, 17);
	cout << "Enter Current Date: "; cin >> currDate;
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("SavingAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "File could not open.!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				int d = currDate - this->upDate;
				if (d >= 30) {
					this->balance += (d / 30)*(this->interestRate); //to calculate monthly interest
					this->upDate = currDate;
				}
				long withdraw;
				cout << "Enter Amount you want to deposit: "; do {
					cin >> withdraw;
					if ((this->balance - withdraw) < 10000) cout << "Your account balance must have at least Rs.10000/-\n"
						<< "or Enter 0 to exit: ";
				}while((this->balance - withdraw) < 10000);
				this->balance -= withdraw;
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("SavingAccount.dat");
		rename("Temp.dat", "SavingAccount.dat");
		if (flag == true) cout << "\tYour amount has been withdrawn...!";
		else { cout << "\n\tAccount Number you entered does not exist..!" << endl; }
	}
}
void SavingAccount::deleteAccount() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	char c;
	ofstream oFile("Temp.dat", ios::binary | ios::out);
	ifstream iFile("SavingAccount.dat", ios::binary);
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
		remove("SavingAccount.dat");
		rename("Temp.dat", "SavingAccount.dat");
		if (flag == true) cout << "Account has been permanently deleted...!" << endl;
		if(flag != true) cout << "Account Number you entered does not exist..!";
	}
}
void SavingAccount::modify(){
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("SavingAccount.dat", ios::binary | ios::in);
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
		remove("SavingAccount.dat");
		rename("Temp.dat", "SavingAccount.dat");
		if (flag == true) cout << "Account has been modified...!";
		else { cout << "Account Number you entered does not exist..!"; }
	}
}
void SavingAccount::displayAccount(){
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	cout << "Enter Current Date: "; cin >> currDate;
	ifstream iFile("SavingAccount.dat", ios::binary | ios::in);
	if (!iFile)cout << "File could not open!";
	else
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				int d = currDate - this->upDate;
				if (d >= 30) {
					this->balance += (d / 30)*(this->interestRate); //to calculate monthly interest
					this->upDate = currDate;
				}
				this->display();
				flag = true;
			}
		}
	if (flag != true)cout << "Account Number you entered does not exist..!";
	iFile.close();
}
void SavingAccount::balanceInquiry(){
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	cout << "Enter Current Date: "; cin >> currDate;
	ifstream iFile("SavingAccount.dat", ios::binary | ios::in);
	if (!iFile)cout << "File could not open!";
	else
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				int d = currDate - this->upDate;
				if (d >= 30) {
					this->balance += (d / 30)*(this->interestRate); //to calculate monthly interest
					this->upDate = currDate;
				}
				cout << "Name: " << this->Name << endl
					<< "Your Current Balance: " << this->balance << endl;
				flag = true;
			}
		}
	if (flag == false)cout << "Account Number you entered does not exist..!";
	iFile.close();
}