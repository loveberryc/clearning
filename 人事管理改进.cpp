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
		cout << "编号:" << num << "姓名:" << name << "出勤率:" << rateOfAttend << endl;
		cout << "基本工资:" << basicSal << "奖金:" << prize << endl;
	}
	void OutputWage() {
		cout << "实发工资:" << basicSal + prize * rateOfAttend << endl;
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
		cout << "编号:" << num << " 姓名:" << name << " 出勤率:" << rateOfAttend << endl;
		cout << "基本工资:" << basicSal << " 奖金:" << prize << endl;
		cout << "销售员提成比例:" << deductRate << " 个人销售额:" << personAmount << endl;
	}
	void OutputWage() {
		cout << "实发工资:" << basicSal + prize * rateOfAttend + deductRate * personAmount << endl;
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
		cout << "编号:" << num << " 姓名:" << name << " 出勤率:" << rateOfAttend << endl;
		cout << "基本工资:" << basicSal << " 奖金:" << prize << endl;
		cout << "经理提成比例:" << totalDeductRate << " 总销售额:" << totalAmount << endl;
	}
	void OutputWage() {
		cout << "实发工资:" << basicSal + prize * rateOfAttend + totalDeductRate * totalAmount << endl;
	}
};
class SaleManager :public Saleman, public Manager {
public:
	SaleManager(float nu, const char* nm, float roa, float bs, float prz, float dr, float pa, float tdr, float ta) :Staff(nu, nm, roa, bs, prz),Saleman(nu, nm, roa, bs, prz, dr, pa), Manager(nu, nm, roa, bs, prz, tdr, ta) {
	}
	void Output() {
		cout << "编号:" << num << " 姓名:" << name << " 出勤率:" << rateOfAttend << endl;
		cout << "基本工资:" << basicSal << " 奖金:" << prize << endl;
		cout << "销售员提成比例:" << deductRate << " 个人销售额:" << personAmount << endl;
		cout << "经理提成比例:" << totalDeductRate << " 总销售额:" << totalAmount << endl;
	}
	void OutputWage() {
		cout << "基本工资:" << basicSal + prize * rateOfAttend + deductRate * personAmount + totalDeductRate * totalAmount << endl;
	}
};
int main() {
	SaleManager sm(123, "李四", 0.89, 3000, 2000, 0.2, 500, 0.3, 1000);
	Staff sta(100, "张三", 0.93, 2000, 200);
	Saleman sam(101, "郭五", 0.92, 2500, 500, 0.2, 500);
	Manager mn(102,"赵六", 0.91, 3000, 1000, 0.3, 1000);
	sm.SaleManager::Output();
	sm.SaleManager::OutputWage();//下面为新增内容
	Staff* st;
	int a = 0;
	cout << "输入1:SaleManger" << endl;
	cout << "输入2:Manager" << endl;
	cout << "输入3:SaleManager" << endl;
	cout << "输入4:Staff" << endl;
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
