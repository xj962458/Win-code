//����Li2_5.cpp
//ͨ�����������͵ĺ�������3�����ĺ�
#include <iostream>
using  namespace std;
int sum(int x,int y)//����������������͵ĺ���
{return x+y;} 
int main()
{
	int a,b,c,sum1,total;
	cout<<"please input 3 integers to a,b,c "<<endl;
	cin>>a>>b>>c;
	sum1=sum(a,b);//���ú��������������ĺ�
    total=sum(sum1,c);//���ú��������������ĺ�
    cout<<"a+b+c="<<total<<endl;//���3�������ĺ�
	return 0;
}
