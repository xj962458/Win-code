//�ļ� Li3_4.cpp
//����������ͶԳ�Ա�ķ���
#include <iostream>
#include "Li3_3.h"
using namespace std;
void Point::setxy(int x,int y)
{
	X=x;
	Y=y;
}
void Point::displayxy()
{
	cout<<"("<<X<<","<<Y<<")"<<endl;
}
using namespace std;
int main()
{
	Point p1,*p2;
	p1.setxy(3,4);
	cout<<"��һ�����λ���ǣ�";
    p1.displayxy();
	p2=&p1;
	p2->setxy(5,6);
	cout<<"�ڶ������λ���ǣ�";
  	(*p2).displayxy();
	return 0;
}