//����Li3_1.cpp
//����һ�����ࣨPoint����ʾ��������ʵ�ֳ�Ա����
#include <iostream>
using namespace std;
class Point  
{
	public:
		void setxy(int,int)
		{
			X=x;
			Y=y;
		}
		void displayxy()
			{
				cout<<"The postion of point:";
				cout<<"("<<X<<","<<Y<<")"<<endl;
			}
	private:
		int X,Y; 
};
