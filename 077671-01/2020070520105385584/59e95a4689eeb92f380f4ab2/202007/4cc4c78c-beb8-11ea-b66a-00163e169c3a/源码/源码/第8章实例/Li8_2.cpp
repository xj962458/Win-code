//����Li8_2.cpp
//�Լ��ֲ�ͬ�Ľ������ͬһ����
//ʾ��ios����Ĺ��о�̬���ų���������
#include <iostream>
using  namespace std;
int main( )
{
	double a=12;
	cout.setf(ios::showbase);
	cout<<"��ʮ�������12Ϊ:";
	cout.setf(ios::dec,ios::basefield);
    cout<<12<<endl;
	cout<<"�԰˽������12Ϊ:";
	cout.setf(ios::oct,ios::basefield);
    cout<<12<<endl;
	cout<<"��ʮ���������12Ϊ:";
	cout.setf(ios::hex,ios::basefield);
    cout<<12<<endl;
	return 0;
}