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
	friend ostream& operator <<(ostream&, Date&);
	friend istream& operator >>(istream&, Date&);
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
istream& operator>>(istream& input, Date& d) {
	cout << "输入年，月，日：" << endl;
	input >> d.year >> d.month >> d.day;
	return input;
}
ostream& operator<<(ostream& output, Date& d) {
	output << "年：";
	output << d.year;
	output << "月：";
	output << d.month;
	output << "日：";
	output << d.day << endl;
	return output;
}
int main() {
	Date d1(2002,9,2);
	Date d2(3, 2, 20);
	d1 = d1 + d2;
	cout << d1;
	d2 = d1 - d2;
	cin >> d2;
	cout << d1;
	d2 = d2 + d1;
	cout << d2;
	return 0;
}
Date Date::operator>>(Date) {
	cout << "Äê£º";
	cin >> year;
	cout << "ÔÂ£º";
	cin >> month;
	cout << "ÈÕ£º";
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
