//����Li7_4.cpp
//����ͨ�������غ���ģ��
#include <iostream>
using  namespace std;
template <typename T>//����ģ��
T max(T a, T b)
{return a>b? a:b;}
int max(int a,float b)// ����ͨ�������غ���ģ��
{return a>b? a:b;}
int main( )
{
	char a='4',b='5';
    int c=5;
	cout << "max(" << "\'"<< a<<"\'" << "," <<"\'"<< b<<"\'"<< ") = ";
	cout<< max(a,b) << endl;
    cout << "max(" <<"\'"<<a<<"\'"<< ","<<b<< ") = "<< max(a,c) << endl;
	return 0;
}