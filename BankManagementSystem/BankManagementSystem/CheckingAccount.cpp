#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include"CheckingAccount.h"
#include"Func.h"
void CheckingAccount::CreateAccount() {
	Account::CreateAccount();
	cout << "Initial Balance(optional, maybe 0): "; cin >> this->balance;
	cout << "Over Draft Credit Limit: "; cin >> this->creditLimit; 
	this->overdraftFee = this->creditLimit / 100;
	cout << "Overdraft Fee becomes: " << this->overdraftFee <<endl;
	ofstream outFile("CheckingAccount.dat", ios::binary | ios::app);
	if (!outFile) cout << "Error in opening the file!";
	else {
		outFile.write((char*)this, sizeof(*this));
		cout << "Your account has been created successfully....!!\n\n";
		outFile.close();
	}
}
void CheckingAccount::displayReport() {
	ifstream iFile("CheckingAccount.dat", ios::binary | ios::in);
	if (!iFile)cout << "Error in opening the file!";
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
void CheckingAccount::display() {
	cout << "Name: " << this->Name << endl << "Father Name: " << this->FName<< endl
		<< "Date of Birth: " << this->DOB << endl << "Gender: " << this->Gender << endl
		<< "CNIC: " << this->CNIC << endl 
		<<"Account Number: " << this->accountNo << endl << "Balance: " << this->balance << endl
		<< "Contact: " << this->phone << endl<< "Address: " << this->Address << endl
		<< "Date of Account Creation: " << this->DateOfAccountCreation << endl
		<< "Credit Limit: " << this->creditLimit << endl << "Overdraft Fee: " << this->overdraftFee << endl;
}
void CheckingAccount::depositAmount() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("CheckingAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "Error in opening the file!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				long deposit;
				cout << "Enter Amount you want to deposit: "; cin >> deposit;
				this->balance += deposit;
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("CheckingAccount.dat");
		rename("Temp.dat", "CheckingAccount.dat");
		if (flag == false) cout << "Account Number you entered does not exist..!" << endl;
	}
}
void CheckingAccount::withdraw() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("CheckingAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "Error in opening the file!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				long withdraw; flag = true;
				cout << "Enter Amount you want to withdraw: "; cin >> withdraw;
				long temp = this->balance - withdraw;
				if ((temp) > 0) this->balance = temp;
				else if ((this->balance - withdraw) >= (-this->creditLimit)) 
					this->balance = temp - this->overdraftFee;
				else { cout << "Sorry..! Your account balance is less than credit limit.\n"; }
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("CheckingAccount.dat");
		rename("Temp.dat", "CheckingAccount.dat");
		if (flag == false) cout << "Account Number you entered does not exist..!" << endl;
	}
}
void CheckingAccount::modify() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ofstream oFile("Temp.dat", ios::binary | ios::app);
	ifstream iFile("CheckingAccount.dat", ios::binary | ios::in);
	if (!iFile) cout << "File could not open.!";
	else {
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				char ch; cout << "\n\t1.Phone\n\t2.Address\n"; ch = _getch();
				if (ch == '1'){ cout << "Enter New Phone Number: "; cin.ignore(); cin.getline(this->phone, 12); }
				if (ch == '2') { cout << "Enter New Address: "; cin.ignore(); cin.getline(this->Address, 50); }
				flag = true;
			}
			oFile.write((char*)this, sizeof(*this));
		}
		oFile.close(); iFile.close();
		remove("CheckingAccount.dat");
		rename("Temp.dat", "CheckingAccount.dat");
		if (flag == true) cout << "Account has been modified...!" << endl;
		if (flag != true)cout << "Account Number you entered does not exist..!";
	}
}
void CheckingAccount::displayAccount() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ifstream iFile("CheckingAccount.dat", ios::binary | ios::in);
	if (!iFile)cout << "Error in opening the file!";
	else
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				this->display();
				flag = true;
			}
		}
	if (flag == false)
	{
		cout << "Account Number you entered does not exist..!";
	}
	iFile.close();
}
void CheckingAccount::balanceInquiry() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	ifstream iFile("CheckingAccount.dat", ios::binary | ios::in);
	if (!iFile)cout << "Error in opening the file!";
	else
		while (iFile.read((char*)this, sizeof(*this))) {
			if (chrcmp(this->accountNo, tmp)) {
				cout << "Name: " << this->Name << endl
					<< "Your Current Balance: " << this->balance << endl;
				flag = true;
			}
		}
	if (flag == false) {
		cout << "Account Number you entered does not exist..!";
	}
		iFile.close();
}
bool chrcmp(char a[], char b[]) {
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}
void CheckingAccount::deleteAccount() {
	char tmp[17]; bool flag = false;
	cout << "Enter Account No.: "; cin.getline(tmp, 17);
	char c;
	ofstream oFile("Temp.dat", ios::binary | ios::out);
	ifstream iFile("CheckingAccount.dat", ios::binary);
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
		remove("CheckingAccount.dat");
		rename("Temp.dat", "CheckingAccount.dat");
		if (flag == true) cout << "Account has been permanently deleted...!" << endl;
		else cout << "Account Number you entered does not exist..!";
	}
}
