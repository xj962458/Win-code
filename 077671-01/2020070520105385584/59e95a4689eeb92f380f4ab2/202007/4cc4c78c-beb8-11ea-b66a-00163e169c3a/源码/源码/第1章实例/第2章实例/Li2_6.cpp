//����Li2_6.cpp
//ʾ������ԭ�����Ĭ�ϲ����ĺ������÷���
#include <iostream>
using  namespace std;
int sum(int ,int=9 );//�������������͵ĺ���ԭ�� 
int main()
{
	int a,b,sum1,sum2;
	cout<<"please input 2 integers to a,b"<<endl;
	cin>>a>>b;
	sum1=sum(a,b);//��a��b�ĺ�
    cout<<"a+b="<<sum1<<endl;//���a��b�ĺ�
    sum2=sum(a);//��a��Ĭ��ֵ�ĺ�
	cout<<"a+?="<<sum2<<endl;//���a��Ĭ��ֵ�ĺ�
	return 0;
}
int sum(int x,int y)//����������������͵ĺ���
{return x+y;} 