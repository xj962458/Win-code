//Li8_6.cpp
//������Ĵ����������ִ���ʾ�����ó�Ա����I/O
#include <iostream>
using namespace std;
int main()
{
	char str[10];
	int i=0;
	cout<<"����һ���ַ��������9���ַ���";
	cin.get(str,10,'!');//����һ���ַ���
	char c=str[i];
	cout<<"���ִ�Ϊ��"<<endl;
	while (i<cin.gcount())
	{
	if (isdigit(c))//������ִ�
		cout.put(c);
	if(isdigit(c)&&!isdigit(str[i+1]))
		cout<<endl;
	i=i+1;
	c=str[i]; 
	}
	cout<<endl;
	return 0;
}	


