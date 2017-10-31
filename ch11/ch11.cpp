#include<iostream>
#include<string>
using namespace std;


//例11.1 访问公有基类的成员
class Student{       //声明基类
public:                     //基类公用成员
	void get_value() {              //输入基类数据的成员函数
		cin >> num >> name >> sex;
	}
	void display() {       //输出基类数据的成员函数
		cout << " num:" << num << endl;
		cout << " name:" << name << endl;
		cout << " sex:" << sex << endl;
	}
private:       //基类私有成员
	int num;
	string name;
	char sex;
};

class Student1 :public Student {          //以public方式声明派生类Student1
public:
	void get_value_1() { cin >> age >> addr; } //输入派生类数据
	void display_1() {
		cout << " age:" << age << endl;   //引用派生类的私有成员，正确
		cout << " address:" << addr << endl;       //引用派生类的私有成员，正确
	}
private:
	int age;
	string addr;
};

//例11.1 访问公有基类的成员 分别调用基类的display函数和派生类中的display_1函数 先后输出5个数据
int main11_1() {
	Student1 stud;  //定义派生类Student1的对象stud
	stud.get_value();
	stud.get_value_1();
	stud.display();
	stud.display_1();
	return 0;
}

//例11.2 将例11.1中的公用继承方式改为私有继承方式，基类Student不改
class Student2 :private Student {          //以private方式声明派生类Student2
public:
	void get_value_1()
	{
		get_value();     //调用基类的公用函数输入基类的3个数据
		cin >> age >> addr; } //输入派生类数据
	void display_1() {
		display();     //调用基类的公用成员函数输出3个数据成员的值
		cout << " age:" << age << endl;   //引用派生类的私有成员，正确
		cout << " address:" << addr << endl;       //引用派生类的私有成员，正确
	}
private:
	int age;
	string addr;
};

//例11.2 将例11.1中的公用继承方式改为私有继承方式，基类Student不改
int main11_2() {
	Student2 stud;  //定义派生类Student1的对象stud
	stud.get_value_1();
	stud.display_1();
	return 0;
}

//例11.3 在派生类中引用保护成员
class Student3 {    //声明基类
public:    //基类无公用成员
protected:   //基类保护成员
	int num;
	string name;
	char sex;
};

class Student31 :protected Student3 {  //用protected方式声明派生类Student31
public:
	void get_value1();  //派生类公用成员函数
	void display1();     //派生类公用成员函数
private:
	int age;     //派生类私有数据成员
	string addr;  //派生类私有数据成员
};

void Student31::get_value1() {     //定义派生类公用成员函数
	cin >> num >> name >> sex;      //输入保护基类数据成员
	cin >> age >> addr;      //输入派生类数据成员
} 

void Student31::display1() {        //定义派生类公用成员函数
	cout << " num:" << num << endl;  //引用基类的保护成员
	cout << " name:" << name << endl;  //引用基类的保护成员
	cout << " sex:" << sex << endl;                 //引用基类的保护成员
	cout << " age:" << age << endl;   //引用派生类的私有成员
	cout << " address:" << addr << endl;    //引用派生类的私有成员
}

//例11.3 在派生类中引用保护成员
int main11_3() {
	Student31 stud1;        //stud1是派生类Student31类的对象
	stud1.get_value1(); //get_value1是派生类中的公用成员函数，输入数据
	stud1.display1();         //display1是派生类中的公用成员函数，输出数据
	return 0;
}

//例11.4 多级派生的访问属性 A是B的公用基类 B是C的保护基类...所以常用的是公用继承..
class A {   //基类
public:
	int i;
protected:
	void f1();
	int j;
private:
	int k;
};

class B:public A {   //基类
public:
	void f2();
protected:
	void f3();
private:
	int m;
};

class C :protected B{   //基类
public:
	void f4();
private:
	int n;
};

//例11.5 定义简单的派生类的构造函数
class Student5 {             //声明基类Student5
public:
	Student5(int n, string nam, char s) {     //定义基类的构造函数
		num = n;
		name = nam;
		sex = s;
	}
	~Student5(){}      //基类析构函数
protected:  //保护部分
	int num;
	string name;
	char sex;
};

class Student51 :public Student5 {   //声明公用派生类Student51
public:     //派生类的公用部分
	Student51(int n, string nam, char s, int a, string ad) :Student5(n, nam, s) { //定义派生类构造函数
		age = a; //在函数体中只对派生类新增的数据成员初始化
		addr = ad;
	}
	void show() {
		cout << "num:" << num << endl;
		cout << " name:" << name << endl;  
		cout << " sex:" << sex << endl;                 
		cout << " age:" << age << endl;  
		cout << " address:" << addr << endl;
	}
	~Student51(){}   //派生类析构函数
private:         //派生类的私有部分
	int age;
	string addr;
};

//例11.5 定义简单的派生类的构造函数
int main11_5() {
	Student51 stud1(10010, "Wang-li", 'f', 19, "115 Beijing Road,Shanghai");
	Student51 stud2(10011, "Zhang-fang", 'm', 21, "213 Shanghai Road,Beijing");
	stud1.show();  //输出第一个学生的数据
	stud2.show();  //输出第二个学生的数据
	return 0;
}

//例11.6 包含子对象的派生类的构造函数
class Student6 { //声明基类
public:  //公用部分
	Student6(int n, string nam) {   //基类构造函数，与例11.5相同
		num = n;
		name = nam;
	}
	void display() {    //成员函数，输出基类数据成员
		cout << "num:" << num << endl << "name:" << name << endl;
	}
protected:    //保护部分
	int num;
	string name;
};

class Student61 :public Student6 {  //声明公用派生类student61
public:
	Student61(int n, string nam, int n1, string nam1, int a, string ad)
		:Student6(n, nam), monitor(n1, nam1) {      //派生类构造函数
		age = a;
		addr = ad;
	}
	void show() {
		cout << "This student is:" << endl;
		display();              //输出num和name
		cout << "age:" << age << endl;   //输出age
		cout << "address" << addr << endl << endl; //输出addr
	}
	void show_monitor() {       //成员函数，输出子对象
		cout << endl << "Class monitor is:" << endl;
		monitor.display();
	}
private:       //派生类的私有数据
	Student6 monitor;   //定义子对象（班长） 所以c++真的好多变化啊，感觉随心所欲的那种
	int age;
	string addr;
};

//例11.6 包含子对象的派生类的构造函数
int main11_6() {
	Student61 stud1(10010, "Wang-li",10001,"Li_sun",19,"115 Beijing Road,Shanghai");
	stud1.show(); //输出学生的数据
	stud1.show_monitor(); //输出子对象的数据
	return 0;
}





int main(){
	main11_6();
	system("pause");
	return 0;
}
 













