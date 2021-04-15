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
		cout << "��ʾ�������ݣ�\n" << endl;
		cout << "������" << name << endl;
		cout << "ѧ�ţ�" << num << endl;
		cout << "��ѧ�ɼ���" << mathScore << endl;
		cout << "Ӣ��ɼ���" << englishScore << endl << endl;

	}
	static void ShowStatic() {
		cout << "��ʾ��̬���ݣ�\n" << endl;
		cout << "��������" << count << endl;
		cout << "��ѧ�ܳɼ���" << mathTotalScore << endl;
		cout << "Ӣ���ܳɼ���" << englishTotalScore << endl;

	}
};
int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;
















#endif