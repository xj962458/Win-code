//����Li7_5.cpp
//����ͨ�������غ���ģ��
#include <iostream>
using  namespace std;
template <typename T>//����ģ��
T max(T a, T b)
{return a>b? a:b;}
int max(int a,float b)//���غ���1
{return a>b? a:b;}
//char* max(char*a,char*b)//���غ���2
//{return strcmp(a,b)>0? a:b;}
int main( )
{
	char a='4',b='5';
    int c=5;
	cout << "max(" << "\'"<< a<<"\'" << "," <<"\'"<< b<<"\'"<< ") = ";
	cout<< max(a,b) << endl;
    cout << "max(" <<"\'"<<a<<"\'"<< ","<<b<< ") = "<< max(a,c) << endl;
	char *p,*h;
    p="qaz";
	h="wsx";
    cout << "max(" << "\""<< p<<"\"" << "," <<"\""<< h<<"\""<< ") = ";
	cout<< max(p,h) << endl;
	return 0;
}