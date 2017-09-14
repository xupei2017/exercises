#include <iostream>

using namespace std;


//例8.1 
class Time{    //定义Time类
public:        //数据成员为公用的
	int hour;
	int minute;
	int sec;
};

//用类来实现输入和输出时间（时：分：秒）
int main8_1(){
	Time t1;   //定义t1为Time类对象
	cin >> t1.hour;    //以下3行的作用是输入设定的时间
	cin >> t1.minute;
	cin >> t1.sec;
	cout << t1.hour << ":" << t1.minute << ":" << t1.sec << endl;       //输出时间
	return 0;
}

//例8.2 用例8.1中的Time类，定义多个类对象，分别输入和输出各对象中的时间（时：分：秒）
int main8_2_a(){
	Time t1;  //定义对象t1
	cin >> t1.hour;    //向t1的数据成员输入数据
	cin >> t1.minute;
	cin >> t1.sec;
	cout << t1.hour << ":" << t1.minute << ":" << t1.sec << endl;       //输出t1中数据成员的值

	Time t2;  //定义对象t2
	cin >> t2.hour;    //向t2的数据成员输入数据
	cin >> t2.minute;
	cin >> t2.sec;
	cout << t2.hour << ":" << t2.minute << ":" << t2.sec << endl;       //输出t2中数据成员的值
	return 0;
}

//为了避免冗余，使用函数来进行输入和输出
int main8_2_b(){
	void set_time(Time&);  //函数声明
	void show_time(Time&);  //函数声明
	Time t1;   //定义t1为Time类对象
	set_time(t1);  //调用set_time函数，向t1对象中的数据成员输入数据
	show_time(t1); //调用show_time函数，输出t1对象中的数据

	Time t2;   //定义t2为Time类对象
	set_time(t2);  //调用set_time函数，向t2对象中的数据成员输入数据
	show_time(t2); //调用show_time函数，输出t2对象中的数据
	return 0;
}

void set_time(Time& t){ //定义函数set_time，形参t是引用变量
	cin >> t.hour;     //输入设定的时间
	cin >> t.minute;
	cin >> t.sec;
}

void show_time(Time& t){    //定义函数show_time，形参t是引用变量
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;   //输出对象中的数据
}

//数据成员的值不再由键盘输入，而是在调用函数时由实参给出，并在函数中使用默认参数
int main8_2_c(){
	void set_time_c(Time&, int hour = 0, int minute = 0, int sec = 0);  //函数声明，指定了默认参数
	void show_time_c(Time&);  //函数声明
	Time t1;   //定义t1为Time类对象
	set_time_c(t1, 12, 23, 34);  //调用set_time函数，通过实参传递时分秒的值
	show_time_c(t1); //调用show_time函数，输出t1对象中的数据

	Time t2;   //定义t2为Time类对象
	set_time_c(t2);  //调用set_time函数，使用默认的时分秒的值
	show_time_c(t2); //调用show_time函数，输出t2对象中的数据
	return 0;
}

void set_time_c(Time& t,int hour,int minute,int sec){ //定义函数时不必再指定默认参数
	t.hour = hour;     
	t.minute = minute;
	t.sec = sec;
}

void show_time_c(Time& t){    //定义函数show_time，形参t是引用变量
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;   //输出对象中的数据
}

//例8.3 让类包含成员函数
class Time1{
public:
	void set_time3();   //公用成员函数
	void show_time3(); //公用成员函数
private:      //数据成员为私有的
	int hour;
	int minute;
	int sec;
};

//将例8.2的程序改用含成员函数的类来处理
int main8_3(){
	Time1 t1;   //定义t1为Time1类对象
	t1.set_time3();  //调用对象t1的成员函数set_time3，向t1的数据成员输入数据
	t1.show_time3(); //调用对象t1的成员函数show_time函数，输出t1的数据成员的值

	Time1 t2;   //定义t2为Time1类对象
	t2.set_time3();  //调用对象t2的成员函数set_time3，向t2的数据成员输入数据
	t2.show_time3(); //调用对象t2的成员函数show_time函数，输出t2的数据成员的值
	return 0;
}

void Time1::set_time3(){      //在类外定义set_time3函数
	cin >> hour;     
	cin >> minute;
	cin >> sec;
}

void Time1::show_time3(){     //在类外定义show_time3函数
	cout << hour << ":" << minute << ":" << sec << endl;
}

//例8.4 找出一个整型数组中的元素的最大值
class Array_max{       //声明类
public:  //以下三行为成员函数原型声明
	void set_value();  //对数组元素设置值
	void max_value();   //找出数组中的最大元素
	void show_value();  //输出最大值
private:
	int array[10]; // 整型数组
	int max;     //max用来存放最大值
};

void Array_max::set_value(){     //成员函数定义 向数组元素输入数值
	int i;
	for (i = 0; i < 10; i++)
		cin >> array[i];
}

void Array_max::max_value(){    //成员函数定义，找出数组元素中的最大值
	int i;
	max = array[0];
	for (i = 1; i < 10;i++)
	if (array[i]>max)  max = array[i];
}

void Array_max::show_value(){      //成员函数定义，输出最大值
	cout << "max=" << max << endl;
}

//找出一个整型数组中的元素的最大值
int main8_4(){
	Array_max arrmax;      //定义对象arrmax
	arrmax.set_value();     //调用arrmax的set_value函数，向数组元素输入数值
	arrmax.max_value();    //调用arrmax的max_value函数，找出数组元素中的最大值
	arrmax.show_value();     //调用arrmax的show_value函数，输出数组元素中的最大值
	return 0;
}



//没有注释可怎么活..... 2017 7 29 周六
int main(){
	main8_4(); 
	return 0;
}
