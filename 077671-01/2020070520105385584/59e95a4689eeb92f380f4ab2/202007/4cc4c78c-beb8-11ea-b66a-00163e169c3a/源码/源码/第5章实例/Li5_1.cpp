//����Li5_1.cpp
//��̬����ĺ���
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
int main()
{
     Figure fig;//����Figure����
	 double area;
	 area=Fig.area();
	 cout<<"Area of  is figure is "<<area<<endl;
     Circle  c(3.0); // ������Circle����
	 area=c.area(); 
     cout<<"Area of circle is "<<area<<endl;
	 Rectangle rec(4.0,5.0);// ������Rectangle����
     area=rec.area(); 
	 cout<<"Area of rectangle is "<<area<<endl;
     return 0;
}
