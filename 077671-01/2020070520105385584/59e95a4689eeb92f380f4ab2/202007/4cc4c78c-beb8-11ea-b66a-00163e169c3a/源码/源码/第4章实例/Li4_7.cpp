//����Li4_7.cpp
//���̳л����¹��캯���ĵ���˳��
#include <iostream>
using namespace std;
class Baseclass
{
	public:
        Baseclass(int i)// ����Ĺ��캯��
	{
		 a=i;
         cout<<"constructing Baseclass a=" <<a<<endl;
	}
	private:
        int a;	
};
class Derivedclass:public Baseclass
{
    public:
        Derivedclass(int i,int j);
    private:
        int b;
};  
Derivedclass::Derivedclass(int i,int j):Baseclass(i)// ������Ĺ��캯��
{ 
	b=j;
    cout<<"constructing Derivedclass b="<<b<<endl;
}
int main()
{ 
    Derivedclass x(5,6);
	return 0;
}



