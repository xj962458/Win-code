//��3_9.cpp
//���thisָ�����ʽʹ��
#include <iostream>
using namespace std;
class Point
{
	public:
		Point(int x,int y) {X=x;Y=y;} //�вι��캯��
        Point(){X=0;Y=0;} //�޲ι��캯��
        void copy(Point& obj);
        void displayxy();
	private:
		int X,Y;
};
void Point::copy(Point& obj)
{
   if (this!=&obj) // thisָ�����ʽʹ�ã�����������ĸ���
   *this=obj;
}
void Point::displayxy()
{ 
   cout<<X<<" ";
   cout<<Y<<endl;
}

int main()
{
   Point obj1(10,20), obj2;
   obj2.copy(obj1);          
   obj1.displayxy();
   obj2.displayxy();
   return 0;
}
