//����Li5_7.cpp
//�麯��˵��û��Ӱ�����Ļ����еĺ���
#include <iostream>
using namespace std;
class Base
{
	public:
		int func(int x)//�����麯��
			{
			cout <<"This is Base class ";
            return x;
			}  
};
class Subclass1 :public Base
{
	public:
		virtual int func(int x)//�麯��
			{
			cout <<"This is Sub1 class ";
			return x;
           	}
};	
class Subclass2 :public Subclass1
{
	public:
		int func(int x)//�Զ���Ϊ�麯��
			{
			cout <<"This is Sub2 class ";
			return x;
           	}
};	
void main ( )
{
   Subclass2 sc2;
   Base& bc=sc2;
   cout<<"x= "<<bc.func(5)<<endl;
   Subclass1& sc1=sc2;
   cout<<"x= "<<sc1.func(5)<<endl;
}
