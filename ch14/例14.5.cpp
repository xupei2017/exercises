//例14.5 利用命名空间来解决例14.4程序名字冲突问题
#include <iostream>
#include "header1.h"
#include "header2.h"

int main() {
	ns1::Student stud1(101, "Wang", 18); //ns1里的Student类定义stud1
	stud1.get_data();
	cout << ns1::fun(5, 3) << endl; //调用ns1里的fun函数
	ns2::Student stud2(102, "Li", 'f'); //ns2中的类定义stud2
	stud2.get_data();
	cout << ns2::fun(5, 3) << endl;
	system("pause");
	return 0;
}