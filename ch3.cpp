#include<iostream>
#include<iomanip>        //如要要使用I/O流控制符，则要该头文件
#include<cmath> //要用到数学函数的时候，需要的头文件



using namespace std;


//例3.1 各行小数点对齐，利用控制符标准输出输入流
int main31(){
	double a = 123.456, b = 3.14159, c = -3214.67;
	cout << setiosflags(ios::fixed) << setiosflags(ios::right) << setprecision(2);
	cout << setw(10) << a << endl;
	cout << setw(10) << b << endl;
	cout << setw(10) << c << endl;
	return 0;
}

//3.2 输出单个字符 putchar()的使用
int main32(){
	char a, b, c;
	a = 'B'; b = 'O'; c = 'Y';
	putchar(a); putchar(b); putchar(c); putchar('\n');   //putchar() 字符输出函数，向终端输出一个字符
	putchar(66); putchar(79); putchar(89); putchar(10);
	return 0;
}

//3.3 输入单个字符
int main33(){
	char c;
	c = getchar(); putchar(c + 32); putchar('\n');     //getchar()函数 字符输入函数 从终端输入一个字符 且只能接收一个字符
	return 0;
}

//3.4 用scanf和printf函数进行输入和输出
int main34(){
	int a;
	float b;
	char c;
	scanf_s("%d %f %c", &a, &b,&c);
	printf("a=%d,b=%f,c=%c\n", a, b, c);
	return 0;
}

//3.5 求一元二次方程式ax^2+bx+c=0的根 编写顺序结构的程序
int main35(){
	float a, b, c, x1, x2;
	cin >> a >> b >> c;
	x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);     //其实还是需要if else结构，免得sqrt()里面小于0 
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	return 0;
}

//3.6 求三角形的面积
int main36(){
	double a, b, c;
	cout << "Please enter a,b,c:";
	cin >> a >> b >> c;
	if (a + b > c&&b + c > a&&a + c > b){   //复合语句开始
		double s, area;   //在复合语句内定义变量
		s = (a + b + c) / 2;
		area = sqrt(s*(s - a)*(s - b)*(s - c));
		cout << setiosflags(ios::fixed) << setprecision(4);  //指定输出的数包含4位小数
		cout << "area=" << area << endl;    //在复合语句内输出局部变量的值
	} //复合语句结束
	else cout << "It's not a trilateral" << endl;
	return 0;
}

//3.7 输入一个字符，判别是否为大写字母，如果是，将它转换成小写字母，否则不转换，输出最后得到的字符
int main37(){
	char ch;
	cin >> ch;
	ch = (ch >= 'A'&&ch <= 'Z') ? (ch + 32) : ch; //判别ch是否为大写字母，是则转换
	cout << ch << endl;
	return 0;
}

//3.8 判断某一年是否为闰年 编写选择结构的程序
int main38(){
	int year;
	bool leap;
	cout << "please enter year:";  //输出提示
	cin >> year;  //输入年份
	if (year % 4 == 0){         //年份能被4整除
		if (year % 100 == 0){     //能被4又能被100整除
			if (year % 400 == 0)//能被4又能被100，400整除
				leap = true;      //是闰年
			else        //4 100能 400不能
				leap = false;  //不是闰年
		}
		else            //4能 100不能
			leap = true;
	}
	else       //4不能
		leap = false;
	if (leap)
		cout << year << " is";       //若leap为真，就输出年份是
	else
		cout << year << "is not";    //假，不是
	cout << " a leap year." << endl;       //输出闰年
	return 0;
}

//3.9 运输公司对用户计算运费  选择结构
int main39(){
	int c, s;   //s 距离  w 货物重量 p 每公里每吨货物的基本运费 d 折扣 f 总运费 c代表250的倍数即s/250
	float p, w, d, f;
	cout << "Please enter p,w,s:";
	cin >> p >> w >> s;
	if (s >= 3000)c = 12;
	else c = s / 250;
	switch (c){
	case 0:d = 0; break;
	case 1:d = 2; break;
	case 2:
	case 3:d = 5; break;
	case 4:
	case 5:
	case 6:
	case 7:d = 8; break;
	case 8:
	case 9:
	case 10:
	case 11:d = 10; break;
	case 12:d = 15; break;
	}
	f = p*w*s*(1 - d / 100.0);
	cout << "freight=" << f << endl;
	return 0;
}

//3.10 求1+2+3+···+100的和  循环结构
int main310(){
	int i = 1, sum = 0;
	while (i <= 100){
		sum = sum + i;
		i++;
	}
	cout << "sum=" << sum << endl;
	return sum;
}

