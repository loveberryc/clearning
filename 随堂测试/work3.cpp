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
        cout << "学生:" << name << " 选课" << class_info << " 的分数为" << score << endl;
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
    
	cout<<"高分段学生共"<<high_cnt<<"个 学生信息："<<endl;
	printAll(highStus,high_cnt);
	
	cout<<"低分段学生共"<<low_cnt<<"个 学生信息："<<endl;
	printAll(lowStus,low_cnt); 
}


int Student::total_num = 0;
double Student::total_score = 0.0;

int main()
{
    Student ss[5] = {
        Student("张yi",70.0,"math"),
        Student("张er",90.5,"math"),
        Student("张san",40.8,"math"),
        Student("李si",89,"computer science"),
		Student("王wu",59.6,"Java") 
    };
    
    int max_index = getMax(ss);
    cout<<"最高分学生信息："<<endl;
    ss[max_index].print();
    cout<<endl;
    
    Student min = getMin(ss);
    cout<<"最低分学生信息："<<endl;
    min.print();
    cout<<endl;
    
    cout<<"统计信息："<<endl; 
    statistics(ss);
    cout<<endl;
    
    cout<<"所有学生信息："<<endl;
    printAll(ss,Student::getTotalNum());
    cout<<endl;
    
    cout<<"所有学生的平均分为："<<getAverage()<<endl; 
}
