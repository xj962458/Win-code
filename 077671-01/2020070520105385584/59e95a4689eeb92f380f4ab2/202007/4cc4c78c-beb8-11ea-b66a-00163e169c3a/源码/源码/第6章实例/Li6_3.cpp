//����Li6_3.cpp
//��Ա���������������Ԫ�ӡ���
#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double r=0.0,double i=0.0);
    Complex operator +(Complex c);//���ض�Ԫ��
    Complex operator -(Complex c);//���ض�Ԫ��
	void display();
private:
    double real,imag;
};
Complex ::Complex(double r,double i)
{
   real=r;imag=i;
}
Complex Complex:: operator+(Complex c)
{ 
  Complex temp;
  temp.real=real + c.real;
  temp.imag=imag + c.imag;
  return temp; 
}
Complex Complex:: operator-(Complex c)
{ 
  Complex temp;
  temp.real=real - c.real;
  temp.imag=imag - c.imag;
  return temp; 
}
void Complex::display() 
{  
	char* str;
    str=(imag<0)?"":"+";
	cout<<real<<str<<imag<<"i"<<endl; 
}
int main()
{
  Complex c1(12.4,13.3),c2(14.4,26.5);
  Complex c;
  cout<<"c1=";
  c1.display();
  cout<<"c2=";
  c2.display();
  c=c1+c2;     //c=c1.operator + (c2);
  cout<<"c1+c2=";
  c.display();
  c=c1-c2; //c=c1.operator - (c2);
  cout<<"c1-c2=";
  c.display();
  return 0;
}
