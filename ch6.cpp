#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



//例6.1 通过指针变量访问整型变量
int main6_1(){
	int a, b;        //定义整型变量a,b
	int *pointer_1, *pointer_2;  //定义pointer_1, pointer_2为（int *)型变量
	a = 100; b = 10;     //对a,b赋值
	pointer_1 = &a;   //把变量a的地址赋给pointer_1
	pointer_2 = &b;   //把变量b的地址赋给pointer_2
	cout << a << " " << b << endl;        //输出a,b的值
	cout << *pointer_1 << " " << *pointer_2 << endl;      //输出*pointer_1, *pointer_2的值
	return 0;
}

//例6.2 输入a,b两个整数，按先大后小的顺序输出a,b（用指针变量处理）
int main6_2(){
	int *p1, *p2, *p, a, b;
	cout << "提示：请输入两个整数" << endl;
	cin >> a >> b;   //输入两个整数
	p1 = &a;    //使p1指向a
	p2 = &b;   //使p2指向b
	if (a < b){
		p = p1; p1 = p2; p2 = p;   //如果a<b，使p1与p2的值互换  p1指向大的值
	}
	cout << "a=" << a << " b=" << b << endl;
	cout << "max=" << *p1 << " min=" << *p2 << endl;
	return 0;
}

//例6.3 题目同例6.2 ，即对输入的两个整数按大小顺序输出 今用函数处理 而且用指针类型的数据作函数参数
int main6_3(){
	void swap(int *p1, int *p2);   //函数声明
	int *pointer_1, *pointer_2, a, b;
	cin >> a >> b;
	pointer_1 = &a;
	pointer_2 = &b;
	if (a < b) swap(pointer_1, pointer_2);
	cout << "max=" << a << " min=" << b << endl;
	return 0;
}

void swap(int *p1, int *p2){ //函数swap的作用是将*p1和*p2的值互换
	int temp;
	temp = *p1;  //temp是整型变量，而不是指针变量
	*p1 = *p2;
	*p2 = temp;
}

//例6.4 输入a,b,c 3个整数，按由大到小的顺序输出
int main6_4(){
	void exchange(int *, int *, int *);  //对exchange函数的声明
	int a, b, c, *p1, *p2, *p3;
	cin >> a >> b >> c;      //输入3个整数
	p1 = &a;
	p2 = &b;
	p3 = &c;
	exchange(p1, p2, p3); //交换p1,p2,p3指向的3个整型变量的值
	cout << a << " " << b << " " << c << endl;  //按由大到小的顺序输出3个整数
	return 0;
}

void exchange(int *q1, int *q2, int *q3){
//	void swap(int *, int *); //对swap函数的声明  前面有
	if (*q1 < *q2)  swap(q1, q2);
	if (*q1 < *q3) swap(q1, q3);
	if (*q2 < *q3)  swap(q2, q3);
}

//例6.5 输出数组中的全部元素，三种方法
//方法一：下标法
int main6_5_1(){
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
		cin >> a[i]; //引用数组元素a[i]
		cout << endl;
		for (i = 0; i < 10; i++)
			cout << a[i] << " "; //引用数组元素a[i]
		cout << endl;
		return 0;
}

//例6.5 输出数组中的全部元素，三种方法
//方法二：指针法
int main6_5_2(){
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
		cin >> *(a+i); //引用数组元素a[i]
	cout << endl;
	for (i = 0; i < 10; i++)
		cout << *(a + i) << " "; //引用数组元素a[i]
	cout << endl;
	return 0;
}

//例6.5 输出数组中的全部元素，三种方法
//方法三：用指针变量指向数组元素
int main6_5_3(){
	int a[10];
	int i,*p=a;
	for (i = 0; i < 10; i++)
		cin >> *(p + i); //引用数组元素a[i]
	cout << endl;
	for (p = a; p < (a+10); p++)
		cout <<*p << " "; //引用数组元素a[i]
	cout << endl;
	return 0;
}

