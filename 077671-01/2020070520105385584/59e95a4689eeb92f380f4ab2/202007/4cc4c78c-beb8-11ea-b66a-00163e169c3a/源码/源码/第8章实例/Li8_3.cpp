//����Li8_3.cpp
//ʾ�����ʹ��ios��ĳ�Ա����������������ַ����������
#include <iostream>   
#include <string>   
using namespace std;
int main()   
{
    double values[] = {1.23,35.36,653.7,4358.24};
    char *names[] = {"aaaaaaa", "bbbb", "ccccc", "dddddd"};
	for (int i=0;i<4;i++)
	{
		cout.setf(ios::left);//���������
	    cout.fill('*');//�����ַ�Ϊ*
        cout.width(10);//�������Ϊ10
	    cout.precision(5);//�������Ϊ5
        cout<<names[i]<<values[i]<< endl;
    }
	return 0;
}