#include <iostream>
#include <string>
#include <iomanip>

using namespace std;




//例7.1 定义两个结构体变量student1和student2，成员包括学号、姓名、性别、出生日期、成绩。
//对student2初始化，再把student2的值赋给student1，输出student1的各种成员
int main7_1(){
	struct Date      //声明结构体类型Date
	{
		int month;
		int day;
		int year;
	};

	struct Student  //声明结构体类型Student
	{
		int num;
		char name[20];
		char sex;
		Date birthday;       // 声明birthday为Date类型的成员
		float score;
	}student1, student2 = { 10002, "Wang Li", 'f', 5, 23, 1992, 89.5 };
	//定义Student类型的变量student1,student2，并对student2初始化

	student1 = student2;    //将student2各成员的值赋予student1的相应成员
	cout << "你猜" << endl;
	cout << student1.num << endl;
	cout << student1.name << endl;
	cout << student1.sex << endl;
	cout << student1.birthday.month << '/' << student1.birthday.day << '/' << student1.birthday.year << endl;
	cout << student1.score << endl;
	return 0;
}



// 结构体数组应用举例
//例7.2 对候选人得票的统计程序。设有3个候选人，最终只能有1个人当选为领导。
//现今有10个人参加投票，从键盘先后输入这10个人所投候选人的名字，要求最后输出各候选人得票结果
int main7_2(){
	struct Person{
		char name[20];
		int count;
	};

	Person leader[3] = { "Li", 0, "Zhang", 0, "Sun", 0 }; //定义Person类型的数组，内容为3个候选人的姓名和当前得票数
	int i, j;
	char leader_name[20]; //leader_name为投票人所选的人的姓名
	cout << "请依次输入投票人所选的人的姓名" << endl;
	for (i = 0; i < 10; i++){
		cin >> leader_name; //先后输入10张票上所写的姓名
		for (j = 0; j < 3;j++)  //将票上姓名和3个候选人的姓名比较
		if (strcmp(leader_name, leader[j].name) == 0)  leader[j].count++;
		//如果与某候选人的姓名相同，则加一票
	}
	cout << endl;
	for (i = 0; i < 3; i++){
		cout << leader[i].name << ":" << leader[i].count << endl;
	}
	return 0;
}

//指向结构体变量的指针变量的应用
//例7.3 定义一个结构体变量stu，成员包括学号、姓名、性别、成绩。定义一个指针变量p指向该结构体变量stu
//通过该指针变量输出各成员的值
int main7_3(){
	struct Student{    //声明结构体类型student
		int num;
		string name;
		char sex;
		float score;
	};
	Student stu;       //定义Student类型的变量stu
	Student *p = &stu; //定义p为指向Student类型数据的指针变量并指向stu
	stu.num = 10301;
	stu.name = "Wang Fang";
	stu.sex = 'f';
	stu.score = 89.5;
	cout << stu.num <<" "<<stu.name << " " << stu.sex << " " << stu.score << endl;
	cout << (*p).num << " " << (*p).name << " " << (*p).sex << " " << (*p).score << endl;
	return 0;
}

//如何建立和输出一个简单链表
//例7.4 建立课本上图7.9所示的简单链表，它由3个学生数据的结点组成。输出各结点中的数据
int main7_4(){
	struct student{
		int num;
		float score;
		struct student *next;
	};
	student a, b, c, *head, *p;
	a.num = 31001; a.score = 89.5;   //对结点a的num和score成员赋值
	b.num = 31003; b.score = 90;       //对结点b的num和score成员赋值
	c.num = 31007; c.score = 85;          //对结点c的num和score成员赋值
	head = &a;   //将结点a的起始地址赋予头指针head
	a.next = &b;   //将结点b的起始地址赋予a结点的next成员
	b.next = &c;      //将结点c的起始地址赋予b结点的next成员
	c.next = NULL;       //结点c的next成员不存放其他结点地址
	p = head;   //使p指针指向a结点
	do{
		cout << p->score << " " << p->num <<" "<<p->next<< endl;    //就像数据结构一样 2017 7 25周二
		p = p->next;            //哈哈，输出p->next，就是输出地址
	} while (p != NULL);
	return 0;
}

//例7.5 有一个结构体变量stu，内含学生学号、姓名和3门课的成绩。
//要求在main函数中为各成员赋值，在另一函数print中将它们的值输出
struct Student1{        //声明结构体类型Student1
	int num;
//	char name[20];
	string name;
	float score[3];
};

int main7_5(){
	void print(Student1);    //函数声明，形参类型为结构体Student1
	Student1 stu; //定义结构体变量
	stu.num = 12345;
	stu.name = "Li Fang";
	stu.score[0] = 67.5;
	stu.score[1] = 89;
	stu.score[2] = 78.5;
	print(stu);    //调用print函数，输出stu各成员的值
	return 0;
}

void print(Student1 stu){
	cout << stu.num << " " << stu.name << " " << stu.score[0] 
		<< " " << stu.score[1] << " " << stu.score[2] << endl;
}

//例7.6 临时开辟一个存储空间以存放一个结构体数据
int main7_6(){
	struct Student{       //声明结构体类型Student
		string name;
		int num;
		char sex;
	};
	Student *p;  //定义指向结构体类型Student的数据的指针变量p
	p = new Student;   //用new运算符开辟一个存放Student型数据的空间，把地址赋给p
	p->name = "Wang Fang";
	p->num = 10123;
	p->sex = 'm';
	cout << p->name << endl << p->num << endl << p->sex << endl; //输出各成员的值
	delete p;  //撤销该空间
	return 0;
}

//枚举类型
//例7.7 口袋中有红、黄、蓝、白、黑5中颜色的球若干个。每次从口袋中任意取出3个球
//得到3种不同颜色的球的可能取法，输出每种排列的情况
int main7_7(){
	enum color{red,yellow,blue,white,black}; //声明枚举类型color
	color pri;            //定义color类型的变量pri
	int i, j, k, n = 0, loop;       //n是累计不同颜色的组合数
	for (i = red; i <= black; i++)
	  for (j = red; j <= black; j++)
	  if (i != j){              //若前两个球的颜色不同
		  for (k = red; k <= black;k++)  //只有前两个球的颜色不同，才需要检查第3个球的颜色
		  if ((k != i) && (k != j)){
			  n = n + 1;
			  cout << setw(3) << n;
			  for (loop = 1; loop <= 3; loop++) //先后对3个球作处理
			  {
				  switch (loop) //loop的值先后为1，2，3
				  {
				  case 1:pri = color(i); break;
				  case 2:pri = color(j); break;
				  case 3:pri = color(k); break;
				  default:break;
				  }
				  switch (pri)     //判断pri的值，输出相应的颜色
				  {
				  case red:cout << setw(8) << "red"; 
					  break;
				  case yellow:cout << setw(8) << "yellow";
					  break;
				  case blue:cout << setw(8) << "blue";
					  break;
				  case white:cout << setw(8) << "white";
					  break;
				  case black:cout << setw(8) << "black";
					  break;
				  default:
					  break;
				  }
			  }
			  cout << endl;
		  }
	  }
	  cout << "total:" << n << endl;       //输出符合条件的组合的总个数n
	  return 0;
}

















int main(){
	main7_7(); //我的天啦，这里加上int main7_1()就不行了，不能加int,只能直接用。。。
	return 0;
}
