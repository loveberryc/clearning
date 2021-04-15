#include <iostream>
#include <string.h>
using namespace std;
const int LEN = 18;
class Staff {
protected:
	float num;
	char name[LEN];
	float rateOfAttend;
	float basicSal;
	float prize;
private:
	float Wage;
public:
	Staff(float nu, const char* nm, float roa, float bs, float prz) {
		num = nu;
		strcpy(name, nm);
		rateOfAttend = roa;
		basicSal = bs;
		prize = prz;
	}
	void Output() {
		cout << "���:" << num << "����:" << name << "������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << "����:" << prize << endl;
	}
	void OutputWage() {
		Wage = basicSal + prize * rateOfAttend;
		cout << "ʵ������:" << Wage << endl;
	}
};
class Saleman :virtual public Staff {
protected:
	float deductRate;
	float personAmount;
private:
	float Wage;
public:
	Saleman(float nu, const char* nm, float roa, float bs, float prz, float dr, float pa) :Staff(nu, nm, roa, bs, prz) {
		deductRate = dr;
		personAmount = pa;
	}
	void Output() {
		cout << "���:" << num << "����:" << name << "������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << "����:" << prize << endl;
		cout << "����Ա��ɱ���:" << deductRate << "�������۶�:" << personAmount << endl;
	}
	void OutputWage() {
		Wage = basicSal + prize * rateOfAttend + deductRate * personAmount;
		cout << "ʵ������:" << Wage << endl;
	}
};
class Manager :virtual public Staff {
protected:
	float totalDeductRate;
	float totalAmount;
private:
	float Wage;
public:
	Manager(float nu, const char* nm, float roa, float bs, float prz, float tdr, float ta) :Staff(nu, nm, roa, bs, prz) {
		totalDeductRate = tdr;
		totalAmount = ta;
	}
	void Output() {
		cout << "���:" << num << "����:" << name << "������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << "����:" << prize << endl;
		cout << "������ɱ���:" << totalDeductRate << "�����۶�:" << totalAmount << endl;
	}
	void OutputWage() {
		Wage = basicSal + prize * rateOfAttend + totalDeductRate * totalAmount;
		cout << "ʵ������:" << Wage << endl;
	}
};
class SaleManager :public Saleman, public Manager {
public:
	SaleManager(float nu, const char* nm, float roa, float bs, float prz, float dr, float pa, float tdr, float ta) :Staff(nu, nm, roa, bs, prz),Saleman(nu, nm, roa, bs, prz, dr, pa), Manager(nu, nm, roa, bs, prz, tdr, ta) {
	}
	void Output() {
		cout << "���:" << num << "����:" << name << "������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << "����:" << prize << endl;
		cout << "����Ա��ɱ���:" << deductRate << "�������۶�:" << personAmount << endl;
		cout << "������ɱ���:" << totalDeductRate << "�����۶�:" << totalAmount << endl;
	}
	void OutputWage() {
		cout << "��������:" << basicSal + prize * rateOfAttend + deductRate * personAmount + totalDeductRate * totalAmount << endl;
	}
};
int main() {
	SaleManager sm(123, "����", 0.89, 3000, 2000, 0.2, 500, 0.3, 1000);
	sm.SaleManager::Output();
	sm.SaleManager::OutputWage();
	return 0;
}
