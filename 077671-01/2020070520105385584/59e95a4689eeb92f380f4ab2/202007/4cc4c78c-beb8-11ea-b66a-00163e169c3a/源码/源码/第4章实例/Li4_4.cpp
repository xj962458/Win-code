//����Li4_4.cpp
//���ò�ͬ�������ͬ��Աʱ���ܳ��ֶ�����
#include <iostream>
using namespace std;
class Baseclass1
{
    public:
        void seta(int x){a=x;}
	   void show(){cout<<"a="<<a<<endl;}
    private:
        int a;
};
class Baseclass2
{
    public:
        void setb(int x){b=x;}
	   void show(){cout<<"b="<<b<<endl;}
    private:
        int b;
};
class Derivedclass:public Baseclass1,public Baseclass2 
{
};
int main()
{
    Derivedclass obj;
    obj.seta(2);
    obj.show();//���ֶ����ԣ����ܱ���
    obj.setb(4);
    obj.show();//���ֶ����ԣ����ܱ���
	return 0;
}

