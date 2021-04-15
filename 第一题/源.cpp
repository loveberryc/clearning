#include <iostream>
#include <string.h>
using namespace std;
const int LEN = 18;
class Person {
protected:
	char name[LEN];
	int age;
	char sex[LEN];
public:
	Person(const char* nm, int ag,const char* sx) {
		strcpy(name,nm);
		age = ag;
		strcpy(sex,sx);
	}
	void Show() {
		cout << "姓名：" << name << "年龄：" << age << "性别" << sex << endl;
	}
};
class Teacher:virtual public Person {
protected:
	char title[LEN];
public:
	Teacher(const char* n, int a,const char* s,const char* t) :Person(n, a, s) {
		strcpy(title , t);
	}
	void Show() {
		cout << "姓名：" << name << "年龄：" << age << "性别:" << sex <<"职称:"<<title<< endl;
	}
};
class Cadre:virtual public Person{
protected:
	char post[LEN];
public:
	Cadre(const char* n, int a, const char* s, const char* p) :Person(n, a, s) {
		strcpy(post , p);
	}
    void Show(){
		cout << "姓名：" << name << "年龄：" << age << "性别:" << sex << "职务"<< post << endl;
	}
};
class TeacherCadre:public Teacher, public Cadre {
private:
	int wages;
public:
	TeacherCadre(const char* n, int a, const char* s, const char* t,const char* p, int w) :Person(n, a, s), Teacher(n, a, s,t), Cadre(n, a, s,p) {
		wages = w;
	}
	void Show() {
		cout << "姓名:" << name << "年龄:" << age << " 性别:" << sex <<"职称:"<<title<< "职务:" << post <<"工资:"<<wages<< endl;
	}
};
int main() {
	TeacherCadre tc("刘谋 ",30,"男 ","教授 ","老师 ",5000);
	tc.TeacherCadre::Show();
	return 0;
}
