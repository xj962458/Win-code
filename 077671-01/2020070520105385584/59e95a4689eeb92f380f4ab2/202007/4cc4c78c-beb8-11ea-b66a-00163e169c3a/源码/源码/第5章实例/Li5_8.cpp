//����Li5_8.cpp
//��Ա�����е����麯��
#include <iostream>
using namespace std;
class Base
{
	public:
		virtual void  func1()//�麯��
			{
			cout <<"This is Base func1() "<<endl;
			}
		void func2(){func1();}
};
class Subclass :public Base
{
	public:
		 virtual void func1()//�麯��
			{
			cout <<"This is Subclass func1() "<<endl;
		    }   
};	

void main ( )
{
   Subclass  sc;
   sc.func2();
}
