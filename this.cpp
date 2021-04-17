#include<iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Person {
public:
    typedef enum {
        BOY = 0,
        GIRL
    }SexType;
    Person(const char* n, int a, SexType s) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);//strcpy_s安全版本最好三个参数才能通过调试（VS）
        age = a;
        sex = s;
    }
    int get_age() const {

        return this->age;
    }
    Person&add_age(int a) {
        age += a;
        return *this;
    }
    ~Person() {
        delete[] name;
    }
private:
    char* name;
    int age;
    SexType sex;
};


int main() {
    Person p("zhangsan", 20, Person::BOY);
    cout << p.get_age() << endl;
    cout << p.add_age(10).get_age() << endl;
    return 0;
}