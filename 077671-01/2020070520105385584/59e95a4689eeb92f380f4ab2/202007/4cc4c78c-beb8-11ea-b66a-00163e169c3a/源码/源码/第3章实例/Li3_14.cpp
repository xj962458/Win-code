//����Li3_14.cpp
//ͳ�Ƶ���Ķ�����
#include <iostream>
using namespace std;
//�������
class Point  
{
	public:
		static int countP;     //��̬���ݳ�Ա˵��
		Point(int=0,int=0);
		~Point();
	private:
		int X,Y; 

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
	cout<<"���ڶ������ǣ�"<<countP<<endl;
}
//��̬���ݳ�Ա����ͳ�ʼ����
int Point::countP=0;
//��������
int main()
{
  Point A(4,5);			//��һ������
  cout<<"���ڶ������ǣ�"<<A.countP<<endl;
  Point B(7,8);			//�ڶ�������
  cout<<"���ڶ������ǣ�"<<Point::countP<<endl;
  return 0;
}
