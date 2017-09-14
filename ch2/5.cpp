#include<iostream>
using namespace std;

//2.5 有符号数据传送给无符号变量
int main25(){
	unsigned short a;
	short int b = -1;
	a = b;
	cout << "a=" << a << endl;
	return 0;
}           //运行结果是a=65535 因为b是负数，补码形式为1111 1111 1111 1111，传送给a了。
