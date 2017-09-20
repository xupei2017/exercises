#include<iostream>
using namespace std;

//例10.1通过函数来实现复数相加
class Complex{         //定义Complex类
public:
	Complex(){ real = 0; imag = 0; }  //定义构造函数
	Complex(double r, double i){ real = r; imag = i; }       //构造函数重载
	Complex complex_add(Complex &c2);       //声明复数相加函数
	void display();       //声明输出函数
private:
	double real;      //实部
	double imag;         //虚部
};

Complex Complex::complex_add(Complex &c2){     //定义复数相加函数
	Complex c;
	c.real = real + c2.real;
	c.imag = imag + c2.imag;
	return c;
}

void Complex::display(){       //定义输出函数
	cout << "(" << real << "," << imag << "i)" << endl;
}

//例10.1通过函数来实现复数相加
int main10_1(){
	Complex c1(3, 4), c2(5, -10), c3;        //定义三个复数对象
	c3 = c1.complex_add(c2); //调用复数相加函数
	cout << "c1=";  c1.display(); //输出c1的值
	cout << "c2="; c2.display();    //输出c2的值
	cout << "c3="; c3.display();   //输出c3的值
	return 0;
}

//例10.2，改写例10.1 对运算符“+”实行重载，使之能用于两个复数相加
class Complex2 {
public:
	Complex2() { real = 0; imag = 0; }
	Complex2(double r, double i) { real = r; imag = i; }       //构造函数重载
	Complex2 operator +(Complex2 &c2);       //声明重载运算符+的函数
	void display();       //声明输出函数
private:
	double real;      //实部
	double imag;         //虚部
};

Complex2 Complex2:: operator +(Complex2 &c2) {     //定义重载运算符+的函数
	Complex2 c;
	c.real = real + c2.real;
	c.imag = imag + c2.imag;
	return c;
}

void Complex2::display() {       //定义输出函数
	cout << "(" << real << "," << imag << "i)" << endl;
}

//例10.2，改写例10.1 对运算符“+”实行重载，使之能用于两个复数相加
int main10_2() {
	Complex2 c1(3, 4), c2(5, -10), c3;        //定义三个复数对象
	c3 = c1 + c2; //调用复数相加函数
	cout << "c1=";  c1.display(); //输出c1的值
	cout << "c2="; c2.display();    //输出c2的值
	cout << "c3="; c3.display();   //输出c3的值
	return 0;
}

//例10.3 将运算符+重载为适用于复数加法，重载函数不作为成员函数，而放在类外，作为Complex类的友元函数
class Complex3{
public:
	Complex3() { real = 0; imag = 0; }
	Complex3(double r, double i) { real = r; imag = i; }       //构造函数重载
	friend Complex3 operator +(Complex3 &c1,Complex3 &c2);       //声明重载函数作为友元函数
	void display();       //声明输出函数
private:
	double real;      //实部
	double imag;         //虚部
};

Complex3 operator +(Complex3 &c1, Complex3 &c2) {     //定义重载运算符+的函数
	return Complex3(c1.real + c2.real, c1.imag + c2.imag);
}

void Complex3::display() {       //定义输出函数
	cout << "(" << real << "," << imag << "i)" << endl;
}

//例10.3 将运算符+重载为适用于复数加法，重载函数不作为成员函数，而放在类外，作为Complex类的友元函数
int main10_3() {
	Complex3 c1(3, 4), c2(5, -10), c3;        //定义三个复数对象
	c3 = c1 + c2; //调用复数相加函数
	cout << "c1=";  c1.display(); //输出c1的值
	cout << "c2="; c2.display();    //输出c2的值
	cout << "c1 + c2="; c3.display();   //输出c3的值
	return 0;
}

//例10.4 定义一个字符串类String，用来存放不定长的字符串，重载运算符“==”，“<”和“>”
//用于两个字符串的等于、小于和大于的比较运算
class String {
public:
	String() { p = NULL; }     //定义默认构造函数
	String(char *str);    //声明构造函数
	friend bool operator >(String &string1, String &string2);    //声明运算符函数为友元函数
	friend bool operator <(String &string1, String &string2);    //声明运算符函数为友元函数
	friend bool operator ==(String &string1, String &string2);    //声明运算符函数为友元函数
	void display();        
private:
	char *p;       //定义字符型指针，用于指向字符串
};

String::String(char *str) {    //定义构造函数
	p = str;        //使p指向实参字符串
}

void String::display() {         //输出p所指向的字符串
	cout << p;
}

bool operator >(String &string1, String &string2) {
	if (strcmp(string1.p, string2.p) > 0)
		return true;
	else
		return false;
}

bool operator <(String &string1, String &string2) {
	if (strcmp(string1.p, string2.p) < 0)
		return true;
	else
		return false;
}

bool operator ==(String &string1, String &string2) {
	if (strcmp(string1.p, string2.p) == 0)
		return true;
	else
		return false;
}

void compare(String &string1, String &string2) {
	if(operator >(string1,string2)==1)
	{
		string1.display(); cout << ">"; string2.display();
	}
	else 
		if (operator <(string1, string2) == 1)
		{
			string1.display(); cout << "<"; string2.display();
		}
		else
			if(operator ==(string1, string2) == 1)
			{
				string1.display(); cout << "=="; string2.display();
			}
	cout << endl;
}


//重载运算符“ == ”，“<”和“>” 用于两个字符串的等于、小于和大于的比较运算
int main10_4() {
	String string1("Hello"), string2("Book"),string3("Computer"),string4("Hello");     //定义对象
	//string1.display();      //调用公用成员函数
	//cout << endl;    //换行
	//string2.display();   //调用公用成员函数

	//cout << (string1 > string2) << endl; //比较结果应该为true，即为1
	//cout << (string1 < string3) << endl; //false 0
	//cout << (string1 == string2) << endl; //false 0
	//用compare函数优化一下
	compare(string1, string2);
	compare(string2, string3);
	compare(string1, string4);
	return 0;
}

