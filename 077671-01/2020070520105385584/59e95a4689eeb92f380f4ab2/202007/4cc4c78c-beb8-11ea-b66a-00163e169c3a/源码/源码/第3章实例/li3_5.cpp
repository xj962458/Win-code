//����Li3_5.cpp
//ʾ�����캯�����÷���
//����Ľ��沿��
#include <iostream>
using namespace std;
class Point  
{
	public:
		Point();//Ĭ�Ϲ��캯��
	    Point(int);//��1���������캯��
		Point(int,int);//��2���������캯��
		void displayxy();
    private:
		int X,Y; 
};
//�����ʵ�ֲ���
Point::Point ()
{
	X=7;
	Y=8;
    cout<<"Default constructor is called! ";
    displayxy();
}
Point::Point (int x)
{
	X=x;
	Y=8;
    cout<<"Constructor is called! ";
    displayxy();
}
Point::Point (int x,int y)
{
	X=x;
	Y=y;
    cout<<"Constructor is called! ";
    displayxy();
}
void Point::displayxy()
{
	cout<<"("<<X<<","<<Y<<")"<<endl;
}
int main()
{
    Point p1(3,4),p2[2]={5,6},p3;
    return 0;
}
