//����Li2_12.cpp
//ʾ��new��delete���÷�
#include <iostream>
using  namespace std;
int main()
{
	int *p;  
	p=new int;
	*p=25;//Ҳ�����ڴ����ʱ,Ϊ��׼����ֵ,��:p=new int(25)
	cout<<*p;
	delete p;
	return 0;
}