//例6.6 将10个整数按由小到大是顺序排列 在例5.7的基础上，将形参改为指针变量
int main6_6(){
	void select_sort(int *p, int n);         //函数声明
	int a[10], i;
	cout << "enter the original array:" << endl; 
	for (i = 0; i < 10; i++)
		cin >> a[i];   //输入10个数
	cout << endl;
	select_sort(a, 10);    //函数调用 数组名作实参
	cout << "the sorted array:" << endl;
	for (i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void select_sort(int *p, int n){   //用指针变量作形参
	int i, j, k, t;
	for (i = 0; i < n - 1; i++){
		k = i;
		for (j = i + 1; j < n;j++)
		if (*(p + j) < *(p + k)) k = j;  //用指针法访问数组元素
		t = *(p + k); *(p + k) = *(p + i); *(p + i) = t;
	}
}

//在C++中可以用3种方法访问一个字符串
//例6.7 定义一个字符数组并初始化，然后输出其中的字符串
int main6_7(){
	char str[] = "I love CHINA!";
	cout << str << endl;
	return 0;
}

//例6.8 定义一个字符串变量并初始化，然后输出其中的字符串
int main6_8(){
	string str = "I love CHINA!";
	cout << str << endl;
	return 0;
}

//例6.9 用字符指针指向一个字符串
int main6_9(){
	char *str = "I love you";
	cout << str << endl;
	return 0;
}

//例6.10 将字符串str1复制为字符串str2
//定义两个字符数组str1和str2，再设两个指针变量p1 p2，分别指向两个字符数组中的有关字符
//通过改变指针变量的值使它们指向字符串中的不同字符，以实现字符的复制
int main6_10(){
	char str1[] = "I want to have summer vacation!!", str2[20], *p1, *p2;
	p1 = str1; p2 = str2;
	for (; *p1 != '\0'; p1++, p2++)
		*p2 = *p1;   //用string变量处理更加方便 直接string str1="",str2;  str2=str1;
	*p2 = '\0';
	p1 = str1; p2 = str2;
	cout << "str1 is:" << p1 << endl;
	cout << "str2 is:" << p2 << endl;
	return 0;
}

//用函数指针调用函数，函数名代表函数入口地址
//例6.11 求a和b中的大者
int main6_11(){
	int max(int x, int y);  //函数声明
	int( * p)(int,int);
	p = max; //函数名代表函数入口地址
	int a, b, m;
	cin >> a >> b;
	//m = max(a, b);
	m = p(a, b);
	cout << "max=" << m << endl;
	return 0;
}

int max(int x, int y){
	int z;
	if (x > y)z = x;
	else z = y;
	return(z);
}

//指针数组 即数组的元素全为指针类型数据
//例6.12 若干字符串按字母顺序（由小到大）输出
int main6_12(){
	void sort(char *name[], int n); //函数声明
	void print(char *name[], int n);  //函数声明
	char *name[] = { "BASIC", "FORTRAN", "C++", "Pascal", "COBOL" };   //定义指针数组
	int n = 5;
	sort(name, n);
	print(name, n);
	return 0;
}

void sort(char *name[], int n){
	char *temp;
	int i, j, k;
	for (i = 0; i < n - 1; i++){
		k = i;
		for (j = i + 1; j < n;j++)
		if (strcmp(name[k], name[j])>0) k = j;
		if (k != i)
		{
			temp = name[i]; name[i] = name[k]; name[k] = temp;
		}
	}
}


void print(char *name[], int n){
	int i;
	for (i = 0; i < n; i++)
		cout << name[i] << endl;
}

//指向指针的指针
//例6.13  指向字符型数据的指针变量
int main6_13(){
	char **p;  //定义指向字符指针数据的指针变量p
	char *name[] = { "BASIC", "FORTRAN", "C++", "Pascal", "COBOL" };
	p = name + 2;
	cout << *p << endl;  //输出name[2]指向的字符串
	cout << **p << endl;  //输出name[2]指向的字符串中的第一个字符
	return 0;
}

//例6.14 在函数中改变指针形参所指对象的值
void fun(int *p){      //形参是指向整型变量的指针变量
	*p = 5 * (*p);    //使p所指的变量为原值的5倍
}

int main6_14(){
	int a = 10;
	fun(&a);    //用a的地址作为实参
	cout << a << " " << endl;
	return 0;
}

//引用的简单使用
//例6.15 引用和变量的关系
int main6_15(){
	int a = 10;
	int &b = a;   //声明b是a的引用
	a = a*a;
	cout << a << setw(6) << b << endl; //a的值变化了，b的值也一起变化
	b = b / 5;
	cout << b << setw(6) << a << endl;   //b的值变化了，a的值也一起变化
	return 0;
}

//将变量名作为实参和形参，传递是单向的。形参值改变不会传回给实参。形参和实参不是在同一个存储单元
//例6.16 要求将变量i和j的值互换，下面程序无法实现此要求
int main6_16(){
	void swap1(int, int);  //函数声明
	int i = 3, j = 5;
	swap1(i, j); //调用函数swap1
	cout << i << " " << j << endl;
	return 0;
}

void swap1(int a, int b){ //试图通过形参a和b的值交换，实现实参i和j的值互换  
	int temp;    //然而并不可以啊！！
	temp = a;
	a = b;
	b = temp;
}

//传递变量地址的方法
//例6.17 使用指针变量作形参，实现两个变量的值互换
int main6_17(){
	void swap2(int *, int *);
	int i = 3, j = 5;
	swap2(&i, &j);      //实参是变量的地址
	cout << i << " " << j << endl;   //i和j的值已互换
	return 0;
}

void swap2(int *p1, int *p2){   //形参是指针变量
	int temp;
	temp = *p1; 
	*p1 = *p2;
	*p2 = temp;
}

//引用作为函数参数  
//例6.18 实现两个变量的值互换 用“引用”作形参
int main6_18(){
	void swap3(int &, int &);
	int i = 3, j = 5;
	swap3(i, j);  //实参为整型变量
	cout << "i=" << i << " " << "j=" << j << endl;
	return 0;
}

void swap3(int &a, int &b){   //形参是引用
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//例6.19 对3个变量按由小到大的顺序排序
int main6_19(){
	void sort1(int &, int &, int &);    //函数声明，形参是引用
	int a, b, c;
	cout << "Please enter 3 integers:";
	cin >> a >> b >> c;    //输入a,b,c
	sort1(a, b, c);
	cout << "sorted order is " << a << " " << b << " " << c << endl;
	return 0;
}

void sort1(int &i, int &j, int &k){
	void change(int &, int &);
	if (i > j)change(i, j);
	if (i > k) change(i, k);
	if (j > k)change(j, k);
}

void change(int &x, int &y){    //使x和y互换
	int temp;
	temp = x;
	x = y;
	y = temp;
}








int main(){
	main6_19();
	return 0;
}
