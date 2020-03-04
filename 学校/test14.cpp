//����Li3_7.cpp
//�˽⿽�����캯�����÷�
//����Ľ��沿��
#include <iostream>
using namespace std;
class Point
{
public:
    Point(int = 0, int = 1);
    Point(const Point &);
    void displayxy();
    ~Point();

private:
    int X, Y;
};
//�����ʵ�ֲ���
Point::Point(int x, int y)
{
    X = x;
    Y = y;
    cout << "Constructor is called! ";
    displayxy();
}
Point::Point(const Point &p)
{
    X = p.X;
    Y = p.Y;
    cout << "Copy constructor is called! ";
    displayxy();
}
Point::~Point()
{
    cout << "Destructor is called! ";
    displayxy();
}
void Point::displayxy()
{
    cout << "(" << X << "," << Y << ")" << endl;
}
Point func(Point p)
{
    int x = 10 * 2;
    int y = 10 * 2;
    Point pp(x, y);
    return pp;
}
int main()
{
    Point p1(3, 4), p2;
    p2 = p1;
    //Point p2=p1;//�����һ������ȥ��ʼ���������һ������ʱ��
    //p2=func(p1);//�������β�����Ķ���,�Һ����ķ���ֵ����Ķ���
    return 0;
}