//����Li4_9.cpp
//��̳з�ʽ�¹��캯���ĵ���˳��
#include <iostream>
using namespace std;
class Base1//����
{ 
    public:
        Base1(int i)// ���๹�캯��
		{
		 a=i;
         cout<<"constructing Base1 a=" <<a<<endl;
		}
	private:
        int a;	 
};
class Base2//����
{ 
    public:
        Base2(int i)// ���๹�캯��
		{
		 b=i;
         cout<<"constructing Base2 b=" <<b<<endl;
		}
	private:
        int b;	 
};
class Derivedclass:public Base1,public Base2 //������
{
    public:
        Derivedclass(int i,int j,int k);
    private:
        int d;
};  
Derivedclass::Derivedclass(int i,int j,int k):Base2(i),Base1(j)
// ������Ĺ��캯��
{ 
    d=k;
    cout<<"constructing Derivedclass d="<<d<<endl;
}
int main()
{ 
    Derivedclass x(5,6,7);
	return 0;
}

