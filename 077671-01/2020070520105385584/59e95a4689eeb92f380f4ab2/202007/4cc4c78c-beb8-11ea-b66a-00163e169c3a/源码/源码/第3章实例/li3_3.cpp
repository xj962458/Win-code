//�ļ� Li3_3.cpp
//�����ʵ�ֲ���
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