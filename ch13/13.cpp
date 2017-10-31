#include <iostream>
#include <cmath>
#include<iomanip>
#include<fstream>
#include <string>
#include <strstream>

using namespace std;

//例13.1 有一元二次方程ax^2+bx+c=0
//用cerr流输出有关信息,用cerr在显示器上显示出错信息
//cerr是不经过缓冲区直接向显示器上输出有关信息，而clog中的信息存放在缓冲区中，
//缓冲区满后或遇到endl时向显示器输出
int main13_1() {
	float a, b, c, disc;
	cout << "Please input a,b,c:";
	cin >> a >> b >> c;
	if (a == 0) {
		cerr << "a is equal to zero,error!" << endl;
	}
	else
		if ((disc = b*b - 4 * a*c) < 0)
			cerr << "disc=b*b-4*a*c<0" << endl;
		else {
			cout << "x1=" << (-b + sqrt(disc)) / (2 * a) << endl;
			cout << "x2=" << (-b - sqrt(disc)) / (2 * a) << endl;
		}

		cout <<endl<< setfill('*') << setw(10) << "xupei" << endl;
	
	return 0; 

}

//例13.2用流对象的成员函数控制输出数据格式
int main13_2() {
	int a = 21;
	cout.setf(ios::showbase); //显示基数符号(0x或0)
	cout << "dec:" << a << endl; //默认以十进制形式输出a
	cout.unsetf(ios::dec);  //终止十进制的格式设置
	cout.setf(ios::hex);   //设置以十六进制输出的状态
	cout << "hex:" << a << endl; //以十六进制形式输出a
	cout.unsetf(ios::hex); //终止十六进制的格式设置
	cout.setf(ios::oct);   //设置以八进制输出的状态
	cout << "oct:" << a << endl; //以八进制形式输出a
	char *pt = "China"; //pt指向字符串"China"
	cout.width(10);    //指定域宽为10
	cout << pt << endl; //输出字符串
	cout.width(10); //指定域宽为10
	cout.fill('*'); //指定空白处以'*'填充
	cout << pt << endl;    //输出字符串
	double pi = 22.0 / 7.0;  //输出pi值
	cout.setf(ios::scientific); //指定用科学记数法输出
	cout << "pi=";   //输出"pi="
	cout.width(14); //指定域宽为14
	cout << pi << endl;  //输出pi值
	cout.unsetf(ios::scientific); //终止科学记数法状态
	cout.setf(ios::fixed); //指定用定点形式输出
	cout.width(12); //指定域宽为12
	cout.setf(ios::showpos); //正数输出"+"号
	cout.setf(ios::internal); //数符出现在左侧
	cout.precision(6); //保留6位小数
	cout << pi << endl;  //输出pi，注意数符+的位置
	return 0;
}

//例13.3 有一个字符串，要求按相反的顺序输出
//流成员函数 cout.put('a')
int main13_3() {
	char *p = "BASIC";    //字母指针指向'B'
	for (int i = 4; i >= 0; i--)     //从最后一个字符开始输出
		cout.put(*(p + i));
		cout.put('\n');
	
	return 0;
}

//例13.4 用get函数读入字符
//无参数的get函数 cin.get()
int main13_4() {
	int c;
	cout << "enter a sentence:" << endl;
	while ((c = cin.get()) != EOF)
		cout.put(c);
	return 0;
}

//例13.5 逐个读入一行字符，将其中的非空格字符输出
int main13_5() {
	char c;
	while (!cin.eof()) //eof()为假表示未遇到文件结束符
		if ((c = cin.get()) != ' ') //检查读入的字符是否为空格字符
			cout.put(c);
	return 0;
}

//例13.6 peek函数和putback函数的用法
int main13_6() {
	char c[20];
	int ch;
	cout << "please enter a sentence:" << endl;
	cin.getline(c, 15, '/');
	cout << "The first part is:" << c << endl;
	ch = cin.peek();
	cout << "The next charactor(ASCII code)is:" << ch << endl;
	cin.putback(c[0]);
	cin.getline(c, 15, '/');
	cout << "The second part is:" << c << endl;
	return 0;
}

//例13.8 有一个整型数组，含10个元素，从键盘输入10个整数给数组，
//将此数组送到磁盘文件中存放
int main13_8() {
	int a[10];
	ofstream outfile("f1.dat", ios::out); //定义文件流对象，打开磁盘文件f1.dat
	if (!outfile) {
		cerr << "open error!" << endl;//如果打开失败，outfile返回0值
		exit(1);
	}
	cout << "enter 10 interger numbers:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		outfile << a[i] << " "; //向磁盘文件f1.dat输出数据
	}
	outfile.close();
	return 0;
}

//例13.9 从例13.8建立的数据文件f1.dat中读入10个整数放在数组中，
//找出并输出10个数中的最大者和它在数组中的序号
int main13_9() {
	int a[10], max, i, order;
	ifstream infile("f1.dat", ios::in | ios::_Nocreate);
	//定义输入文件流对象，以输入方式打开磁盘文件f1.dat
	if (!infile) {
		cerr << "open error!" << endl;
		exit(1);
	}
	for (i = 0; i < 10; i++) {
		infile >> a[i];
		cout << a[i] << " ";
	}
	cout << endl;
	max = a[0];
	order = 0;
	for (i = 0; i < 10; i++)
		if (a[i]>max) {
			max = a[i];
			order = i;
		}
	cout << "max=" << max << endl << "order=" << order << endl;
	infile.close();
	return 0;
}

