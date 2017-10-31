#pragma once
#pragma once
#include <string>
#include <cmath>
#include<iostream>
using namespace std;

namespace ns2 {  //声明命名空间ns2
	class Student {
	public:
		Student(int n, string nam, char s) {  //定义构造函数
			num = n; name = nam; sex = s;
		}

		void get_data(); //成员函数声明
	private:
		int num;
		string name;
		char sex;
	};

	void Student::get_data() { //定义成员函数

		cout << num << " " << name << " " << sex << endl;
	}

	double fun(double a, double b) { //在命名空间ns1内定义fun函数
		return sqrt(a - b);
	}
}