#include<iostream>
using namespace std;

//2.2 将小写字母转换为大写字母
int main(){
	char c1, c2;
	c1 = 'a';
	c2 = 'b';
	c1 = c1 - 32;
	c2 = c2 - 32;
	cout << c1 << '\n' << c2 << endl;
	return 0;
}