//3.11用do-while语句写出1+2+3+···+100的和
int main311(){
	int i = 1, sum = 0;
	do{
		sum = sum + i;
		i++;
	}while (i <= 100);
	cout << "sum=" << sum << endl;
	return 0;
}

//3.12 求pi的近似值 循环结构程序
int main312(){
	int s = 1;
	double n = 1, t = 1, pi = 0; //不要把n定义为整型变量，不然会得到t的值为0，当两个整型相除时。
	while ((fabs(t)) > 1e-7){
		pi = pi + t;
		n = n + 2;
		s = -s;
		t = s / n;
	}
	pi = pi * 4;
	cout << "pi=" << setiosflags(ios::fixed) << setprecision(6) << pi << endl;
	return 0;
}

//3.13 求Fibonacci数列前40个数，后面的数是前两个数之和
int main313(){
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i <= 20; i++){  //循环20次
		cout << setw(12) << f1 << setw(12) << f2;   //设备输出字段宽度为12，每次输出两个数
		if (i % 2 == 0)cout << endl;         //每输出完4个数后换行，使每行输出4个数
		f1 = f1 + f2;    //左边的f1代表第三个数，是第一、二个数之和
		f2 = f2 + f1;  //左边的f2代表第四个数，是第二、三个数之和
	}
	return 0;
}

//3.14 求出100~200之间的全部素数
int main314(){
	int m, k, i, n = 0;
	bool prime;   //定义布尔变量
	for (m = 101; m <= 200; m = m + 2){  //判别m是否为素数，m由101变化到200 增量为2
		prime = true;   //循环开始时，使prime为真，即先认为m是素数
		k = int(sqrt(m));  
		for (i = 2; i <= k; i++)
			if (m%i == 0){            //如果能整除 代表m不是素数
				prime = false;      
				break; //终止执行本次循环
			}
			if (prime)         //如果m为素数
			{
				cout << setw(5) << m;   //输出素数m  字段宽度为5
				n = n + 1;
			}
			if (n % 10 == 0) cout << endl; 
	}
		cout << endl;
		return 0;
	
}

//3.15 译密码 把字母变成后面的第4个字母
int main315(){
	char c;
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')){ 
			c = c + 4;
			if ((c > 'Z'&&c<='Z'+4) || c>'z')
				c = c - 26;
		}
		

		cout << c;
	}
	cout << endl;
	return 0;
}

//课后习题 2.输入圆半径、圆柱高 求一系列数据
int main3_2(){
	double r, h, pi = 3.14;   
	double l, s, s1, v, v1; //l:圆周长 s:圆面积 s1:圆球表面积  v:圆球体积 v1:圆柱体积
	cout << "输入圆半径r的值：" << endl;
	cin >> r;
	cout << "输入圆柱高h的值：" << endl;
	cin >> h;
	l = 2 * pi*r;     //l:圆周长
	s = pi*r*r;  //s:圆面积
	s1 = 4 * pi*r*r; //s1:圆球表面积
	v = (4 * pi*r*r*r) / 3;   //v:圆球体积
	v1 = s*h; // v1:圆柱体积
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长l=" << l << endl;
	cout << "圆面积s=" << s << endl;
	cout << "圆球表面积s1=" << s1 << endl;
	cout << "圆球体积v=" << v << endl;
	cout << "圆柱体积v1=" << v1 << endl;
	return 0;
}

//习题 3.输入一个华氏温度，输出摄氏温度
int main3_3(){
	double F, c; //F 华氏温度  c 摄氏温度
	cout << "输入一个华氏温度F：" << endl;
	cin >> F;
	c = (F - 32.0)*(5.0 / 9.0);
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "对应的摄氏温度c=" << c << endl;
	return 0;
}

//习题 4.用getchar输入，分别用cout和putchar输出
int main3_4(){
	char c1,c2;
	cout << "分别输入c1,c2两个字符：（原来输入的时候不用打空格或逗号....）" << endl;
	c1 = getchar();
	c2 = getchar();      //原来输入的时候不用打空格或逗号....
	//putchar(c1); putchar('\n');
	//putchar(c2); putchar('\n');     //getchar()函数 字符输入函数 从终端输入一个字符 且只能接收一个字符

	cout << (int)c1 <<","<< c2 << endl; //用cout输出
	return 0;
}

//习题 9.有三个整数a,b,c，由键盘输入，输出其中的最大值
int main3_9(){
	int a, b, c, m;
	cout << "请输入3个整数a,b,c:" << endl;
	cin >> a >> b >> c;
	m = (a > b) ? a : b;   //我觉得条件表达式很爽啊啊啊啊哈哈哈
	m = (m > c) ? m : c;
	cout << "3个整数中的最大值为：" << m << endl;
	return 0;
}

