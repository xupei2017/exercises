#include <iostream>
#include <iomanip>
#include <string>
using namespace std;




//例5.1 定义整型数组，0~9赋给数组元素a[0]~a[9],再按a[9]~a[0]的顺序输出
int main5_1()
{
	int i, a[10];
	for (i = 0; i <= 9; i++) //使a[0]~a[9]的值为0~9
		a[i] = i;
	for (i = 9; i >= 0; i--)
		cout << a[i] << ","; //按a[9]~a[0]的顺序输出
	cout << endl;     //换行
	return 0;
}

//例5.2用数组问题来处理求Fibonacci问题
int main5_2(){
	int i;
	int f[20] = { 1, 1 }; //f[0]=1,f[1]=1
	for (i = 2; i < 20; i++)
		f[i] = f[i - 1] + f[i - 2];
	for (i = 0; i < 20; i++)  //输出20个数时，每5个数一行
	{
		if (i % 5 == 0)cout << endl;
		cout << setw(8) << f[i];
	}
	cout << endl;
	return 0;
}

//例5.3 编写程序，用起泡法对10个数排序（由小到大) 设定a[11]  a[0]不用，只用a[1]~a[10]
int main5_3(){
	int a[11];
	int i, j, t;
	cout << "input 10 numbers:" << endl;
	for (i = 1; i < 11; i++)
		cin >> a[i];
	cout << endl;
	for (j = 1; j <= 9;j++)
	for (i = 1; i <= 10 - j;i++)
	if (a[i]>a[i + 1])
	{
		t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
	}
	cout << "the sorted numbers:" << endl;
	for (i = 1; i < 11; i++)
		cout << a[i] << ",";
	cout << endl;
	return 0;
}

//例5.4 将一个2*3的二维数组行列元素互换，存到3*2的数组中
int main5_4(){
	int a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	int b[3][2], i, j;
	cout << "array a:" << endl;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
			b[j][i] = a[i][j];
		}
		cout << endl;
	}
	cout << "array b；" << endl;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 2; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	return 0;
}

//例5.5 有一个3*4矩阵，求出其中值最大的那个元素，并输出行号和列号
int main5_5(){
	int i, j, row = 0, colum = 0, max;
	int a[3][4] = { { 5, 12, 23, 56 }, { 19, 28, 37, 46 }, { -12, -34, 6, 8 } };
	max = a[0][0];
	for (i = 0; i < 3;i++)
	for (j = 0; j < 4;j++)
	if (a[i][j]>max)
	{
		max = a[i][j];
		row = i;
		colum = j;
	}
	cout << "max=" << max << endl;
	cout << "row=" << row << endl;
	cout << "colum=" << colum << endl;
	return 0;
}

//例5.6 用函数处理例5.5——用数组元素作函数实参
int main5_6(){
	int max_value(int x, int max); //函数声明
	int i, j, row = 0, colum = 0, max;
	int a[3][4] = { { 5, 12, 23, 56 }, { 19, 28, 37, 46 }, { -12, -34, 6, 8 } };  //数组初始化
	max = a[0][0];
	for (i = 0; i < 3; i++)
	for (j = 0; j < 4; j++)
	{   
		max = max_value(a[i][j], max);  //调用函数
		if (max==a[i][j]){ //好吧，此处刚刚写了=，结果就出错了。要用==
			row = i;
			colum = j;
		}	
	}
	cout << "max=" << max << endl;
	cout << "row=" << row << endl;
	cout << "colum=" << colum << endl;
	return 0;
}

int max_value(int x, int max){
	if (x > max) return x;
	else return max;
}

//例5.7 用选择法对数组中的10个数按由小到大排序
int main5_7(){
	void select_sort(int array[], int n); //函数声明
	int a[10], i;
	cout << "enter the original array:" << endl;
	for (i = 0; i < 10; i++)
		cin >> a[i];
	cout << endl;
	select_sort(a, 10); //函数调用，数组名作实参
	cout << "the sorted array:" << endl;
	for (i = 0; i < 10; i++)   //输出10个已排好序的数
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void select_sort(int array[], int n){      //形参array是数组名
	int i, j, k, t;
	for (i = 0; i < n - 1; i++){
		k = i;
		for (j = i + 1; j < n;j++)
		if (array[j] < array[k])k = j;
		t = array[k]; array[k] = array[i]; array[i] = t;
	}
}

//例5.8 有一个3*4的矩阵，求矩阵中所有元素的最大值，用函数处理
int main5_8(){
	int max_value1(int array[][4]); //函数声明
	int a[3][4] = { { 11, 32, 45, 67 }, { 22, 44, 66, 88 }, { 15, 72, 43, 37 } }; //定义数组并初始化
	cout << "max value is " << max_value1(a) << endl;
	return 0;
}

int max_value1(int array[][4]){
	int i, j, max;
	max = array[0][0];
	for (i = 0; i < 3;i++)
	for (j = 0; j < 4;j++)
	if (array[i][j]>max) max = array[i][j];     //返回最大值
	return max;
}

//例5.9 设计和输出一个钻石图形
int main5_9(){
	char diamond[][5] = { { ' ', ' ', '*' }, { ' ', '*', ' ', '*' }, { '*', ' ', ' ', ' ', '*' }, { ' ', '*', ' ', '*' }, { ' ', ' ', '*' } };
	int i, j;
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++)
			cout << diamond[i][j]; //逐个引用数组元素，每次输出一个字符
		cout << endl;
	}
	return 0;
}

