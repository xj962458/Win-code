//xt4_1.cpp
#include<iostream>
using namespace std;
class Point                        //�������
{
    protected:
        int x,y;
    public:
        Point(int myx,int myy){x=myx;y=myy;}
        void displayxy()
		{
			cout<<"("<<x<<","<<y<<")"<<endl;
		}

};
class Rectangle:public Point          //���������࣬���м̳з�ʽ
{                       
    private:
        int l,w;
    public:                                    
        Rectangle(int myx,int myy,int myl,int myw):Point(myx,myy)
		{l=myl;w=myw;}
        void displaylw()
		{
			cout<<l<<","<<w;
		}
};
class Cube:public Rectangle    //���������࣬���м̳з�ʽ
{
     private:
    	int h;
     public:
    	Cube(int myx,int myy,int myl,int myw,int myh):Rectangle(myx,myy,myl,myw)
		{h=myh;}
		void displayh(){cout<<h<<endl;}
};
int main()
{
     Cube v(20,40,3,5,6);                // ���������
	 cout<<"The data of cube:"<<endl;
     cout<<"The postion of cube:";
	 v.displayxy();
	 cout<<"The length, width and height of cube:";
	 v.displaylw();
	 cout<<",";
	 v.displayh();
	 return 0;
}
