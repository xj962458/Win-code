//����Li2_3.cpp
//���ָ���ֵ����ַ��ָ����ָ��Ķ����ֵ����ַ�ĺ���
#include <iostream>
using namespace std;
int main()
{
	int icount=36;
	int * pointer=&icount;
	*pointer=95;
	cout<<icount<<endl;
	cout<<pointer<<endl;
	cout<<&icount<<endl;      //��pointerֵ��ͬ
	cout<<* pointer<<endl;   //��icountֵ��ͬ
	cout<<&pointer<<endl;    //ָ�뱾��ĵ�ַ
	return 0;
}