//引申..输出一个爱心。。 调整了半天还是勉勉强强的爱心啊啊啊。。。感觉直接每一行输出来得快，比数组。
int main5_9_1(){
	char love[][9] = { { ' ', '*', ' ', ' ', ' ', ' ', ' ', '*' }, { '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*' }, { ' ', '*', ' ', ' ', ' ', ' ', ' ', '*' }, { ' ', ' ', ' ', ' ', '*' } };
	int i, j;
	cout << "I love you~" << endl;
	cout << endl;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 9; j++)
			cout << love[i][j]; //逐个引用数组元素，每次输出一个字符
		cout << endl;
	}
	return 0;
}

//字符数组应用举例 
//例5.10 有3个国家名，要求找出按字母排序排在最前面的国家。要求用函数调用
int main5_10(){
	void smallest_string(char str[][30], int i); //函数声明
	int i;
	char country_name[3][30]; //定义二维字符数组。
	cout << "请输入3个国家的名字;" << endl;
	for (i = 0; i < 3; i++)
		cin >> country_name[i]; //输入3个国家名
	smallest_string(country_name, 3); //调用smallest_string函数
	return 0;
}

void smallest_string(char str[][30], int n){
	int i;
	char string[30];
	strcpy_s(string, str[0]);
	for (i = 0; i < n;i++)
	if (strcmp(str[i], string) < 0)
		strcpy_s(string, str[i]);
	cout << endl << "the smallest string is:" << string << endl; //输出最小的字符串

}

//例5.11 输入3个字符串，要求将字母按由小到大的顺序输出
int main5_11(){
	string string1, string2, string3, temp;
	cout << "please input three strings:";
	cin >> string1 >> string2 >> string3;
	if (string2 > string3){ temp = string2; string2 = string3; string3 = temp; }
	if (string1 <= string2)
		cout << string1 << " " << string2 << " " << string3 << endl;
	else if (string1<=string3) 
		cout << string2 << " " << string1 << " " << string3 << endl;
	else
		cout << string2 << " " << string3 << " " << string1 << endl;
	return 0;
}

//例5.12  定义的全局字符串数组
string name[50], num[50]; // 定义两个字符串数组，分别存放姓名和学号。
int n;  //n是实际的学生数。

//例5.12 一个班有n个学生，需要把每个学生的姓名和学号输入计算机中保存。
//然后输入姓名查找学生，有则输出姓名和学号，无则输出“本班无此人”
int main5_12(){
	void input_data(); //函数声明
	void search(string find_name); //函数声明
	string find_name; //定义字符串变量，find_name是要找的学生
	cout << "please input number of this class："; //输入提示：请输入本班学生的人数
	cin >> n; //输入学生数
	input_data(); //调用input_data函数，输入学生数据
	cout << "please input name you want find:"; //输入提示：请输入你要找的学生姓名
	cin >> find_name;
	search(find_name); //调用search函数，寻找该学生姓名
	return 0;
}

void input_data(){ //函数首部
	int i;
	for (i = 0; i < n; i++){
		cout << "input name and NO. of student" << i + 1 << ":"; //输入提示
		cin >> name[i] >> num[i]; //输入n个学生的姓名和学号
	}
}

void search(string find_name){ //函数首部
	int i;
	bool flag = false;
	for (i = 0; i < n;i++)
	if (name[i] == find_name){
		cout << name[i] << "has been found,his number is " << num[i] << endl; //输出姓名和学号
		flag = true;
		break;
	}
	if (flag == false) cout << "can't find this name" << endl;   //如果找不到，输出“找不到”的信息
}








int main(){
	main5_12();
	return 0;
}
