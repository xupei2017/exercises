#include <iostream>
#include <string>

using namespace std;

//例9.1 用构造函数为对象的数据成员赋初值
class Time{         //声明Time类
public:     //以下为公用函数
	Time(){      //定义构造成员函数，函数名与类名相同
		hour = 0; minute = 0; sec = 0;
	}
	void set_time(); //成员函数声明
	void show_time();  //成员函数声明
private:
	int hour;      //果然真的可以在后面定义
	int minute;
	int sec;
};

void Time::set_time(){        //定义成员函数 向数据成员赋值
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::show_time(){         //定义成员函数 输出数据成员的值
	cout << hour << ":" << minute << ":" << sec << endl;
}


//用构造函数为对象的数据成员赋初值
int main9_1(){
	Time t1;     //建立对象t1,同时调用构造函数t1.Time()
	t1.set_time();       //对t1的数据成员赋值
	t1.show_time();   //显示t1的数据成员的值
	Time t2;     //建立对象t2,同时调用构造函数t2.Time()
	t2.show_time();       //显示t2的数据成员的值
	return 0;
}

//例9.2  带参数的构造函数
class Box{         //声明Box类
public:
	Box(int, int, int);       //声明带参数的构造函数
	int volume();    //声明计算体积的函数
private:
	int height; //高
	int width;           //宽
	int length; //长
};

Box::Box(int h, int w, int len){       //在类外定义带参数的构造函数
	height = h;
	width = w;
	length = len;
}

int Box::volume(){        //定义计算体积的函数
	return(height*width*length);
}

//有两个长方柱，其高、宽、长分别为（1）12, 25, 30；（2）15, 30, 21.求它们的体积。
//编写一个基于对象的程序，在类中用带参数的构造函数对数据成员初始化
int main9_2(){
	Box box1(12, 25, 30);  //建立对象box1,并指定box1的高、宽、长的值
	cout << "The volume of box1 is" << box1.volume() << endl;
	Box box2(15, 30, 21);  //建立对象box2,并指定box2的高、宽、长的值
	cout << "The volume of box2 is" << box2.volume() << endl;
	return 0;
}

//例9.3 构造函数的重载
class Box1{         //声明Box1类
public:
	Box1();     //声明一个无参的构造函数Box1
	Box1(int h, int w, int len) :height(h), width(w), length(len){}       //定义一个带参数的构造函数，用参数的初始化表对数据成员初始化
	int volume();    //声明成员函数volume
private:
	int height; //高
	int width;           //宽
	int length; //长
};

Box1::Box1(){       //在类外定义无参数的构造函数
	height = 10;
	width = 10;
	length = 10;
}

//Box1::Box1(int h, int w, int len){       //在类外定义带参数的构造函数 
//	height = h;
//	width = w;         //此处竟然不需要这样定义了！！！直接在类里面就赋值了，即参数初始化表！！！
//	length = len;
//}

int Box1::volume(){        //定义计算体积的函数
	return(height*width*length);
}

//在例9.2的基础上定义两个构造函数，其中一个无参数，一个有参数
int main9_3(){
	Box1 box1;  //建立对象box1,不指定实参
	cout << "The volume of box1 is " << box1.volume() << endl;
	Box1 box2(15, 30, 21);  //建立对象box2,指定3个实参
	cout << "The volume of box2 is " << box2.volume() << endl;
	return 0;
}

//例9.4 使用默认参数的构造函数
class Box2{
public:
	Box2(int h = 10, int w = 10, int len = 10);         //在声明构造函数时指定默认参数
	int volume();
private:
	int height;
	int width;
	int length;
};
Box2::Box2(int h, int w, int len){      //在定义函数时可以不指定默认参数
	height = h;
	width = w;
	length = len;
}

int Box2::volume(){
	return(height*width*length);
}

//在例9.3中的构造函数改用含默认参数值的参数，高、宽、长的默认值均为10
int main9_4(){
	Box2 box1;  //没有给实参
	cout << "The volume of box1 is " << box1.volume() << endl;
	Box2 box2(15);  //只给定一个实参
	cout << "The volume of box2 is " << box2.volume() << endl;
	Box2 box3(15,30);  //只给定两个实参
	cout << "The volume of box3 is " << box3.volume() << endl;
	Box2 box4(15,30,20);  //没有给实参
	cout << "The volume of box4 is " << box4.volume() << endl;
	return 0;
}
/******************声明构造函数时指定默认值，而不能在定义构造函数时指定默认值，此处具体查看p264*/

//例9.5析构函数
class Student{
public:
	Student(int n, string nam, char s){    //定义有参数的构造函数
		num = n; 
		name = nam; 
		sex = s;
		cout << "constructor called." << endl;         //输出有关信息
	}
	~Student(){      //定义析构函数
		cout << "destructor called." << endl;      //输出有关信息
	}
	void display(){        //定义成员函数
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		cout << "sex: " << sex << endl << endl;
	}
private:
	int num;
	string name;
	char sex;
};

//例9.5 包含构造函数和析构函数的C++程序
int main9_5(){
	Student stud1(10010,"zhang", 'f');   //建立对象stud1
	stud1.display();    //输出学生1的数据
	Student stud2(10011, "lisi", 'm');     //定义对象stud2
	stud2.display();          //输出学生2的数据
	return 0;
}

//例9.9 将一个对象的值赋给另一个对象
class Box9{
public:
	Box9(int = 10, int = 10, int = 10);        //声明有默认参数的构造函数
	int volume();
private:
	int height;
	int width;
	int length;
};

Box9::Box9(int h, int w, int len){    //定义构造函数
	height = h;
	width = w;
	length = len;
}

int Box9::volume()  //定义volume函数
{
	return(height*width*length);   //返回体积
}

//例9.9 将一个对象的值赋给另一个对象
int main9_9(){
	Box9 box1(15, 30, 25), box2;   //定义两个对象box1,box2
	cout << "The volume of box1 is " << box1.volume() << endl;
	box2 = box1;           //将box1的值赋给box2
	cout << "The volume of box2 is " << box2.volume() << endl;
	return 0;
}

//例9.10 
class Box10{
public:
	Box10(int, int);
	int volume();
	static int height;          //把height定义为公用的静态数据成员
	int width;
	int length;
};

Box10::Box10(int w, int len){     //通过构造函数对width和length赋初值
	width = w;
	length = len;
}

int Box10::volume(){     //定义成员函数volume
	return(height*width*length);
}

int Box10::height = 10;     //对静态数据成员height初始化

//例9.10 引用静态数据成员
int main9_10(){
	Box10 a(15, 20), b(20, 30);     //建立两个对象
	cout << a.height << endl;             //通过对象名a引用静态数据成员
	cout << b.height << endl;          //通过对象名b引用静态数据成员
	cout << Box10::height << endl;           //通过类名引用静态数据成员
	cout << a.volume() << endl;    //调用volume函数，计算体积，输出结果
	return 0;
}

//例9.11
class Student11{
public:
	Student11(int n, int a, float s) :num(n), age(a), score(s){}    //定义构造函数
	void total(); //声明成员函数
	static float average();     //声明静态成员函数
private:
	int num;
	int age;
	float score;
	static float sum;     //静态数据成员sum(总分)
	static int count;        //静态数据成员count(计数)
};

void Student11::total(){      //定义非静态成员函数
	sum += score;     //累计总分
	count++;      //累计已统计的人数
}

float Student11::average(){  //定义静态成员函数
	return(sum / count);
}

float Student11::sum = 0;            //对静态数据成员初始化
int Student11::count = 0;      //对静态数据成员初始化

//例9.11 统计学生平均成绩。使用静态成员函数
int main9_11(){
	Student11 stud[3] = {        //定义对象数组并初始化
		Student11(1001, 18, 70),
		Student11(1002, 19, 78),
		Student11(1005, 20, 98)
	};
	int n;
	cout << "Please input the number of students:";
	cin >> n;      //输入需要求前面多少名学生的平均成绩
	for (int i = 0; i < n; i++)   //调用三次total函数
		stud[i].total();
	cout << "the average score of " << n << " student is " << Student11::average() << endl; //调用静态成员函数
	return 0;
}

//例9.12 友元函数的简单例子
class Time12{
public:
	Time12(int, int, int);    //声明构造函数
	friend void display(Time12 &);       //声明display函数为Time类的友元函数
private:                //以下数据是私有数据成员
	int hour;
	int minute;
	int sec;
};

Time12::Time12(int h, int m, int s){     //定义构造函数，给hour,minute,sec赋初值
	hour = h;
	minute = m;
	sec = s;
}

void display(Time12&t)    //这是普通函数，形参t是Time类对象的引用
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}

