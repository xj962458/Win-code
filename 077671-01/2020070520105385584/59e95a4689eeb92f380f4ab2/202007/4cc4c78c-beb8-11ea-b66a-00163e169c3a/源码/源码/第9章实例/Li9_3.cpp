//Li9_3.cpp
//ʹ���쳣�ӿ���������һ��ʾ���쳣�����ִ�й���
#include<iostream>
#include <string>
using namespace std;
void test(int) throw(int, char);//����쳣�ĺ����������쳣�ӿ�����
void handler(int i);//�����쳣�ĺ���
int main()
{
	cout << "����ʼ"<<endl;
    int i=1;
	handler(i);//���ô����쳣�ĺ���
	i=-1;
	handler(i);//���ô����쳣�ĺ���
	cout << "�������"<<endl;
	return 0;
}
void handler(int i)
{
	try
	{
		test(i); //���ü���쳣����			
	}
	catch(int) //����int���쳣
	{
		cout << "����һ��int���쳣"<<endl;
	}
	catch(char)//����char���쳣
	{
		cout << "����һ��char���쳣"<<endl;
	}
}
void test(int i) throw(int, char)
{
	if(i>0) throw i; 	// throw int
	if(i<0)  throw char(i); // throw char
	if(i==0) 
	{
		cout<<"�׳�δ�������͵��쳣�����򽫱���ֹ!"<<endl;
		throw double(i);// throw double
    }
}