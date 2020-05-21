#include<iostream>
#include<fstream>
using namespace std;
#include"CDate.h"
//static initialization
int CDate::count = 0;
int CDate::died = 0;
char CDate::strMon[12][4] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
char CDate::stringMon[12][10] = { "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int CDate::daysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//constructor-initializer list
CDate::CDate() : day(0), month(0), year(0) { ++count; }
//constructor paratmetrized definition
CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) { ++count; }

//validation
void CDate::validate() {
	if (this->month < 1 || this->month > 12 || this->day < 1)
		this->day = -1;
	else {
		if (this->isLeapYear())
			CDate::daysOfMonth[1] = 29;
		if (this->day > daysOfMonth[this->month - 1])
			this->day = -1;
	}
}
/*void CDate::validate() {
if (this->month < 1 || this->month > 12 || this->day < 1 || this->day > 31)
this->day = -1;
else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
if (this->day > 30)
this->day = -1;
}
else if (this->month == 2) {
if (isLeapYear()) {
if (this->day > 29)
this->day = -1;
}
else
if (this->day > 28)
this->day = -1;
}
}*/

bool CDate::isLeapYear() {
	if (this->year % 4 != 0)
		return false;
	else if (this->year % 100 != 0)
		return true;
	else if (this->year % 400 == 0)
		return true;
	else
		return false;
}

void CDate::setDay(int d) {
	this->day = d;
	this->validate();
}
void CDate::setMonth(int m) {
	this->month = m;
	this->validate();
}
void CDate::setYear(int y) {
	this->year = y;
	this->validate();
}
void CDate::setDate(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
	this->validate();
}

void CDate::readFromKB() {
	do {
		cout << "Enter date as dd mm yyyy: ";
		cin >> this->day >> this->month >> this->year;
		validate();
		if (this->day == -1)
			cout << "\a\aInvalid Date....!!!!\n";
	} while (this->day == -1);
}
void CDate::print(int option)const {
	if (option == 1) {
		cout << this->day << "-" << strMon[this->month - 1] << "-" << this->year;
	}
	else if (option == 2) {
		cout << stringMon[this->month - 1] << " " << this->day << "," << this->year;
	}
	else if (option == 3) {
		cout << "Day/s: " << this->day << "\tMonth/s: " << this->month << "\tYear/s: " << this->year;
	}
	else
		cout << this->day << "/" << this->month << "/" << this->year;
}

//getters definition
int CDate::getDay() const { return this->day; }
int CDate::getMonth() const { return this->month; }
int CDate::getYear() const { return this->year; }
int CDate::getNoOfObjects() { return count; }
int CDate::getExistingObjects() { return count - died; }

//File input/output
void CDate::WriteToFile(ofstream& oFile) {
	//for text file: oFile << this->day << ' ' << this->month << ' ' << this->year << endl;
	oFile.write((char*)this, sizeof(*this)); //binary file
}
void CDate::ReadFromFile(ifstream& inFile) {
	inFile.read((char*)this, sizeof(*this));
	//inFile >> this->day >>this->month >> this->year;
}

//destructor
//CDate::~CDate() { cout << "\nDestructor called for "; this->print(); ++died; }

//operator overloading..
CDate& CDate::operator ++() {
	++this->day;
	if (this->isLeapYear()) CDate::daysOfMonth[1] = 29; else CDate::daysOfMonth[1] = 28;
	if (CDate::daysOfMonth[this->month - 1] < this->day) {
		this->day = 1;
		++this->month;
		if (this->month > 12) {
			this->month = 1;
			++this->year;
		}
	}
	return *this;
}
CDate CDate::operator ++(int) {
	CDate tmp = *this;
	++this->day;
	if (this->isLeapYear()) CDate::daysOfMonth[1] = 29; else CDate::daysOfMonth[1] = 28;
	if (CDate::daysOfMonth[this->month - 1] < this->day) {
		this->day = 1;
		++this->month;
		if (this->month > 12) {
			this->month = 1;
			++this->year;
		}
	}
	return tmp;
}
CDate& CDate::operator -- () {
	--this->day;
	if (this->day < 1) {
		--this->month;
		if (this->month < 1) {
			--this->year;
			this->month = 12;
		}
		this->day = daysOfMonth[this->month - 1];
	}
	return *this;
}
CDate CDate::operator --(int) {
	CDate tmp = *this;
	--this->day;
	if (this->day < 1) {
		--this->month;
		if (this->month < 1) {
			--this->year;
			this->month = 12;
		}
		this->day = CDate::daysOfMonth[this->month - 1];
	}
	return tmp;
}

