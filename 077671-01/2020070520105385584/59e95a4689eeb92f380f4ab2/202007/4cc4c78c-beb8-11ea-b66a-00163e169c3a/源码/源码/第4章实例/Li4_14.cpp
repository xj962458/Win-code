//����Li4_14.cpp
//������ȱʡ���캯��ʱ�������๹�캯���Ĺ���
#include <iostream>
using namespace std;
class Baseclass
{ 
   public:
        Baseclass(int i)
		{
		    a=i;
            cout<<"constructing Baseclass a="<<a<<endl;
		}
	private:
        int a;	 
};
class Derivedclass:public Baseclass 
{
    public:
        Derivedclass(int i);
        Derivedclass(int i,int j);
    private:
        int b;
};  
Derivedclass::Derivedclass(int i) //������û����ʽ���û��๹�캯��
{ 
    b=i;
    cout<<"constructing Derivedclass b="<<b<<endl;
} 
Derivedclass::Derivedclass(int i,int j):Baseclass(i)
{ 
    b=j;
    cout<<"constructing Derivedclass b="<<b<<endl;
}
int main()
{ 
    Derivedclass x1(5,6);
    Derivedclass x2(7);
	return 0;
}



