//����Li4_15.cpp
//���������������ĵ���˳��
#include <iostream>
using namespace std;
class Base1//����
{ 
    public:
        Base1(int i)//���๹�캯��
		{
		    a=i;
            cout<<"constructing Base1 a=" <<a<<endl;
		}
		~ Base1()//������������
		{
		    cout<<"destructing Base1"<<endl;
		}
    private:
        int a;
};
class Base2//�Ӷ���f������
{ 
   public:
        Base2(int i)//���캯��
		{
			b=i;
            cout<<"constructing Base2 b=" <<b<<endl;
		}
		~Base2()//��������
		{
            cout<<"destructing Base2"<<endl;
		}
    private:
        int b;		
};
class Base3//�Ӷ���g������
{ 
    public:
        Base3(int i)//���캯��
		{
			c=i;
            cout<<"constructing Base3 c=" <<c<<endl;
		}
		~Base3()//��������
		{
		    cout<<"destructing Base3"<<endl;
		}
    private:
        int c;
};
class Derivedclass:public Base1//������
{
    public:
        Derivedclass(int i,int j,int k,int m);
        ~Derivedclass();
    private:
        int d;
		Base2 f;
		Base3 g; 
};  
Derivedclass::Derivedclass(int i,int j,int k,int m):Base1(i),g(j),f(k)
//�����๹�캯��
{ 
	d=m;
    cout<<"constructing Derivedclass d="<<d<<endl;
}
Derivedclass::~Derivedclass()//��������������
{
    cout<<"destructing Derivedclass"<<endl;
}

int main()
{ 
    Derivedclass x(5,6,7,8);
	return 0;
}



