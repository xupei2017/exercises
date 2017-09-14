#include <iostream>
using namespace std;






//例4.1 在主函数中调用其他函数
void printstar(void){    //定义printstar函数
	cout << "********************************" << endl;      //输出30个*
}

void print_message(void){     //定义print_message函数
	cout << "Welcome to C++!" << endl;     //输出一行文字
}

int main41(void){
	printstar();    //调用printstar函数
	print_message();       //调用print_message函数
	printstar();      //调用printstar函数
	return 0;
}

//例4.2 调用函数时的数据传递
int max(int x, int y){         //定义有参函数max  两个数的最大值
	int z;
	z = x > y ? x : y;
	return z;
}

int main42(){
	int a, b, c;
	cout << "please enter two integer numbers:";
	cin >> a >> b;
	c = max(a, b);   //调用max函数，给定实参为a,b。函数值赋给c
	cout << "max=" << c << endl;
	return 0;
}

//4.3 对被调用的函数作声明
int main43(){
	float add(float x, float y); //对add函数作声明
	float a, b, c;
	cout << "Please enter a,b:";
	cin >> a >> b;
	c = add(a, b);
	cout << "sum=" << c << endl;
	return 0;
}

float add(float x, float y){    //定义add函数
	float z;
	z = x + y;
	return(z);
}

//4.4 输入4个整数，找出其中最大的数
int main44(){
	int max_4(int a, int b, int c, int d);//max_4函数的声明
	int a, b, c, d, max;
	cout << "Please enter 4 interger numbers:" << endl;
	cin >> a >> b >> c >> d;
	max = max_4(a, b, c, d);  //调用max_4函数，得到4个数中的最大者，赋给变量max
	cout << "max=" << max << endl;
	return 0;
}

int max_4(int a,int b,int c,int d){  //定义max_4函数
	int max1(int x, int y);   //max1函数的声明
	int m;
	m = max1(a, b);    //调用max1函数，找出a,b中的大者
	m = max1(m, c);    //调用max1函数，找出a,b,c中的大者
	m = max1(m, d);    //调用max1函数，找出a,b,c,d中的大者
	return(m);        //函数返回值是4个数中的最大者
}

int max1(int x, int y){ //定义max1函数
	if (x > y)
		return x;
	else
		return y;    //函数返回值是x,y中的最大值
}

//4.5 递归函数问题
int age(int);  //函数声明
int main45(){
	cout << age(5) << endl;
	return 0;
}
int age(int n){    //求年龄的递归函数
	int c;     //用c作为存放年龄的变量
	if (n == 1)c = 10;    //当n=1时，年龄为10
	else c = age(n - 1) + 2;  //当n>1时，此人年龄是他前一个人的年龄加2
	return c;       //将年龄值带回主函数
}

//4.6 用递归方法求n!
long fac(int);      //函数声明
int main46(){
	int n;       //n为需要求阶乘的整数
	long y;     //y为存放n!的变量
	cout << "please input an interger:"; //输入的提示
	cin >> n;   //输入n
	y = fac(n);    //调用fac函数以求n!
	cout << n << "!=" << y << endl;  //输出n！的值
	return 0;
}

long fac(int n){  //递归函数
	long f;
	if (n < 0){
		cout << "n<0,data error!" << endl;
		f = -1;             //如果输入负数，报错并以-1作为返回值
	}
	else if (n == 0 || n == 1)f = 1;      //0！和1！的值为1
	else f = fac(n - 1)*n;      //n>1时，进行递归调用
	return f;    //将f的值作为函数值返回
}

//中间的例题是*号

//4.12 静态局部变量的值 
int f(int a){  //定义f函数，a为形参
	int b = 0;   //定义b为自动变量.....auto int竟然出错，说是类型说明符的组合无效
	static int c = 3;    //定义c为静态局部变量
	b = b + 1;
	c = c + 1;
	return a + b + c;
}

int main412(){
	int a = 2, i;
	for (i = 0; i < 3; i++)
		cout << f(a) << " ";
	cout << endl;
	return 0;
}

//什么情况下需要用到局部静态变量呢——需要保留函数上一次调用结束时的值
//4.13 输出1~5的阶乘值
int fac1(int);  //函数声明        此处总忘了打分好....晕==
int main413(){
	int i;
	for (i = 1; i <= 5; i++)
		cout << i << "!=" << fac1(i) << endl;
	return 0;
}

int fac1(int n){
	static int f = 1;    //f为静态局部变量，函数结束时f的值不释放
	f = f*n;    //在f原值基础上乘以n
	return f;
}

//4.14 用extern对外部变量作提前引用声明，以扩展程序文件中的作用域
int max2(int, int); //函数声明
void main414(){
	extern int a, b; //对全局变量a,b作提前引用声明
	cout << max2(a, b) << endl;
}
int a = 15, b = -7;    //定义全局变量a,b
int max2(int x, int y){
	int z;
	z = x > y ? x : y;
	return z;
}

//4.15 输入两个整数，要求输出其中的大者，用外部函数实现。即只能本文件使用的——static   可供其他文件调用的——extern
int main415(){
	extern int max(int, int); //声明在本函数中将要调用在其他文件中定义的max函数
	int a, b;
	cout << "请输入两个整数值：" << endl;
	cin >> a >> b;
	cout << max(a, b) << endl;
	return 0;
}






int main(){
	main414();
	return 0;
}
