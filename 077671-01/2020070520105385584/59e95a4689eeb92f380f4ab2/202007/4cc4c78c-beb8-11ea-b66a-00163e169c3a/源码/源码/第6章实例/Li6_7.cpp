//����Li6_7.cpp
//�Ƚ���������غ����뿽�����캯��������
#include <iostream>
using namespace std;
#include <cstring>
class Namelist
{
    char *name;
	public:
        Namelist (char *p)
		{
         name= new char[strlen(p)+1];
	     if (name!=0) strcpy(name,p);
		}
        Namelist(){ };
		Namelist(Namelist&);
        Namelist& operator=(char *p );
	    Namelist& operator=(  Namelist& );	
        void display(){cout<<name<<endl;}
		~ Namelist ()
		{
         delete [] name ;
		}
};
Namelist::Namelist(Namelist& a)//���忽�����캯��
{
    name= new char[strlen(a.name)+1];
	if (name!=0) strcpy(name,a.name);
}
Namelist& Namelist::operator=( char *p)//
//��һ�����ظ�ֵ�����������ó���������ֵ
{
    name= new char[strlen(p)+1];
	if (name!=0) strcpy(name,p);
    return *this;
}	
Namelist& Namelist::operator=(  Namelist& a)
//�ڶ������ظ�ֵ���������������֮��ĸ�ֵ
{
	if (this!=&a)
    {
		delete[] name;
		name=new char[strlen(a.name)+1];
		if (name!=0) strcpy(name,a.name);
	}
	return *this;
}	
int main()
{
	Namelist n1("first object"),n2("second object"),n3;
    cout<<"��ֵǰ�����ݣ�"<<endl;
	n1.display();
	n2.display();
    n3="third object";//���õ�һ�����ظ�ֵ���������
    n2=n1;//���õڶ������ظ�ֵ���������
	Namelist n4(n2);//���ÿ������캯������
	cout<<"��ֵ������ݣ�"<<endl;
	n1.display();
	n2.display();
	n3.display();
	n4.display();
	return 0;
}



