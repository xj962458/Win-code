#include <iostream>
#include<cmath>
using namespace std;
#include<windows.h> 
extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();
class point
{
public:
	point(int x, int y);
	int getx() { return X;};
	int gety() { return Y; };
private:
	int X, Y;
};

point::point(int x, int y)
{
	X = x;
	Y = y;
}

class line
{
	point start, end;
public:
	line(point s, point e);  //s和e分别代起始点和终点，需要实现
	void draw();              //绘出这条线
	int getLength();        //求直线的长度,需要实现	
};

line::line(point s, point e):start(s),end(e){}

int line::getLength()
{
	int x = end.getx() - start.getx();
	int y = end.gety() - start.gety();
	return int(sqrt(x * x + y * y));
}
void line::draw()
{
	HWND hwnd = GetConsoleWindow(); //获取控制台窗口句柄
	HDC hdc = GetDC(hwnd); //获取设备控制器句柄
	//system("color 3D");
	MoveToEx(hdc, start.getx(), start.gety(), NULL);//移到画图起始点
	LineTo(hdc, end.getx(), end.gety()); //画线
	ReleaseDC(hwnd, hdc);//释放设备控制器
}

int main()
{
	point p1(20, 20), p2(20, 200);  //实例化两个点对象p1和p2
	line l(p1, p2);   //线段对象
	cout << "直线长度为：" << l.getLength();
	l.draw();
	system("pause");
	return 0;
}
