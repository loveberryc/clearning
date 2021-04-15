#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Student
{
private:
	int num;
	int mathScore;
	int englishScore;
	static int count;
	static int mathTotalScore;
	static int englishTotalScore;
	char name[18];
public:
	Student(const char* nm, int nu, int math, int english) {
		strcpy_s(name, nm);
		num = nu;
		mathScore = math;
		englishScore = english;
		count++; 
		mathTotalScore += math; 
		englishTotalScore += english; 
	}
	void ShowBase() {
		cout << "显示基本数据：\n" << endl;
		cout << "姓名：" << name << endl;
		cout << "学号：" << num << endl;
		cout << "数学成绩：" << mathScore << endl;
		cout << "英语成绩：" << englishScore << endl << endl;

	}
	static void ShowStatic() {
		cout << "显示静态数据：\n" << endl;
		cout << "总人数：" << count << endl;
		cout << "数学总成绩：" << mathTotalScore << endl;
		cout << "英语总成绩：" << englishTotalScore << endl;

	}
};
int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;
















#endif