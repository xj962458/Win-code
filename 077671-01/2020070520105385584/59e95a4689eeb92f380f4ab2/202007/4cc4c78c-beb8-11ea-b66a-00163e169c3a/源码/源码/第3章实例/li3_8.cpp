//��3_8.cpp
//���thisָ�����ʽʹ��
#include <iostream>
using namespace std;
class Point
{
	public:
		Point(int=0, int=0 );
		void displayxy();
    private:
		int X,Y;
};
Point::Point(int x,int y)
{
	X=x;
	Y=y;
}
void Point::displayxy()
{
	cout<<X<<endl;//�൱��cout<< this->X<<endl;
	cout<<Y<<endl;//�൱��cout<< this->Y<<endl;
}

int main()
{
   Point obj1(10,20), obj2(8,9),*p;
   p=&obj1;       //pָ�����obj1           
   p->displayxy();
   p=&obj2;      //pָ�����obj2
   p->displayxy();
   return 0;
}
