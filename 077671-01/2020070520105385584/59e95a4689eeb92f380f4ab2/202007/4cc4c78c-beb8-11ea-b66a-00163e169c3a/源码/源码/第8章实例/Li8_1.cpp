//����Li8_1.cpp
//�Լ��ֲ�ͬ�ĸ�ʽ���ͬһ������
//ʾ�����ʹ�ó�Ա������������־��
#include <iostream>
using  namespace std;
int main( )
{
	double a=12.34;
	cout<<"a="<<a<<endl;
	cout.setf(ios::showpos);
    cout.setf(0x1000);
    cout<<"a="<<a<<endl;
	return 0;
}