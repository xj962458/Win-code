//����Li2_11.cpp
//ʾ���������������غ������÷���
#include <iostream>
using  namespace std;
inline void print(int a)//�����������β�Ϊint
{
	cout<<a<<endl;
}
int sum(int x,int y);//�����β�
int sum(int x,int y,int z);//3���β�
void print(double a);//��ͨ�������β�Ϊdouble
int main()
{
    int x1,x2;
	double y=8.6;
	x1=sum(3,4);
	cout<<"3+4=";
    print(x1);
	x2=sum(3,4,5);
    cout<<"3+4+5=";
    print(x2);
    cout<<"1 double is ";
	print(y) ;
	return 0;
} 
void print(double a)
{
	cout<<a<<endl;
}
int sum(int x,int y)//����������������͵ĺ���
{
	return x+y;
} 
int sum(int x,int y,int z)//�������3�������͵ĺ���
{
	return x+y+z;
} 