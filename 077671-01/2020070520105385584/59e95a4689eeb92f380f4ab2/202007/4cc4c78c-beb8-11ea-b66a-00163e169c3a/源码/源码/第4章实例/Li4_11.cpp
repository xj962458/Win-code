//����Li4_11.cpp
//����û�й��캯��ʱ�������๹�캯���Ĺ���
#include <iostream>
using namespace std;
class Baseclass
{ 
   private:
       int a;
};
class Derivedclass:public Baseclass
{
    public:
        Derivedclass();//������ȱʡ���캯��
        Derivedclass(int i); //�������вι��캯��
    private:
       int b; 
};  
Derivedclass::Derivedclass()
{
    cout<<"default constructor Derivedclass"<<endl;  
}	 
Derivedclass::Derivedclass(int i)
{ 
    b=i;
    cout<<"constructing Derivedclass b="<<b<<endl;
}
int main()
{ 
    Derivedclass x1(5);
    Derivedclass x2;
	return 0;
}

