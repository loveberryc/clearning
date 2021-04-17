#include <iostream>
#include <string.h> 
#define float double
using namespace std;
const int LEN = 18;
class Staff {
protected:
	float num;
	char name[LEN];
	float rateOfAttend;
	float basicSal;
	float prize;
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
		cout << "ʵ������:" << basicSal + prize * rateOfAttend << endl;
	}
};
class Saleman :virtual public Staff {
protected:
	float deductRate;
	float personAmount;
public:
	Saleman(float nu, const char* nm, float roa, float bs, float prz, float dr, float pa) :Staff(nu, nm, roa, bs, prz) {
		deductRate = dr;
		personAmount = pa;
	}
	void Output() {
		cout << "���:" << num << " ����:" << name << " ������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << " ����:" << prize << endl;
		cout << "����Ա��ɱ���:" << deductRate << " �������۶�:" << personAmount << endl;
	}
	void OutputWage() {
		cout << "ʵ������:" << basicSal + prize * rateOfAttend + deductRate * personAmount << endl;
	}
};
class Manager :virtual public Staff {
protected:
	float totalDeductRate;
	float totalAmount;
public:
	Manager(float nu, const char* nm, float roa, float bs, float prz, float tdr, float ta) :Staff(nu, nm, roa, bs, prz) {
		totalDeductRate = tdr;
		totalAmount = ta;
	}
	void Output() {
		cout << "���:" << num << " ����:" << name << " ������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << " ����:" << prize << endl;
		cout << "������ɱ���:" << totalDeductRate << " �����۶�:" << totalAmount << endl;
	}
	void OutputWage() {
		cout << "ʵ������:" << basicSal + prize * rateOfAttend + totalDeductRate * totalAmount << endl;
	}
};
class SaleManager :public Saleman, public Manager {
public:
	SaleManager(float nu, const char* nm, float roa, float bs, float prz, float dr, float pa, float tdr, float ta) :Staff(nu, nm, roa, bs, prz),Saleman(nu, nm, roa, bs, prz, dr, pa), Manager(nu, nm, roa, bs, prz, tdr, ta) {
	}
	void Output() {
		cout << "���:" << num << " ����:" << name << " ������:" << rateOfAttend << endl;
		cout << "��������:" << basicSal << " ����:" << prize << endl;
		cout << "����Ա��ɱ���:" << deductRate << " �������۶�:" << personAmount << endl;
		cout << "������ɱ���:" << totalDeductRate << " �����۶�:" << totalAmount << endl;
	}
	void OutputWage() {
		cout << "��������:" << basicSal + prize * rateOfAttend + deductRate * personAmount + totalDeductRate * totalAmount << endl;
	}
};
int main() {
	SaleManager sm(123, "����", 0.89, 3000, 2000, 0.2, 500, 0.3, 1000);
	Staff sta(100, "����", 0.93, 2000, 200);
	Saleman sam(101, "����", 0.92, 2500, 500, 0.2, 500);
	Manager mn(102,"����", 0.91, 3000, 1000, 0.3, 1000);
	sm.SaleManager::Output();
	sm.SaleManager::OutputWage();//����Ϊ��������
	Staff* st;
	int a = 0;
	cout << "����1:SaleManger" << endl;
	cout << "����2:Manager" << endl;
	cout << "����3:SaleManager" << endl;
	cout << "����4:Staff" << endl;
	cin >> a;
	switch (a) {
	case 1:
		st = &sm;
		st->Output();
		st->OutputWage();
		break;
	case 2:
		st = &mn;
		st->Output();
		st->OutputWage();
		break;
	case 3:
		st = &sm;
		st->Output();
		st->OutputWage();
		break;
	case 4:
		st = &sta;
		st->Output();
		st->OutputWage();
		break;
	default:
		cout << "error" << endl;
	}
	return 0;
}
