//����Li3_16.cpp
//��̬��Ա������ʹ�á�
#include <iostream>
using namespace std;
class Point  
{
	public:
		Point(int=0,int=0);
       	static void displayxy( Point p);
	private:
		int X,Y; 
};
Point::Point (int x,int y)
{
	X=x;
	Y=y;
}

void Point::displayxy( Point p)
{
	cout<<"("<<p.X<<","<<p.Y<<")"<<endl;//���÷Ǿ�̬���ݳ�Ա
}
//��������
int main()
{
  Point A(4,5);	//��һ������
  cout<<"��һ�����λ���ǣ�";
  Point::displayxy(A); 
  Point B(7,8); 	//�ڶ�������
  cout<<"�ڶ������λ���ǣ�";
  Point::displayxy(B);
  return 0;
}