//习题 10.编写程序输入x,输出y的值
int main3_10(){
	double x, y;
	cout << "输入x的值：" << endl;
	cin >> x;
	if (x < 1)
		y = x;
	else
	  if (x < 10) y = 2 * x - 1;
	  else y = 3 * x - 11;
	cout << "y的值为：" << y << endl;
	return 0;
}

//习题 11.给出一个百分制的成绩，要求输出成绩等级
int main3_11(){
	double grade;   //百分制的成绩	
	int t;
	char k;   //等级
	cout << "请输入百分制的成绩：" << endl;
	cin >> grade;
	if (grade < 0 || grade>100)
		cout << "error!不要调皮噢~" << endl;
	else 
	  if (grade<60)  
		  t = 5;
	  else 
		  t = (int)grade / 10;
	switch (t){
	case 10:
	case 9:k = 'A';  break;
	case 8:k = 'B';  break;
	case 7:k = 'C'; break;
	case 6:k = 'D'; break;
	case 5:k = 'E'; break;
	}
	cout << "对应的成绩等级为：" << k << endl;
	return 0;
}

//习题 12.给出一个不多于5位的正整数，输出：它是几位数；分别打印每一位数字；逆序打印各位数字
int main3_12(){
	int s, t;     //s是输入的正整数；t是正整数的位数
	cout << "请输入一个不多于5位的正整数：" << endl;
	cin >> s;
	if (0 <= s <= 99999){
		if (s > 9999) t = 5;
		else if (s > 999) t = 4;
		else if (s > 99) t = 3;
		else if (s > 9)  t = 2;
		else t = 1;
	}
	else
		cout << "error!" << endl;
	cout << "该整数是" << t << "位数" << endl;
	int t1, t2, t3, t4, t5;// t1代表个位数，t2十位数 t3百位数，t4 千位数，t5万位数  即s=t5t4t3t2t1
	t5 = s / 10000;
	t4 = (s - 10000 * t5) / 1000;
	t3 = (s - 10000 * t5 - 1000 * t4) / 100;
	t2 = (s - 10000 * t5 - 1000 * t4 - 100 * t3) / 10;
	t1 = s - 10000 * t5 - 1000 * t4 - 100 * t3 - 10 * t2;
	switch (t){
	case 5:cout << t5 << "," << t4 << "," << t3 << "," << t2 << "," << t1 << endl;
		cout << t1 << t2 << t3 << t4 << t5 << endl;
		break;
	case 4:cout  << t4 << "," << t3 << "," << t2 << "," << t1 << endl;
		cout << t1 << t2 << t3 << t4 << endl;
		break;
	case 3:cout <<  t3 << "," << t2 << "," << t1 << endl;
		cout << t1 << t2 << t3 << endl;
		break;
	case 2:cout << t2 << "," << t1 << endl;
		cout << t1 << t2 << endl;
		break;
	case 1:cout << t1 << endl;
		cout << t1 << endl;
		break;
	}
	return 0;
}

//习题 13. 用if和switch分别写，从键盘输入当月利润i，求应发的奖金总数
int main3_13_if(){
	double i, s;   //i是当月利润，s是应发奖金总数
	cout << "请输入当月利润i:" << endl;
	cin >> i;
	if (i <= 100000)
		s = 0.1*i;
	else if (i <= 200000)
		s = 0.1 * 100000 + 0.075*(i - 100000);
	else if (i <= 400000)
		s = 0.1 * 100000 + 0.075 * 100000 + 0.05*(i - 200000);
	else if (i<=600000)
		s = 0.1 * 100000 + 0.075 * 100000 + 0.05*200000+0.03*(i - 400000);
	else if (i<=1000000)
		s = 0.1 * 100000 + 0.075 * 100000 + 0.05 * 200000+ 0.03*200000+0.015*(i - 600000);
	else
		s = 0.1 * 100000 + 0.075 * 100000 + 0.05 * 200000 + 0.03 * 200000 +0.015*400000+ 0.01*(i - 1000000);
	cout << "当月应发奖金总数为：" << s << "元~" << endl;
	return s;	
}

//习题 13. 用if和switch分别写，从键盘输入当月利润i，求应发的奖金总数
int main3_13_switch(){
	double i, s;       //i是当月利润，s是应发奖金总数
	int t; 
	t = i / 100000;
	switch (t){
	case 0:s = 0.1*i;
	case 1:
	}
		

}






//习题 24.输出某个图案   //我就是懒....
int main3_24(){
	cout << "*" << endl;
	cout << "* * *" << endl;
	cout << "* * * * *" << endl;
	cout << "* * * * * * *" << endl;
	cout << "* * * * *" << endl;
	cout << "* * *" << endl;
	cout << "*" << endl;
	return 0;
}

//习题 25.







int main(){
	main3_13_if();
	return 0;
}


