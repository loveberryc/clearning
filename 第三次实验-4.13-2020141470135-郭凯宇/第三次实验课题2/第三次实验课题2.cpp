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
	void operator<<(Time t1);
	Time operator>>(Time t1);
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
void Time::operator<<(Time) {
	cout << hour << "时 " << minute << "分 " << second << "秒 " << endl;
}
Time Time::operator>>(Time) {
	cout << "时：";
	cin >> hour;
	cout << "分：";
	cin >> minute;
	cout << "秒：";
	cin >> second;
	return *this;
}
int main() {
	Time t1(3, 8, 34);
	Time t2(4, 21, 11);
	t1 = t1 + t2;
	t2 = t2 + t1;
	t1 << t1;
	t2 << t2;
	t1 >> t1;
	t2 = t1 + t2;
	t2 << t2;
	return 0;
}