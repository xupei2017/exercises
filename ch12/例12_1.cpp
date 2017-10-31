#include<iostream>
#include<string>

using namespace std;
   
//Point->Circle(增加数据成员半径r）->Cylinder(增加数据成员高h）

//声明基类Point类
class Point {
public:
	Point(float x = 0, float y = 0);   //有默认参数的构造函数
	void setPoint(float, float);     //设置坐标值
	float getX() const { return x; }  //读x坐标，getX函数为常成员函数
	float getY() const { return y; }  //读y坐标，getY函数为常成员函数
	friend ostream&operator<<(ostream &, const Point &); //友元重载运算符<<  对这个真是不太了解
	 
protected: //受保护成员
	float x;
	float y;
};

Point::Point(float a, float b) { //对x,y初始化
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

/*
  //测试point
int main() { 
	Point p(3.5, 6.4);
	cout << "x=" << p.getX() << ",y=" << p.getY() << endl; //输出p的坐标值x,y
	p.setPoint(8.5, 6.8);
	cout << "p(new):" << p << endl;

	system("pause");
	return 0;
}
*/

class Circle:public Point { //Circle是Point类的公用派生类
public:
	Circle(float x = 0, float y = 0, float r = 0);  //构造函数
	void setRaius(float); //设置半径值
	float getRadius() const;  //读取半径值
	float area() const; //计算圆面积
	friend ostream &operator<<(ostream &, const Circle &);   //重载运算符"<<"

protected:
	float radius;
};

//定义构造函数，对圆心坐标和半径初始化
Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}
//设置半径值
void Circle::setRaius(float r) 
{ radius = r; }
//读取半径值
float Circle::getRadius() const { return radius; }

//计算圆面积
float Circle::area() const { return 3.14159*radius*radius; }

//重载运算符"<<"，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output, const Circle &c) {
	output << "Center=[" << c.x << "," << c.y 
		<< "],r=" << c.radius << ",area=" << c.area() << endl;
	return output;
}

/*
//测试Circle
int main() { 
	Circle c(3.5, 6.4, 5.2);
	cout << "original circle:\nx=" << c.getX() << ",y=" << c.getY() << ",r=" << c.getRadius()
		<< ",area=" << c.area() << endl; //输出圆心坐标，半径和面积
	c.setRaius(7.5);  //设置半径值
	c.setPoint(5, 5); //设置圆心坐标x,y

	
	cout << "new circle:\n" << c << endl; //用重载运算符"<<"输出圆对象的信息

	Point &pRef = c; //pRef是Point类的引用，被c初始化
	cout << "pRef:" << pRef; //输出pRef的信息


	system("pause");
	return 0;
}
*/


class Cylinder :public Circle {
public:
	Cylinder(float x = 0, float y = 0, float r = 0,float h=0);  //构造函数
	void setHeight(float); //设置圆柱高
	float getHeight() const;  //读取圆柱高
	float area() const; //计算圆表面积
	float volume() const; //计算圆柱体积
	friend ostream &operator<<(ostream &, const Cylinder &);   //重载运算符"<<"

protected:
	float height; //圆柱高
};

//定义构造函数
Cylinder::Cylinder(float a, float b, float r, float h) :Circle(a, b,r),height(h) {}
//设置圆柱高的函数
void Cylinder::setHeight(float h)
{
	height = h;
}
//读取圆柱高的函数
float Cylinder::getHeight() const { return height; }

//计算圆表面积
float Cylinder::area() const { return 2 * Circle::area() + 2 * 3.14159*radius *height; }

//计算圆柱体积
float Cylinder::volume() const {
	return Circle::area()*height;
}

//重载运算符"<<"
ostream &operator<<(ostream &output, const Cylinder &cy) {
	output << "Center=[" << cy.x << "," << cy.y
		<< "],r=" << cy.radius <<",h="<<cy.height<<
		"\narea=" << cy.area() << ",volume=" << cy.volume()<<endl;
	return output;
}

//测试Cylinder
int main() {
	Cylinder cy1(3.5, 6.4, 5.2, 10);
	cout << "original Cylinder:\nx=" << cy1.getX() << ",y=" << cy1.getY() << ",r=" << cy1.getRadius()
		<<",h="<<cy1.getHeight()<< "\narea=" << cy1.area() 
		<< ",volume=" << cy1.volume() << endl; //输出圆柱cy1的数据
	cy1.setHeight(15);  //设置圆柱高
	cy1.setRaius(7.5);  //设置圆半径值
	cy1.setPoint(5, 5); //设置圆心坐标x,y


	cout << "new cylinder:\n" << cy1 << endl; //用重载运算符"<<"输出圆对象的信息

	Point &pRef = cy1; //pRef是Point类的引用，被c初始化
	cout << "pRef as a point:" << pRef; //输出pRef的信息

	Circle &cRef = cy1; //cRef是Circle类的引用
	cout << "cRef as a circle:" << cRef; //输出cRef的信息,作为一个圆输出

	system("pause");
	return 0;
}






