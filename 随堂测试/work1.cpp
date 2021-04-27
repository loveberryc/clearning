#include<iostream>

using namespace std;

class Staff{
	public:
		 int num;
		 Staff(){}
		 Staff(int nu): num(nu){}
		 virtual void OutputWage(){}
};

class Saleman : virtual public Staff{
	public:
		Saleman(){}
		Saleman(int nu):Staff(nu){}
		void OutputWage(){
		 	cout<<"销售员的实发工资为"<<Staff::num<<endl;
		}
};

class Manager : virtual public Staff{
	public:
		Manager(){}
		Manager(int nu):Staff(nu){}
		void OutputWage(){
		 	cout<<"经理的实发工资为"<<Staff::num<<endl;
		}
};

class Administrator : public Staff{
	public:
		Administrator(int nu): Staff(nu){}
		void OutputWage(){
		 	cout<<"行政人员的实发工资为"<<Staff::num<<endl;
		}
};

class SaleManager : public Saleman, public Manager
{		
	public:
		int sa;
		SaleManager(int nu): sa(nu){}
		void OutputWage(){
		 	cout<<"销售经理的实发工资为"<<sa<<endl;
		};
};

void function(Staff* s){
	s->OutputWage();
} 


int main(){
	Staff *s1 = new Saleman(100);
	Staff *s2 = new Manager(200);
	Staff *s3 = new Administrator(300);
	Staff *s4 = new SaleManager(400);
	
	function(s1);
	function(s2);
	function(s3);
	function(s4);
} 
