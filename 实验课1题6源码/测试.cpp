#include "student.h"
int main() {
	Student stu[3] = { {"����",2018,81,99},
					   {"�緹��",2019,100,99},
					   {"����",2020,59,89}
	};
	for (int i = 0; i < 3; i++) {
		stu[i].ShowBase();
	}
	stu->ShowStatic();
	return 0;
}