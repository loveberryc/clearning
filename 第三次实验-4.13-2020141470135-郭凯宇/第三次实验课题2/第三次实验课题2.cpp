#include <iostream>
using namespace std;
class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h, int m, int s);
	Time operator+(Time t1);
	Time operator-(Time t1);
	friend ostream& operator <<(ostream&, Time&);
	friend istream& operator >>(istream&, Time&);
};
Time::Time(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}
Time Time::operator+(Time t1) {
	hour += t1.hour;
	minute += t1.minute;
	second += t1.second;
	return *this;
}
Time Time::operator-(Time t1) {
	hour -= t1.hour;
	minute -= t1.minute;
	second -= t1.second;
	return *this;
}
istream& operator>>(istream& input, Time& t) {
	cout << "输入时，分，秒：" << endl;
	input >> t.hour >> t.minute >> t.second;
	return input;
}
ostream& operator<<(ostream& output, Time& t) {
	output << "时：";
	output << t.hour;
	output << "分：";
	output << t.minute;
	output << "秒：";
	output << t.second << endl;
	return output;
}
int main() {
	Time t1(3, 8, 34);
	Time t2(4, 21, 11);
	t1 = t1 + t2;
	t2 = t2 + t1;
	cout << t1;
	cout << t2;
	cin >> t1;
	t2 = t1 + t2;
	cout << t2;
	return 0;
}
