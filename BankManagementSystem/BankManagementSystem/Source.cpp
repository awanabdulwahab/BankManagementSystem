#include<iostream>
using namespace std;
#include<Windows.h>
#include"CheckingAccount.h"
#include"SavingAccount.h"
#include"LoanAccount.h"
#include"Func.h"
int main() {
	CheckingAccount c;
	SavingAccount s;
	LoanAccount l;
	int option, select, choice;
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t**					   **" << endl;
	cout << "\t\t\t\t**	Bank Management System		   **" << endl;
	cout << "\t\t\t\t**					   **" << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	
	cout << "1- Customer " << endl;
	cout << "2- Manager" << endl;
	cout << "3- Exit" << endl << endl;
	cout << "Choose an Option : ";
	cin >> option;
	system("cls");
	switch (option)
	{
	case 1:
		cout << "1- Checking Account " << endl;
		cout << "2- Saving Account " << endl;
		cout << "3- Loan Account " << endl;
		cout << "4- Exit" << endl;
		cout << "Choose Account Type : ";
		cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
				cout << "1- Deposit " << endl;
				cout << "2- Wihthdraw " << endl;
				cout << "3- Balance Inquiry " << endl;
				cout << "4- Account Details " << endl;
				cout << "5- Exit" << endl;
				cout << "Select an Option: ";
				cin >> choice;
				system("cls");
				switch (choice)
				{
				case 1:
					cin.ignore();
					c.depositAmount();
					break;
				case 2:
					cin.ignore();
					c.withdraw();
					break;
				case 3:
					cin.ignore();
					c.balanceInquiry();
					break;
				case 4:
					cin.ignore();
					c.displayAccount();
					break;
				case 5:
					break;
				default:
					cout << "Invalid Input...!" << endl;
					Sleep(2000);
					system("cls");
					main();
					break;
				}
				break;

		case 2:
			cout << "1- Deposit " << endl;
			cout << "2- Wihthdraw " << endl;
			cout << "3- Balance Inquiry " << endl;
			cout << "4- Account Details " << endl;
			cout << "5- Exit" << endl;
			cout << "Select an Option: ";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				cin.ignore();
				s.depositAmount();
				break;
			case 2:
				cin.ignore();
				s.withdraw();
				break;
			case 3:
				cin.ignore();
				s.balanceInquiry();
				break;
			case 4:
				cin.ignore();
				s.displayAccount();
				break;
			case 5:
				break;
			default:
				cout << "Invalid Input...!" << endl;
				Sleep(2000);
				system("cls");
				main();
				break;
			}
			break;
		case 3:
			cout << "1- Return Loan " << endl;
			cout << "2- Balance Inquiry " << endl;
			cout << "3- Account Details " << endl;
			cout << "4- Exit" << endl;
			cout << "Select an Option: ";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				cin.ignore();
				l.ReturnLoan();
				break;
			case 2:
				cin.ignore();
				l.balanceInquiry();
				break;
			case 3:
				cin.ignore();
				l.displayAccount();
				break;
			case 4:
				break;
			default:
				cout << "Invalid Input...!" << endl;
				Sleep(2000);
				system("cls");
				main();
				break;
			}
			break;
		case 4:
			break;
		default:
			cout << "Invalid Input...!" << endl;
			Sleep(2000);
			system("cls");
			main();
			break;
		}
		break;
	case 2:
		cout << "1- Create Account " << endl;
		cout << "2- Modify Account " << endl;
		cout << "3- Delete Account " << endl;
		cout << "4- Display Account " << endl;
		cout << "5- Report" << endl;
		cout << "6- Exit" << endl;
		cout << "Choose Your Choice: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "1- Checking Account " << endl;
			cout << "2- Saving Account " << endl;
			cout << "3- Loan Account " << endl;
			cout << "4- Exit" << endl;
			cout << "Choose Account Type : ";
			cin >> select;
			system("cls");
			switch (select)
			{
				case 1:
					cin.ignore();
					c.CreateAccount();
					break;
				case 2:
					cin.ignore();
					s.CreateAccount();
					break;
				case 3:
					cin.ignore();
					l.CreateAccount();
					break;
				case 4:
					break;
				default:
					cout << "Invalid Input...!" << endl;
					Sleep(2000);
					system("cls");
					main();
				break;
			}
			break;
		case 2:
			cout << "1- Checking Account " << endl;
			cout << "2- Saving Account " << endl;
			cout << "3- Loan Account " << endl;
			cout << "4- Exit" << endl;
			cout << "Choose Account Type : ";
			cin >> select;
			system("cls");
			switch (select)
			{
			case 1:
				cin.ignore();
				c.modify();
				break;
			case 2:
				cin.ignore();
				s.modify();
				break;
			case 3:
				cin.ignore();
				l.modify();
				break;
			case 4:
				break;
			default:
				cout << "Invalid Input...!" << endl;
				Sleep(2000);
				system("cls");
				main();
				break;
			}
			break;
		case 3:
			cout << "1- Checking Account " << endl;
			cout << "2- Saving Account " << endl;
			cout << "3- Loan Account " << endl;
			cout << "4- Exit" << endl;
			cout << "Choose Account Type : ";
			cin >> select;
			system("cls");
			switch (select)
			{
			case 1:
				cin.ignore();
				c.deleteAccount();
				break;
			case 2:
				cin.ignore();
				s.deleteAccount();
				break;
			case 3:
				cin.ignore();
				l.deleteAccount();
			case 4:
				break;
			default:
				cout << "Invalid Input...!" << endl;
				Sleep(2000);
				system("cls");
				main();
				break;
			}
			break;
		case 4:
			cout << "1- Checking Account " << endl;
			cout << "2- Saving Account " << endl;
			cout << "3- Loan Account " << endl;
			cout << "4- Exit" << endl;
			cout << "Choose Account Type : ";
			cin >> select;
			system("cls");
			switch (select)
			{
			case 1:
				cin.ignore();
				c.displayAccount();
				break;
			case 2:
				cin.ignore();
				s.displayAccount();
				break;
			case 3:
				cin.ignore();
				l.displayAccount();
				break;
			case 4:
				break;
			default:
				cout << "Invalid Input...!" << endl;
				Sleep(2000);
				system("cls");
				main();
				break;
			}
			break;
		case 5:
			cout << "1- Checking Account " << endl;
			cout << "2- Saving Account " << endl;
			cout << "3- Loan Account " << endl;
			cout << "4- Exit" << endl;
			cout << "Choose Account Type : ";
			cin >> select;
			system("cls");
			switch (select)
			{
			case 1:
				cin.ignore();
				c.displayReport();
				break;
			case 2:
				cin.ignore();
				s.displayReport();
				break;
			case 3:
				cin.ignore();
				l.displayReport();
				break;
			case 4:
				break;
			default:
				cout << "Invalid Input...!" << endl;
				Sleep(2000);
				system("cls");
				main();
				break;
			}
			break;
		case 6:
			break;
		default:
			cout << "Invalid Input...!" << endl;
			Sleep(2000);
			system("cls");
			main();
			break;
		}
		break;
	case 3:
		break;
	default:
		cout << "Invalid Input...!"<<endl;
		Sleep(2000);
		system("cls");
		main();
		break;
	}
	system("pause");
	return 0;
}