//例9.12 友元函数的简单例子
int main9_12(){
	Time12 t1(10, 13, 56);      //调用display函数，实参t1是Time类对象
	display(t1);
	return 0;
}

//例9.13
class Date13;    //对Date13类的提前引用声明
class Time13         //声明Time13类
{
public:
	Time13(int, int, int); //声明构造函数
	void display(Date13 &);         //display是成员函数，形参是Date13类对象的引用
private:
	int hour;
	int minute;
	int sec;
};

class Date13{     //声明Date13类
public:
	Date13(int, int, int);     //声明构造函数
//	friend void Time13::display(Date13 &);    //声明Time13中的display函数为本类的友元成员函数
	friend Time13;
private:
	int month;
	int day;
	int year;
};

Time13::Time13(int h, int m, int s){   //定义Time13的构造函数
	hour = h;
	minute = m;
	sec = s;
}

void Time13::display(Date13 &d){         //display的作用是输出年、月、日和时、分、秒
	cout << d.month << "/" << d.day << "/" << d.year << endl;     //引用Date13类对象中的私有数据
	cout << hour << ":" << minute << ":" << sec << endl;        //引用本类对象中的私有数据
}

Date13::Date13(int m, int d, int y){      //类Date13的构造函数
	month = m;
	day = d;
	year = y;
}
//例9.13 友元成员函数
int main9_13(){
	Time13 t1(10, 13, 56);     //定义Time13类对象t1
	Date13 d1(12, 25, 2004);     //定义Date13类对象d1
	t1.display(d1);    //调用t1中的display函数，实参是Date13类对象d1
	return 0;
}

