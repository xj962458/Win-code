//����Li4_2.cpp
//˽�м̳�����
#include <iostream>
using namespace std;
class Point                       //�������
{    
    public:
        void setxy(int myx,int myy){X=myx;Y=myy;}
		void movexy(int x,int y){X+=x;Y+=y;}
    protected:
        int X,Y;
};
class Circle : private Point         //����������
{                       
    public:                                    
        void setr(int myx,int myy,int myr)
		{setxy(myx,myy);R=myr;}	
        void movexy(int x,int y){Point::movexy(x,y);}
        void display();
	private:
        int R;
};
void Circle::display()
{
    cout<<"The postion of center is ";
	cout<<"("<<X<<","<<Y<<")"<<endl;
	cout<<"The radius of Circle is "<<R<<endl;
}
int main()
{
     Circle  c; // ���������
	 c.setr(4,5,6);
	 cout<<"The start data of Circle:"<<endl;
	 c.display();
	 c.movexy(7,8);
     cout<<"The new data of Circle:"<<endl;
	 c.display();
	 return 0;
}
