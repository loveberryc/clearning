#ifndef _PEOPLE_H_
#define _PEOPLE_H_
#include <iostream>
using namespace std;
class People
{
protected:
	int age;
	int height;
	int weight;
	static int num;
public:
	People(int a, int h, int w) {
		age = a;
		height = h;
		weight = w;
		num += 1;
	}
	void Eating() {
		weight += 1;
	}
	void Sporting() {
		height += 1;
	}
	void Sleeping() {
		age += 1;
		weight += 1;
		height += 1;
	}
	void Show() {
		cout <<age<<" "<<height<<" "<<weight<<" " << endl;
	}
	static void ShowNum() {
		cout<<num<<endl;
	}
};
int People::num = 0;

#endif
