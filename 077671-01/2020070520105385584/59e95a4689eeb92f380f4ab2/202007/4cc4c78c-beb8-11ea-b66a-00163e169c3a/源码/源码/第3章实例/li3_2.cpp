//����Li3_2.cpp
//����һ�����ࣨPoint����ʾ��������ʵ�ֳ�Ա����
//����Ľ��沿��
#include <iostream>
using namespace std;
class Point  
{
	public:
		void setxy(int,int);
		void displayxy();
    private:
		int X,Y; 
};
//�����ʵ�ֲ���
void Point::setxy(int x,int y)
{
	X=x;
	Y=y;
}
void Point::displayxy()
{
	cout<<"("<<X<<","<<Y<<")"<<endl;
}