//例10.5 有一个Time类，包含数据成员minute和sec，模拟秒表，每次走1秒，满60秒进1分钟，此时秒又从0起算。要求输出分和秒的值
//使用运算符++，时钟的特点是60秒为1分。
//例10.6 在此上面添加了后置自增运算符的重载
class Time {
public:
	Time() { minute = 0; sec = 0; } //默认构造函数
	Time(int m,int s):minute(m),sec(s){}    //构造函数重载
	Time operator ++();   //声明前置自增运算符重载成员函数
	Time operator ++(int);   //声明后置自增运算符重载成员函数
	void display() { cout << minute << ":" << sec << endl;}      //定义输出时间函数
private:
	int minute;
	int sec;
};

Time Time::operator++() {   //定义前置自增运算符重载成员函数
	if (++sec >= 60) {
		sec -= 60;  //满60秒进一分钟
		++minute;
	}
	return *this;   //返回自加后的当前对象值
}

Time Time::operator++(int) {   //定义后置自增运算符重载成员函数
	Time temp(*this);//建立临时对象temp
	sec++;
	if (sec >= 60) {
		sec -= 60;  //满60秒进一分钟
		++minute;
	}
	return temp;   //返回的是自加前的对象值
}

//要求输出分和秒的值
int main10_5()
{
	Time time1(34, 59),time2;
	cout << "time1: "; //time1原值   34：59
	time1.display();
	++time1;
	cout << "++time1: "; //执行++time1后的time1的值  35：0
	time1.display();
	time2 = time1++;   //将自加前的对象的值赋给time2
	cout << "time1++: "; //再执行time1++后time1++的值   35：1
	time1.display();
	cout << "time2: ";  //time2保存的是执行time1++前time1的值  35：0
	time2.display();
	//for (int i = 0; i < 61; i++) {
	//	++time1;
	//	time1.display();
	//}
	return 0;
}

//例10.7 在例10.2的基础上，用重载的运算符<<输出复数
class Complexx {
public:
	Complexx() { real = 0; imag = 0;}
	Complexx(double r,double i) { real = r; imag = i; }
	Complexx operator +(Complexx &c2);     //运算符+重载为成员函数
	friend ostream& operator <<(ostream&, Complexx&);         //运算符<<重载为友元函数
private:
	double real;
	double imag;
};

Complexx Complexx::operator+(Complexx &c2)
{
	return Complexx(real + c2.real, imag + c2.imag);
}

ostream & operator<<(ostream &output,Complexx &c)
{
	output << "(" << c.real << " +" << c.imag << "i)" << endl;
	return output;
}

//例10.7 用重载的运算符<<输出复数 
int main10_7(){
	Complexx c1(2, 4), c2(6, 10), c3;
	c3 = c1 + c2;
	cout << c3;
	return 0;
}

//例10.8 在10.7的基础上添加>>运算符，用重载流提取运算符>>输入复数，用重载的运算符<<输出复数
class Complex8 {
public:	
	friend ostream& operator <<(ostream&, Complex8&);         //运算符<<重载为友元函数
	friend istream& operator >>(istream&, Complex8&);
private:
	double real;
	double imag;
};

ostream & operator<<(ostream &output, Complex8 &c)
{
	output << "(" << c.real;
	if (c.imag >= 0)output << "+"; //虚部为正数时，在虚部前加“+”号
	output << c.imag << "i)" << endl; //虚部为负数时，不加+号
	return output;
}

istream & operator>>(istream &input, Complex8 &c)
{
	cout << "input real part and imaginary part of complex8 number:";
	input >> c.real >> c.imag;
	return input;
}

//例10.8 用重载流提取运算符>>输入复数,用重载的运算符<<输出复数 
int main10_8() {
	Complex8 c1, c2;
	cin >> c1>>c2;
	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;
	return 0;
}

//例10.9 将一个double数据与Complex9类数据相加
class Complex9 {
public:
	Complex9() { real = 0; imag = 0; }
	Complex9(double r,double i) { real = r; imag = i; }
	operator double() { return real; }      //定义类型转换函数
private:
	double real;
	double imag;
};

//例10.9 将一个double数据与Complex9类数据相加
int main10_9() {
	Complex9 c1(3, 4), c2(5, -10), c3;   //建立3个Complex9类对象
	double d;
	d = 2.5 + c1;   //要求将一个double数据与Complex9类数据相加
	cout << d << endl;
	return 0;
}

//例10.10 包含转换构造函数和运算符重载函数
class Complex10 {
public:
	Complex10() { real = 0; imag = 0; } //默认构造函数，无形参
	Complex10(double r) { real = r; imag = 0; }  //转换构造函数，一个形参
	Complex10(double r,double i) { real = r; imag = i; }  //实现初始化的构造函数，两个形参
	friend Complex10 operator +(Complex10 c1, Complex10 c2);      //重载运算符+的友元函数
	void display();
private:
	double real;
	double imag;
};

Complex10 operator +(Complex10 c1, Complex10 c2) {    //定义运算符+的重载函数
	return Complex10(c1.real + c2.real, c1.imag + c2.imag);
}

void Complex10::display() {    //定义输出函数
	cout << "(" << real << "," << imag << "i)" << endl;
}

//例10.10 包含转换构造函数和运算符重载函数
int main10_10() {
	Complex10 c1(3, 4), c2(5, -10), c3;   //建立3个Complex10类对象
	c3 = c1 + 2.5;      //复数与double数据相加
	c3.display();
	return 0;
}









int main(){
	main10_10();
	system("pause");
	return 0;
}