/*
例13.10 从磁盘读入一行字符，把其中的字母字符依次存放在磁盘文件f2.dat中。
再把它从磁盘文件读入程序，将其中的小写字母改为大写字母，再存入磁盘文件f3.dat
*/

//save_to_file函数从键盘读入一行字符并将其中的字母存入磁盘文件
void save_to_file() {
	ofstream outfile("f2.dat");
	//定义输出文件流对象outfile，以输出方式打开磁盘文件f2.dat
	if (!outfile) {
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	char c[80];
	cin.getline(c, 80); //从键盘读入一行字符
	for (int i = 0; c[i] != 0;i++)//对字符逐个处理，直到遇到‘/0’为止
		if (c[i] >= 65 && c[i] <= 90 || c[i] >= 97 && c[i] <= 122) { //如果是字母字符
			outfile.put(c[i]);//将字母字符传入磁盘文件f2.dat
			cout << c[i]; //同时送显示器显示
		}
	cout << endl;
	outfile.close();  //关闭f2.dat
	
}

//从磁盘文件f2.dat读入字母字符，将其中的小写字母改为大写字母，再存入f3.dat
void get_from_file() {
	char ch;
	ifstream infile("f2.dat",ios::in|ios::_Nocreate);
	//定义输入文件流infile,以输入方式打开磁盘文件f2.dat
	if (!infile) {
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	ofstream outfile("f3.dat");
	//定义输出文件流对象outfile，以输出方式打开磁盘文件f2.dat
	if (!outfile) {
		cerr << "open f3.dat error!" << endl;
		exit(1);
	}
	while (infile.get(ch)) {
		if (ch >= 97 && ch <= 122) //判断ch是否为小写字母
			ch = ch - 32; //将小写字母变为大写字母
		outfile.put(ch); //将大写字母存入磁盘文件f3.dat
		cout << ch; //同时在显示器输出
	}
	cout << endl;
	infile.close(); //关闭磁盘文件f2.dat
	outfile.close(); //关闭磁盘文件f3.dat
	
}

//例13.10
int main13_10() {
	save_to_file();
	//调用save_to_file(),从键盘读入一行字符并将其中的字母存入磁盘文件f2.dat
	get_from_file(); //调用get_from_file()，从f2.dat读入字母字符，改为大写字母，再存入f3.dat
	
	return 0;
}

//例13.11 将一批数据以二进制形式存放在磁盘文件中
struct student {
	char name[20];
	int num;
	int age;
	char sex;
};

int main13_11() {
	student stud[] = { "Li",1001,18,'f',"Fang",1002,19,'m',"Wang",1004,17,'f' };
	ofstream outfile("stud.dat", ios::binary);
	if (!outfile) {
		cerr << "open error!" << endl;
		abort(); //退出程序
	}
	for (int i = 0; i < 3; i++) {
		outfile.write((char *)&stud[i], sizeof(stud[i]));
		cout << stud[i].name <<"  "<< stud[i].num << "  " 
			<< stud[i].age << "  " << stud[i].sex << endl; //测试有没有写进去，因为打开是乱码啊
	}
		
	outfile.close();
	return 0;
}

//例13.12 将执行例13.11程序时存放在磁盘文件中的二进制形式的数据读入内存并在显示器上显示


int main13_12() {
	student stud[3];
	int i;
	ifstream infile("stud.dat", ios::binary);
	if (!infile) {
		cerr << "open error!" << endl;
		abort(); //退出程序
	}
	for (i = 0; i < 3; i++){
		infile.read((char *)&stud[i], sizeof(stud[i]));
	
	
		cout << "NO." << i + 1 << endl;
		cout << "name:" << stud[i].name << endl;
		cout << "num:" << stud[i].num << endl;
		cout << "age:" << stud[i].age << endl;
		cout << "sex:" << stud[i].sex << endl;
		cout << endl;
	}
	infile.close();
	return 0;
}

//例13.14 将一组数据保存在字符数组中
struct student1 {
	int num;
	char name[20];
	float score;
};

//例13.14 将一组数据保存在字符数组中
int main13_14() {
	student1 stud[3] = { 1001,"Li",78,1002,"Wang",89.5,1004,"Fang",90 };
	char c[30]; //用户定义的字符数组
	ostrstream strout(c, 30);//建立输出字符串流，与数组c建立关系，缓冲区长30
	for (int i = 0; i < 3; i++) //向字符数组c写3个学生的数据
		strout << stud[i].num  << stud[i].name  << stud[i].score << endl;
	strout << ends; //ends是C++的I/O操作符，插入一个'\0'
	cout << "array c:" <<endl<< c << endl; //显示字符数组c中的字符
	return 0;
}

//例13.15 在一个字符数组c中存放了10个整数，以空格相间隔，要求将它们放到整型数组中，
//再按大小排序，然后再存放回字符数组c中。
int main13_15() {
	char c[50] = "12 34 65 -23 -32 33 61 99 321 32";
	int a[10], i, j;
	int temp = 0;
	cout << "array c:" << c << endl; //显示字符数组中的字符串
	istrstream strin(c, sizeof(c)); //建立输入串流对象strin并与字符数组c关联
	for (i = 0; i < 10; i++) {
		strin >> a[i];
	}
	cout << "array a:";
	for (i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	for (i = 0; i < 9; i++){
		for (j = i+1; j < 10; j++) 
			if (a[i]>a[j]) { //选择法升序
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}
	ostrstream strout(c, sizeof(c)); 
	for (i = 0; i < 10; i++)
		strout << a[i] << " ";
	strout << ends;  //加入'\0'
	cout << "array c:" << c << endl; //显示字符数组c
	return 0;
}









int main() {
	main13_15();
	system("pause");
	return 0;

}