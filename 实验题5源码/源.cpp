#include<iostream>
#include "people.h"
int main() {
	People people1(18, 185, 67);
	people1.Eating();
	people1.Sleeping();
	people1.Sporting();
	people1.Show();
	people1.ShowNum();
	People people2(19, 175, 99);
	people2.Eating();
	people2.Sleeping();
	people2.Sporting();
	people2.Show();
	people2.ShowNum();
	return 0;
}