//例9.14 类模板
template<class numtype>       //声明类模板，虚拟类型名为numtype
class Compare{       //类模板名为Compare
public:
	Compare(numtype a, numtype b) //定义构造函数
	{
		x = a; y = b;
	}
	numtype max(){        //函数类型暂定为numtype
		return(x > y) ? x : y;
	}
	numtype min(){      
		return(x < y) ? x : y;
	}
private:
	numtype x, y;   //数据类型暂定为numtype
};

//例9.14 声明一个类模板，利用它分别实现两个整数、浮点数和字符的比较，求出大数和小数。
int main9_14(){
	Compare<int> cmp1(3, 7); //定义对象cmp1,用于两个整数的比较
	cout << cmp1.max() << " is the Maximum of two integer numbers." << endl;
	cout << cmp1.min() << " is the Minimum of two integer numbers." << endl << endl;
	Compare<float> cmp2(45.78, 93.6); //定义对象cmp2,用于两个浮点数的比较
	cout << cmp2.max() << " is the Maximum of two float numbers." << endl;
	cout << cmp2.min() << " is the Minimum of two float numbers." << endl << endl;
	Compare<char> cmp3('a', 'A'); //定义对象cmp3,用于两个字符的比较
	cout << cmp3.max() << " is the Maximum of two characters." << endl;
	cout << cmp3.min() << " is the Minimum of two characters." << endl;
	return 0;
}









int main(){
	main9_14();
	return 0;
}
