#include <iostream>
#include<cmath>
#include<string>

using namespace std;

//例14.1 设置异常处理程序，输入三角形三条边，输出三角形面积
int main14_1() {
	double triangle(double, double, double);
	double a, b, c;
	cin >> a >> b >> c;
	try
	{
		while (a > 0 && b > 0 && c > 0) {
			cout << triangle(a, b, c) << endl;
			cin >> a >> b >> c;
		}
	}
	catch (double) {
		cout << "a=" << a << ",b=" << b << ",c=" << c << ",that is not a triangle!" << endl;
	}
	cout << "end" << endl;
	return 0;
}

double triangle(double a, double b, double c) {
	double s = (a + b + c) / 2;
	if (a + b <= c || b + c <= a || a + c <= b) throw a;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

//例14.2 在函数嵌套的情况下检测异常处理
int main14_2() {
	void f1();
	try
	{
		f1(); //调用f1()
	}
	catch (double) {
		cout << "error0!!" << endl;
	}
	cout << "end0" << endl;
	return 0;
}

void f1() {
	void f2();
	try { f2(); } //调用f2()
	catch (char) {
		cout << "error1 !!" << endl;
	}
	cout << "end1" << endl;
}

void f2() {
	void f3();
	try { f3(); } //调用f3()
	catch (int) {
		cout << "error2 !!" << endl;
	}
	cout << "end2" << endl;
}

void f3() {
	double a = 0;
	try { throw a; }  //抛出double类型异常
	//catch (double)
	catch (float) {
		cout << "error3 !!" << endl;
	//	throw;
	}
	cout << "end3" << endl;
}

//例14.3 在异常处理中处理析构函数
class Student {
public:
	Student(int n, string nam) {  //定义构造函数
		cout << "constructor -" << n << endl;
		num = n; name = nam;
	}
	~Student() { cout << "destructor -" << num << endl; } //定义析构函数
	void get_data(); //成员函数声明
private:
	int num;
	string name;
};

void Student::get_data() { //定义成员函数
	if (num == 0)throw num; //若num=0，抛出int型变量num
	else cout << num << " " << name << endl; //若num不等于0，输出num,name
	cout << "in get_data()" << endl; //表示目前在get_data函数中
}

void fun() {
	Student stud1(1101, "Tan"); //建立对象stud1
	stud1.get_data(); //调用stud1的get_data函数
	Student stud2(0, "Li"); //建立对象stud2
	stud2.get_data(); //调用stud2的get_data函数
}

//例14.3 在异常处理中处理析构函数
int main14_3() {
	cout << "main begin" << endl;   //表示主函数开始了
	cout << "call fun()" << endl; //表示调用fun函数
	try {
		fun();
	}
	catch (int n) {
		cout << "num=" << n << ",error!" << endl; //表示num=0出错
	}
	cout << "main end" << endl; //表示主函数结束
	return 0;
}

/* 14.3运行结果为：
main begin
call fun()
constructor -1101
1101 tan
in get_data()
constructor -0 
destructor -0 //先是stud2的析构函数
destructor -1101 //再是stud1的析构函数
num=0,error!
main end
*/





int main() {
	main14_3();
	system("pause");
	return 0;
}