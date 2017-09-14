#include<iostream>
using namespace std;

#define PRICE 30    //符号常量

//2.3 计算货款，使用符号常量
int main(){
	int num, total;
	num = 10;
	total = num*PRICE;
	cout << "total=" << total << endl;
	return 0;
}
