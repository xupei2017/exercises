#include <iostream>
#include<string>
#include <stdlib.h>
#include<cstring>

using namespace std;

//Point->Circle(增加数据成员半径r）->Cylinder(增加数据成员高h）
//声明抽象基类Shape
class Shape {
public:
	virtual float area() const { return 0.0; } //虚函数
	virtual float volume() const { return 0.0; } //虚函数
	virtual void shapeName() const = 0; //纯虚函数 就是声明虚函数时被初始化为0的函数。
	
};




//声明Point类
class Point:public Shape{ //Point类是Shape类的公用派生类
public:
	Point(float= 0, float = 0);   //声明构造函数
	void setPoint(float, float);     //设置坐标值
	float getX() const { return x; }  //读x坐标，getX函数为常成员函数
	float getY() const { return y; }  //读y坐标，getY函数为常成员函数
	virtual void shapeName() const { cout << "Point:"; } //对虚函数进行再定义
	friend ostream&operator<<(ostream &, const Point &); //友元重载运算符<<  对这个真是不太了解

protected: //受保护成员
	float x;
	float y;
};

Point::Point(float a, float b) { //定义构造函数//对x,y初始化
	x = a;
	y = b;
}

//设置x,y的坐标值
void Point::setPoint(float a, float b) { //对x,y赋予新值
	x = a; y = b;
}

//重载运算符“<<"，使之能输出点的坐标
ostream &operator<<(ostream &output, const Point &p) {
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}




class Circle :public Point { //Circle是Point类的公用派生类
public:
	Circle(float x = 0, float y = 0, float r = 0);  //构造函数
	void setRadius(float); //设置半径值
	float getRadius() const;  //读取半径值
	virtual float area() const; //对虚函数进行再定义
	virtual void shapeName() const 
	{ cout<< "Circle:"; }      //对虚函数进行再定义
	friend ostream &operator<<(ostream &, const Circle &);   //重载运算符"<<"

protected:
	float radius;
};

//声明Circle类成员函数
Circle::Circle(float a, float b, float r) :Point(a, b), radius(r) {}//定义构造函数

void Circle::setRadius(float r) { radius = r; }

float Circle::getRadius() const { return radius; }

float Circle::area() const { return 3.14159*radius*radius; }

//重载运算符"<<"，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output, const Circle &c) {
	output << "Center=[" << c.x << "," << c.y
		<< "],r=" << c.radius  << endl;
	return output;
}


class Cylinder :public Circle {
public:
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);  //构造函数
	void setHeight(float); //设置圆柱高
	
	virtual float area() const; //重载虚函数
	virtual float volume() const; //重载虚函数
	virtual void shapeName() const {cout<< "Cylinder:"; } //重载虚函数
	friend ostream &operator<<(ostream &, const Cylinder &);   //重载运算符"<<"

protected:
	float height; //圆柱高
};

//定义构造函数
Cylinder::Cylinder(float a, float b, float r, float h) :Circle(a, b, r), height(h) {}
//设置圆柱高的函数
void Cylinder::setHeight(float h)
{
	height = h;
}


//计算圆表面积
float Cylinder::area() const { return 2 * Circle::area() + 2 * 3.14159*radius *height; }

//计算圆柱体积
float Cylinder::volume() const {
	return Circle::area()*height;
}

//重载运算符"<<"
ostream &operator<<(ostream &output, const Cylinder &cy) {
	output << "Center=[" << cy.x << "," << cy.y
		<< "],r=" << cy.radius << ",h=" << cy.height <<
		"\narea=" << cy.area() << ",volume=" << cy.volume() << endl;
	return output;
}


int main() {
	Point point(3.2, 4.5);
	Circle circle(2.4, 1.2, 5.6);
	Cylinder cylinder(3.5, 6.4, 5.2, 10.5);
	point.shapeName();  //用对象名建立静态关联
	cout << point << endl; //输出点的数据

	circle.shapeName();  //静态关联
	cout << circle << endl; //输出圆柱的数据

	cylinder.shapeName();
	cout << cylinder << endl << endl;

	Shape *pt;
	pt = &point;
	pt->shapeName();
	cout << "x=" << point.getX() << ",y=" << point.getY() << "\narea=" << pt->area()
		<< "\nvolume=" << pt->volume() << "\n\n";

	pt = &circle;
	pt->shapeName();
	cout << "x=" << circle.getX() << ",y=" << circle.getY() << "\narea=" << pt->area()
		<< "\nvolume=" << pt->volume() << "\n\n";

	pt = &cylinder;
	pt->shapeName();
	cout << "x=" << cylinder.getX() << ",y=" << cylinder.getY() << "\narea=" << pt->area()
		<< "\nvolume=" << pt->volume() << "\n\n";

	

	system("pause");
	return 0;
}






