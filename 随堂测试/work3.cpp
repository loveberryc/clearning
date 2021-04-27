#include <iostream>
#include <string>
using namespace std;

#define MAX_NUM 100

class Student
{
private:
    string name;
    string class_info;
    double score;

    static double total_score;
    static int total_num;

public:
    Student() {};
    Student(string name, double score, string class_info)
    {
        this->name = name;
        this->score = score;
        this->class_info = class_info;

        total_score += score;
        total_num++;
    }
    double getScore() { return score; }
    void set(string name, double score) {
        this->name = name;
        this->score = score;
    }
    string getName() { return name; }
    void print()
    {
        cout << "ѧ��:" << name << " ѡ��" << class_info << " �ķ���Ϊ" << score << endl;
    }
    static double getTotalScore() {
        return total_score;
    }
    static int getTotalNum() {
        return total_num;
    }
};

int getMax(Student ss[]) {
    double max = 0.0;
    int tmp = -1;
    for (int i = 0; i < Student::getTotalNum(); i++) {
        if (ss[i].getScore() > max) {
            max = ss[i].getScore();
            tmp = i;
        }
    }
    return tmp;
}
Student getMin(Student* ss) {
    double min = 101.0;
    Student tmp;
    for (int i = 0; i < Student::getTotalNum(); i++) {
        if (ss[i].getScore() < min) {
            min = ss[i].getScore();
            tmp = ss[i];
        }
    }
    return tmp;
}
double getAverage() {
    return Student::getTotalScore() / Student::getTotalNum();
}

void printAll(Student ss[],int cnt){
    for(int i=0;i<cnt;i++){
		ss[i].print();
    }
}

void statistics(Student ss[]){
	Student lowStus[MAX_NUM];
	Student highStus[MAX_NUM];
	int low_cnt = 0;
	int high_cnt = 0;
	for(int i=0;i<Student::getTotalNum();i++){
		if(ss[i].getScore() > 85){
			highStus[high_cnt++] = ss[i];
		}
		if(ss[i].getScore() < 60){
			lowStus[low_cnt++] = ss[i];
		}
    }
    
	cout<<"�߷ֶ�ѧ����"<<high_cnt<<"�� ѧ����Ϣ��"<<endl;
	printAll(highStus,high_cnt);
	
	cout<<"�ͷֶ�ѧ����"<<low_cnt<<"�� ѧ����Ϣ��"<<endl;
	printAll(lowStus,low_cnt); 
}


int Student::total_num = 0;
double Student::total_score = 0.0;

int main()
{
    Student ss[5] = {
        Student("��yi",70.0,"math"),
        Student("��er",90.5,"math"),
        Student("��san",40.8,"math"),
        Student("��si",89,"computer science"),
		Student("��wu",59.6,"Java") 
    };
    
    int max_index = getMax(ss);
    cout<<"��߷�ѧ����Ϣ��"<<endl;
    ss[max_index].print();
    cout<<endl;
    
    Student min = getMin(ss);
    cout<<"��ͷ�ѧ����Ϣ��"<<endl;
    min.print();
    cout<<endl;
    
    cout<<"ͳ����Ϣ��"<<endl; 
    statistics(ss);
    cout<<endl;
    
    cout<<"����ѧ����Ϣ��"<<endl;
    printAll(ss,Student::getTotalNum());
    cout<<endl;
    
    cout<<"����ѧ����ƽ����Ϊ��"<<getAverage()<<endl; 
}
