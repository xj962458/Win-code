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
	line(point s, point e);  //s��e�ֱ����ʼ����յ㣬��Ҫʵ��
	void draw();              //���������
	int getLength();        //��ֱ�ߵĳ���,��Ҫʵ��	
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
	HWND hwnd = GetConsoleWindow(); //��ȡ����̨���ھ��
	HDC hdc = GetDC(hwnd); //��ȡ�豸���������
	//system("color 3D");
	MoveToEx(hdc, start.getx(), start.gety(), NULL);//�Ƶ���ͼ��ʼ��
	LineTo(hdc, end.getx(), end.gety()); //����
	ReleaseDC(hwnd, hdc);//�ͷ��豸������
}

int main()
{
	point p1(20, 20), p2(20, 200);  //ʵ�������������p1��p2
	line l(p1, p2);   //�߶ζ���
	cout << "ֱ�߳���Ϊ��" << l.getLength();
	l.draw();
	system("pause");
	return 0;
}
