//����Li3_11.cpp
//ͳ�Ƶ���Ķ�����
#include <iostream>
using namespace std;
//�������
class Point  
{
	public:
		Point(int=0,int=0);
		~Point();
		static void dispcount();
	private:
		int X,Y; 
		static int countP;     //��̬���ݳ�Ա˵��

};
Point::Point (int x,int y)
{
	X=x;
	Y=y;
    cout<<"Constructor is called!"<<endl;
    countP++;//ÿ����һ�����󣬵�����1
}
Point::~Point()
{
	cout<<"Destructor is called!"<<endl;
	countP--;//ÿ����һ�����󣬵�����1
	cout<<"���ڶ������ǣ�"<<Point::countP<<endl;
}
void Point::dispcount()
{
cout<<"���ڶ������ǣ�"<<Point::countP<<endl;
}
//��̬���ݳ�Ա����ͳ�ʼ����
int Point::countP=0;
//��������
int main()
{
  Point A(4,5);			//��һ������
  Point::dispcount();
  Point B(7,8);			//�ڶ�������
  Point::dispcount();
  return 0;
}
