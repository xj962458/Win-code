//����Li5_5.cpp
//��ǡ�����麯�� 
#include <iostream>
using namespace std;
class Base
{
	public:
		virtual int func(x)//�麯����������Ϊint
			{
			cout <<"This is Base class ";
            return x;
			}  
};
class Subclass :public Base
{
	public:
		virtual float  func(int x)//�麯����������Ϊ float
			{
			cout <<"This is Sub class ";
			float y=float(x);
			return y;
           	}
};	
void test (Base& x)
{
	cout<<"x= "<<x.func(5)<<endl; 
}
void main ( )
{
   Base bc;
   Subclass sc;
   test (bc);
   test (sc);
}
