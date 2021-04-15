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
		cout << "������" << name << "���䣺" << age << "�Ա�" << sex << endl;
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
		cout << "������" << name << "���䣺" << age << "�Ա�:" << sex <<"ְ��:"<<title<< endl;
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
		cout << "������" << name << "���䣺" << age << "�Ա�:" << sex << "ְ��"<< post << endl;
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
		cout << "����:" << name << "����:" << age << " �Ա�:" << sex <<"ְ��:"<<title<< "ְ��:" << post <<"����:"<<wages<< endl;
	}
};
int main() {
	TeacherCadre tc("��ı ",30,"�� ","���� ","��ʦ ",5000);
	tc.TeacherCadre::Show();
	return 0;
}
