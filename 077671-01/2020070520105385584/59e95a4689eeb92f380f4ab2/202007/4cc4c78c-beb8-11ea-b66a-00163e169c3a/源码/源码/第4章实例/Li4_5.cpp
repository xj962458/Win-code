//����Li4_5.cpp
//���ʹ�ͬ����ĳ�Աʱ���ܳ��ֶ�����
#include <iostream>
using namespace std;
class Base
{
	protected:
		int val;
};		
class Baseclass1:public Base
{
    public:
        void seta(int x){val=x;}
};
class Baseclass2:public Base
{
    public:
        void setb(int x){val=x;}
};
class Derivedclass:public Baseclass1,public Baseclass2 
{
    public:
		void show(){cout<<"val="<<val;}//���岻�壬���ܱ���
};
int main()
{
	Derivedclass obj;
	obj.seta(2);
    obj.show(); 
    obj.setb(4);
    obj.show(); 
	return 0;
}


