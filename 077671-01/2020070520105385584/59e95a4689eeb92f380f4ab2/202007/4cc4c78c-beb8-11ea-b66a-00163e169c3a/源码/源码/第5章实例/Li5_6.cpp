//����Li5_6.cpp
//��ʧ������
#include <iostream>
using namespace std;
class Base
{
	public:
		virtual int func(int x)//�麯��,�β�Ϊint��
			{
			cout <<"This is Base class ";
            return x;
			}  
};
class Subclass :public Base
{
	public:
		virtual int func(float x)//�麯�����β�Ϊfloat��
			{
			cout <<"This is Sub class ";
			int y=float(x);
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
