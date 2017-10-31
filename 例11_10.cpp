#include<iostream>
#include<string>

using namespace std;

class Student {       //声明基类Student
public:                     //基类公用成员
	Student(int, string, float); //声明构造函数
	void display(); //声明输出函数
	
private:       //基类私有成员
	int num;
	string name;
	float score;
};

Student::Student(int n, string nam, float s) { //定义构造函数
	num = n;
	name = nam;
	score = s;
}

void Student::display() { //定义输出函数
	cout <<endl<< " num:" << num<< endl;  
	cout <<  " name:" << name << endl;
	cout << " score:" <<score << endl;
}

class Graduate :public Student {          //以public方式声明派生类Graduate
public:
	Graduate(int, string, float,float);  //声明构造函数
	void display();  //声明输出函数
private:
	float wage; //津贴
};


Graduate::Graduate(int n, string nam, float s, float w) :Student(n, nam, s), wage(w) {} //定义构造函数
	

void Graduate::display() { //定义输出函数
	Student::display(); //调用Student类的display函数
	cout << " wage:" << wage << endl;
}

int main() {
	Student stud1(1001, "Li", 87.5);  //定义Student类对象stud1
	Graduate grad1(2001, "Wang", 98.5, 1000); //定义Graduate类对象grad1
	Student *pt = &stud1;  //定义指向Student类对象的指针并指向stud1
	pt->display(); //调用stud1.display函数
	//pt = &grad1;  //指针指向grad1
	//pt->display();  //err  因为指向基类对象的指针只能访问派生类中的基类成员，
	////而不能访问派生类增加的成员。//调用grad1.display函数 不能调用出wage
	Graduate *pt1 = &grad1;
	pt1->display(); //这样才可以也输出wage

	system("pause");
	return 0;
}