//apple.cpp
class Apple
{
private:
    int people[100];
public:
    Apple(int i);
    const int apple_number;
    void take(int num) const;
    int add(int num);
    int add(int num) const;
    int getCount() const;

};
//main.cpp
#include<iostream>
using namespace std;

Apple::Apple(int i) :apple_number(i)
{

}
int Apple::add(int num) {
    take(num);
    cout << "op1"<<endl;
    return 0;
}
int Apple::add(int num) const {
    take(num);
    cout << "op2"<<endl;
    return 0;
}
void Apple::take(int num) const
{
    cout << "take func " << num << endl;
}
int Apple::getCount() const
{
    take(1);
    //    add(); //error
    return apple_number;
}
int main() {
    Apple a(5);
    cout << a.getCount() << endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}