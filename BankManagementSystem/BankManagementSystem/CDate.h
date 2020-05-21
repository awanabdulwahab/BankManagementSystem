#ifndef CDate_HEADER
#define CDate_HEADER
class CDate {
private:
	int day, month, year;
	//static declaration
	static int count;
	static int died;
	static char strMon[12][4];
	static char stringMon[12][10];
	static int daysOfMonth[12];
	void validate();
	bool isLeapYear();
public:
	CDate();
	CDate(int, int, int); //constructor for object using in CDateTime
	void readFromKB();
	void print(int = 0)const;

	//setter functions
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);

	//getter functions
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	static int getNoOfObjects();
	static int getExistingObjects();

	//operator overloading...
	CDate& operator ++();
	CDate operator ++(int);
	CDate& operator --();
	CDate operator --(int);

	//relation operator overloading
	/*bool operator < (const CDate&)const;
	bool operator >= (const CDate&)const;
	bool operator > (const CDate&)const;
	bool operator <= (const CDate&)const;
	bool operator == (const CDate&)const;
	bool operator != (const CDate&)const;
	*/

	// friend functions, relation operator overloading
	friend bool operator < (const CDate&, const CDate&);
	friend bool operator >= (const CDate&, const CDate&);
	friend bool operator > (const CDate&, const CDate&);
	friend bool operator <= (const CDate&, const CDate&);
	friend bool operator == (const CDate&, const CDate&);
	friend bool operator != (const CDate&, const CDate&);

	//+ operator
	friend CDate operator +(CDate&, int);	//e.g date+40
	friend CDate operator +(int, CDate&);	//e.g 40+date
	friend CDate operator +=(CDate&, int);	//e.g date += 40
	//- operator
	friend CDate operator -(CDate&, int);	//e.g date-40
	friend CDate operator -=(CDate&, int);	//e.g date -= 40
	friend int operator -(CDate, CDate);	//e.g date1 - date2
											//<< operator - friend function operator overloadin
	friend ostream& operator<< (ostream&, const CDate&);
	friend istream& operator>> (istream&, CDate&);
	//file i/o
	void WriteToFile(ofstream&);
	void ReadFromFile(ifstream&);
	//~CDate();
};
#endif