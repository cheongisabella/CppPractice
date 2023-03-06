#include <iostream>
#include <string>
//#define TEST_PROGRAM
#ifdef TEST_PROGRAM

using namespace std;

class Date {
public:
	Date(int m, int d, int y)
	: day(d), year(y) {
		setMonth(m);
	}

	void setMonth(int m) {
		if (m >= 1 && m <= 12) {
			month = m;
		}
		else {
			cerr << m << " is not a valid month. m has to be in the range 1-12." << endl;
		}
	}
	void setDay(int d) {
		day = d;
	}
	void setYear(int y) {
		year = y;
	}

	int getMonth() const {
		return month;
	}
	int getDay() const {
		return day;
	}
	int getYear() const {
		return year;
	}

	void displayDate() const {
		cout << "The date is: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
	}

private:
	int month;
	int day;
	int year;
};

int main() {
	Date date(9, 23, 1997);
	date.displayDate();

	date.setDay(11);
	date.setMonth(12);
	date.setYear(1989);
	date.displayDate();

	date.setMonth(13);
	date.displayDate();

	date.setMonth(-1);
	date.displayDate();

	date.setMonth(5);
	date.displayDate();
}

#endif