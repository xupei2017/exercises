#include<iostream>
#include<string>

using namespace std;

//基类与派生类中有同名函数

class Student {       //声明基类Student
public:                     //基类公用成员
	Student(int, string, float); //声明构造函数
    virtual void display(); //声明输出函数. 虚函数噢！！具体查看P401
	//此处加virtual也可以输出Graduate的wage数据了

protected:       //基类保护成员，派生类可以访问
	int num;
	string name;
	float score;
};

//Student类成员函数的实现
Student::Student(int n, string nam, float s) { //定义构造函数
	num = n;
	name = nam;
	score = s;
}

void Student::display() { //定义输出函数
	cout << endl << " num:" << num << endl;
	cout << " name:" << name << endl;
	cout << " score:" << score << endl;
}

class Graduate :public Student {          //以public方式声明派生类Graduate
public:
	Graduate(int, string, float, float);  //声明构造函数
	void display();  //声明输出函数，与基类的输出函数同名
private:
	float wage; //津贴
};

//Graduate类成员函数的实现
Graduate::Graduate(int n, string nam, float s, float w) :Student(n, nam, s), wage(w) {} //定义构造函数


void Graduate::display() { //定义输出函数
	
	cout  << " \n\nnum:" << num << "\n name:" << name << " \nscore:" 
		<< score <<  "\n wage:" << wage << endl;
}

//主函数
int main() {
	Student stud1(1001, "Li", 87.5);  //定义Student类对象stud1
	Graduate grad1(2001, "Wang", 98.5, 1000); //定义Graduate类对象grad1
	Student *pt = &stud1;  //定义指向Student类对象的指针并指向stud1
	pt->display(); //调用stud1.display函数
	pt = &grad1;  //指针指向grad1
	pt->display();  //调用grad1.display函数
	
	system("pause");
	return 0;
}