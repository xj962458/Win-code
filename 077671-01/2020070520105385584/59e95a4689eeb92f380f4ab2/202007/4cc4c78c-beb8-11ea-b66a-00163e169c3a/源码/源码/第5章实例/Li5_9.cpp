//����Li5_9.cpp
//���캯�������������е����麯��
#include <iostream>
using namespace std;
class Base
{
	public:
		Base(){func1();}
		virtual void  func1()//�麯��
			{
			cout <<"This is Base func1() "<<endl;
			}
		virtual void func2()
			{
            cout <<"This is Base func2() "<<endl;
			}
        ~Base(){func2();}
};
class Subclass :public Base
{
	public:
		 virtual void func1()//�麯��
			{
			cout <<"This is Subclass func1() "<<endl;
		    } 
		 virtual void func2()//�麯��
			{
			cout <<"This is Subclass func2() "<<endl;
		    }   
};	

void main ( )
{
   Subclass  sc;
   cout<<"Exit main"<<endl;
}
