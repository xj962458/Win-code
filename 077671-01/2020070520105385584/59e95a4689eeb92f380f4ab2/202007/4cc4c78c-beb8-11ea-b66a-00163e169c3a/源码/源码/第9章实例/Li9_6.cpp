//Li9_6.cpp
//�쳣�����еĹ���������
#include<iostream>
#include <string>
using namespace std;
void test(int) throw(int, char);//����쳣�ĺ���
void handler(int i);//�����쳣�ĺ���
class Demo//����һ��������ʾ����
{
	public:
		Demo();
		~ Demo( );
		static k;
    private:
		int d;

};
Demo::Demo()
{
	k=k+1;
	d=k;
	cout<<"����Demo,d="<<d<<endl;
}
Demo:: ~ Demo( )
{
	cout<<"���� Demo,d="<<d<<endl;
}
int Demo::k=0;
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
	Demo D;
	try
	{
		test(i); //���ü���쳣����			
	}
	catch(int) //����int���쳣
	{
		cout << "����һ��int���쳣."<<endl;
	}
	catch(char)//����char���쳣
	{
		cout << "����һ��char���쳣."<<endl;
	}
}
void test(int i) throw(int, char)
{
	Demo D;
	if(i>0) throw i; 	// throw int
	if(i<0)  throw char(i); // throw char
}
