//����Li5_2.cpp
//��̬���������
#include <iostream>
const double PI=3.14;
using namespace std;
class Figure                       //�������
{    
    public:
        Figure(){};
		double area() const {return 0.0;}
};
class Circle : public Figure           //���������࣬���м̳з�ʽ
{                       
    public:                                    
        Circle(double myr){R=myr;}
		double area() const {return PI*R*R;}
	protected:
        double R;
};
class Rectangle : public Figure           //���������࣬���м̳з�ʽ
{                       
    public:                                    
        Rectangle (double myl,double myw){L=myl;W=myw;}
		double area() const {return L*W;}
	private:
        double L,W;
};
void func(Figure &p)//�β�Ϊ�����������
{
	cout<<p.area()<<endl;
}
double main()
{
	Figure fig;//����Figure����
    cout<<"Area of  is Figure is ";
    func(fig);
	Circle  c(3.0); // Circle���������
    cout<<"Area of circle is ";
    func(c);
    Rectangle rec(4.0,5.0);// Rectangle���������
	cout<<"Area of rectangle is ";
    func(rec);
	return 0;
}