//relation operator overloading
/*bool CDate::operator < (const CDate& date)const {
if (this->year < date.year) return true;
if (this->year > date.year) return false;
if (this->month < date.month) return true;
if (this->month > date.month) return false;
if (this->day < date.day) return true;
return false;
}
bool CDate::operator >= (const CDate& date)const {
return !this->operator<(date);
//can be: !(*this).operator<(date)	or !(*this<date);
}
//Allaboration
bool CDate::operator >= (const CDate& date)const {
if (this->year > date.year) return true;
if (this->year < date.year) return false;
if (this->month > date.month)  return true;
if (this->month < date.month) return false;
if (this->day >= date.day) return true;
return false;
}


bool CDate::operator > (const CDate& date)const {
if (this->year > date.year) return true;
if (this->year < date.year) return false;
if (this->month > date.month)  return true;
if (this->month < date.month) return false;
if (this->day > date.day) return true;
return false;
}
bool CDate::operator <= (const CDate& date)const {
return !(*this>date);
}
//Allaboration
bool CDate::operator <= (const CDate& date)const {
if (this->year < date.year) return true;
if (this->year > date.year) return false;
if (this->month < date.month)  return true;
if (this->month > date.month) return false;
if (this->day <= date.day) return true;
return false;
}
bool CDate::operator == (const CDate& date)const {
if (this->year != date .year) return false;
if (this->month != date.month)  return false;
if (this->day != date.day) return false;
return true;
}
bool CDate::operator != (const CDate& date)const {
return !(*this).operator==(date);
}
//Allaboration...
bool CDate::operator != (const CDate& date)const {
if (this->year != date.year) return true;
if (this->month != date.month) return true;
if (this->day != date.day) return true;
return false;
}*/


// friend functions, relation operator overloading
bool operator < (const CDate& ldate, const CDate& rdate) {
	if (ldate.year < rdate.year) return true;
	if (ldate.year > rdate.year) return false;
	if (ldate.month < rdate.month) return true;
	if (ldate.month > rdate.month) return false;
	if (ldate.day < rdate.day) return true;
	return false;
}
bool operator >= (const CDate& ldate, const CDate& rdate) {
	return !(ldate < rdate);
}
bool operator > (const CDate& ldate, const CDate& rdate) {
	if (ldate.year > rdate.year) return true;
	if (ldate.year < rdate.year) return false;
	if (ldate.month > rdate.month) return true;
	if (ldate.month < rdate.month) return false;
	if (ldate.day > rdate.day) return true;
	return false;
}
bool operator <= (const CDate& ldate, const CDate& rdate) {
	return !operator>(ldate, rdate);
}
bool operator == (const CDate& ldate, const CDate& rdate) {
	if (ldate.year != rdate.year) return false;
	if (ldate.month != rdate.month) return false;
	if (ldate.day != rdate.day) return false;
	return true;
}
bool operator != (const CDate& ldate, const CDate& rdate) {
	return !operator==(ldate, rdate);
}

//+ operator like: obj+intg e.g date+40;
/*CDate operator +(CDate& date, int n) {
if (date.isLeapYear()) CDate::daysOfMonth[1] = 29;
else CDate::daysOfMonth[1] = 28;

date.day += n;
if (date.day > CDate::daysOfMonth[date.month - 1]) {
int tmp = date.day / CDate::daysOfMonth[date.month - 1];
if (date.day % CDate::daysOfMonth[date.month - 1] == 0) date.day = tmp;
else date.day %= CDate::daysOfMonth[date.month - 1];
date.month += tmp;
if (date.month > 12) {
date.year += date.month / 12;
if (date.month % 12 == 0) date.month /= 12;
else date.month %= 12;
}
}
return date;
}*/
CDate operator +(CDate& date, int n) {
	CDate tmp = date;
	tmp.day += n;
	if (tmp.isLeapYear()) CDate::daysOfMonth[1] = 29;
	else CDate::daysOfMonth[1] = 28;
	while (tmp.day > CDate::daysOfMonth[tmp.month - 1]) {
		tmp.day -= CDate::daysOfMonth[tmp.month - 1];
		++tmp.month;
		if (tmp.month > 12) {
			tmp.month = 1;
			++tmp.year;
			if (tmp.isLeapYear()) CDate::daysOfMonth[1] = 29;
			else CDate::daysOfMonth[1] = 28;
		}
	}
	return tmp;
}

