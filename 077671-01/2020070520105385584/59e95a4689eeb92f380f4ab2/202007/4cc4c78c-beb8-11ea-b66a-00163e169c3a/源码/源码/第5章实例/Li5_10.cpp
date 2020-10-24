//����Li5_10.cpp
//ʹ�ô��麯��
#include <iostream>
const double PI=3.14;
using namespace std;
class Figure                       //�������
{    
    public:
        Figure(){};
		virtual double area() const =0;//����Ϊ���麯��
};
class Circle : public Figure           //���������࣬���м̳з�ʽ
{                       
    public:                                    
        Circle(double myr){R=myr;}
		virtual double area() const {return PI*R*R;}//����Ϊ�麯��
	protected:
        double R;
};
class Rectangle : public Figure           //���������࣬���м̳з�ʽ
{                       
    public:                                    
        Rectangle (double myl,double myw){L=myl;W=myw;}
		virtual double area() const {return L*W;}//����Ϊ�麯��
	private:
        double L,W;
};
void func(Figure &p)//�β�Ϊ���������
{
	cout<<p.area()<<endl;
}
double main()
{
	Circle  c(3.0); // Circle���������
    cout<<"Area of circle is ";
    func(c);
    Rectangle rec(4.0,5.0);// Rectangle���������
	cout<<"Area of rectangle is ";
    func(rec);
	return 0;
}
