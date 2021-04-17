#include <iostream>
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d);
	Date operator+(Date d1);
	Date operator-(Date d1);
	void operator<<(Date);
	Date operator>>(Date);
};

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
Date Date::operator+(Date d1) {
	day += d1.day;
	month += d1.month;
	year += d1.year;
	return *this;
}
Date Date::operator-(Date d1) {
	day -= d1.day;
	month -= d1.month;
	year -= d1.year;
	return *this;
}
void Date::operator<<(Date){
	cout << year << "年 " << month << "月 " << day << "日" << endl;
}
Date Date::operator>>(Date) {
	cout << "年：";
	cin >> year;
	cout << "月：";
	cin >> month;
	cout << "日：";
	cin >> day;
	return *this;
}

int main() {
	Date d1(2002,9,2);
	Date d2(3, 2, 20);
	d1 = d1 + d2;
	d1 << d1;
	d2 = d1 - d2;
	d2 << d2;
	d1 >> d1;
	d2 = d2 + d1;
	d2 << d2;
	return 0;
}