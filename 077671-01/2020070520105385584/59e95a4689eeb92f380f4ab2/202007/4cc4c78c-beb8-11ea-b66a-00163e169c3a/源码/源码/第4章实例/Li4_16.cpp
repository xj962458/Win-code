//����Li4_16.cpp
//Ӧ��ʵ��
#include<iostream>
using namespace std;
class Point                        //�������
{
    public:
        Point(int myx,int myy){x=myx;y=myy;}
        void displayxy()
		{
			cout<<"The postion of center:";
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
	protected:
        int x,y;//���ܶ���Ϊ˽�г�Ա����ö���Ϊ������Ա
};
class Circle:public Point          //���������࣬���м̳з�ʽ
{                       
    public:                                    
        Circle(int myx,int myy,int myr):Point(myx,myy)
		{r=myr;}
        void displayr(){cout<<"The radius of circle:"<<r<<endl;}
    private:
        int r;
};
class Cylinder:public Circle         //���������࣬���м̳з�ʽ
{
    public:
    	Cylinder(int myx,int myy,int myr,int myh):Circle(myx,myy,myr)
		{h=myh;}
		void displayh(){cout<<"The height of cylinder :"<<h<<endl;}
    private:
    	int h;
};
int main()
{
     Cylinder  v(4,5,6,8);                // ���������
	 cout<<"The data of cylinder:"<<endl;
	 v.displayxy();
	 v.displayr();
	 v.displayh();
	 return 0;
}
