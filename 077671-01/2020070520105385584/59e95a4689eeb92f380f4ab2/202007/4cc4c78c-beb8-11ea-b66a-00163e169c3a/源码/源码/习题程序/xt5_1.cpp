//xt5_1.cpp
#include<iostream>
using namespace std;
const double PI=3.14159265;
class Circle
{
	public:
		Circle(double r) {radius=r;}
        virtual double area(){return 0.0;}
        virtual double volume(){return 0.0;}
    protected:
        double radius;
};
class Sphere:public Circle
{
	public:
		Sphere(double r):Circle(r){}
        double area(){return 4.0*PI*radius*radius;}
        double volume(){return 4.0*PI*radius*radius*radius/3.0;}
};
class Column:public Circle
{
	public:
		Column(double r,double h):Circle(r){height=h;}
		double area(){return 2.0*PI*radius*(height+radius);}
        double volume(){return PI*radius*radius*height;}
    private:
         double height;
};
int main( )
{
	Circle *p;
	Sphere sobj(1);
	p=&sobj;
	cout<<"����:"<<endl;
	cout<<"���="<<p->volume()<<endl;
	cout<<"�����="<<p->area()<<endl;
	Column cobj(2,4);
	p=&cobj;
	cout<<"Բ����:"<<endl;
	cout<<"���="<<p->volume()<<endl;
	cout<<"�����="<<p->area()<<endl;
	return 0;
 }