// intg+obj	e.g 40+date;
CDate operator +(int n, CDate& date) {
	return date + n;
}
// obj += intg e.g date += 40;
CDate operator +=(CDate& date, int n) {
	date.day += n;
	if (date.isLeapYear()) CDate::daysOfMonth[1] = 29;
	else CDate::daysOfMonth[1] = 28;
	while (date.day > CDate::daysOfMonth[date.month - 1]) {
		date.day -= CDate::daysOfMonth[date.month - 1];
		++date.month;
		if (date.month > 12) {
			date.month = 1;
			++date.year;
			if (date.isLeapYear()) CDate::daysOfMonth[1] = 29;
			else CDate::daysOfMonth[1] = 28;
		}
	}
	return date;
}

//obj-intg e.g date-40
CDate operator -(CDate& date, int n) {
	CDate tmp = date;
	if (tmp.isLeapYear()) CDate::daysOfMonth[1] = 29;
	else CDate::daysOfMonth[1] = 28;

	tmp.day -= n;
	while (tmp.day < 1) {
		--tmp.month;
		if (tmp.month < 1) tmp.day += CDate::daysOfMonth[11]; //to add the days of dec
		else tmp.day += CDate::daysOfMonth[tmp.month - 1];
		if (tmp.month < 1) {
			tmp.month = 12;
			--tmp.year;
			if (tmp.isLeapYear()) CDate::daysOfMonth[1] = 29;
			else CDate::daysOfMonth[1] = 28;
		}
	}
	return tmp;
}
//obj-=intg e.g date-=40
CDate operator -=(CDate& date, int n) {
	if (date.isLeapYear()) CDate::daysOfMonth[1] = 29;
	else CDate::daysOfMonth[1] = 28;

	date.day -= n;
	while (date.day < 1) {
		--date.month;
		if (date.month < 1) date.day += CDate::daysOfMonth[11]; //to add the days of dec
		else date.day += CDate::daysOfMonth[date.month - 1];
		if (date.month < 1) {
			date.month = 12;
			--date.year;
			if (date.isLeapYear()) CDate::daysOfMonth[1] = 29;
			else CDate::daysOfMonth[1] = 28;
		}
	}
	return date;
}
// obj-obj  e.g date1-date2...
/*CDate operator -(CDate& date1, CDate& date2) {
CDate res;
if (date1 > date2) {
if (date1.isLeapYear()) CDate::daysOfMonth[1] = 29;
else CDate::daysOfMonth[1] = 28;
res.day = date1.day - date2.day;
if (res.day < 1) {
date1.day += CDate::daysOfMonth[date1.month - 1];
res.day = date1.day - date2.day;
--date1.month;
if (date1.month < 1) {
date1.month = 12;
--date1.year;
if (date1.isLeapYear()) CDate::daysOfMonth[1] = 29;
else CDate::daysOfMonth[1] = 28;
}
}
res.month = date1.month - date2.month;
if (res.month < 1) {
date1.month += 12;
res.month = date1.month - date2.month;
--date1.year;
if (date1.isLeapYear()) CDate::daysOfMonth[1] = 29;
else CDate::daysOfMonth[1] = 28;
}
res.year = date1.year - date2.year;
}
return res;
}*/
int operator -(CDate date1, CDate date2) {
	int res = 0;
	if (date1 > date2) {
		while (date1.year > date2.year) {
			++date2.year;
			if (date2.isLeapYear()) {
				res += 366;
			}
			else res += 365;
		}
		while (date1.month != date2.month) {
			if (date2.isLeapYear()) CDate::daysOfMonth[1] = 29;
			else CDate::daysOfMonth[1] = 28;
			if (date1.month < date2.month) {
				--date2.month;
				res -= CDate::daysOfMonth[date2.month - 1];
			}
			else {
				++date2.month;
				res += CDate::daysOfMonth[date2.month - 1];
			}
		}
		res += (date1.day - date2.day);
	}
	return res;
}

//friend function operator overloading...
ostream& operator<< (ostream& output, const CDate& obj) {
	output << obj.day << "/" << obj.month << "/" << obj.year;
	return output;
}
istream& operator>> (istream& input, CDate& obj) {
	cout << "(as dd mm yyyy): ";
	input >> obj.day >> obj.month >> obj.year;
	return input;
}