//����Li6_6.cpp
//���ظ�ֵ�����
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
        ~ Namelist ()
		{
         delete [] name ;
		}
        Namelist& operator=(char *p );
	    Namelist& operator=( Namelist& );	
        void display(){cout<<name<<endl;}
};
Namelist& Namelist::operator=( char *p)//
//���ظ�ֵ�����������ó���������ֵ
{
    name= new char[strlen(p)+1];
	if (name!=0) strcpy(name,p);
    return *this;
}	
Namelist& Namelist::operator=( Namelist& a)
//���ظ�ֵ���������������֮��ĸ�ֵ
{
	if (this!=&a)
    {
		delete name;
		name=new char[strlen(a.name)+1];
		if (name!=0) strcpy(name,a.name);
	
	}
	return *this;
}	
int main()
{
	Namelist n1("right object"),n2("left object");
    cout<<"��ֵǰ�����ݣ�"<<endl;
    n1.display();
	n2.display();
    cout<<"��ֵ������ݣ�"<<endl;
    n2=n1;
	n1.display();
	n2.display();
	return 0;
}


